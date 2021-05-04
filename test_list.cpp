//
// Created by Rinat Nurutdinow on 5/4/21.
//

#include "tests.hpp"

void printHeader(std::string header)
{
	std::cout  << "\033[1;35m"
			   << "<<<<< "
			   << header
			   << " >>>>>"
			   << "\033[0m"
			   << std::endl;
}

void test_list()
{
	{
		printHeader("myList iterators begin() end()");
		ft::List<int>	myList;
		myList.push_back(10);
		myList.push_back(20);
		myList.push_back(30);

		printList(myList);
	}
	{
		printHeader("std::list iterators begin() end()");
		std::list<int>	myList;
		myList.push_back(10);
		myList.push_back(20);
		myList.push_back(30);

		printList(myList);
	}

	{
		printHeader("myList iterators rbegin() rend()");
		ft::List<int>	myList;
		myList.push_back(10);
		myList.push_back(20);
		myList.push_back(30);
		ft::List<int>::reverse_iterator it_r = myList.rend();
		printList(myList, myList.rbegin());
	}
	{
		printHeader("std::list iterators rbegin() rend()");
		std::list<int>	myList;
		myList.push_back(10);
		myList.push_back(20);
		myList.push_back(30);

		printList(myList, myList.rbegin());
	}
}
