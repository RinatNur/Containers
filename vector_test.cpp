//
// Created by Jamis Heat on 5/23/21.
//

#include "tests.hpp"
#include "vector.hpp"

void printHeader(std::string header);
void printDescription(std::string desc);

void vector_test() {
	{
		printHeader("myvector");
		ft::Vector<int> myvector;
		ft::Vector<int> myvector2;

		ft::Vector<int>::iterator it;
		myvector.push_back(100);
		myvector.push_back(200);
		myvector.push_back(300);
		myvector2.push_back(400);
		myvector2.push_back(500);
		it = myvector.begin();
		++it;

//		it = myvector.insert ( it , 200 );
		myvector.insert (it, myvector2.begin(), myvector2.end());
//
////		myvector.push_back(15);
////		myvector.push_back(25);
//
////		ft::Vector<int>::iterator it = myvector.begin();
////		++it;
////		++it;
////		++it;
////		++it;
////		++it;
////		--it;
////		cout << "it = " << *it << endl;
//
////		myvector.pop_back();
////		myvector.pop_back();
////		myvector.pop_back();
////		myvector.pop_back();
////		myvector.pop_back();
		for (ft::Vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it) {
			cout << " " << *it;
		}
		cout << endl;
//		for (ft::Vector<int>::iterator it = myvector2.begin(); it != myvector2.end(); ++it) {
//			cout << " " << *it;
//		}
//		cout << endl;
	}
	{
		printHeader("std vector");
		std::vector<int> myvector;
		std::vector<int>::iterator it;//		it = myvector.begin();
		myvector.push_back(100);
		myvector.push_back(200);
		myvector.push_back(300);
		myvector.push_back(400);
		myvector.push_back(500);
		it = myvector.begin();
//		++it;

//		it = myvector.insert ( it , 200 );
		myvector.insert (it, ++myvector.begin(), myvector.end());
//		std::vector<int> tmp (myvector);


//		// "it" no longer valid, get a new one:
//		it = myvector.begin();
//////
//		std::vector<int> anothervector (2,400);
//		myvector.insert (it+2,anothervector.begin(),anothervector.end());
//		cout << "capacity = " << myvector.capacity() << endl;
////
//		int myarray [] = { 501,502,503 };
//		myvector.insert (myvector.begin(), myarray, myarray+3);

		std::cout << "myvector contains:";
		for (it=myvector.begin(); it<myvector.end(); it++)
			std::cout << ' ' << *it;
		std::cout << '\n';

//	myVector[2].int::~int();
		cout << endl;
	}
}
