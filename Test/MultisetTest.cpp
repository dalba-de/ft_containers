#include <set>
#include "../includes/Multiset/Multiset.hpp"
#include "../includes/Tools/Shared_functions.hpp"
#include "Test.hpp"
# define RESET		"\033[0m"
# define RED		"\033[1;31m"
# define GREEN		"\033[1;32m"
# define ORANGE		"\033[1;33m"
# define PURPLE		"\033[35m"
# define CYAN		"\033[1;36m"
# define BLUE       "\033[1;34m"
# define GREY		"\033[1;30m"
# define UNDER		"\033[4m"

template <class T>
void	printmultisets(std::multiset<T> map, ft::Multiset<T> mymap)
{
	std::cout << GREEN"Map output:\n" << RESET << std::endl;
	ft::printoMultiset(map);
	std::cout << GREEN"\nMy Map output:\n" << RESET << std::endl;
	ft::printMultiset(mymap);
}

void	printmultisetBanner()
{
	system("clear");
	printf(CYAN"\n\n \
			\t\t\t\t\t\t████  ████╗██╗  ██╗██╗  ████████╗██╗███████╗███████╗████████╗ ████████╗███████╗███████╗████████╗\n \
			\t\t\t\t\t\t██╔████═██║██║  ██║██║  ╚══██╔══╝██║██╔════╝██╔════╝╚══██╔══╝ ╚══██╔══╝██╔════╝██╔════╝╚══██╔══╝\n \
			\t\t\t\t\t\t██║ ██  ██║██║  ██║██║     ██║   ██║███████╗█████╗     ██║       ██║   █████╗  ███████╗   ██║\n \
			\t\t\t\t\t\t██║     ██║██║  ██║██║     ██║   ██║╚════██║██╔══╝     ██║       ██║   ██╔══╝  ╚════██║   ██║\n \
			\t\t\t\t\t\t██║     ██║ █████╔╝██████╗ ██║   ██║███████║███████╗   ██║       ██║   ███████╗███████║   ██║\n \
			\t\t\t\t\t\t╚═╝     ╚═╝ ╚════╝ ╚═════╝ ╚═╝   ╚═╝╚══════╝╚══════╝   ╚═╝       ╚═╝   ╚══════╝╚══════╝   ╚═╝\n \
					\t\t\t\t\t\tby dalba-de			\n\n\033[0m");
}

void	checkmultisetContinue()
{
	std::cout << std::endl;
	std::string input;
	while (input != "c")
	{
		std::cout << ORANGE"Press 'c' to continue..." << RESET << std::endl;
		std::getline(std::cin, input);
	}
	printmultisetBanner();
}

void	multisetcount()
{
	std::cout << RED"Starting count() test" << RESET << std::endl;
	std::cout << BLUE"\nCreate map<int, string> and insert single values:\n" << RESET << std::endl;
	std::multiset<int>	map;
	ft::Multiset<int>	mymap;

	map.insert(12);
	map.insert(10);
	map.insert(9);
	map.insert(11);
	map.insert(10);
	map.insert(20);
	map.insert(12);
	map.insert(12);

	mymap.insert(12);
	mymap.insert(10);
	mymap.insert(9);
	mymap.insert(11);
	mymap.insert(10);
	mymap.insert(20);
	mymap.insert(12);
	mymap.insert(12);
	printmultisets(map, mymap);

	std::cout << GREEN"\nNumber of nodes with key 12 in multiset is: " << RESET << map.count(12) << std::endl;
	std::cout << GREEN"Number of nodes with key 12 in mymultiset is: " << RESET << map.count(12) << std::endl;
	checkmultisetContinue();
}

void	multiseterase()
{
	std::cout << RED"Starting erase() test" << RESET << std::endl;
	std::cout << BLUE"\nCreate map<int, string> and insert single values:\n" << RESET << std::endl;
	std::multiset<int>	map;
	ft::Multiset<int>	mymap;

	map.insert(12);
	map.insert(10);
	map.insert(9);
	map.insert(11);
	map.insert(10);
	map.insert(20);
	map.insert(12);
	map.insert(12);

	mymap.insert(12);
	mymap.insert(10);
	mymap.insert(9);
	mymap.insert(11);
	mymap.insert(10);
	mymap.insert(20);
	mymap.insert(12);
	mymap.insert(12);
	printmultisets(map, mymap);

	std::cout << BLUE"\nErase with key (12):\n" << RESET << std::endl;
	std::cout << GREEN"\nNumber of nodes erased in map: " << RESET << map.erase(12) << std::endl;
	std::cout << GREEN"\nNumber of nodes erased in mymap: " << RESET << mymap.erase(12) << std::endl << std::endl;
	printmultisets(map, mymap);
	checkmultisetContinue();
}

void	multisetInsert()
{
	std::cout << RED"Starting insert test" << RESET << std::endl;
	std::cout << BLUE"\nCreate map<int, string> and insert single values:\n" << RESET << std::endl;
	std::multiset<int>	map;
	ft::Multiset<int>	mymap;

	map.insert(12);
	map.insert(10);
	map.insert(9);
	map.insert(11);
	map.insert(10);
	map.insert(20);
	map.insert(12);
	map.insert(12);

	mymap.insert(12);
	mymap.insert(10);
	mymap.insert(9);
	mymap.insert(11);
	mymap.insert(10);
	mymap.insert(20);
	mymap.insert(12);
	mymap.insert(12);
	printmultisets(map, mymap);

	std::cout << BLUE"\nInsert new value with hint (max efficiency):\n" << RESET << std::endl;
	std::multiset<int>::iterator it = map.find(20);
	ft::Multiset<int>::iterator myit = mymap.find(20);
	map.insert(21);
	mymap.insert(21);
	printmultisets(map, mymap);

	std::cout << BLUE"\nInsert new value with hint (no max efficiency):\n" << RESET << std::endl;
	it = map.find(12);
	myit = mymap.find(12);
	map.insert(it, (13));
	mymap.insert(myit, (13));
	printmultisets(map, mymap);

	std::cout << BLUE"\nCreate new map with range insert:\n" << RESET << std::endl;
	std::multiset<int>	anothermap;
	ft::Multiset<int>	myanothermap;
	anothermap.insert(map.begin(), map.find(13));
	myanothermap.insert(mymap.begin(), mymap.find(13));
	printmultisets(anothermap, myanothermap);
	checkmultisetContinue();
}

int		testMultiset()
{
	printmultisetBanner();
	multisetInsert();
	multiseterase();
	multisetcount();
	return 0;
}