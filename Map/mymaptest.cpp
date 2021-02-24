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

	std::map<char, int>	map;
	std::map<char,int>::key_compare mycomp = map.key_comp();

	map['a']=100;
  	map['b']=200;
  	map['c']=300;

	std::map<char, int>::reverse_iterator	rit = map.rbegin();
	rit++;
	char highest = rit->first;

	std::map<char,int>::iterator it = map.begin();
	do {
		std::cout << it->first << " => " << it->second << '\n';
	} while ( mycomp((*it++).first, highest) );

  	std::cout << '\n';

	/*std::map<int, std::string>	map;
	std::map<int, std::string>	map1;

	map.insert(std::pair<int, std::string>(6, "Madrid"));
	map.insert(std::pair<int, std::string>(2, "Holanda"));
	map.insert(std::pair<int, std::string>(1, "Suecia"));
	map.insert(std::pair<int, std::string>(4, "Vitoria"));
	map.insert(std::pair<int, std::string>(11, "Suances"));
	map.insert(std::pair<int, std::string>(15, "Silicon Valley"));
	map.insert(std::pair<int, std::string>(17, "Filipinas"));

	map1[1] = "hola";
	map1[2] = "como estas";
	map1[3] = "adios";

	ft::printoMap(map);
	std::cout << std::endl;
	ft::printoMap(map1);
	std::cout << std::endl;

	map.swap(map1);

	ft::printoMap(map);
	std::cout << std::endl;
	ft::printoMap(map1);

	std::cout << std::endl;
	std::cout << "map size: " << map.size() << std::endl;
	std::cout << "map1 size: " << map1.size() << std::endl;*/

	std::cout << "\n\033[1;33m My Map\n \033[0m" << std::endl;
	
	ft::Map<char, int>	my_map;
	ft::Map<char,int>::key_compare my_mycomp = my_map.key_comp();

	my_map['a']=100;
  	my_map['b']=200;
  	my_map['c']=300;

	ft::Map<char, int>::reverse_iterator	my_rit = my_map.rbegin();
	my_rit++;
	char my_highest = my_rit->first;

	ft::Map<char,int>::iterator my_it = my_map.begin();
	do {
		std::cout << my_it->first << " => " << my_it->second << '\n';
	} while ( my_mycomp((*my_it++).first, my_highest) );

  	std::cout << '\n';

	/*ft::Map<int, std::string> my_map;
	ft::Map<int, std::string> my_map1;

	my_map.insert(std::pair<int, std::string>(6, "Madrid"));
	my_map.insert(std::pair<int, std::string>(2, "Holanda"));
	my_map.insert(std::pair<int, std::string>(1, "Suecia"));
	my_map.insert(std::pair<int, std::string>(4, "Vitoria"));
	my_map.insert(std::pair<int, std::string>(11, "Suances"));
	my_map.insert(std::pair<int, std::string>(15, "Silicon Valley"));
	my_map.insert(std::pair<int, std::string>(17, "Filipinas"));

	my_map1[1] = "hola";
	my_map1[2] = "como estas";
	my_map1[3] = "adios";


	ft::printMap(my_map);
	std::cout << std::endl;
	ft::printMap(my_map1);
	std::cout << std::endl;

	my_map.swap(my_map1);

	ft::printMap(my_map);
	std::cout << std::endl;
	ft::printMap(my_map1);
	std::cout << std::endl;

	std::cout << "my_map size: " << my_map.size() << std::endl;
	std::cout << "my_map1 size: " << my_map1.size() << std::endl;*/

}