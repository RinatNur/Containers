//
// Created by Jamis Heat on 5/23/21.
//

#include "tests.hpp"
#include "vector.hpp"

void printHeader(std::string header);
void printDescription(std::string desc);
//void printHeader(std::string header)
//{
//	std::cout  << "\033[1;35m"
//			   << "<<<<< "
//			   << header
//			   << " >>>>>"
//			   << "\033[0m"
//			   << std::endl;
//}

//void printDescription(std::string desc)
//{
//	std::cout	<< "["
//				 << desc
//				 << "]:";
//}

void vector_test() {
	{
		printHeader("myvector reverse iterator");
		ft::Vector<int> myVector;
		for (int i = 1; i < 11; ++i)
			myVector.push_back(i);
		ft::Vector<int>::iterator it = myVector.begin();
		printDescription("myVector");
		for (; it != myVector.end(); ++it)
			cout << " " << *it;
		cout << endl;
		ft::Vector<int>::reverse_iterator rit = myVector.rbegin();
		cout << "rit.rbegin = " << *rit << endl;
		int y = 0;
		for (; rit != myVector.rend(); ++rit)
			cout << " " << *rit;
		cout << endl;
	}

//	{
//		printHeader("myvector front() back()");
//		ft::Vector<int> myvector(2,3);
//		ft::Vector<int> myvector3(myvector);
////		myvector3 = myvector;
//		std::cout << "myvector3 contains:";
//		for (ft::Vector<int>::iterator it = myvector3.begin(); it != myvector3.end(); ++it)
//			std::cout << ' ' << *it;
//		std::cout << '\n';
//		std::cout << "myvector2 contains:";
//		ft::Vector<int> myvector2(3, 5);
//		for (ft::Vector<int>::iterator it = myvector2.begin(); it != myvector2.end(); ++it)
//			std::cout << ' ' << *it;
//		std::cout << '\n';
//		myvector.swap(myvector2);
//		std::cout << "myvector contains:";
//		for (ft::Vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
//			std::cout << ' ' << *it;
//		std::cout << '\n';
//		std::cout << "myvector2 contains:";
//		for (ft::Vector<int>::iterator it = myvector2.begin(); it != myvector2.end(); ++it)
//			std::cout << ' ' << *it;
//		std::cout << '\n';
//		int * p;
//		unsigned int i;
//
//		if (myvector < myvector2)
//			cout << "true" << endl;
//		else
//			cout << "false" << endl;
//
//		// allocate an array with space for 5 elements using vector's allocator:
//		p = myvector.get_allocator().allocate(5);
//
//		// construct values in-place on the array:
//		for (i=0; i<5; i++) myvector.get_allocator().construct(&p[i],i);
//
//		std::cout << "The allocated array contains:";
//		for (i=0; i<5; i++) std::cout << ' ' << p[i];
//		std::cout << '\n';
//
//		// destroy and deallocate:
//		for (i=0; i<5; i++) myvector.get_allocator().destroy(&p[i]);
//		myvector.get_allocator().deallocate(p,5);
//	}
//
//	{
//		std::vector<int> myvector;  // 5 default-constructed ints
//		int * p;
//		unsigned int i;
//
//		// allocate an array with space for 5 elements using vector's allocator:
//		p = myvector.get_allocator().allocate(5);
//
//		// construct values in-place on the array:
//		for (i=0; i<5; i++) myvector.get_allocator().construct(&p[i],i);
//
//		std::cout << "The allocated array contains:";
//		for (i=0; i<5; i++) std::cout << ' ' << p[i];
//		std::cout << '\n';
//
//		// destroy and deallocate:
//		for (i=0; i<5; i++) myvector.get_allocator().destroy(&p[i]);
//		myvector.get_allocator().deallocate(p,5);
//	}
//	{
//		printHeader("myvector front() back()");
//		ft::Vector<int> myvector(5);
//
//		int i=0;
//
//		ft::Vector<int>::reverse_iterator rit = myvector.rbegin();
//		for (; rit!= myvector.rend(); ++rit)
//			*rit = ++i;
//
//		ft::Vector<int>::iterator it = myvector.begin();
//		cout << "begin = " << *it << endl;
//		it = it + 2;
//		cout << "begin = " << *it << endl;
//
//		std::cout << "myvector contains:";
//		for (ft::Vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
//			std::cout << ' ' << *it;
//		std::cout << '\n';
//	}
//
//	{
//		std::vector<int> myvector (5);  // 5 default-constructed ints
//
//		int i=0;
//
//		std::vector<int>::reverse_iterator rit = myvector.rbegin();
//		for (; rit!= myvector.rend(); ++rit)
//			*rit = ++i;
//
//		std::cout << "myvector contains:";
//		for (std::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
//			std::cout << ' ' << *it;
//		std::cout << '\n';
//	}
//	{
//		printHeader("myvector front() back()");
//		ft::Vector<int> myvector;
//		// set some initial content:
//		for (int i=1;i<10;i++) myvector.push_back(i);
//
//		myvector.resize(5);
//		myvector.resize(8,100);
//		myvector.resize(12);
//
//		std::cout << "myvector contains:";
//		for (int i=0;i<myvector.size();i++)
//			std::cout << ' ' << myvector[i];
//		std::cout << '\n';
//	}
//
//	{
//		printHeader("std front() back()");
//		std::vector<int> myvector;
//		// set some initial content:
//		for (int i=1;i<10;i++) myvector.push_back(i);
//
//		myvector.resize(5);
//		myvector.resize(8,100);
//		myvector.resize(12);
//
//		std::cout << "myvector contains:";
//		for (int i=0;i<myvector.size();i++)
//			std::cout << ' ' << myvector[i];
//		std::cout << '\n';
//	}
//	{
//		printHeader("myvector front() back()");
//		ft::Vector<int> myvector;
//		myvector.push_back(78);
//		myvector.push_back(16);
//
//		// now front equals 78, and back 16
//
//		myvector.front() -= myvector.back();
//
//		std::cout << "myvector.front() is now " << myvector.front() << '\n';
//	}
//
//	{
//		printHeader("std front() back()");
//		std::vector<int> myvector;
//
//		myvector.push_back(78);
//		myvector.push_back(16);
//
//		// now front equals 78, and back 16
//
//		myvector.front() -= myvector.back();
//
//		std::cout << "myvector.front() is now " << myvector.front() << '\n';
//	}
//	{
//		printHeader("myvector at()");
//		ft::Vector<int> myvector (10);
//		for (unsigned i=0; i<myvector.size(); i++)
//			myvector.at(i)=i;
//
//		std::cout << "myvector contains:";
//		for (unsigned i=0; i<myvector.size(); i++)
//			std::cout << ' ' << myvector.at(i);
//		std::cout << '\n';
//	}
//
//	{
//		printHeader("std at()");
//		std::vector<int> myvector (10);   // 10 zero-initialized ints
//
//		// assign some values:
//		for (unsigned i=0; i<myvector.size(); i++)
//			myvector.at(i)=i;
//
//		std::cout << "myvector contains:";
//		for (unsigned i=0; i<myvector.size(); i++)
//			std::cout << ' ' << myvector.at(i);
//		std::cout << '\n';
//	}
//	{
//		printHeader("myvector swap()");
//		ft::Vector<int> myvector (5,5);
//		ft::Vector<int> myvector2 (3,3);
//		ft::Vector<int> myvector3;
//
//		std::cout << "myvector contains:";
//		for (unsigned i=0; i<myvector.size(); ++i)
//			std::cout << ' ' << myvector[i];
//		std::cout << '\n';
//
//		std::cout << "myvector2 contains:";
//		for (unsigned i=0; i<myvector2.size(); ++i)
//			std::cout << ' ' << myvector2[i];
//		std::cout << '\n';
//
//		printDescription("after swap");
//		cout << endl;
//		myvector.swap(myvector2);
//
//		std::cout << "myvector contains:";
//		for (unsigned i=0; i<myvector.size(); ++i)
//			std::cout << ' ' << myvector[i];
//		std::cout << '\n';
//
//		std::cout << "myvector2 contains:";
//		for (unsigned i=0; i<myvector2.size(); ++i)
//			std::cout << ' ' << myvector2[i];
//		std::cout << '\n';
//
//		printDescription("is myvector3 empty");
//		cout << std::boolalpha << myvector3.empty() << endl;
//		printDescription("myvector3.push_back(3)");
//		cout << endl;
//		myvector3.push_back(3);
//		printDescription("is myvector3 empty");
//		cout << std::boolalpha << myvector3.empty() << endl;
//
//	}
//	{
//		printHeader("myvector erase()");
//		ft::Vector<int> myvector;
//
//		// set some values (from 1 to 10)
//		for (int i=1; i<=10; i++) myvector.push_back(i);
//
//		// erase the 6th element
//		myvector.erase (myvector.begin()+5);
//
//		// erase the first 3 elements:
//		myvector.erase (myvector.begin(),myvector.begin()+3);
//
//		std::cout << "myvector contains:";
//		for (unsigned i=0; i<myvector.size(); ++i)
//			std::cout << ' ' << myvector[i];
//		std::cout << '\n';
//	}
//	{
//		printHeader("std erase()");
//		std::vector<int> myvector;
//
//		// set some values (from 1 to 10)
//		for (int i=1; i<=10; i++) myvector.push_back(i);
//
//		// erase the 6th element
//		myvector.erase (myvector.begin()+5);
//
//		// erase the first 3 elements:
//		myvector.erase (myvector.begin(),myvector.begin()+3);
//
//		std::cout << "myvector contains:";
//		for (unsigned i=0; i<myvector.size(); ++i)
//			std::cout << ' ' << myvector[i];
//		std::cout << '\n';
//	}
//	{
//		printHeader("myvector assign()");
//		ft::Vector<int> first;
//		ft::Vector<int> second;
//		ft::Vector<int> third;
//
//		ft::Vector<int>::iterator it;
//
//		first.assign (7,100);             // 7 ints with a value of 100
//		std::cout << "myvector contains:";
//		for (it=first.begin(); it<first.end(); it++)
//			std::cout << ' ' << *it;
//		std::cout << '\n';
//		cout << "capacity = " << first.capacity() << endl;
//
//		it=first.begin()+1;
//		second.assign (it,first.end()-1); // the 5 central values of first
//		std::cout << "myvector contains:";
//		for (it=second.begin(); it<second.end(); it++)
//			std::cout << ' ' << *it;
//		std::cout << '\n';
//		cout << "capacity = " << second.capacity() << endl;
//
//		int myints[] = {1776,7,4};
//		third.assign (myints,myints+3);   // assigning from array.
//		std::cout << "myvector contains:";
//		for (it=third.begin(); it<third.end(); it++)
//			std::cout << ' ' << *it;
//		std::cout << '\n';
//		cout << "capacity = " << third.capacity() << endl;
//
//		std::cout << "Size of first: " << int (first.size()) << '\n';
//		std::cout << "Size of second: " << int (second.size()) << '\n';
//		std::cout << "Size of third: " << int (third.size()) << '\n';
//	}
//	{
//		printHeader("std  assign()");
//		std::vector<int> first;
//		std::vector<int> second;
//		std::vector<int> third;
//
//		first.assign (7,100);             // 7 ints with a value of 100
//
//		std::vector<int>::iterator it;
//		it=first.begin()+1;
//
//		second.assign (it,first.end()-1); // the 5 central values of first
//
//		int myints[] = {1776,7,4};
//		third.assign (myints,myints+3);   // assigning from array.
//
//		std::cout << "Size of first: " << int (first.size()) << '\n';
//		std::cout << "Size of second: " << int (second.size()) << '\n';
//		std::cout << "Size of third: " << int (third.size()) << '\n';
//	}
//	{
//		printHeader("myvector insert()");
//		ft::Vector<int> myvector;
//		ft::Vector<int> myvector2;
//
//		ft::Vector<int>::iterator it;
//		it = myvector.begin();
//		it = myvector.insert ( it ,  200 );
//
//		myvector.insert (it,2,300);
//
//		// "it" no longer valid, get a new one:
//		it = myvector.begin();
//
//		std::vector<int> anothervector (2,400);
//		myvector.insert (it+2,anothervector.begin(),anothervector.end());
//
//		int myarray [] = { 501,502,503 };
//		myvector.insert (myvector.begin(), myarray, myarray+3);
//
//		std::cout << "myvector contains:";
//		for (it=myvector.begin(); it<myvector.end(); it++)
//			std::cout << ' ' << *it;
//		std::cout << '\n';
//	}
//	{
//		printHeader("std  insert()");
//		std::vector<int> myvector;
//		std::vector<int>::iterator it;//		it = myvector.begin();
//		it = myvector.begin();
//		it = myvector.insert ( it , 200 );
//
//		myvector.insert (it,2,300);
//
////		 "it" no longer valid, get a new one:
//		it = myvector.begin();
//
//		std::vector<int> anothervector (2,400);
//		myvector.insert (it+2,anothervector.begin(),anothervector.end());
//
//		int myarray [] = { 501,502,503 };
//		myvector.insert (myvector.begin(), myarray, myarray+3);
//
//		std::cout << "myvector contains:";
//		for (it=myvector.begin(); it<myvector.end(); it++)
//			std::cout << ' ' << *it;
//		std::cout << '\n';
//	}
}
