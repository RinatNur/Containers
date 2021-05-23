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

		friend bool operator==(Queue<value_type, container_type> const &lhs, Queue<value_type, container_type> const &rhs) {
			return (lhs.cntr == rhs.cntr);
		}

		friend bool operator!=(Queue<value_type, container_type> const &lhs, Queue<value_type, container_type> const &rhs) {
			return (lhs.cntr != rhs.cntr);
		}

		friend bool operator<(Queue<value_type, container_type> const &lhs, Queue<value_type, container_type> const &rhs) {
			return (lhs.cntr < rhs.cntr);
		}

		friend bool operator<=(Queue<value_type, container_type> const &lhs, Queue<value_type, container_type> const &rhs) {
			return (lhs.cntr <= rhs.cntr);
		}

		friend bool operator>(Queue<value_type, container_type> const &lhs, Queue<value_type, container_type> const &rhs) {
			return (lhs.cntr > rhs.cntr);
		}

		friend bool operator>=(Queue<value_type, container_type> const &lhs, Queue<value_type, container_type> const &rhs) {
			return (lhs.cntr >= rhs.cntr);
		}

	};//Queue end
};//ft end
#endif //CONT_MY_QUEUE_HPP
