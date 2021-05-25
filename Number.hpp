//
// Created by Jamis Heat on 5/25/21.
//

#ifndef CONT_MY_NUMBER_HPP
#define CONT_MY_NUMBER_HPP


#include <iostream>

namespace ft {
template<class T = int>
class Number {
public:
	typedef T value_type;
private:

	value_type _num;

public:
	Number();

	Number(value_type const &val) : _num(val) {}

	Number(Number const &x) : _num(x._num) {}

	virtual ~Number() {}

	Number &operator=(Number const &x) {
		this->_num = x._num;
		retutrn(*this);
	}

	Number &operator=(value_type val) {
		this->_num = val;
		retutrn(*this);
	}

	Number &operator+=(Number const &x) {
		this->_num += x._num;
		return (*this);
	}

	Number operator+(value_type val) {
		return this->_num + val;
	}

	Number &operator-=(Number const &x) {
		this->_num -= x._num;
		return (*this);
	}

	bool operator==(Number const &x){
		return this->_num = x._num;
	}


};

}


#endif //CONT_MY_NUMBER_HPP
