//
// Created by Rinat Nurutdinow on 4/17/21.
//

#ifndef CONT_MY_NODE_HPP
#define CONT_MY_NODE_HPP

#include <iostream>

//namespace ft {
//template<typename value_type>
//class Node {
//private:
//	Node<value_type> *prev_;
//	value_type value_;
//	Node<value_type> *next_;
//public:
//	Node() : prev_(nullptr), value_(), next_(nullptr) {};
//
//	Node(value_type const &value) : prev_(nullptr), value_(value), next_(nullptr) {};
//
//	Node(const Node &obj) : prev_(obj.prev_), value_(obj.value_), next_(obj.next_) {};
//
//	virtual ~Node() {};
//
//	Node &operator=(const Node &obj) {
//		if (this != &obj) {
//			this->prev_ = obj.prev_;
//			this->value_ = obj.value_;
//			this->next_ = obj.next_;
//		}
//		return *this;
//	};
//
//	void insert_before(Node* node) {
//		if(this->prev_)
//		{
//			node->prev_ = this->prev_;
//			this->prev_->next_ = node;
//		}
//		node->next_ = this;
//		this->prev_ = node;
//	}
//
//	void insert_after(Node* node)
//	{
//		if (this->next_)
//		{
//			node->next_ = this->next_;
//			this->next_->prev_ = node;
//		}
//		this->next_ = node;
//		node->prev_ = this;
//	}
//
//	Node*& prev(){
//		return this->prev_;
//	}
//	Node const& prev() const {
//		return this->prev_;
//	}
//
//	value_type& value() {
//		return this->value_;
//	}
//	value_type const& value() const {
//		return this->value_;
//	}
//
//	Node*& next(){
//		return this->next_;
//	}
//	Node const& next() const{
//		return this->next_;
//	}
//
//};
//}

#endif //CONT_MY_NODE_HPP
