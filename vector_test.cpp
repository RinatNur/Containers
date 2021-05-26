//
// Created by Jamis Heat on 5/23/21.
//

#include "tests.hpp"
#include "vector.hpp"

void printHeader(std::string header);
void printDescription(std::string desc);

void vector_test() {
	{
		printHeader("myVector");
		ft::Vector<int> myVector;
		myVector.push_back(5);
		myVector.push_back(10);
		myVector.push_back(15);
		myVector.push_back(25);

		ft::Vector<int>::iterator it = myVector.begin();
//		++it;
//		++it;
//		++it;
//		++it;
//		++it;
//		--it;
//		cout << "it = " << *it << endl;
		cout << "max_size = " << myVector.max_size() << endl;

		myVector.pop_back();
		myVector.pop_back();
		myVector.pop_back();
		myVector.pop_back();
		myVector.pop_back();
		for (ft::Vector<int>::iterator it = myVector.begin(); it != myVector.end(); ++it) {
			cout << " " << *it;
		}
		cout << endl;
	}
	{
		printHeader("std vector");
		std::vector<int> myVector;
		myVector.push_back(5);
		myVector.push_back(10);
		myVector.push_back(15);
		myVector.push_back(25);
		std::vector<int>::iterator it = myVector.begin();
		cout << "max_size = " << myVector.max_size() << endl;

//		++it;
//		--it;
//		cout << "it = " << *it << endl;
//		myVector.pop_back();
		for (std::vector<int>::iterator it = myVector.begin(); it != myVector.end(); ++it) {
			cout << " " << *it;
		}
//	myVector[2].int::~int();
		cout << endl;
	}
}
