//
// Created by Jamis Heat on 5/23/21.
//

#include "tests.hpp"
#include "queue.hpp"
//
void printHeader(std::string header);
void printDescription(std::string desc);

void queue_test(){
		{
		printHeader("myQueue");
//
		ft::Queue<int> myQueue1;
		ft::Queue<int> myQueue2;

		printDescription("is empty");
		cout << std::boolalpha << myQueue1.empty() << endl;

		printDescription("push 21");
		myQueue1.push(21);
		cout << endl;
		printDescription("push 1");
		myQueue1.push(1);
		cout << endl;

		printDescription("front element");
		cout << myQueue1.front() << endl;
		printDescription("back element");
		cout << myQueue1.back() << endl;
		printDescription("myQueue1.size()");
		cout << myQueue1.size() << endl;

		printDescription("front - back");
		cout << myQueue1.front() - myQueue1.back() << endl;



		printDescription("push myQueue2 22");
		myQueue2.push(22);
		cout << endl;

		printDescription("myQueue1 = mQueue2");
		cout << std::boolalpha << (myQueue1 == myQueue2) << endl;

		printDescription("myQueue1 < mQueue2");
		cout << std::boolalpha << (myQueue1 < myQueue2) << endl;

		printDescription("myQueue1 <= mQueue2");
		cout << std::boolalpha << (myQueue1 <= myQueue2) << endl;

		printDescription("myQueue1 > mQueue2");
		cout << std::boolalpha << (myQueue1 > myQueue2) << endl;

		printDescription("myQueue1 >= mQueue2");
		cout << std::boolalpha << (myQueue1 >= myQueue2) << endl;

		printDescription("myQueue2.pop()");
		myQueue2.pop();
		cout << endl;
		printDescription("is myQueue empty");
		cout << std::boolalpha << myQueue2.empty() << endl;
	}
	{
		printHeader("std queue");
		std::queue<int> myQueue1;
		std::queue<int> myQueue2;

		printDescription("is empty");
		cout << std::boolalpha << myQueue1.empty() << endl;

		printDescription("push 21");
		myQueue1.push(21);
		cout << endl;
		printDescription("push 1");
		myQueue1.push(1);
		cout << endl;

		printDescription("front element");
		cout << myQueue1.front() << endl;
		printDescription("back element");
		cout << myQueue1.back() << endl;
		printDescription("myQueue1.size()");
		cout << myQueue1.size() << endl;

		printDescription("front - back");
		cout << myQueue1.front() - myQueue1.back() << endl;



		printDescription("push myQueue2 22");
		myQueue2.push(22);
		cout << endl;

		printDescription("myQueue1 = mQueue2");
		cout << std::boolalpha << (myQueue1 == myQueue2) << endl;

		printDescription("myQueue1 < mQueue2");
		cout << std::boolalpha << (myQueue1 < myQueue2) << endl;

		printDescription("myQueue1 <= mQueue2");
		cout << std::boolalpha << (myQueue1 <= myQueue2) << endl;

		printDescription("myQueue1 > mQueue2");
		cout << std::boolalpha << (myQueue1 > myQueue2) << endl;

		printDescription("myQueue1 >= mQueue2");
		cout << std::boolalpha << (myQueue1 >= myQueue2) << endl;

		printDescription("myQueue2.pop()");
		myQueue2.pop();
		cout << endl;
		printDescription("is myQueue empty");
		cout << std::boolalpha << myQueue2.empty() << endl;
	}
}