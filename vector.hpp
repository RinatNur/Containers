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
		typedef const value_type&							const_reference;
		typedef value_type*									pointer;
		typedef const value_type*							const_pointer;
		typedef VectorIterator<value_type>					iterator;
		typedef VectorIterator<value_type const>			const_iterator;
//		typedef Reverse_iterator<iterator>					reverse_iterator;
//		typedef Reverse_iterator<const_iterator>			const_reverse_iterator;
		typedef std::ptrdiff_t								difference_type;
		typedef unsigned long								size_type;
//		typedef typename Vector<value_type>::VectorIterator	it_type;

	private:

		pointer		cntr_;
		size_type	size_;
		size_type	capacity_;

		void printVector(Vector& tmp) {
			for (iterator it = tmp.begin(); it != tmp.end(); ++it)
			{
				std::cout << " " << *it;
			}
			std::cout << std::endl;
		}

		void copy_to_allocated_mem(size_type index, const_reference val)
		{
			new(&this->cntr_[index]) value_type(val);
		}


	public:
		Vector (const allocator_type& alloc = allocator_type()) : cntr_(nullptr), size_(0), capacity_(0) {
		}
		Vector (size_type n, const_reference val = value_type(),
		  	const allocator_type& alloc = allocator_type()) : cntr_(nullptr), capacity_(0), size_(0) {
			this->assign(n, val);
		}
		template <class InputIterator>
		Vector (InputIterator first, InputIterator last,
		const allocator_type& alloc = allocator_type()) :  cntr_(nullptr), capacity_(0), size_(0) {
			this->assign(first, last);
		}
		Vector (const Vector& x) : cntr_(x.cntr_), capacity_(x.capacity_), size_(x.size_) {
			//TODO write constructor's code
		}

		virtual ~Vector() {
			this->clear();
			if (this->cntr_)
				::delete (this->cntr_);
		}

		Vector& operator=(Vector const & x) {
			//TODO write code
		}

		reference operator[](size_type index)
		{
			return this->cntr_[index];
		}

		iterator begin() {
			return (iterator(this->cntr_));
		}
		const_iterator begin() const{
			return (const_iterator(this->cntr_));
		}

		iterator end() {
			return (iterator(&(this->cntr_[this->size_])));
		}
		const_iterator end() const{
			return (const_iterator(&(this->cntr_[this->size_])));
		}

		//Capacity
		size_type size() const {
			return this->size_;
		}

		size_type max_size() const {
			return std::numeric_limits<size_type>::max() / sizeof(value_type);
		}

		size_type capacity() const {
			return this->capacity_;
		}

		void reserve (size_type n){
			if (n > this->max_size())
				throw std::bad_alloc();
			if (this->capacity_ == 0)
			{
				n = (this->size_ <= 1) ? 1 : n;
				this->cntr_ = static_cast<pointer>(::operator new(sizeof(value_type) * n));
				this->capacity_ = n;
			} else if (n > this->capacity_)
			{
				n = (n > this->capacity_ * 2) ? n : this->capacity_ * 2;
				pointer tmp = static_cast<pointer>(::operator new(sizeof (value_type) * n));
				if (this->cntr_)
				{
					for (int i = 0; i < this->size_; ++i)
						new(&tmp[i]) value_type(this->cntr_[i]);
					::operator delete(this->cntr_);				}
				this->cntr_ = tmp;
				this->capacity_ = n;
			}
		}

		//Modifiers
		template <class InputIterator>
		void assign (InputIterator first, InputIterator last,
					 typename enable_if<!std::numeric_limits<InputIterator>::is_specialized>::type * = 0)
		{
			this->clear();
			for (; first != last; ++first)
				this->push_back(*first);
		}
		void assign (size_type n, const value_type& val){
			this->clear();
			for (int i = 0; i < n; ++i)
				this->push_back(val);
		}

		void push_back (const value_type& val){
			if (this->size_ == this->capacity_) {
				this->reserve(this->size_ * 2);
			}
			new(&this->cntr_[this->size_]) value_type(val);
			size_ = size_ + 1;
		}
		void pop_back(){
			if (this->size_ > 0)
				--this->size_;
				this->cntr_[this->size_].value_type::~value_type();
		}

		iterator insert (iterator position, const value_type& val){
			size_type i = 0;
			iterator it = this->begin();

			for (; it != position; ++it)
				++i;
			if (this->size_ + 1 >= this->capacity_)
				this->reserve(this->size_ + 1);


			for (size_type j = this->size_; j >= 1 && j >= i; j--) // loop moves values in array after position to the and of new array
				this->copy_to_allocated_mem(j + 1 - 1, this->cntr_[j - 1]);
			for (size_type j = 0; j < 1; j++) // loop fills inserted cells with val;
				this->copy_to_allocated_mem(i + j, val);
			this->size_ += 1;
			it = this->begin();
			while (i > 0)
			{
				++it;
				--i;
			}
			return (it);
		}

		void insert (iterator position, size_type n, const value_type& val){
			size_type i = 0;
			iterator it = this->begin();

			for (; it != position; ++it)
				++i;
			if (this->size_ + n >= this->capacity_)
				this->reserve(this->size_ + n);


			for (size_type j = this->size_; j >= 1 && j >= i; j--) // loop moves values in array after position to the and of new array
				this->copy_to_allocated_mem(j + n - 1, this->cntr_[j - 1]);
			for (size_type j = 0; j < n; j++) // loop fills inserted cells with val;
				this->copy_to_allocated_mem(i + j, val);
			this->size_ += n;

		}

		template <class InputIterator>
		void insert (iterator position, InputIterator first, InputIterator last,
					 typename enable_if<!std::numeric_limits<InputIterator>::is_specialized>::type * = 0){
			iterator it = this->begin();
			size_type i = 0;
			for (; it != position; ++it)
				++i;
			size_type size = last - first;
			if (this->size_ + size >= this->capacity_)
				this->reserve(this->size_ + size);
			for (size_type j = this->size_; j >= 1 && j > i; j--) // loop moves values in array after position to the and of new array
				this->copy_to_allocated_mem(j + size - 1, this->cntr_[j - 1]);
			for (size_type j = 0; j < size; j++) // loop fills inserted cells with val;
				this->copy_to_allocated_mem(i + j, *first++);
			this->size_ += size;
		}

		iterator erase (iterator position) {
			iterator next(position);
			++next;
			return (erase(position, next));
		}

		iterator erase (iterator first, iterator last){
			iterator it = this->begin();
			size_type NumOfEraseElements = last -first;
			size_type i = 0;
			size_type j;
			for (; it != first; ++it)
				++i;
			j = i;
			for (it = last; it != this->end(); ++it) {
				this->cntr_[j] = *it;
				++j;
			}
			for (it = last;  it != this->end(); ++it) {
				this->cntr_[j].value_type::~value_type();
				++j;
			}
			this->size_ -= NumOfEraseElements;
			return last;
		}


		void clear(){
			for (size_type i = 0; i < this->size_; ++i)
				this->cntr_[i].value_type::~value_type();
			this->size_ = 0;
		}

		void swap (Vector& x) {
			ft::swap(this->cntr_, x.cntr_);
			ft::swap(this->size_, x.size_);
			ft::swap(this->capacity_, x.capacity_);
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
