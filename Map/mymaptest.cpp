#include <map>
#include <iostream>
#include <string>
#include "Map.hpp"

struct cmpByStringLength {
    bool operator()(const std::string& a, const std::string& b) const {
        return a.length() < b.length();
    }
};

int	main()
{

	std::cout << "\n\033[1;31m Map Original\n \033[0m" << std::endl;

	std::map<int, std::string>	map;

	std::cout << (map.insert(std::pair<int, std::string>(1, "hola"))).first->second << std::endl;
	map.insert(std::pair<int, std::string>(3, "adios"));
	map.insert(std::pair<int, std::string>(2, "¿como estas?"));

	/*std::map<int, std::string>::iterator it = map.find(4);

	if (it != map.end())
		std::cout << it->second << std::endl;
	else
	{
		std::cout << "Key not found\n";
	}
	

	for ( ; it != map.end(); it++)
		std::cout << it->first << ' ' << it->second << std::endl;*/

	std::cout << "\n\033[1;33m My Map\n \033[0m" << std::endl;
	

	ft::Map<int, std::string> my_map;

	/*my_map.insert(std::pair<int, std::string>(42, "Madrid"));
	my_map.insert(std::pair<int, std::string>(24, "Marrakech"));
	my_map.insert(std::pair<int, std::string>(84, "Pa tu culo mi aparato"));
	my_map.insert(std::pair<int, std::string>(13, "Cuanti mas me la meneas mas me crece"));

	ft::Map<int, std::string>::iterator my_it = my_map.begin();

	for ( ; my_it != my_map.end(); ++my_it)
		std::cout << my_it->first << ' ' << my_it->second << std::endl;


	ft::Map<int, std::string>::iterator my_it;

	my_it = my_map.find(32);
	
	if (my_it != my_map.end())
		std::cout << my_it->second << std::endl;
	else
	{
		std::cout << "Key not found\n";
	}*/

	my_map.insert(std::pair<int, std::string>(42, "Madrid"));

	ft::Map<int, std::string>::iterator my_it = my_map.begin();

	my_map.insert(my_it, std::pair<int, std::string>(24, "Marrakech"));

	my_it = my_map.begin();

	for ( ; my_it != my_map.end(); ++my_it)
		std::cout << my_it->first << ' ' << my_it->second << std::endl;
	
}