//
// Created by Jamis Heat on 6/2/21.
//

#include "tests.hpp"
#include "map.hpp"

void printHeader(std::string header);
void printDescription(std::string desc);

void map_test(){
	{
		printHeader("myMap test");
		ft::map<int,int> mymap;
		ft::map<int,int> mymap1;
		mymap.insert(std::pair<int,int>(50,5) );
		mymap.insert(mymap.begin(),std::pair<int,int>(2,5) );
		mymap.insert(std::pair<int,int>(40,5) );
		mymap.insert(std::pair<int,int>(12,5) );
		mymap.insert(std::pair<int,int>(6,5) );
		mymap.insert(std::pair<int,int>(75,5) );
		mymap.insert(std::pair<int,int>(16,5) );
		mymap.insert(std::pair<int,int>(67,5) );
		mymap.insert(std::pair<int,int>(1,5) );
		ft::map<int,int>::iterator it = mymap.begin();
		cout <<  it->first << endl;

	}
	{
		printHeader("std test");
		std::map<int,std::string> mymap;
		mymap[50] = "hello";
		mymap.at(50) += "TTT";
		mymap[60] = "world";
		std::map<int,std::string>::iterator it = mymap.begin();
		for (; it != mymap.end(); ++it)
			cout << it->first << " = " << it->second << endl;
	}
}
