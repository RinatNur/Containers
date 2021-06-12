//
// Created by Jamis Heat on 5/20/21.
//

#ifndef CONT_MY_STACK_HPP
#define CONT_MY_STACK_HPP

#include "list.hpp"

namespace ft
{
template<class T, class Container = ft::list<T> >
class stack {

public:

	typedef T value_type;
	typedef Container container_type;
	typedef size_t size_type;

protected:
	container_type cntr;
public:
	explicit stack(const container_type &ctnr = container_type()) : cntr(ctnr) {}
	stack(stack const &x) : cntr(x.cntr) {}
	virtual ~stack() {};

	bool empty() const {
		return this->cntr.empty();
	}

	size_type size() const {
		return this->cntr.size();
	}

	value_type& top(){
		return this->cntr.back();
	}
	const value_type& top() const{
		return this->cntr.back();
	}

	void push (const value_type& val){
		this->cntr.push_back(val);
	}

	void pop() {
		this->cntr.pop_back(); //TODO test it
	}

	friend bool operator==(stack<value_type, container_type> const &lhs, stack<value_type, container_type> const &rhs) {
		return (lhs.cntr == rhs.cntr);
	}

	friend bool operator!=(stack<value_type, container_type> const &lhs, stack<value_type, container_type> const &rhs) {
		return (lhs.cntr != rhs.cntr);
	}

	friend bool operator<(stack<value_type, container_type> const &lhs, stack<value_type, container_type> const &rhs) {
		return (lhs.cntr < rhs.cntr);
	}

	friend bool operator<=(stack<value_type, container_type> const &lhs, stack<value_type, container_type> const &rhs) {
		return (lhs.cntr <= rhs.cntr);
	}

	friend bool operator>(stack<value_type, container_type> const &lhs, stack<value_type, container_type> const &rhs) {
		return (lhs.cntr > rhs.cntr);
	}

	friend bool operator>=(stack<value_type, container_type> const &lhs, stack<value_type, container_type> const &rhs) {
		return (lhs.cntr >= rhs.cntr);
	}

};//stack end
}//ft end
#endif //CONT_MY_STACK_HPP
