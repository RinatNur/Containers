//
// Created by Jamis Heat on 5/23/21.
//

#ifndef CONT_MY_VECTOR_HPP
#define CONT_MY_VECTOR_HPP


#include <iostream>
#include <iterator>
#include "Reverse_iterator.hpp"
#include "Algorithm.hpp"
#include "Number.hpp"

namespace ft {

	template<typename T>
	class VectorIterator {
	public:

		typedef T value_type;
		typedef value_type *pointer;
		typedef value_type const *const_pointer;
		typedef value_type &reference;
		typedef value_type const &const_reference;
		typedef std::ptrdiff_t difference_type;
	public:
		pointer _ptr;

	public:
		VectorIterator() : _ptr(nullptr) {}

		VectorIterator(pointer ptr) : _ptr(ptr) {}

		VectorIterator(const VectorIterator &rhs) : _ptr(rhs._ptr) {}

		virtual ~VectorIterator() {};

		VectorIterator const &operator=(const VectorIterator &rhs) {
			this->_ptr = rhs._ptr;
			return *this;
		}

		reference operator*() {
			return (*this->_ptr);
		}

		const_reference operator*() const {
			return (*this->_ptr);
		}

		pointer operator->() {
			return (this->_ptr);
		}

		const_pointer operator->() const {
			return (this->_ptr);
		}

		reference operator[](int val) {
			return (*(this->_ptr + val));
		}

		const_reference operator[](int val) const {
			return (*(this->_ptr + val));
		}

		VectorIterator &operator++() {
			++this->_ptr;
			return *this;
		}

		VectorIterator operator++(int) {
			VectorIterator tmp(*this);
			++this->_ptr;
			return tmp;
		}// postfix increment operator

		VectorIterator &operator--() {
			--this->_ptr;
			return *this;
		}// prefix decrement operator

		VectorIterator operator--(int) {
			VectorIterator tmp(*this);
			--this->_ptr;
			return tmp;
		}// postfix decrement operator

		VectorIterator operator+=(int value) {
			this->_ptr += value;
			return (*this);
		}

		VectorIterator operator+(int value) {
			VectorIterator tmp(*this);
			return (tmp += value);
		}

		VectorIterator operator-=(int value) {
			this->_ptr -= value;
			return (*this);
		}

		VectorIterator operator-(int value) {
			VectorIterator tmp(*this);
			return (tmp -= value);
		}

		difference_type operator-(VectorIterator const &rhs) const {
			return (this->_ptr - rhs._ptr);
		}

		bool operator==(const VectorIterator &rhs) const { return this->_ptr == rhs._ptr; }

		bool operator!=(const VectorIterator &rhs) const { return this->_ptr != rhs._ptr; }

		bool operator<(const VectorIterator &rhs) const { return this->_ptr < rhs._ptr; }

		bool operator<=(const VectorIterator &rhs) const { return this->_ptr <= rhs._ptr; }

		bool operator>(const VectorIterator &rhs) const { return this->_ptr > rhs._ptr; }

		bool operator>=(const VectorIterator &rhs) const { return this->_ptr >= rhs._ptr; }
	};// VectorIterator end

	template<class T, class Alloc = std::allocator<T> >
	class Vector {
	public:

		typedef T											value_type;
		typedef Alloc										allocator_type;
		typedef value_type&									reference;
		typedef const value_type*							const_reference;
		typedef value_type*									pointer;
		typedef const value_type*							const_pointer;
		typedef VectorIterator<value_type>					iterator;
		typedef VectorIterator<value_type const>			const_iterator;
		typedef Reverse_iterator<iterator>					reverse_iterator;
		typedef Reverse_iterator<const_iterator>			const_reverse_iterator;
		typedef std::ptrdiff_t								difference_type;
		typedef size_t										size_type;
//		typedef typename Vector<value_type>::VectorIterator	it_type;

	private:

		pointer		_cntr;
		size_type	_capacity;
		size_type	_size;

	public:
		explicit Vector (const allocator_type& alloc = allocator_type()) :  _cntr(nullptr), _capacity(0), _size(0) {}
		explicit Vector (size_type n, const_reference val = value_type(),
		const allocator_type& alloc = allocator_type()) :  _cntr(nullptr), _capacity(0), _size(0) {
//			this->assign(n, val);
		}
		template <class InputIterator>
		Vector (InputIterator first, InputIterator last,
		const allocator_type& alloc = allocator_type()) :  _cntr(nullptr), _capacity(0), _size(0) {
			this->assign(first, last);
		}
		Vector (const Vector& x) : _cntr(nullptr), _capacity(0), _size(x._size) {
			//TODO write constructor's code
		}

		virtual ~Vector() {
			//TODO write destructor's code
		}

		Vector& operator=(Vector const & x) {
			//TODO write code
		}//TODO asdadsg

		iterator begin() {
			return (iterator(this->_cntr));
		}
		const_iterator begin() const{
			return (iterator(this->_cntr));
		}

		iterator end() {
			return (iterator(&(this->_cntr[this->_size])));
		}
		const_iterator end() const{
			return (iterator(&(this->_cntr[this->_size])));
		}

		//Capacity
		size_type size() const {
			return this->_size;
		}

		size_type max_size() const {
			return std::numeric_limits<size_type>::max() / sizeof(value_type);
		}

		void reserve (size_type n){
			if (this->_capacity == 0)
			{
				n = (n > 128) ? n : 128;
				this->_cntr = static_cast<pointer>(::operator new( sizeof(value_type) * n));
				this->_capacity = n;
			} else if (n > this->_capacity)
			{
				n = (n > this->_capacity * 2) ? n : this->_capacity * 2;
				pointer tmp = static_cast<pointer>(::operator new(sizeof (value_type) * n));
				if (this->_cntr)
				{
					for (int i = 0; i < this->_size; ++i)
						tmp[i] = this->_cntr[i];
					::operator delete(this->_cntr);
				}
				this->_cntr = tmp;
				this->_capacity = n;
			}
		}

		//Modifiers
		void push_back (const value_type& val){
			if (this->_size == this->_capacity)
				this->reserve(this->_size * 2);
			this->_cntr[this->_size] = val;
			++_size;
		}
		void pop_back(){
			if (this->_size > 0)
				this->_cntr[--this->_size].value_type::~value_type();
		}






	};//vector end

	template <class T, class Alloc>
	bool operator== (const Vector<T,Alloc>& lhs, const Vector<T,Alloc>& rhs){

	}

//	template <class T, class Alloc>
//	bool operator!= (const Vector<T,Alloc>& lhs, const Vector<T,Alloc>& rhs){}
//
//	template <class T, class Alloc>
//	bool operator<  (const Vector<T,Alloc>& lhs, const Vector<T,Alloc>& rhs){}
//
//	template <class T, class Alloc>
//	bool operator<= (const Vector<T,Alloc>& lhs, const Vector<T,Alloc>& rhs){}
//
//	template <class T, class Alloc>
//	bool operator>  (const Vector<T,Alloc>& lhs, const Vector<T,Alloc>& rhs){}
//
//	template <class T, class Alloc>
//	bool operator>= (const Vector<T,Alloc>& lhs, const Vector<T,Alloc>& rhs){}

}// ft end

#endif //CONT_MY_VECTOR_HPP
