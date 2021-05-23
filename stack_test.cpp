//
// Created by Jamis Heat on 5/20/21.
//

#include "tests.hpp"
#include "stack.hpp"

void printHeader(std::string header);
void printDescription(std::string desc);

void stack_test() {
	{
		printHeader("myStack");

		ft::Stack<int, ft::List<int> > myStack1;
		ft::Stack<int, ft::List<int> > myStack2;
		myStack1.push(5);
		myStack1.push(10);

		myStack2.push(6);
		myStack2.push(10);
		if (myStack1 == myStack2)
			cout << "true" << endl;
		else
			cout << "false" << endl;

		cout << myStack1.empty() << endl;
		cout << myStack1.size() << endl;
//		myStack1.pop();
		printDescription("last element entered");
		cout << myStack1.top() << endl;
		printDescription("myStack1.size()");
		cout << myStack1.size() << endl;
	}
	{
		printHeader("std stack");
		std::stack<int> myStack1;
		std::stack<int> myStack2;
		myStack1.push(5);
//		myStack1.push(10);

		myStack2.push(6);
		myStack2.push(10);
		if (myStack1 <= myStack2)
			cout << "true" << endl;
		else
			cout << "false" << endl;

		cout << myStack1.empty() << endl;
		cout << myStack1.size() << endl;
//		myStack1.pop();
		printDescription("last element entered");
		cout << myStack1.top() << endl;
		printDescription("myStack1.size()");
		cout << myStack1.size() << endl;
	}
}