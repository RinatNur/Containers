//
// Created by Jamis Heat on 5/23/21.
//

#ifndef CONT_MY_QUEUE_HPP
#define CONT_MY_QUEUE_HPP
#include "list.hpp"

namespace ft
{
	template<class T, class Container = ft::list<T> >
	class queue {

	public:

		typedef T value_type;
		typedef Container container_type;
		typedef size_t size_type;

	protected:
		container_type cntr;
	public:
		explicit queue (const container_type& ctnr = container_type()) : cntr(ctnr) {}
		queue(queue const &x) : cntr(x.cntr) {}
		virtual ~queue() {};

		bool empty() const {
			return this->cntr.empty();
		}

		size_type size() const {
			return this->cntr.size();
		}

		value_type& front(){
			return this->cntr.front();
		}
		const value_type& front() const{
			return this->cntr.front();
		}

		value_type& back(){
			return this->cntr.back();
		}
		const value_type& back() const{
			return this->cntr.back();
		}

		void push (const value_type& val){
			this->cntr.push_back(val);
		}

		void pop() {
			this->cntr.pop_front();
		}

		friend bool operator==(queue<value_type, container_type> const &lhs, queue<value_type, container_type> const &rhs) {
			return (lhs.cntr == rhs.cntr);
		}

		friend bool operator!=(queue<value_type, container_type> const &lhs, queue<value_type, container_type> const &rhs) {
			return (lhs.cntr != rhs.cntr);
		}

		friend bool operator<(queue<value_type, container_type> const &lhs, queue<value_type, container_type> const &rhs) {
			return (lhs.cntr < rhs.cntr);
		}

		friend bool operator<=(queue<value_type, container_type> const &lhs, queue<value_type, container_type> const &rhs) {
			return (lhs.cntr <= rhs.cntr);
		}

		friend bool operator>(queue<value_type, container_type> const &lhs, queue<value_type, container_type> const &rhs) {
			return (lhs.cntr > rhs.cntr);
		}

		friend bool operator>=(queue<value_type, container_type> const &lhs, queue<value_type, container_type> const &rhs) {
			return (lhs.cntr >= rhs.cntr);
		}

	};//queue end
};//ft end
#endif //CONT_MY_QUEUE_HPP
