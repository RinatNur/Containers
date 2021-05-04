//
// Created by Rinat Nurutdinow on 4/15/21.
//

#ifndef CONT_MY_LIST_HPP
#define CONT_MY_LIST_HPP


#include <iostream>
#include <iterator>

namespace ft {

struct Node {
	Node *previous;
	Node *next;

	Node() : previous(this), next(this) {}
};

template <typename T>
struct DataNode : Node {
	T data;
};

template <typename T>
class iterator {
public:
	typedef T							value_type;
	typedef ft::DataNode<value_type>	DataNode;
	typedef ft::Node					node;
	typedef node*						node_pointer;

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

template<typename T>
class List {
public:

	typedef T value_type;
	typedef value_type*	pointer;
	typedef value_type const *	const_pointer;
	typedef value_type&	reference;
	typedef value_type const *	const_reference;
	typedef ft::iterator<T> iterator;
	typedef ft::DataNode<value_type> DataNode;
	typedef DataNode* DataNode_pointer;
	typedef ft::Node node;
	typedef node* node_pointer;

public:

	List() : m_sentinal(new node) {}

	iterator begin() { return iterator(m_sentinal->next); }
	iterator end() { return iterator(m_sentinal); }

	iterator rbegin() { return iterator(m_sentinal); }
	iterator rend() { return iterator(m_sentinal->next); }

	iterator insert(iterator position, T data) {
		DataNode* data_node = new DataNode;
		data_node->data = data;
		node_pointer tmp = position.getNode();
		data_node->next = tmp;
		data_node->previous = tmp->previous;
		tmp->previous->next = data_node; // tmp->previous = m_sentinal
		tmp->previous = data_node;
		return iterator(tmp);
	}

	void push_back(T data) {
		insert(end(), data);
	}
	void push_front(T data) {
		insert(begin(), data);
	}

private:
	node_pointer m_sentinal;
};
}

#endif //CONT_MY_LIST_HPP
