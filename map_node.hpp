//
// Created by Jamis Heat on 6/2/21.
//

#ifndef CONT_MY_MAP_NODE_HPP
#define CONT_MY_MAP_NODE_HPP

#include <iostream>

namespace ft{
	template<class Key, class T>
	class MapNode {

	public:

		typedef std::pair<Key, T>									value_type;
//		typedef Alloc										allocator_type;
		typedef value_type&									reference;
		typedef const value_type&							const_reference;
		typedef value_type*									pointer;
		typedef const value_type*							const_pointer;
//		typedef VectorIterator<value_type>					iterator;
//		typedef VectorIterator<value_type const>			const_iterator;
//		typedef Reverse_iterator<iterator>					reverse_iterator;
//		typedef Reverse_iterator<const_iterator>			const_reverse_iterator;
		typedef std::ptrdiff_t								difference_type;
		typedef unsigned long								size_type;
		typedef MapNode*									node_pointer;

	protected:
		value_type		m_value;
		node_pointer	m_parent;
		node_pointer	m_left;
		node_pointer	m_right;

	public:
		MapNode() : m_value(std::pair<Key,T>(0,0)), m_parent(nullptr), m_left(nullptr), m_right(nullptr) {}
		MapNode(const_reference val) : m_value(val), m_parent(nullptr), m_left(nullptr), m_right(nullptr) {}
		virtual~MapNode(){}

		node_pointer nodeInsert(const_reference val)
		{
			node_pointer new_node = new MapNode(val);
			return  new_node;
		}
		void setValue(const value_type& data) {
			this->m_value = data;
		}

		value_type& getValue() const {
			return this->m_value;
		}



	};
}
#endif //CONT_MY_MAP_NODE_HPP
