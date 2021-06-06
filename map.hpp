//
// Created by Jamis Heat on 6/2/21.
//

#ifndef CONT_MY_MAP_HPP
#define CONT_MY_MAP_HPP

#include <map_node.hpp>

namespace ft {
	template<class T>
	class MapIterator {
	public:
		typedef T							value_type;
		typedef MapIterator					iterator;
		typedef value_type&					reference;
		typedef const value_type&			const_reference;
		typedef value_type*					pointer;
		typedef const value_type*			const_pointer;
		typedef std::ptrdiff_t				difference_type;
		typedef ft::MapNode<value_type>		node;
		typedef node*						node_pointer;
	private:
		node_pointer m_parent;
		node_pointer m_left;
		node_pointer m_right;
		node_pointer m_nil;


		node_pointer NextValue(node_pointer ptr){
			if (m_nil == ptr)
				return ptr;
			inorder(this->m_left);
		}

	public:
		MapIterator() : m_parent(nullptr), m_left(nullptr), m_right(nullptr),  m_nil(nullptr){}
		MapIterator(node_pointer node) : m_parent(node), m_left(nullptr), m_right(nullptr),  m_nil(nullptr){}
		virtual ~MapIterator(){};

		iterator const& operator=(const iterator& rhs) {
			this->m_parent = rhs.m_parent;
			this->m_left = rhs.m_left;
			this->m_right = rhs.m_right;
			return *this;
		}

		iterator &operator++() {
			iterator tmp(this);
			if (this->m_right != this->m_nil)
				return *this->m_right;
			else if (this->m_parent != this->m_nil)
				return *this->m_parent;
			return *this->m_nil;
		}

		iterator operator++(int) {
			iterator tmp(*this);
			operator++();
			return tmp;
		}

		iterator &operator--() {

		}

		iterator operator--(int) {

		}

		bool operator==(const iterator &rhs) const { return this->_ptr == rhs._ptr; }
		bool operator!=(const iterator &rhs) const { return this->_ptr != rhs._ptr; }
		bool operator<(const iterator &rhs) const { return this->_ptr < rhs._ptr; }
		bool operator<=(const iterator &rhs) const { return this->_ptr <= rhs._ptr; }
		bool operator>(const iterator &rhs) const { return this->_ptr > rhs._ptr; }
		bool operator>=(const iterator &rhs) const { return this->_ptr >= rhs._ptr; }

	};

	template<class Key, class T, class Compare = std::less<Key> , class Alloc = std::allocator<std::pair<const Key,T> > >
	class Map {
	public:

		typedef Key	key_type;
		typedef T	mapped_type;
		typedef std::pair<const key_type , mapped_type> value_type;
		typedef Compare	key_compare;
		typedef Compare	value_compare;
		typedef Alloc	allocator_type;
		typedef value_type&									reference;
		typedef const value_type&							const_reference;
		typedef value_type*									pointer;
		typedef const value_type*							const_pointer;
		typedef ft::MapIterator<value_type>					iterator;
		typedef ft::MapIterator<const value_type>			const_iterator;
		typedef Reverse_iterator<iterator>					reverse_iterator;
		typedef const reverse_iterator						const_reverse_iterator;
		typedef ptrdiff_t									difference_type;
		typedef unsigned long								size_type;
		typedef ft::MapNode<value_type>						node;
		typedef node*										node_pointer;

	private:

		node_pointer	m_nil;
		node_pointer	m_root;
		node_pointer	m_begin;
		node_pointer	m_last;

		node_pointer findMin(node_pointer ptr){
			if (m_nil == ptr)
				return ptr;
			findMin(this->m_left);
		}

	public:
		Map (const key_compare& comp = key_compare(),
			 const allocator_type& alloc = allocator_type()) :
				m_nil(nullptr), m_root (m_nil), m_begin(m_nil), m_last(m_nil){}

//		template <class InputIterator>
//		Map (InputIterator first, InputIterator last,
//		const key_compare& comp = key_compare(),
//		const allocator_type& alloc = allocator_type()){}
//
//		Map (const Map& x){}
		virtual ~Map(){}
//

		iterator begin() {
			return iterator(findMin(m_root));
		}

		const_iterator begin() const{
			return const_iterator(findMin(m_root));
		}

		iterator end(){
			return iterator(m_nil);
		}
		const_iterator end() const{
			return const_iterator(m_nil);
		}

		typename std::pair<iterator,bool> insert (const_reference val) {
				node_pointer tmp = m_root;
			if (tmp == this->m_nil) {
				node_pointer inserted_node = tmp->nodeInsert(val);
				m_root = inserted_node;
				return std::make_pair(iterator(inserted_node),true);
			}
			return std::make_pair(iterator(tmp),false);
		}
//
//		iterator insert (iterator position, const value_type& val);
//
//		template <class InputIterator>
//		void insert (InputIterator first, InputIterator last){

//		}
	};
}
#endif //CONT_MY_MAP_HPP
