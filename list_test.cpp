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

void printDescription(std::string desc)
{
	std::cout	<< "["
				 << desc
				 << "]:";
}

//bool single_digit (const int& value) { return (value<10); }
//bool same_integral_part (double first, double second)
//{ return ( int(first)==int(second) ); }
bool mycomparison (double first, double second)
{ return ( int(first)<int(second) ); }
bool compare_nocase (const std::string& first, const std::string& second)
{
	unsigned int i=0;
	while ( (i<first.length()) && (i<second.length()) )
	{
		if (tolower(first[i])<tolower(second[i])) return true;
		else if (tolower(first[i])>tolower(second[i])) return false;
		++i;
	}
	return ( first.length() < second.length() );
}

void list_test()
{
	{
		printHeader("myList reverse iterator");
		ft::list<int> mylist1;
		ft::list<int>::iterator it = mylist1.begin();
		for (int i = 1; i < 11; ++i)
			mylist1.push_back(i);
		printDescription("mylist1");
		printList(mylist1);
		ft::list<int>::reverse_iterator rit = mylist1.rbegin();
		cout << "rit.rbegin = " << *rit << endl;
		int y = 0;
		for (; rit != mylist1.rend(); ++rit)
			cout << " " << *rit;
		cout << endl;
//		for ()

	}
	{
		printHeader("std reverse iterator");
		std::list<int> mylist1;
		std::list<int>::iterator it = mylist1.begin();
		for (int i = 1; i < 11; ++i)
			mylist1.push_back(i);
		printDescription("mylist1");
		printList(mylist1);
		std::list<int>::reverse_iterator rit = mylist1.rbegin();
		int y = 0;
		for (; rit != mylist1.rend(); ++rit)
			cout << " " << *rit;
		cout << endl;
//		for ()

	}
//	{
//		printHeader("myList insert()");
//		ft::list<int> mylist1;
//		for (int i = 1; i < 11; ++i)
//			mylist1.push_back(i);
//		ft::list<int> mylist2;
//		std::vector<int> vec;
//		for (int i = 33; i < 40; ++i)
//			vec.push_back(i);
////		mylist1.insert(mylist1.end(), 5,99);
////		mylist1.insert(mylist1.end(), vec.begin(), vec.end());
//
//		printDescription("mylist1");
//		printList(mylist1);
//		printDescription("mylist1.size()");
//		cout << mylist1.size() << endl;
//		ft::list<int>::iterator it = mylist1.end();
//		ft::list<int>::iterator it2;
//		it2 = mylist1.erase(--it);
////		++it;
//		cout << "it2 = " << *it2 << endl;
//		printDescription("mylist1");
//		printList(mylist1);
//		printDescription("mylist1.size()");
//		cout << mylist1.size() << endl;
//	}
//	{
//		printHeader("std insert()");
//		std::list<int> mylist1;
//		for (int i = 1; i < 11; ++i)
//			mylist1.push_back(i);
//		std::list<int> mylist2;
//		std::vector<int> vec;
//		for (int i = 33; i < 40; ++i)
//			vec.push_back(i);
//		mylist1.insert(mylist1.end(), 5,99);
//		mylist1.insert(mylist1.end(), vec.begin(), vec.end());
//
//
//		printDescription("mylist1");
//		printList(mylist1);
//		printDescription("mylist1.size()");
//		cout << mylist1.size() << endl;
//
//		printDescription("mylist2");
//		printList(mylist2);
//		printDescription("mylist2.size()");
//		cout << mylist2.size() << endl;
//	}

//	{
//		printHeader("myList swap_alg(list, list");
//		for (int i = 1; i < 3; ++i)
//			mylist1.push_back(i);
//		ft::list<int> mylist2;
//		for (int i = 11; i < 21; ++i)
//			mylist2.push_back(i);
//		ft::iterator it = mylist2.begin();
//		++it;
//		++it;
//		++it;
//		++it;
//		++it;
//		ft::list<int> mylist1(mylist2);
//
//		printDescription("mylist1");
//		printList(mylist1);
//		printDescription("mylist1.size()");
//		cout << mylist1.size() << endl;
//
//		printDescription("mylist2");
//		printList(mylist2);
//		printDescription("mylist1.size()");
//		cout << mylist2.size() << endl;
//
//		ft::swap_alg(mylist1, mylist2);
//
//		printDescription("mylist1");
//		printList(mylist1);
//		printDescription("mylist1.size()");
//		cout << mylist1.size() << endl;
//
//		printDescription("mylist2");
//		printList(mylist2);
//		printDescription("mylist2.size()");
//		cout << mylist2.size() << endl;
//
//	}
//	{
//		printHeader("myList operator == < > <= >=");
//
//		ft::list<int> mylist1, mylist2;
//
//		for (int i=1; i<= 11; ++i) mylist1.push_back(i);
//		for (int i=1; i<= 22; ++i) mylist2.push_back(i);
//		printDescription("mylist1");
//		printList(mylist1);
//
//		printDescription("mylist2");
//		printList(mylist2);
//
//		if (mylist1 >= mylist2)
//			cout << "true" << endl;
//		else
//			cout << "false" << endl;
//
//
//	}
//	{
//		printHeader("std operator == < > <= >=");
//
//		std::list<int> mylist;// = {1,2, 3, 8, 5, 6, 7};
//		std::list<int> mylist2;// = {5};
//
//		for (int i=1; i<= 11; ++i) mylist.push_back(i);
//		for (int i=1; i<= 22; ++i) mylist2.push_back(i);
//		if (mylist  >= mylist2)
//			cout << "true" << endl;
//		else
//			cout << "false" << endl;
//
//		mylist.reverse();
//
//		printDescription("mylist");
//		printList(mylist);
//		printDescription("mylist.size()");
//		cout << mylist.size() << endl;
//	}
//	{
//		printHeader("myList reverse()");
//
//		ft::list<int> mylist;
//
//		for (int i=10; i >= 0; --i)
//			mylist.push_back(i);
//
//		printDescription("mylist");
//		printList(mylist);
//		printDescription("mylist.size()");
//		cout << mylist.size() << endl;
//
//		mylist.reverse();
//
//		printDescription("mylist");
//		printList(mylist);
//		printDescription("mylist.size()");
//		cout << mylist.size() << endl;
//	}
//	{
//		printHeader("std reverse()");
//
//		std::list<int> mylist;// = {1,2, 3, 8, 5, 6, 7};
//
//		for (int i=1; i<= 11; ++i) mylist.push_back(i);
//
//		mylist.reverse();
//
//		printDescription("mylist");
//		printList(mylist);
//		printDescription("mylist.size()");
//		cout << mylist.size() << endl;
//	}
//	{
//		printHeader("myList merge()");
//
//		ft::list<std::string> mylist;
//
//		mylist.push_back ("one");
//		mylist.push_back ("two");
//		mylist.push_back ("Three");
//
//		mylist.sort();
//
//		printDescription("mylist");
//		printList(mylist);
//		printDescription("mylist.size()");
//		cout << mylist.size() << endl;
//
//		mylist.sort(compare_nocase);
//
//		printDescription("mylist");
//		printList(mylist);
//		printDescription("mylist.size()");
//		cout << mylist.size() << endl;
//	}
//	{
//		printHeader("std3 merge()");
//
//		std::list<std::string> mylist;
//		std::list<std::string>::iterator it;
//		mylist.push_back ("one");
//		mylist.push_back ("two");
//		mylist.push_back ("Three");
//
//		mylist.sort();
//
//		printDescription("mylist");
//		printList(mylist);
//		printDescription("mylist.size()");
//		cout << mylist.size() << endl;
//
//		mylist.sort(compare_nocase);
//
//		printDescription("mylist");
//		printList(mylist);
//		printDescription("mylist.size()");
//		cout << mylist.size() << endl;
//	}
//	{
//		printHeader("myList merge()");
//
//		ft::list<double> first, second;
//		ft::list<double>::iterator it;
//
//
//		first.push_back (3.1);
//		first.push_back (2.2);
//		first.sort();
//		first.push_back (2.9);
//
//		second.push_back (3.7);
//		second.push_back (7.1);
//		second.push_back (1.4);
//
//		first.sort();
//		second.sort();
//
//		first.merge(second);
//
//		// (second is now empty)
//
//		second.push_back (2.1);
//
//		first.merge(second,mycomparison);
//
//		printDescription("first");
//		printList(first);
//		printDescription("first.size()");
//		cout << first.size() << endl;
//
//		printDescription("second");
//		printList(second);
//		printDescription("second.size()");
//		cout << second.size() << endl;
//	}
//	{
//		printHeader("std3 merge()");
//
//		std::list<double> first, second;
//
//		first.push_back (3.1);
//		first.push_back (2.2);
//		first.push_back (2.9);
//
//		second.push_back (3.7);
//		second.push_back (7.1);
//		second.push_back (1.4);
//
//		first.sort();
//		second.sort();
//
//		first.merge(second);
//
//		// (second is now empty)
//
//		second.push_back (2.1);
//
//		first.merge(second,mycomparison);
//
//		printDescription("first");
//		printList(first);
//		printDescription("first.size()");
//		cout << first.size() << endl;
//
//		printDescription("second");
//		printList(second);
//		printDescription("second.size()");
//		cout << second.size() << endl;
//	}

//	{
//		printHeader("myList unique()");
//		double mydoubles[]={ 2.72,  3.14, 12.15, 12.77, 12.77,
//				15.3,  72.25, 72.25, 73.0,  73.35 };
//		ft::list<double> mylist;
//		for (int i = 0; i < 10; ++i)
//			mylist.push_back(mydoubles[i]);   // 15 36 7 17 20 39 4 1
//
//		printDescription("mylist before unique");
//		printList(mylist);
//
//		mylist.unique();           //  2.72,  3.14, 12.15, 12.77
//		// 15.3,  72.25, 73.0,  73.35
//		printDescription("mylist after unique ");
//		printList(mylist);
//
//		mylist.unique (same_integral_part);  //  2.72,  3.14, 12.15
//		// 15.3,  72.25, 73.0
//
//		mylist.unique (is_near());           //  2.72, 12.15, 72.25
//
//		printDescription("mylist              ");
//		printList(mylist);
//		printDescription("mylist.size()");
//		cout << mylist.size() << endl;
//	}
//	{
//		printHeader("std unique()");
//		double mydoubles[]={ 2.72,  3.14, 12.15, 12.77, 12.77,
//							 15.3,  72.25, 72.25, 73.0,  73.35 };
//		std::list<double> mylist (mydoubles,mydoubles+10);
//		printDescription("mylist before unique");
//		printList(mylist);
//
//		mylist.unique();           //  2.72,  3.14, 12.15, 12.77
//		// 15.3,  72.25, 73.0,  73.35
//		printDescription("mylist after unique ");
//		printList(mylist);
//
//		mylist.unique (same_integral_part);  //  2.72,  3.14, 12.15
//		// 15.3,  72.25, 73.0
//
//		mylist.unique (is_near());           //  2.72, 12.15, 72.25
//
//
//		printDescription("mylist              ");
//		printList(mylist);
//		printDescription("mylist.size()");
//		cout << mylist.size() << endl;
//	}
//	{
//		printHeader("myList remove_if()");
//		int myints[]= {15,36,7,17,20,39,4,1};
//		ft::list<int> mylist;
//		for (int i = 0; i < 8; ++i)
//			mylist.push_back(myints[i]);   // 15 36 7 17 20 39 4 1
//
//		mylist.remove_if (single_digit);           // 15 36 17 20 39
//
//		mylist.remove_if (is_odd());               // 36 20
//
//		printDescription("mylist");
//		printList(mylist);
//		printDescription("mylist.size()");
//		cout << mylist.size() << endl;
//	}
//	{
//		printHeader("std remove_if()");
//		int myints[]= {15,36,7,17,20,39,4,1};
//		std::list<int> mylist (myints,myints+8);   // 15 36 7 17 20 39 4 1
//
//		mylist.remove_if (single_digit);           // 15 36 17 20 39
//
//		mylist.remove_if (is_odd());               // 36 20
//
//		printDescription("mylist");
//		printList(mylist);
//		printDescription("mylist.size()");
//		cout << mylist.size() << endl;
//	}
//	{
//		printHeader("myList remove()");
//		int myints[]= {17,89,7,14};
//		ft::list<int> mylist;
//		for (int i = 0; i < 4; ++i)
//			mylist.push_back(myints[i]);
//
//		mylist.remove(89);
//
//		printDescription("mylist");
//		printList(mylist);
//		printDescription("mylist.size()");
//		cout << mylist.size() << endl;
//	}
//	{
//		printHeader("std remove()");
//		int myints[]= {17,89,7,14};
//		std::list<int> mylist;// (myints,myints+4);
//
//		mylist.remove(89);
//
//		printDescription("mylist");
//		printList(mylist);
//		printDescription("mylist.size()");
//		cout << mylist.size() << endl;
//	}
//	{
//		printHeader("myList swap_alg()");
//		ft::list<int> mylist1, mylist2;
//		ft::list<int>::iterator it;
//
//		// set some initial values:
//		for (int i=1; i<=4; ++i)
//			mylist1.push_back(i);      // mylist1: 1 2 3 4
//
//		for (int i=1; i<=3; ++i)
//			mylist2.push_back(i*10);   // mylist2: 10 20 30
//
//		it = mylist1.begin();
//		++it;                         // points to 2
//
//		mylist1.splice (it, mylist2); // mylist1: 1 10 20 30 2 3 4
//		// mylist2 (empty)
//		// "it" still points to 2 (the 5th element)
//
//		mylist2.splice (mylist2.begin(),mylist1, it);
//		// mylist1: 1 10 20 30 3 4
//		// mylist2: 2
//		// "it" is now invalid.
//		it = mylist1.begin();
//		++it;          // "it" points now to 30
//		++it;          // "it" points now to 30
//		++it;          // "it" points now to 30
//
//		mylist1.splice ( mylist1.begin(), mylist1, it, mylist1.end());
//		// mylist1: 30 3 4 1 10 20
//
//		printDescription("myList1");
//		printList(mylist1);
//		printDescription("myList1.size()");
//		cout << mylist1.size() << endl;
//
//		printDescription("myList2");
//		printList(mylist2);
//		printDescription("myList2.size()");
//		cout << mylist2.size() << endl;
//	}
//	{
//		printHeader("std splice()");
//		std::list<int> mylist1, mylist2;
//		std::list<int>::iterator it;
//
//		// set some initial values:
//		for (int i=1; i<=4; ++i)
//			mylist1.push_back(i);      // mylist1: 1 2 3 4
//
//		for (int i=1; i<=3; ++i)
//			mylist2.push_back(i*10);   // mylist2: 10 20 30
//
//		it = mylist1.begin();
//		++it;                         // points to 2
//
//		mylist1.splice (it, mylist2); // mylist1: 1 10 20 30 2 3 4
//		// mylist2 (empty)
//		// "it" still points to 2 (the 5th element)
//
//		mylist2.splice (mylist2.begin(),mylist1, it);
//		// mylist1: 1 10 20 30 3 4
//		// mylist2: 2
//		// "it" is now invalid.
//		it = mylist1.begin();
//		std::advance(it,3);           // "it" points now to 30
//
//		mylist1.splice ( mylist1.begin(), mylist1, it, mylist1.end());
//		// mylist1: 30 3 4 1 10 20
//
//		printDescription("myList1");
//		printList(mylist1);
//		printDescription("myList1.size()");
//		cout << mylist1.size() << endl;
//
//		printDescription("myList2");
//		printList(mylist2);
//		printDescription("myList2.size()");
//		cout << mylist2.size() << endl;
//	}
//	{
//		printHeader("myList front() back()");
//		ft::list<int> mylist;
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
//		ft::list<int>	myList;
//		ft::list<int>	myList_tmp;
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
//		ft::list<int>	myList;
//		myList.push_back(10);
//
//		printList(myList);
//		std::cout << "size_ = " << myList.size() << endl;
//		cout << "max_size = " << myList.max_size() << endl;
//		std::cout << "is list empty " << myList.empty() << endl;
//	}
//	{
//		printHeader("std empty() size() max_size()");
//		std::list<int>	myList;
//		myList.push_back(10);
//		printList(myList);
//		std::cout << "size_ = " << myList.size() << endl;
//		cout << "max_size = " << myList.max_size() << endl;
//		std::cout << "is list empty " << myList.empty() << endl;
//	}
//	{
//		printHeader("myList pop_back() pop_front()");
//		ft::list<int>	myList;
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
//		ft::list<int>	myList;
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
//		ft::list<int>	myList;
//		myList.push_back(10);
//		myList.push_back(20);
//		myList.push_back(30);
//		myList.push_back(40);
//		ft::list<int>::iterator first = myList.begin();
//		ft::list<int>::iterator second = myList.end();
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
////		ft::list<int>	myList;
////		myList.push_back(10);
////		myList.push_back(20);
////		myList.push_back(30);
////		ft::list<int>::reverse_iterator it_r = myList.rend();
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
//		ft::list<int>	myList;
//		for (int i = 1; i < 9; ++i)
//			myList.push_back(i);
//		ft::list<int>::reverse_iterator it_r = myList.rbegin();
//		ft::list<int>::reverse_iterator it_tmp;
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
