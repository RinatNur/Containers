//
// Created by Rinat Nurutdinow on 4/15/21.
//

#ifndef CONT_MY_LIST_HPP
#define CONT_MY_LIST_HPP


#include <iostream>
#include <iterator>


namespace ft {
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
		public:
			iterator(Node *node) : m_node(node) {}
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

			Node * getNode() const { return this->m_node; }
		private:
			Node *m_node;
		};

	public:
		List() : m_sentinal(new Node) {}

		iterator begin() { return iterator(m_sentinal->next); }
		iterator end() { return iterator(m_sentinal); }

		iterator rbegin() { return iterator(m_sentinal); }
		iterator rend() { return iterator(m_sentinal->next); }

		iterator insert(iterator position, T data) {
			DataNode *data_node = new DataNode; // pass data
			data_node->data = data;
			data_node->next = position.getNode();
			data_node->previous = position.getNode()->previous;
			position.getNode()->previous->next = data_node;
			position.getNode()->previous = data_node;
			return iterator(data_node);
		}


		void push_back(T data) {
			insert(end(), data);
		}
		void push_front(T data) {
			insert(begin(), data);
		}

	private:
		Node *m_sentinal;
	};
}

#endif //CONT_MY_LIST_HPP
