#include <map>
#include <iostream>
#include <string>
#include "Map.hpp"
#include "../Tools/Shared_functions.hpp"

struct cmpByStringLength {
    bool operator()(const std::string& a, const std::string& b) const {
        return a.length() < b.length();
    }
};

int	main()
{

	std::cout << "\n\033[1;31m Map Original\n \033[0m" << std::endl;

	std::map<char,int> first;
	

	first['x']=8;
	first['y']=16;
	first['z']=32;

	std::map<char,int> second(first.begin(), first.end());                // second now contains 3 ints

	ft::printoMap(second);

	std::cout << "\n\033[1;33m My Map\n \033[0m" << std::endl;
	
	ft::Map<char, int>	myfirst;
	

	myfirst['x']=8;
	myfirst['y']=16;
	myfirst['z']=32;

	ft::Map<char, int>	mysecond(myfirst.begin(), myfirst.end());

	ft::printMap(mysecond);

	return 0;
}