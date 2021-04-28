//
// Created by Rinat Nurutdinow on 4/15/21.
//

#ifndef CONT_MY_LIST_HPP
#define CONT_MY_LIST_HPP


#include <iostream>
#include <iterator>


namespace ft {
	template <typename T>
	class iterator : public std::iterator<std::input_iterator_tag, int> {
	public:
		using value_type 		= T;
		using pointer			= value_type*;
		using reference			= value_type&;
		using iterator_category	= std::forward_iterator_tag;
		using difference_type   = std::ptrdiff_t;

	private:
		pointer		_ptr;

	public:

		iterator() : _ptr(nullptr) {};
		iterator(pointer ptr) : _ptr(ptr) {};
		iterator(const iterator& rhs) : _ptr(rhs._ptr) {};
		virtual ~iterator(){};

		iterator const& operator=(const iterator& rhs) {
			this->_ptr = rhs._ptr;
			return *this;
		}
		iterator& operator++(){
			++this->_ptr;
			return *this;
		}// prefix increment operator
		iterator operator++(int) {
			iterator tmp(*this);
			operator++();
			return tmp;
		}// postfix increment operator

		iterator& operator--(){
			--this->_ptr;
			return *this;
		}// prefix decrement operator
		iterator operator--(int) {
			iterator tmp(*this);
			operator--();
			return tmp;
		}// postfix decrement operator

		bool operator==(const iterator& rhs) const { return this->_ptr == rhs._ptr; }
		bool operator!=(const iterator& rhs) const { return this->_ptr != rhs._ptr; }
		reference operator*() { return *_ptr; }

	};


//	template <typename T>
//	class list {
//	private:
//		typedef struct s_list {
//			T				*value;
//			struct s_list	*next;
//			struct s_list	*prev;
//		}				t_list;
//	public:
//		list() {};
//		virtual ~list() {};
//
//		t_list		*lstnew(T* content)
//		void push_back(T value);
//
//	};
//
//	template<typename T>
//	void list<T>::push_back(T value) {
//
//	}
//
//	template<typename T>
//	ft::t_list *list<T>::lstnew(void *content) {
//		return nullptr;
//	}
}

#endif //CONT_MY_LIST_HPP
