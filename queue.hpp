//
// Created by Jamis Heat on 5/23/21.
//

#ifndef CONT_MY_QUEUE_HPP
#define CONT_MY_QUEUE_HPP
#include "list.hpp"

namespace ft
{
	template<class T, class Container = ft::List<T> >
	class Queue {

	public:

		typedef T value_type;
		typedef Container container_type;
		typedef size_t size_type;

	protected:
		container_type cntr;
	public:
		explicit Queue (const container_type& ctnr = container_type()) : cntr(ctnr) {}
		Queue(Queue const &x) : cntr(x.cntr) {}
		virtual ~Queue() {};

		bool empty() const {
			return this->cntr.empty();
		}

		size_type size() const {
			return this->cntr.size();
		}

		value_type& front(){
			return this->cntr.back();
		}
		const value_type& front() const{
			return this->cntr.back();
		}

		value_type& back(){
			return this->cntr.front();
		}
		const value_type& back() const{
			return this->cntr.front();
		}

		void push (const value_type& val){
			this->cntr.push_front(val);
		}

		void pop() {
			this->cntr.pop_front();
		}
	};//Queue end

	template <class T, class Container>
	bool operator== (const Queue<T,Container>& lhs, const Queue<T,Container>& rhs){
		Queue<T,Container> lcopy(lhs);
		Queue<T,Container> rcopy(rhs);
		if (lcopy.size() != rcopy.size())
			return false;
		for (int i = 0; lcopy.size(); ++i)
		{
			if (lcopy.front() != rcopy.front())
				return false;
			lcopy.pop();
			rcopy.pop();
		}
		return true;
	}

	template <class T, class Container>
	bool operator!= (const Queue<T,Container>& lhs, const Queue<T,Container>& rhs){
		return !(lhs == rhs);
	}

	template <class T, class Container>
	bool operator<  (const Queue<T,Container>& lhs, const Queue<T,Container>& rhs){
		bool equal = true;
		Queue<T,Container> lcopy(lhs);
		Queue<T,Container> rcopy(rhs);
		if (lcopy.size() != rcopy.size())
		{
			while (lcopy.size() > rcopy.size())
				lcopy.pop();
			while (rcopy.size() > lcopy.size())
				rcopy.pop();
		}

		while (!lcopy.empty())
		{
			if (lcopy.front() > rcopy.front())
				return false;
			else if (rcopy.front() > lcopy.front())
				equal = false;
			lcopy.pop();
			rcopy.pop();
		}
		if (equal && (lhs.size() == rhs.size() || lhs.size() > rhs.size()))
			return false;
		return true;
	}

	template <class T, class Container>
	bool operator<= (const Queue<T,Container>& lhs, const Queue<T,Container>& rhs){
		return !(rhs < lhs);
	}

	template <class T, class Container>
	bool operator>  (const Queue<T,Container>& lhs, const Queue<T,Container>& rhs){
		return rhs < lhs;
	}

	template <class T, class Container>
	bool operator>= (const Queue<T,Container>& lhs, const Queue<T,Container>& rhs){
		return !(lhs < rhs);;
	}

};//ft end
#endif //CONT_MY_QUEUE_HPP
