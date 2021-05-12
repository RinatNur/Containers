//
// Created by Rinat Nurutdinow on 5/4/21.
//

#include "tests.hpp"

using std::endl;
using std::cout;

void printHeader(std::string header)
{
	std::cout  << "\033[1;35m"
			   << "<<<<< "
			   << header
			   << " >>>>>"
			   << "\033[0m"
			   << std::endl;
}

void printDescription(std::string desc)
{
	std::cout	<< "["
				<< desc
				<< "]:";
}

void test_list()
{
	{
		printHeader("myList assign()");
		unsigned long s;
		ft::List<int>	myList;
		ft::List<int>	myList_tmp;

		myList.push_back(10);
		myList.push_back(20);
		myList.push_back(30);
		myList.push_back(40);

		for (int i = 100; i < 115; ++i)
			myList_tmp.push_back(i);

		printDescription("ft::myList");
		printList(myList);

		printDescription("ft::myList_tmp");
		printList(myList_tmp);

		myList_tmp.assign(myList.begin(), myList.end());
		printDescription("myList_tmp.assign\n(myList.begin(), myList.end())");
		printList(myList_tmp);

		myList_tmp.assign(8, 50);
		printDescription("myList_tmp.assign(8, 50)");
		printList(myList_tmp);

	}
	{
		printHeader("std assign()");
		unsigned long s;
		std::list<int>	myList;
		std::list<int>	myList_tmp;

		myList.push_back(10);
		myList.push_back(20);
		myList.push_back(30);
		myList.push_back(40);

		for (int i = 100; i < 115; ++i)
			myList_tmp.push_back(i);

		printDescription("std::myList");
		printList(myList);

		printDescription("std::myList_tmp");
		printList(myList_tmp);

		myList_tmp.assign(myList.begin(), myList.end());
		printDescription("myList_tmp.assign\n(myList.begin(), myList.end())");
		printList(myList_tmp);

		myList_tmp.assign(8, 50);
		printDescription("myList_tmp.assign(8, 50)");
		printList(myList_tmp);
	}
//	{
//		printHeader("myList empty() size() max_size()");
//		unsigned long s;
//		ft::List<int>	myList;
//		myList.push_back(10);
//
//		printList(myList);
//		std::cout << "m_size = " << myList.size() << endl;
//		cout << "max_size = " << myList.max_size() << endl;
//		std::cout << "is list empty " << myList.empty() << endl;
//	}
//	{
//		printHeader("std empty() size() max_size()");
//		std::list<int>	myList;
//		myList.push_back(10);
//		printList(myList);
//		std::cout << "m_size = " << myList.size() << endl;
//		cout << "max_size = " << myList.max_size() << endl;
//		std::cout << "is list empty " << myList.empty() << endl;
//	}
//	{
//		printHeader("myList pop_back() pop_front()");
//		ft::List<int>	myList;
//		myList.push_back(10);
//		myList.push_back(20);
//		myList.push_back(30);
//		myList.push_back(40);
//
//		printList(myList);
//		myList.pop_back();
//		myList.pop_front();
//		printList(myList);
//	}
//	{
//		printHeader("std pop_back() pop_front()");
//		std::list<int>	myList;
//		myList.push_back(10);
//		myList.push_back(20);
//		myList.push_back(30);
//		myList.push_back(40);
//
//		printList(myList);
//		myList.pop_back();
//		myList.pop_front();
//		printList(myList);
//	}
//	{
//		printHeader("myList resize");
//		ft::List<int>	myList;
//		myList.push_back(10);
//		myList.push_back(20);
//		myList.push_back(30);
//		myList.push_back(40);
//
//		printList(myList);
//		myList.resize( 10,55);
//		printList(myList);
//	}
//	{
//		printHeader("std::list resize");
//		std::list<int>	myList;
//		myList.push_back(10);
//		myList.push_back(20);
//		myList.push_back(30);
//		myList.push_back(40);
//
//		printList(myList);
//		myList.resize(0, 55);
//		printList(myList);
//	}
//	{
//		printHeader("myList iterators begin() end()");
//		ft::List<int>	myList;
//		myList.push_back(10);
//		myList.push_back(20);
//		myList.push_back(30);
//		myList.push_back(40);
//		ft::List<int>::iterator first = myList.begin();
//		ft::List<int>::iterator second = myList.end();
////		--second;
////		--second;
//		printList(myList);
//		myList.erase( first,second);
//		printList(myList);
//	}
//	{
//		printHeader("std::list iterators begin() end()");
//		std::list<int>	myList;
////		myList.erase(myList.end()); //segfault
//		myList.push_back(10);
//		myList.push_back(20);
//		myList.push_back(30);
//		myList.push_back(40);
//		std::list<int>::iterator first = myList.begin();
//		std::list<int>::iterator second = myList.end();
//		--second;
//		--second;
////		std::cout << *myList.begin() << std::endl;
//		printList(myList);
//		myList.erase(first,first);
//		printList(myList);
//	}
//
//	{
//		printHeader("myList iterators rbegin() rend()");
//		ft::List<int>	myList;
//		myList.push_back(10);
//		myList.push_back(20);
//		myList.push_back(30);
//		ft::List<int>::reverse_iterator it_r = myList.rend();
//
//		printList(myList, myList.rbegin());
//		myList.clear();
////		printList(myList, myList.rbegin());
//	}
//	{
//		printHeader("std::list iterators rbegin() rend()");
//		std::list<int>	myList;
//		myList.push_back(10);
//		myList.push_back(20);
//		myList.push_back(30);
//
//		printList(myList, myList.rbegin());
//		myList.clear();
//		printList(myList, myList.rbegin());
//	}
//	{
//		printHeader("myList operator+ operator-");
//		ft::List<int>	myList;
//		for (int i = 1; i < 9; ++i)
//			myList.push_back(i);
//		ft::List<int>::reverse_iterator it_r = myList.rbegin();
//		ft::List<int>::reverse_iterator it_tmp;
////		std::cout << *it_r << "\n";
////		++it_r;
////		std::cout << *it_r << "\n";
////		++it_r;
////		std::cout << *it_r << "\n";
////		++it_r;
////		std::cout << *it_r << "\n";
////		++it_r;
////		std::cout << *it_r << "\n";
////		it_tmp = it_r + 4;
////		std::cout << *it_tmp << "\n";
////		printList(myList, myList.rbegin());
//	}
//	{
//		printHeader("std::list operator+ operator-");
//		std::list<int>	myList;
//		for (int i = 1; i < 9; ++i)
//			myList.push_back(i);
//		std::list<int>::reverse_iterator it_r = myList.rbegin();
//		std::list<int>::reverse_iterator it_tmp;
////		std::cout << *it_r << "\n";
////		++it_r;
////		std::cout << *it_r << "\n";
////		++it_r;
////		std::cout << *it_r << "\n";
////		++it_r;
////		std::cout << *it_r << "\n";
////		++it_r;
////		std::cout << *it_r << "\n";
////		it_tmp = it_r + 4;
////		std::cout << *it_tmp << "\n";
////		printList(myList, myList.rbegin());
//	}
}
