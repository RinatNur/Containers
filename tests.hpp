//
// Created by Rinat Nurutdinow on 5/4/21.
//

#ifndef CONT_MY_TESTS_HPP
#define CONT_MY_TESTS_HPP

#include <iostream>
#include "list.hpp"
#include <list>
#include "Node.hpp"


// ft::List print
template <typename T>
void printList(ft::List<T> list){
	typename ft::List<T>::iterator it_begin = list.begin();
	for (; it_begin != list.end(); ++it_begin)
		std::cout <<  *(it_begin) << ' ';
	std::cout << std::endl;
}

// std::list print
template <typename T>
void printList(std::list<T> list){
	typename std::list<T>::iterator it_begin = list.begin();
	for (; it_begin != list.end(); ++it_begin)
		std::cout <<  *(it_begin) << ' ';
	std::cout << std::endl;
}

template <typename T>
void printList(ft::List<T> list, ft::reverse_iterator<T> it_reverse){
	for (it_reverse = list.rbegin(); it_reverse != list.rend(); ++it_reverse)
		std::cout <<  *(it_reverse) << ' ';
	std::cout << std::endl;
}

// std::list print
template <typename T>
void printList(std::list<T> list, typename std::list<T>::reverse_iterator it_reverse){
//	typename std::list<T>::reverse_iterator it_rbegin = iterator_begin;
	for (it_reverse = list.rbegin(); it_reverse != list.rend(); ++it_reverse)
		std::cout <<  *(it_reverse) << ' ';
	std::cout << std::endl;
}




void printHeader(std::string header);
void test_list();

#endif //CONT_MY_TESTS_HPP