//
// Created by Rinat Nurutdinow on 4/15/21.
//

#include "list.hpp"
#include <list>
#include "Node.hpp"
//#include "test.hpp"

//template <typename T>
//void printList (std::list<T> listToPrint)
//{
//	typename std::list<T>::iterator it = listToPrint.begin();
//	for (; it != listToPrint.end(); ++it)
//		std::cout << *it << " ";
//	std::cout << std::endl;
//}

int main ()
{
//	ft::Node<int>		myNode1(15);
//	ft::Node<int>		myNode2(25);
//	std::cout << myNode1.value() << std::endl;

//	myNode1.insert_before(&myNode2);
//	std::cout << myNode1.prev() << std::endl;
//	int numbers[]={10,20,30,40,50};
//	std::list<int> 	myVector;
//	ft::iterator<int> from(numbers);
//	ft::iterator<int> until(numbers+5);
//	for (ft::iterator<int> it=from; it!=until; it++)
//		std::cout << *myVector.end() << ' ';
	ft::List<int>	myList;
	ft::List<int>::iterator it = myList.begin();
//	std::list<int> myList;
//	std::list<int>::reverse_iterator it = myList.rbegin();

	myList.push_back(10);
	myList.push_back(20);
	myList.push_back(30);

	for (it = myList.begin(); it != myList.end(); ++it)
		std::cout <<  *(it) << ' ';
	std::cout << '\n';


//	std::list<double> myList;
//	myList.push_back(15.15);
//	myList.push_back(25);
//	myList.push_back(35);
//	printList(myList);

	return 0;
}
