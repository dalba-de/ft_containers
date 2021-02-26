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
	std::map<char,int> second;
	
	first['a']=1;
	first['b']=2;
	first['c']=3;

	second['d']=4;
	second['e']=5;

	first.swap(second);

	ft::printoMap(first);

	std::cout<< std::endl;

	ft::printoMap(second);

	std::cout << "\n\033[1;33m My Map\n \033[0m" << std::endl;
	
	ft::Map<char, int>	myfirst;
	//ft::Map<char, int>	mysecond;

	myfirst['a']=1;
	myfirst['b']=2;
	myfirst['b']=3;

	return 0;
}