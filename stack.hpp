//
// Created by Jamis Heat on 5/20/21.
//

#ifndef CONT_MY_STACK_HPP
#define CONT_MY_STACK_HPP

#include "list.hpp"

namespace ft
{
template<class T, class Container = ft::List<T> >
class Stack {

public:

	typedef T value_type;
	typedef Container container_type;
	typedef size_t size_type;

protected:
	container_type cntr;
public:
	explicit Stack(const container_type &ctnr = container_type()) : cntr(ctnr) {}
	Stack(Stack const &x) : cntr(x.cntr) {}
	virtual ~Stack() {};

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
		this->cntr.pop_back();
	}
};//stack end

	template <class T, class Container>
	bool operator== (const Stack<T,Container>& lhs, const Stack<T,Container>& rhs){
		Stack<T,Container> lcopy(lhs);
		Stack<T,Container> rcopy(rhs);
		if (lcopy.size() != rcopy.size())
			return false;
		for (int i = 0; lcopy.size(); ++i)
		{
			if (lcopy.top() != rcopy.top())
				return false;
			lcopy.pop();
			rcopy.pop();
		}
		return true;
	}

	template <class T, class Container>
	bool operator!= (const Stack<T,Container>& lhs, const Stack<T,Container>& rhs){
		return !(lhs == rhs);
	}

	template <class T, class Container>
	bool operator<  (const Stack<T,Container>& lhs, const Stack<T,Container>& rhs){
//		if (lhs == rhs)
//			return false;
		bool equal = true;
		Stack<T,Container> lcopy(lhs);
		Stack<T,Container> rcopy(rhs);
		if (lcopy.size() != rcopy.size())
		{
			while (lcopy.size() > rcopy.size())
				lcopy.pop();
			while (rcopy.size() > lcopy.size())
				rcopy.pop();
		}

		while (!lcopy.empty())
		{
			if (lcopy.top() > rcopy.top())
				return false;
			else if (rcopy.top() > lcopy.top())
				equal = false;
			lcopy.pop();
			rcopy.pop();
		}
		if (equal && (lhs.size() == rhs.size() || lhs.size() > rhs.size()))
			return false;
		return true;
	}

	template <class T, class Container>
	bool operator<= (const Stack<T,Container>& lhs, const Stack<T,Container>& rhs){
		return !(rhs < lhs);
	}

	template <class T, class Container>
	bool operator>  (const Stack<T,Container>& lhs, const Stack<T,Container>& rhs){
		return rhs < lhs;
	}

	template <class T, class Container>
	bool operator>= (const Stack<T,Container>& lhs, const Stack<T,Container>& rhs){
		return !(lhs < rhs);;
	}

}//ft end
#endif //CONT_MY_STACK_HPP
