//
// Created by Rinat Nurutdinow on 4/15/21.
//

#ifndef CONT_MY_LIST_HPP
#define CONT_MY_LIST_HPP


#include <iostream>
#include <iterator>
#include "Reverse_iterator.hpp"
#include "Node.hpp"

namespace ft {
template <typename T>
class iterator {
public:
	typedef T							value_type;
	typedef ft::DataNode<value_type>	DataNode;
	typedef ft::Node					node;
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
		m_node = m_node->next;
		return *this;
	}
	iterator operator++(int) {
		iterator tmp(*this);
		operator++();
		return tmp;
	}// postfix increment operator

	iterator &operator--() {
		m_node = m_node->previous;
		return *this;
	}// prefix decrement operator

	iterator operator--(int) {
		iterator tmp(*this);
		operator--();
		return tmp;
	}// postfix decrement operator

	bool operator==(const iterator& rhs) const { return this->m_node == rhs.m_node; }
	bool operator!=(const iterator& rhs) const { return this->m_node != rhs.m_node; }
	T & operator*() { return reinterpret_cast<DataNode *>(m_node)->data; }

	node_pointer  getNode() const { return this->m_node; }

private:

	node_pointer m_node;

};

template<class T, class Alloc = std::allocator<T> >
class List {
public:

	typedef T							value_type;
	typedef Alloc						allocator_type;
	typedef value_type&					reference;
	typedef const value_type*			const_reference;
	typedef value_type*					pointer;
	typedef const value_type*			const_pointer;
	typedef ft::iterator<T>				iterator;
	typedef const iterator				const_iterator;
	typedef ft::Reverse_iterator<T>		reverse_iterator;
	typedef const reverse_iterator		const_reverse_iterator;
	typedef std::ptrdiff_t				difference_type;
	typedef size_t						size_type;
	typedef ft::DataNode<value_type>	DataNode;
	typedef DataNode*					DataNode_pointer;
	typedef ft::Node					node;
	typedef node*						node_pointer;

public:

	List(const allocator_type& alloc = allocator_type()) : m_sentinal(new node), size(0) {}
	explicit List (size_type n, const value_type& val = value_type(),
				const allocator_type& alloc = allocator_type()) : m_sentinal(new node), size(n){

	};
	~List(){
		std::cout << "List destructor called" << std::endl;
		clear();
		if (m_sentinal)
			delete m_sentinal;
	}
	iterator begin() const { return iterator(m_sentinal->next); }
	iterator end() const { return iterator(m_sentinal); }

	reverse_iterator rbegin() {
		return reverse_iterator(m_sentinal->previous); }
	reverse_iterator rend() { return reverse_iterator(m_sentinal); }

	iterator insert(iterator position, T data) {
		DataNode* data_node = new DataNode;
		data_node->data = data;
		node_pointer tmp = position.getNode();
		data_node->next = tmp;
		data_node->previous = tmp->previous;
		tmp->previous->next = data_node; // tmp->previous = m_sentinal
		tmp->previous = data_node;
		++this->size;
		return iterator(tmp);
	}

	iterator erase (iterator position) {
		node_pointer tmp = position.getNode();
		tmp->next->previous = tmp->previous;
		tmp->previous->next = tmp->next;
		delete tmp;
		return iterator(++position);
	}

	iterator erase (iterator first, iterator last){
		node_pointer first_ptr = first.getNode();
		node_pointer last_ptr = last.getNode()->previous;
		first_ptr->previous->next = last_ptr->next;
		last_ptr->next->previous = first_ptr->previous;
		for (; first != last; ++first)
			delete first.getNode();
		return (++last);
	}

//	void resize (size_type n, value_type val = value_type()){
//		iterator it = this->begin();
//		if (n < this->size)
//		{
//			for (int i = 0; i < n ; ++i)
//				++it;
//			for(; it != this->end(); ++it)
//				delete it.getNode();
//		}
//	};

	void clear(){
		for (typename List<value_type>::iterator it = this->begin(); it != this->end(); ++it)//TODO invalid read in operator++;
			delete it.getNode();
		delete m_sentinal;
		m_sentinal = new node;
		this->size = 0;
	};

	void push_back(T data) {
		insert(end(), data);
	}
	void push_front(T data) {
		insert(begin(), data);
	}

private:
	node_pointer	m_sentinal;
	size_type		size;
};
}

#endif //CONT_MY_LIST_HPP
