//
// Created by Jamis Heat on 5/23/21.
//

#ifndef CONT_MY_VECTOR_HPP
#define CONT_MY_VECTOR_HPP


#include <iostream>
#include <iterator>
#include "Reverse_iterator.hpp"
#include "Algorithm.hpp"

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

		virtual reference operator*() {
			return (*this->_ptr);
		}

		virtual const_reference operator*() const {
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
	class vector {
	public:

		typedef T											value_type;
		typedef Alloc										allocator_type;
		typedef value_type&									reference;
		typedef const value_type&							const_reference;
		typedef value_type*									pointer;
		typedef const value_type*							const_pointer;
		typedef VectorIterator<value_type>					iterator;
		typedef VectorIterator<value_type const>			const_iterator;
		typedef Reverse_iterator<iterator>					reverse_iterator;
		typedef Reverse_iterator<const_iterator>			const_reverse_iterator;
		typedef std::ptrdiff_t								difference_type;
		typedef unsigned long								size_type;
//		typedef typename vector<value_type>::VectorIterator	it_type;

	private:

		pointer		cntr_;
		size_type	size_;
		size_type	capacity_;

		void printVector(vector& tmp) {
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
		vector (const allocator_type& alloc = allocator_type()) : cntr_(nullptr), size_(0), capacity_(0) {
		}
		vector (size_type n, const_reference val = value_type(),
				const allocator_type& alloc = allocator_type()) : cntr_(nullptr), capacity_(0), size_(0) {
			this->assign(n, val);
		}
		template <class InputIterator>
		vector (InputIterator first, InputIterator last,
				const allocator_type& alloc = allocator_type()) :  cntr_(nullptr), capacity_(0), size_(0) {
			this->assign(first, last);
		}
		vector (const vector& x) : cntr_(nullptr), capacity_(0), size_(x.size_) {
			this->clear();
			this->assign(x.begin(),x.end());
		}

		virtual ~vector() {
			this->clear();
			if (this->cntr_)
				::delete (this->cntr_);
		}

		vector& operator=(vector const & x) {
			this->clear();
			this->assign(x.begin(),x.end());
			return *this;
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

		reverse_iterator rbegin(){
			return (reverse_iterator(this->end()));
		}
		const_reverse_iterator rbegin() const{
			return (const_reverse_iterator(this->end()));
		}

		reverse_iterator rend(){
			return (reverse_iterator(this->cntr_));
		}
		const_reverse_iterator rend() const{
			return (const_reverse_iterator(this->cntr_));
		}

		//Capacity
		size_type size() const {
			return this->size_;
		}

		size_type max_size() const {
			return std::numeric_limits<size_type>::max() / sizeof(value_type);
		}

		void resize (size_type n, value_type val = value_type()){
			if (n > this->capacity_)
				reserve(n);
			else if (n <= this->size_)
			{
				for (size_type i = (this->size_ - 1); i >= n; --i)
				{
					this->cntr_[i].value_type::~value_type();
					--this->size_;
				}
			}
			else if (n > this->size_){
				for (int i = this->size_; i < n; ++i)
				{
					this->copy_to_allocated_mem(i, val);
					++this->size_;
				}

			}
		}

		size_type capacity() const {
			return this->capacity_;
		}

		bool empty() const {
			return this->size_ == 0;
		}

		void reserve (size_type n){
			if (n > this->max_size())
				throw std::bad_alloc();
			if (this->capacity_ == 0)
			{
				n = (n == 0) ? 1 : n;
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

//		Element access:
		reference operator[](size_type index)
		{
			return this->cntr_[index];
		}

		const_reference operator[](size_type index) const
		{
			return this->cntr_[index];
		}

		reference at (size_type n) {
			if (n >= this->size_)
				throw std::out_of_range ("out of range");
			return *(this->cntr_ + n);
		}
		const_reference at (size_type n) const{
			if (n >= this->size_)
				throw std::out_of_range ("out of range");
			return *(this->cntr_ + n);
		}

		reference front(){
			return *this->cntr_;
		}
		const_reference front() const{
			return *this->cntr_;
		}

		reference back() {
			return *(this->cntr_ + this->size_ - 1);
		}
		const_reference back() const {
			return *(this->cntr_ + this->size_ - 1);
		}

		//Modifiers
		template <class InputIterator>
		void assign (InputIterator first, InputIterator last,
					 typename enable_if<!std::numeric_limits<InputIterator>::is_specialized>::type * = 0)
		{
			this->clear();
			reserve(last - first);
			for (; first != last; ++first)
				this->push_back(*first);
		}
		void assign (size_type n, const value_type& val){
			this->clear();
			this->reserve(n);
			for (int i = 0; i < n; ++i)
				this->push_back(val);
		}

		void push_back (const value_type& val){
			if (this->size_ == this->capacity_) {
				this->reserve(this->size_ * 2);
			}
			new(&this->cntr_[this->size_]) value_type(val);
			this->size_ = this->size_ + 1;
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
			return first;
		}

		void swap (vector& x) {
			ft::swap_alg(this->cntr_, x.cntr_);
			ft::swap_alg(this->size_, x.size_);
			ft::swap_alg(this->capacity_, x.capacity_);
		}

		void clear(){
			for (size_type i = 0; i < this->size_; ++i)
				this->cntr_[i].value_type::~value_type();
			this->size_ = 0;
		}

		allocator_type get_allocator() const {
			return (Alloc());
		}

	};//vector end

	template <class T, class Alloc>
	bool operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs){
		if (lhs.size() != rhs.size())
			return false;
		for (size_t i = 0; i < lhs.size(); ++i)
		{
			if (lhs[i] != rhs[i])
				return false;
		}
		return true;

	}
	template <class T, class Alloc>
	bool operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs){
		return (!(lhs == rhs));
	}

	template <class T, class Alloc>
	bool operator<  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs){
		if (lexicographical_compare(lhs.begin(), lhs.end(),rhs.begin(),rhs.end()))
			return true;
		return false;
	}

	template <class T, class Alloc>
	bool operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs){
		return (!(rhs < lhs));
	}

	template <class T, class Alloc>
	bool operator>  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs){
		if (lhs < rhs || lhs == rhs)
			return false;
		return true;
	}

	template <class T, class Alloc>
	bool operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs){
		return (!(lhs < rhs));
	}

	template <class T, class Alloc>
	void swap (vector<T,Alloc>& x, vector<T,Alloc>& y)
	{
		x.swap(y);
	}

}// ft end

#endif //CONT_MY_VECTOR_HPP
