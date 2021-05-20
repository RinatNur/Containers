//
// Created by Rinat Nurutdinow on 4/15/21.
//

#ifndef CONT_MY_LIST_HPP
#define CONT_MY_LIST_HPP


#include <iostream>
#include <iterator>
#include "Reverse_iterator.hpp"
#include "Node.hpp"
#include "Algorithm.hpp"

namespace ft {

template <typename T>
class iterator {
public:
	typedef T							value_type;
//	typedef ft::DataNode<value_type>	DataNode;
	typedef ft::Node<value_type>		node;
	typedef node*						node_pointer;
//	typedef d difference_type;

public:
	iterator(node_pointer node) : m_node(node) {}
	iterator() : m_node(0) {}

	iterator(const iterator& rhs) : m_node(rhs.m_node) {};
	virtual ~iterator(){};

	iterator const& operator=(const iterator& rhs) {
		this->m_node = rhs.m_node;
		return *this;
	}
	iterator &operator++() {
		m_node = m_node->next();
		return *this;
	}
	iterator operator++(int) {
		iterator tmp(*this);
		operator++();
		return tmp;
	}// postfix increment operator

	iterator &operator--() {
		m_node = m_node->previous();
		return *this;
	}// prefix decrement operator

	iterator operator--(int) {
		iterator tmp(*this);
		operator--();
		return tmp;
	}// postfix decrement operator

	bool operator==(const iterator& rhs) const { return this->m_node == rhs.m_node; }
	bool operator!=(const iterator& rhs) const { return this->m_node != rhs.m_node; }
	T & operator*() { return (m_node->getValue()); }

	node_pointer  getNode() const { return this->m_node; }

private:

	node_pointer m_node;

};
//TODO intergrate disconnect function
template<class T, class Alloc = std::allocator<T> >
class List {
public:

	typedef T							value_type;
	typedef Alloc						allocator_type;
	typedef value_type&					reference;
	typedef const value_type*			const_reference;
	typedef value_type*					pointer;
	typedef const value_type*			const_pointer;
	typedef ft::iterator<value_type>	iterator;
	typedef const iterator				const_iterator;
	typedef ft::Reverse_iterator<T>		reverse_iterator;
	typedef const reverse_iterator		const_reverse_iterator;
	typedef std::ptrdiff_t				difference_type;
	typedef size_t						size_type;
//	typedef ft::DataNode<value_type>	DataNode;
//	typedef DataNode*					DataNode_pointer;
	typedef ft::Node<value_type>		node;
	typedef node*						node_pointer;
	typedef typename List<value_type>::iterator it_type;

public:
	explicit List(const allocator_type& alloc = allocator_type()) : m_sentinal(new node), m_size(0) {}
	explicit List (size_type n, const value_type& val = value_type(),
	const allocator_type& alloc = allocator_type()) : m_sentinal(new node), m_size(0) {
		for (int i = 0; i < n; ++i)
			this->push_back(val);
	}
	List (iterator first, iterator last,
	const allocator_type& alloc = allocator_type()) : m_sentinal(new node), m_size(0) {
		while (first != last)
		{
			push_back(*first);
			++first;
		}
	}
	List (const List& x): m_sentinal(new node), m_size(0){
		this->assign(x.begin(),x.end());
	}

	~List(){
//		std::cout << "List destructor called" << std::endl;
//		clear();
		if (m_sentinal)
			delete m_sentinal;
	}

	//ITERATORS
	iterator begin() { return iterator(m_sentinal->next()); }
	const_iterator begin() const { return const_iterator(m_sentinal->next()); }

	iterator end() { return iterator(m_sentinal); }
	const_iterator end() const { return const_iterator(m_sentinal); }

	reverse_iterator rbegin() {
		return reverse_iterator(m_sentinal->previous()); }
	reverse_iterator rend() { return reverse_iterator(m_sentinal); }

	//Capacity

	bool empty() const{
		return (this->begin() == this->end());
	}

	size_type size() const{
		return (this->m_size);
	}

	size_type max_size() {
		return std::numeric_limits<size_type>::max() / sizeof(Node<T>);
	}

	//Element access:

	reference front(){
		return this->m_sentinal->next()->getValue();
	}
	const_reference front() const{
		return this->m_sentinal->next()->getValue();
	}

	reference back(){
		return this->m_sentinal->previous()->getValue();
	}
	const_reference back() const{
		return this->m_sentinal->previous()->getValue();
	}

	//Modifiers
	template <class InputIterator>
	void assign (InputIterator first, InputIterator last, typename enable_if<!std::numeric_limits<InputIterator>::is_specialized>::type * = 0){
		this->clear();
		for (; first != last; ++first)
			this->push_back(*first);
	}

	void assign (size_type n, const value_type& val){
		this->clear();
		for (int i = 0; i < n; ++i)
			this->push_back(val);
	}

	iterator insert(iterator position, T data) {
		node_pointer data_node = new node;
		data_node->setValue(data);
		node_pointer tmp = position.getNode();
		data_node->setNext(tmp);
		data_node->setPrevious(tmp->previous());
		tmp->previous()->setNext(data_node); // tmp->previous() = m_sentinal
		tmp->setPrevious(data_node);
		++this->m_size;
		tmp = tmp->previous();
		return iterator(tmp);
	}

	iterator erase (iterator position) {
		node_pointer tmp = position.getNode();
		tmp->next()->setPrevious(tmp->previous());
		tmp->previous()->setNext(tmp->next());
		delete tmp;
		if (this->m_size > 0)
			--this->m_size;
		return iterator(++position);
	}

	iterator erase (iterator first, iterator last){
		node_pointer first_ptr = first.getNode();
		node_pointer last_ptr = last.getNode()->previous();
		first_ptr->previous()->setNext(last_ptr->next());
		last_ptr->next()->setPrevious(first_ptr->previous());
		for (; first != last; ++first)
			delete first.getNode();
		if (this->m_size > 0)
			--this->m_size;
		return (++last);
	}

	void resize (size_type n, value_type val = value_type()){
		iterator it = this->begin();
		if (n <= this->m_size)
		{
			for (int i = 0; i < n ; ++i)
				++it;
			for(; it != this->end(); ++it)
				erase(it);
		}
		else
		{
			for (int i = this->m_size; i < n; ++i)
				insert(this->m_sentinal, val);
		}
		this->m_size = n;
	}

	void clear(){
		int count = 0;
		if (!this->empty()) {
			for (it_type it = this->begin(); it != this->end(); ++it)//TODO invalid read in operator++;
			{
				delete it.getNode();
				--this->m_size;
			}
		}
		delete m_sentinal;
		m_sentinal = new node;
		this->m_size = 0;
	}

	void push_back(T data) {
		insert(end(), data);
	}

	void push_front(T data) {
		insert(begin(), data);
	}

	void pop_back() {
		erase(this->m_sentinal->previous());
		if (this->m_size > 0)
			--this->m_size;
	}

	void pop_front() {
		erase(this->begin());
		if (this->m_size > 0)
			--this->m_size;
	}

	//Operations:

	void splice (iterator position, List& x){
		splice(position, x, x.begin(), x.end());
	};

	void splice (iterator position, List& x, iterator i){
		splice(position, x, i, ++i);
	};

	void splice (iterator position, List& x, iterator first, iterator last){
		if (first == last)
			return ;
		int sizeOfCutSection = ft::distance(first, last);
		it_type	 tmp_target = position;
		--position;
		it_type endOfCutSection = last;
		--endOfCutSection;
		//change this list
		first.getNode()->previous()->setNext(last.getNode()); // link from "first" to "last"
		last.getNode()->setPrevious(first.getNode()->previous()); // link "last" to "before first" node

		//change x list
		first.getNode()->setPrevious(position.getNode()); // link "first" to "position" node
		position.getNode()->setNext(first.getNode()); // link "position" to "firs" node
		endOfCutSection.getNode()->setNext(tmp_target.getNode()); // link "last of cut section" to "after cut section" node
		tmp_target.getNode()->setPrevious(endOfCutSection.getNode()); // link "after cut section" to "last of cut section" node

		//change size of both lists
		this->m_size += sizeOfCutSection;
		x.m_size -= sizeOfCutSection;
	};

	void remove (const value_type& val){
		for (it_type it = this->begin(); it != this->end(); ++it)
		{
			if (*it == val)
				this->erase(it);
		}
	}

	template <class Predicate>
	void remove_if (Predicate pred){
		for (it_type it = this->begin(); it != this->end(); ++it)
		{
			if (pred(*it))
				this->erase(it);
		}
	}

	void unique(){
		unique(&_isEqual);
	}

	template <class BinaryPredicate>
	void unique (BinaryPredicate binary_pred){
		it_type first = this->begin();
		it_type it = first;
		++it;
		for (; it != this->end(); ++it)
		{
			if (binary_pred(*it, *first)) {
				erase(it);
				if (++it == this->end())
					break;
			}
			++first;
		}
	}

	void merge (List& x){
		this->merge(x, &_isLower);
	}

	template <class Compare>
	void merge (List& x, Compare comp) {
		if (&x == this)
			return ;
		if (x.empty())
			return ;
		if (this->m_size == 0)
		{
			this->assign(x.begin(), x.end());
			x.clear();
			return ;
		}
		it_type b1 = this->begin();
		it_type e1 = this->end();
		it_type b2 = x.begin();
		it_type e2 = x.end();
		while (b1 != e1 && b2 != e2)
		{
			if ((*comp)(*b2, *b1))
			{
				this->splice(b1, x, b2);
				b2 = x.begin();
			}
			else
				++b1;
		}
		this->splice(this->end(), x);
	}

	void sort(){
		this->sort(&_isLower);
	}

	template <class Compare>
	void sort (Compare comp){
		// Do nothing if the list has length 0 or 1.
		if (this->m_size && this->m_size != 1)
		{
			List carry;
			List tmp[64];
			List * fill = &tmp[0];
			List * counter;
			do
			{
				carry.splice(carry.begin(), *this, begin());

				for(counter = &tmp[0]; counter != fill && !counter->empty(); ++counter)
				{
					counter->merge(carry, comp);
					carry.swap(*counter);
				}
				carry.swap(*counter);
				if (counter == fill)
					++fill;
			}
			while ( !empty() );
			for (counter = &tmp[1]; counter != fill; ++counter)
				counter->merge(*(counter - 1), comp);
			this->swap(*(fill - 1));
		}
	}

	void reverse(){
		if (this->m_size <= 1)
			return ;
		it_type begin = this->begin();
		it_type end = this->end();
		size_t size = this->m_size / 2;
		for (int i = 0; i < size; ++i)
		{
			this->swap(*(begin++), *(--end));
		}
//		it_type last, it, itToSplice;
//		itToSplice = this->begin();
//		for (it = this->begin(); it != this->end(); ++it) {
////			last = this->end();
//			this->splice(itToSplice, *this, --this->end());
//			printList(*this);
//		}
//		this->splice(itToSplice, *this, --this->end());
//		printList(*this);
	}

		void swap(List<value_type , Alloc>& x) {
			ft::swap(this->m_sentinal, x.m_sentinal);
			ft::swap(this->m_size, x.m_size);
		}
private:
	node_pointer	m_sentinal;
	size_type		m_size;

	static bool _isEqual (value_type& first, value_type& second)
	{ return ( first == second ); }
	static bool _isLower (value_type& first, value_type& second)
	{ return ( first < second ); }
	void printList(const ft::List<T>& list) {
		typename ft::List<T>::iterator it_begin = list.begin();
		for (; it_begin != list.end(); ++it_begin)
			std::cout << ' ' <<  *(it_begin);
		std::cout << std::endl;
	}//TODO delete

}; //list_end

	template <class T, class Alloc>
	bool operator== (const List<T,Alloc>& lhs, const List<T,Alloc>& rhs) {
		if (lhs.size() != rhs.size())
			return false;
		iterator lit = lhs.begin();
		iterator rit = rhs.begin();
		for(; lit != lhs.end(); ++lit)
		{
			if (*lit != *(rit++))
				return false;
		}
		return true;
	}

	template <class T, class Alloc>
	bool operator!= (const List<T,Alloc>& lhs, const List<T,Alloc>& rhs){
		return (!(lhs == rhs));
	}

	template <class T, class Alloc>
	bool operator<  (const List<T,Alloc>& lhs, const List<T,Alloc>& rhs){
		if (lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()))
			return true;
		return false;
	}

	template <class T, class Alloc>
	bool operator<= (const List<T,Alloc>& lhs, const List<T,Alloc>& rhs){
		return (!(rhs < lhs));
	}

	template <class T, class Alloc>
	bool operator>  (const List<T,Alloc>& lhs, const List<T,Alloc>& rhs){
		if (lhs < rhs || lhs == rhs)
			return false;
		return true;
	}

	template <class T, class Alloc>
	bool operator>= (const List<T,Alloc>& lhs, const List<T,Alloc>& rhs){
		return (!(lhs < rhs));
	}


	template <class T, class Alloc>
	void swap (List<T,Alloc>& x, List<T,Alloc>& y){
		x.swap(y);
	}

} //ft_end

#endif //CONT_MY_LIST_HPP
