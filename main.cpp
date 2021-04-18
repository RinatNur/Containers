//
// Created by Rinat Nurutdinow on 4/15/21.
//

#include "list.hpp"
#include <list>
#include "Node.hpp"

template <typename T>
void printList (std::list<T> listToPrint)
{
	typename std::list<T>::iterator it = listToPrint.begin();
	for (; it != listToPrint.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
}

int main ()
{
	ft::Node<int>		myNode(15);
	std::cout << myNode.value() << std::endl;

//	std::list<double> myList;
//	myList.push_back(15.15);
//	myList.push_back(25);
//	myList.push_back(35);
//	printList(myList);

	return 0;
}
