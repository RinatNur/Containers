//
// Created by Rinat Nurutdinow on 5/4/21.
//

#ifndef CONT_MY_TESTS_HPP
#define CONT_MY_TESTS_HPP

#include <iostream>
#include <math.h>
#include "list.hpp"
#include <list>
#include <string>
#include "Node.hpp"


// ft::List print

template <typename T>
void printList(const ft::List<T>& list) {
	typename ft::List<T>::iterator it_begin = list.begin();
	for (; it_begin != list.end(); ++it_begin)
		std::cout << ' ' <<  *(it_begin);
	std::cout << std::endl;
}

// std::list print
template <typename T>
void printList(std::list<T> list){
	typename std::list<T>::iterator it_begin = list.begin();
	for (; it_begin != list.end(); ++it_begin)
		std::cout << ' ' <<  *(it_begin);
	std::cout << std::endl;
}

template <typename T>
void printList(ft::List<T> list, ft::Reverse_iterator<T> it_reverse){
	for (it_reverse = list.rbegin(); it_reverse != list.rend(); ++it_reverse)
		std::cout << ' ' <<  *(it_reverse);
	std::cout << std::endl;
}

// std::list print
template <typename T>
void printList(std::list<T> list, typename std::list<T>::reverse_iterator it_reverse){
//	typename std::list<T>::Reverse_iterator it_rbegin = iterator_begin;
	for (it_reverse = list.rbegin(); it_reverse != list.rend(); ++it_reverse)
		std::cout << ' ' <<  *(it_reverse);
	std::cout << std::endl;
}

// a predicate implemented as a class:
struct is_odd {
	bool operator() (const int& value) { return (value%2)==1; }
};

// a binary predicate implemented as a class:
struct is_near {
	bool operator() (double first, double second)
	{ return (fabs(first-second)<5.0); }
};

void printHeader(std::string header);
void test_list();
bool single_digit (const int& value);
bool same_integral_part (double first, double second);

#endif //CONT_MY_TESTS_HPP
