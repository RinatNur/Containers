//
// Created by Jamis Heat on 5/23/21.
//

#include "tests.hpp"
#include "vector.hpp"

//void printHeader(std::string header);
//void printDescription(std::string desc);
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

void vector_test() {
	{
		printHeader("myvector erase()");
		ft::Vector<int> myvector (5,5);
		ft::Vector<int> myvector2 (3,3);

		std::cout << "myvector contains:";
		for (unsigned i=0; i<myvector.size(); ++i)
			std::cout << ' ' << myvector[i];
		std::cout << '\n';

		std::cout << "myvector2 contains:";
		for (unsigned i=0; i<myvector2.size(); ++i)
			std::cout << ' ' << myvector2[i];
		std::cout << '\n';

		printDescription("after swap");
		cout << endl;
		myvector.swap(myvector2);

		std::cout << "myvector contains:";
		for (unsigned i=0; i<myvector.size(); ++i)
			std::cout << ' ' << myvector[i];
		std::cout << '\n';

		std::cout << "myvector2 contains:";
		for (unsigned i=0; i<myvector2.size(); ++i)
			std::cout << ' ' << myvector2[i];
		std::cout << '\n';
	}
	{
		printHeader("myvector erase()");
		ft::Vector<int> myvector;

		// set some values (from 1 to 10)
		for (int i=1; i<=10; i++) myvector.push_back(i);

		// erase the 6th element
		myvector.erase (myvector.begin()+5);

		// erase the first 3 elements:
		myvector.erase (myvector.begin(),myvector.begin()+3);

		std::cout << "myvector contains:";
		for (unsigned i=0; i<myvector.size(); ++i)
			std::cout << ' ' << myvector[i];
		std::cout << '\n';
	}
	{
		printHeader("std erase()");
		std::vector<int> myvector;

		// set some values (from 1 to 10)
		for (int i=1; i<=10; i++) myvector.push_back(i);

		// erase the 6th element
		myvector.erase (myvector.begin()+5);

		// erase the first 3 elements:
		myvector.erase (myvector.begin(),myvector.begin()+3);

		std::cout << "myvector contains:";
		for (unsigned i=0; i<myvector.size(); ++i)
			std::cout << ' ' << myvector[i];
		std::cout << '\n';
	}
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
