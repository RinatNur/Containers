//
// Created by Rinat Nurutdinow on 5/4/21.
//

#ifndef CONT_MY_REVERSE_ITERATOR_H
#define CONT_MY_REVERSE_ITERATOR_H

#include <iterator>
#include "Node.hpp"

namespace ft {
	template<class It>
	class Reverse_iterator : public It {
	public:
		using typename It::value_type;
		using typename It::pointer;
		using typename It::const_pointer;
		using typename It::reference;
		using typename It::const_reference;
		using typename It::difference_type;
	public:
		Reverse_iterator(): It() {}
		Reverse_iterator(It const &x): It(x) {}
		Reverse_iterator(Reverse_iterator const &rhs): It(rhs._ptr) {}
		virtual ~Reverse_iterator() {};

		Reverse_iterator &operator=(const Reverse_iterator &rhs) {
			this->_ptr = rhs._ptr;
			return *this;
		}

		Reverse_iterator operator++(int) {
			Reverse_iterator tmp(*this);
			operator++();
			return tmp;
		}

		It &operator++() {
			return (this->It::operator--());
		}

		Reverse_iterator operator--(int) {
			Reverse_iterator tmp(*this);
			operator--();
			return tmp;
		}

		It &operator--() {
			return (this->It::operator++());
		}

		reference operator*() {
			It tmp(*this);
			--tmp;
			return (*tmp);
		}
		const_reference operator*() const {
			It tmp(*this);
			--tmp;
			return (*tmp);
		}
	};
}
//	template<typename T>
//	class Reverse_iterator {
//	public:
//
//		typedef T							value_type;
//		typedef ft::DataNode<value_type>	DataNode;
//		typedef ft::Node<value_type>		node;
//		typedef node						*node_pointer;
//		typedef std::ptrdiff_t				difference_type;
//
//	public:
//		Reverse_iterator(node_pointer node) : m_node(node) {}
//
//		Reverse_iterator() : m_node(0) {}
//
//		Reverse_iterator(const Reverse_iterator &rhs) : m_node(rhs.m_node) {};
//
//		virtual ~Reverse_iterator() {};
//
//		Reverse_iterator const &operator=(const Reverse_iterator &rhs) {
//			this->m_node = rhs.m_node;
//			return *this;
//		}
//
//		Reverse_iterator &operator++() {
//			m_node = m_node->previous();
//			return *this;
//		}
//
//		Reverse_iterator  operator+(difference_type n) const {//TODO add const
//			for (int i = 0; i < n; ++i)
//				++rev_it;
//			Reverse_iterator tmp(*this);
//			return tmp ;//  += n;
//		}
//
//		Reverse_iterator & operator-(difference_type n) {
//			for (int i = 0; i < n; ++i)
//				m_node = m_node->next;
//			return *this;
//		}
//
//		Reverse_iterator operator++(int) {
//			Reverse_iterator tmp(*this);
//			operator++();
//			return tmp;
//		}// postfix increment operator
//
//		Reverse_iterator &operator--() {
//			m_node = m_node->next;
//			return *this;
//		}// prefix decrement operator
//
//		Reverse_iterator operator--(int) {
//			Reverse_iterator tmp(*this);
//			operator--();
//			return tmp;
//		}// postfix decrement operator
//
//		bool operator==(const Reverse_iterator &rhs) const { return this->m_node == rhs.m_node; }
//
//		bool operator!=(const Reverse_iterator &rhs) const { return this->m_node != rhs.m_node; }
//
//		T &operator*() { return m_node->getValue(); }
//
//		node_pointer getNode() const { return this->m_node; }
//
//	private:
//
//		node_pointer m_node;
//
//	};
//}

#endif //CONT_MY_REVERSE_ITERATOR_H
