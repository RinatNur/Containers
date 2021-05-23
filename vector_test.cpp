//
// Created by Jamis Heat on 5/23/21.
//

#include "tests.hpp"
#include "vector.hpp"

void vector_test() {
	ft::Vector<int> myVector;
	myVector.push_back(5);
	myVector.push_back(10);
	myVector.push_back(15);

	for (ft::Vector<int>::iterator it = myVector.begin(); it != myVector.end(); ++it)
	{

	}
}
