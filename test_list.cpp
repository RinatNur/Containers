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
		printHeader("myList swap()");
		ft::List<int> mylist1, mylist2;
		ft::List<int>::iterator it;

		// set some initial values:
		for (int i=1; i<=4; ++i)
			mylist1.push_back(i);      // mylist1: 1 2 3 4

		for (int i=1; i<=3; ++i)
			mylist2.push_back(i*10);   // mylist2: 10 20 30

		it = mylist1.begin();
		++it;                         // points to 2

		mylist1.splice (it, mylist2); // mylist1: 1 10 20 30 2 3 4
		// mylist2 (empty)
		// "it" still points to 2 (the 5th element)

		mylist2.splice (mylist2.begin(),mylist1, it);
		// mylist1: 1 10 20 30 3 4
		// mylist2: 2
		// "it" is now invalid.
		it = mylist1.begin();
		++it; ++it; ++it;          // "it" points now to 30

		mylist1.splice ( mylist1.begin(), mylist1, it, mylist1.end());
		// mylist1: 30 3 4 1 10 20

		printDescription("mylist1 contains:");
		printList(mylist1);
		printDescription("myList1.size()");
		cout << mylist1.size() << endl;
		printDescription("mylist2 contains:");
		printList(mylist2);
		printDescription("myList2.size()");
		cout << mylist2.size() << endl;
	}
	{
		printHeader("std splice()");
		std::list<int> mylist1, mylist2;
		std::list<int>::iterator it;

		// set some initial values:
		for (int i=1; i<=4; ++i)
			mylist1.push_back(i);      // mylist1: 1 2 3 4

		for (int i=1; i<=3; ++i)
			mylist2.push_back(i*10);   // mylist2: 10 20 30

		it = mylist1.begin();
		++it;                         // points to 2

		mylist1.splice (it, mylist2); // mylist1: 1 10 20 30 2 3 4
		// mylist2 (empty)
		// "it" still points to 2 (the 5th element)

		mylist2.splice (mylist2.begin(),mylist1, it);
		// mylist1: 1 10 20 30 3 4
		// mylist2: 2
		// "it" is now invalid.
		it = mylist1.begin();
		std::advance(it,3);           // "it" points now to 30

		mylist1.splice ( mylist1.begin(), mylist1, it, mylist1.end());
		// mylist1: 30 3 4 1 10 20

		printDescription("mylist1 contains:");
		printList(mylist1);
		printDescription("myList1.size()");
		cout << mylist1.size() << endl;
		printDescription("mylist2 contains:");
		printList(mylist2);
		printDescription("myList2.size()");
		cout << mylist2.size() << endl;
	}
//	{
//		printHeader("myList front() back()");
//		ft::List<int> mylist;
//
//		mylist.push_back(77);
//		mylist.push_back(22);
//
//		// now front equals 77, and back 22
//
//		mylist.front() -= mylist.back();
//
//		std::cout << "mylist.front() is now " << mylist.front() << '\n';
//	}
//	{
//		printHeader("std front() back()");
//		std::list<int> mylist;
//
//		mylist.push_back(77);
//		mylist.push_back(22);
//
//		// now front equals 77, and back 22
//
//		mylist.front() -= mylist.back();
//
//		std::cout << "mylist.front() is now " << mylist.front() << '\n';
//	}
//	{
//		printHeader("myList assign()");
//		unsigned long s;
//		ft::List<int>	myList;
//		ft::List<int>	myList_tmp;
//
//		myList.push_back(10);
//		myList.push_back(20);
//		myList.push_back(30);
//		myList.push_back(40);
//
//		for (int i = 100; i < 115; ++i)
//			myList_tmp.push_back(i);
//
//		printDescription("ft::myList");
//		printList(myList);
//
//		printDescription("ft::myList_tmp");
//		printList(myList_tmp);
//
////		myList_tmp.assign(myList.begin(), myList.end());
//		printDescription("myList_tmp.assign\n(myList.begin(), myList.end())");
//		printList(myList_tmp);
//
//		myList_tmp.assign(8, 50);
//		printDescription("myList_tmp.assign(8, 50)");
//		printList(myList_tmp);
//
//	}
//	{
//		printHeader("std assign()");
//		unsigned long s;
//		std::list<int>	myList;
//		std::list<int>	myList_tmp;
//
//		myList.push_back(10);
//		myList.push_back(20);
//		myList.push_back(30);
//		myList.push_back(40);
//
//		for (int i = 100; i < 115; ++i)
//			myList_tmp.push_back(i);
//
//		printDescription("std::myList");
//		printList(myList);
//
//		printDescription("std::myList_tmp");
//		printList(myList_tmp);
//
//		myList_tmp.assign(myList.begin(), myList.end());
//		printDescription("myList_tmp.assign\n(myList.begin(), myList.end())");
//		printList(myList_tmp);
//
//		myList_tmp.assign(8, 50);
//		printDescription("myList_tmp.assign(8, 50)");
//		printList(myList_tmp);
//	}
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
////		printHeader("myList iterators rbegin() rend()"); TODO segmentation fault
////		ft::List<int>	myList;
////		myList.push_back(10);
////		myList.push_back(20);
////		myList.push_back(30);
////		ft::List<int>::reverse_iterator it_r = myList.rend();
////
////		printList(myList, myList.rbegin());
////		myList.clear();
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
