//
// Created by Rinat Nurutdinow on 4/15/21.
//

#ifndef CONT_MY_LIST_HPP
#define CONT_MY_LIST_HPP


#include <iostream>
#include <iterator>


namespace ft {
//	template <typename T>
//	class iterator : public std::iterator<std::input_iterator_tag, int> {
//	public:
//		using value_type 		= T;
//		using pointer			= value_type*;
//		using reference			= value_type&;
//		using iterator_category	= std::forward_iterator_tag;
//		using difference_type   = std::ptrdiff_t;
//
//	private:
//		pointer		_ptr;
//
//	public:
//
//		iterator() : _ptr(nullptr) {};
//		iterator(pointer ptr) : _ptr(ptr) {};
//		iterator(const iterator& rhs) : _ptr(rhs._ptr) {};
//		virtual ~iterator(){};
//
//		iterator const& operator=(const iterator& rhs) {
//			this->_ptr = rhs._ptr;
//			return *this;
//		}
//		iterator& operator++(){
//			++this->_ptr;
//			return *this;
//		}// prefix increment operator
//		iterator operator++(int) {
//			iterator tmp(*this);
//			operator++();
//			return tmp;
//		}// postfix increment operator
//
//		iterator& operator--(){
//			--this->_ptr;
//			return *this;
//		}// prefix decrement operator
//		iterator operator--(int) {
//			iterator tmp(*this);
//			operator--();
//			return tmp;
//		}// postfix decrement operator
//
//		bool operator==(const iterator& rhs) const { return this->_ptr == rhs._ptr; }
//		bool operator!=(const iterator& rhs) const { return this->_ptr != rhs._ptr; }
//		reference operator*() { return *_ptr; }
//
//	};

	template<typename T>
	class List {
	private:
		struct Node {
			Node *previous;
			Node *next;

			Node() : previous(this), next(this) {}
		};

		struct DataNode : Node {
			T data;
		};

	public:
		class iterator {
			friend class List;

		private:
			iterator(Node *node) : m_node(node) {}

		public:
			iterator() : m_node(0) {}

			iterator &operator++() {
				m_node = m_node->next;
				return *this;
			}

			iterator &operator--() {
				m_node = m_node->previous;
				return *this;
			}

			T &operator*() {
				// Note: Dereferncing the end (sentinal node) is undefined behavior.
				return reinterpret_cast<DataNode *>(m_node)->data;
			}

			bool operator!=(const iterator &rhs) const { return (this->m_node != rhs.m_node); }

			// More iterator functions.

		private:
			Node *m_node;
		};

	public:
		List() : m_sentinal(new Node) {}

		iterator begin() { return iterator(m_sentinal->next); }

		iterator end() { return iterator(m_sentinal); }

		iterator insert(iterator position, T data) {
			DataNode *data_node = new DataNode; // pass data
			data_node->data = data;
			data_node->next = position.m_node;
			data_node->previous = position.m_node->previous;
			position.m_node->previous->next = data_node;
			position.m_node->previous = data_node;
			return iterator(data_node);
		}


		void append(T data) {
			insert(end(), data);
		}

	private:
		Node *m_sentinal;
	};
}

#endif //CONT_MY_LIST_HPP
