#include <map>
#include "../includes/Multimap/Multimap.hpp"
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

template <class K, class T>
void	printMultimaps(std::multimap<K, T> map, ft::Multimap<K, T> mymap)
{
	std::cout << GREEN"Map output:\n" << RESET << std::endl;
	ft::printoMultimap(map);
	std::cout << GREEN"\nMy Map output:\n" << RESET << std::endl;
	ft::printMultimap(mymap);
}

void	printMultimapBanner()
{
	system("clear");
	printf(CYAN"\n\n \
			\t\t\t\t\t\t████  ████╗██╗  ██╗██╗  ████████╗██╗████  ████╗   ██═╗  ███████═╗ ████████╗███████╗███████╗████████╗\n \
			\t\t\t\t\t\t██╔████═██║██║  ██║██║  ╚══██╔══╝██║██╔████═██║  ████╚╗ ██╔═══██║ ╚══██╔══╝██╔════╝██╔════╝╚══██╔══╝\n \
			\t\t\t\t\t\t██║ ██  ██║██║  ██║██║     ██║   ██║██║ ██  ██║ ██╔═██╚╗███████═╝    ██║   █████╗  ███████╗   ██║\n \
			\t\t\t\t\t\t██║     ██║██║  ██║██║     ██║   ██║██║     ██║████████║██║          ██║   ██╔══╝  ╚════██║   ██║\n \
			\t\t\t\t\t\t██║     ██║ █████╔╝██████╗ ██║   ██║██║     ██║██╔═══██║██║          ██║   ███████╗███████║   ██║\n \
			\t\t\t\t\t\t╚═╝     ╚═╝ ╚════╝ ╚═════╝ ╚═╝   ╚═╝╚═╝     ╚═╝╚═╝   ╚═╝╚═╝          ╚═╝   ╚══════╝╚══════╝   ╚═╝\n \
					\t\t\t\t\t\tby dalba-de			\n\n\033[0m");
}

void	checkMultimapContinue()
{
	std::cout << std::endl;
	std::string input;
	while (input != "c")
	{
		std::cout << ORANGE"Press 'c' to continue..." << RESET << std::endl;
		std::getline(std::cin, input);
	}
	printMultimapBanner();
}

void	multicount()
{
	std::cout << RED"Starting count() test" << RESET << std::endl;
	std::cout << BLUE"\nCreate map<int, string> and insert single values:\n" << RESET << std::endl;
	std::multimap<int, std::string>	map;
	ft::Multimap<int, std::string>	mymap;

	map.insert(std::pair<int, std::string>(12, "París"));
	map.insert(std::pair<int, std::string>(10, "Roma"));
	map.insert(std::pair<int, std::string>(9, "Luxemburgo"));
	map.insert(std::pair<int, std::string>(11, "Oslo"));
	map.insert(std::pair<int, std::string>(10, "Munich"));
	map.insert(std::pair<int, std::string>(20, "Lisboa"));
	map.insert(std::pair<int, std::string>(12, "Londres"));
	map.insert(std::pair<int, std::string>(12, "Madrid"));

	mymap.insert(std::pair<int, std::string>(12, "París"));
	mymap.insert(std::pair<int, std::string>(10, "Roma"));
	mymap.insert(std::pair<int, std::string>(9, "Luxemburgo"));
	mymap.insert(std::pair<int, std::string>(11, "Oslo"));
	mymap.insert(std::pair<int, std::string>(10, "Munich"));
	mymap.insert(std::pair<int, std::string>(20, "Lisboa"));
	mymap.insert(std::pair<int, std::string>(12, "Londres"));
	mymap.insert(std::pair<int, std::string>(12, "Madrid"));
	printMultimaps(map, mymap);

	std::cout << GREEN"\nNumber of nodes with key 12 in multimap is: " << RESET << map.count(12) << std::endl;
	std::cout << GREEN"Number of nodes with key 12 in mymultimap is: " << RESET << map.count(12) << std::endl;
	checkMultimapContinue();
}

void	multierase()
{
	std::cout << RED"Starting erase() test" << RESET << std::endl;
	std::cout << BLUE"\nCreate map<int, string> and insert single values:\n" << RESET << std::endl;
	std::multimap<int, std::string>	map;
	ft::Multimap<int, std::string>	mymap;

	map.insert(std::pair<int, std::string>(12, "París"));
	map.insert(std::pair<int, std::string>(10, "Roma"));
	map.insert(std::pair<int, std::string>(9, "Luxemburgo"));
	map.insert(std::pair<int, std::string>(11, "Oslo"));
	map.insert(std::pair<int, std::string>(10, "Munich"));
	map.insert(std::pair<int, std::string>(20, "Lisboa"));
	map.insert(std::pair<int, std::string>(12, "Londres"));
	map.insert(std::pair<int, std::string>(12, "Madrid"));

	mymap.insert(std::pair<int, std::string>(12, "París"));
	mymap.insert(std::pair<int, std::string>(10, "Roma"));
	mymap.insert(std::pair<int, std::string>(9, "Luxemburgo"));
	mymap.insert(std::pair<int, std::string>(11, "Oslo"));
	mymap.insert(std::pair<int, std::string>(10, "Munich"));
	mymap.insert(std::pair<int, std::string>(20, "Lisboa"));
	mymap.insert(std::pair<int, std::string>(12, "Londres"));
	mymap.insert(std::pair<int, std::string>(12, "Madrid"));
	printMultimaps(map, mymap);

	std::cout << BLUE"\nErase with key (12):\n" << RESET << std::endl;
	std::cout << GREEN"\nNumber of nodes erased in map: " << RESET << map.erase(12) << std::endl;
	std::cout << GREEN"\nNumber of nodes erased in mymap: " << RESET << mymap.erase(12) << std::endl << std::endl;
	printMultimaps(map, mymap);
	checkMultimapContinue();
}

void	multiInsert()
{
	std::cout << RED"Starting insert test" << RESET << std::endl;
	std::cout << BLUE"\nCreate map<int, string> and insert single values:\n" << RESET << std::endl;
	std::multimap<int, std::string>	map;
	ft::Multimap<int, std::string>	mymap;

	map.insert(std::pair<int, std::string>(12, "París"));
	map.insert(std::pair<int, std::string>(10, "Roma"));
	map.insert(std::pair<int, std::string>(9, "Luxemburgo"));
	map.insert(std::pair<int, std::string>(11, "Oslo"));
	map.insert(std::pair<int, std::string>(10, "Munich"));
	map.insert(std::pair<int, std::string>(20, "Lisboa"));
	map.insert(std::pair<int, std::string>(12, "Londres"));
	map.insert(std::pair<int, std::string>(12, "Madrid"));

	mymap.insert(std::pair<int, std::string>(12, "París"));
	mymap.insert(std::pair<int, std::string>(10, "Roma"));
	mymap.insert(std::pair<int, std::string>(9, "Luxemburgo"));
	mymap.insert(std::pair<int, std::string>(11, "Oslo"));
	mymap.insert(std::pair<int, std::string>(10, "Munich"));
	mymap.insert(std::pair<int, std::string>(20, "Lisboa"));
	mymap.insert(std::pair<int, std::string>(12, "Londres"));
	mymap.insert(std::pair<int, std::string>(12, "Madrid"));
	printMultimaps(map, mymap);

	std::cout << BLUE"\nInsert new value with hint (max efficiency):\n" << RESET << std::endl;
	std::multimap<int, std::string>::iterator it = map.find(20);
	ft::Multimap<int, std::string>::iterator myit = mymap.find(20);
	map.insert(it, std::pair<int, std::string>(21, "Moscú"));
	mymap.insert(myit, std::pair<int, std::string>(21, "Moscú"));
	printMultimaps(map, mymap);

	std::cout << BLUE"\nInsert new value with hint (no max efficiency):\n" << RESET << std::endl;
	it = map.find(12);
	myit = mymap.find(12);
	map.insert(it, std::pair<int, std::string>(13, "Dublin"));
	mymap.insert(myit, std::pair<int, std::string>(13, "Dublin"));
	printMultimaps(map, mymap);

	std::cout << BLUE"\nCreate new map with range insert:\n" << RESET << std::endl;
	std::multimap<int, std::string>	anothermap;
	ft::Multimap<int, std::string>	myanothermap;
	anothermap.insert(map.begin(), map.find(13));
	myanothermap.insert(mymap.begin(), mymap.find(13));
	printMultimaps(anothermap, myanothermap);
	checkMultimapContinue();
}

int		testMultimap()
{
	printMultimapBanner();
	multiInsert();
	multierase();
	multicount();
	return 0;
}