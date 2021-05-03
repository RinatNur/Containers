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

	ft::List<int>	myList;
//	ft::List<int>::iterator it = myList.begin();
	ft::List<int>::iterator it = myList.begin();
//	std::list<int> myList { 10, 20, 30};
//	std::list<int>::reverse_iterator it = myList.rbegin();

//	myList.push_back(10);
//	myList.
	myList.push_back(22);
	myList.push_back(30);
//	++it;
//	std::cout << *it_e << std::endl;

////	std::list<int>::iterator it = myList.begin();
	ft::List<int>	myList2(myList);
	myList2 = myList;
	for (it = myList2.begin(); it != myList2.end(); ++it)
		std::cout <<  *(it) << ' ';
//	std::cout << '\n';

	return 0;
}
