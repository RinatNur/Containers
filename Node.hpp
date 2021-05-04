//
// Created by Rinat Nurutdinow on 4/17/21.
//

#ifndef CONT_MY_NODE_HPP
#define CONT_MY_NODE_HPP

#include <iostream>

//namespace ft {
//template<typename value_type>
//class node {
//private:
//	node<value_type> *prev_;
//	value_type value_;
//	node<value_type> *next_;
//public:
//	node() : prev_(nullptr), value_(), next_(nullptr) {};
//
//	node(value_type const &value) : prev_(nullptr), value_(value), next_(nullptr) {};
//
//	node(const node &obj) : prev_(obj.prev_), value_(obj.value_), next_(obj.next_) {};
//
//	virtual ~node() {};
//
//	node &operator=(const node &obj) {
//		if (this != &obj) {
//			this->prev_ = obj.prev_;
//			this->value_ = obj.value_;
//			this->next_ = obj.next_;
//		}
//		return *this;
//	};
//
//	void insert_before(node* node) {
//		if(this->prev_)
//		{
//			node->prev_ = this->prev_;
//			this->prev_->next_ = node;
//		}
//		node->next_ = this;
//		this->prev_ = node;
//	}
//
//	void insert_after(node* node)
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
//	node*& prev(){
//		return this->prev_;
//	}
//	node const& prev() const {
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
//	node*& next(){
//		return this->next_;
//	}
//	node const& next() const{
//		return this->next_;
//	}
//
//};
//}

#endif //CONT_MY_NODE_HPP
