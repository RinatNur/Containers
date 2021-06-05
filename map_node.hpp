//
// Created by Jamis Heat on 6/2/21.
//

#ifndef CONT_MY_MAP_NODE_HPP
#define CONT_MY_MAP_NODE_HPP

#include <iostream>

namespace ft{
	template<class T>
	struct MapNode {

	public:

//		typedef T											value_type;
//		typedef Alloc										allocator_type;
//		typedef value_type&									reference;
//		typedef const value_type&							const_reference;
//		typedef value_type*									pointer;
//		typedef const value_type*							const_pointer;
//		typedef VectorIterator<value_type>					iterator;
//		typedef VectorIterator<value_type const>			const_iterator;
//		typedef Reverse_iterator<iterator>					reverse_iterator;
//		typedef Reverse_iterator<const_iterator>			const_reverse_iterator;
//		typedef std::ptrdiff_t								difference_type;
//		typedef unsigned long								size_type;
	private:
		value_type	m_value;
		MapNode*	m_parent;
		MapNode*	m_left;
		MapNode*	m_right;

	public:
		MapNode() : m_value(0), m_parent(nullptr), m_left(nullptr), m_right(nullptr) {}

	};
}
#endif //CONT_MY_MAP_NODE_HPP
