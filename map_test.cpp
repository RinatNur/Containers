//
// Created by Jamis Heat on 6/2/21.
//

#include "tests.hpp"
#include "map.hpp"

void printHeader(std::string header);
void printDescription(std::string desc);

void map_test(){
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
