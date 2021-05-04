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
	{
		printHeader("myList operator+ operator-");
		ft::List<int>	myList;
		for (int i = 1; i < 9; ++i)
			myList.push_back(i);
		ft::List<int>::reverse_iterator it_r = myList.rbegin();
		ft::List<int>::reverse_iterator it_tmp;
		std::cout << *it_r << "\n";
		++it_r;
		std::cout << *it_r << "\n";
		++it_r;
		std::cout << *it_r << "\n";
		++it_r;
		std::cout << *it_r << "\n";
		++it_r;
		std::cout << *it_r << "\n";
		it_tmp = it_r + 4;
//		std::cout << *it_tmp << "\n";
//		printList(myList, myList.rbegin());
	}
	{
		printHeader("std::list operator+ operator-");
		std::list<int>	myList;
		for (int i = 1; i < 9; ++i)
			myList.push_back(i);
		std::list<int>::reverse_iterator it_r = myList.rbegin();
		std::list<int>::reverse_iterator it_tmp;
		std::cout << *it_r << "\n";
		++it_r;
		std::cout << *it_r << "\n";
		++it_r;
		std::cout << *it_r << "\n";
		++it_r;
		std::cout << *it_r << "\n";
		++it_r;
		std::cout << *it_r << "\n";
//		it_tmp = it_r + 4;
//		std::cout << *it_tmp << "\n";
//		printList(myList, myList.rbegin());
	}
}
