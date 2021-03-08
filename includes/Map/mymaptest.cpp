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

	
	std::cout << "\n\033[1;33m My Map\n \033[0m" << std::endl;
	
	ft::Map<int, int>	myfirst;
	myfirst[6] = 6;
	myfirst[2] = 2;
	myfirst[1] = 1;
	myfirst[9] = 9;
	myfirst[8] = 8;
	myfirst[15] = 15;
	myfirst[13] = 13;
	myfirst[11] = 11;
	myfirst[18] = 18;
	myfirst[20] = 20;
	ft::printMap(myfirst);

	return 0;
}