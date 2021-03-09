#include <map>
#include "../includes/Map/Map.hpp"
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

class mapfoo
{
private:
	/* data */
public:
	mapfoo(/* args */);
	~mapfoo();
};

mapfoo::mapfoo(/* args */)
{
}

mapfoo::~mapfoo()
{
}


template <class K, class T>
void	printMaps(std::map<K, T> map, ft::Map<K, T> mymap)
{
	std::cout << GREEN"Map output:\n" << RESET << std::endl;
	ft::printoMap(map);
	std::cout << GREEN"\nMy Map output:\n" << RESET << std::endl;
	ft::printMap(mymap);
}

void	printMapBanner()
{
	system("clear");
	printf(CYAN"\n\n \
			\t\t\t\t\t\t████  ████╗   ██═╗  ███████═╗ ████████╗███████╗███████╗████████╗\n \
			\t\t\t\t\t\t██╔████═██║  ████╚╗ ██╔═══██║ ╚══██╔══╝██╔════╝██╔════╝╚══██╔══╝\n \
			\t\t\t\t\t\t██║ ██  ██║ ██╔═██╚╗███████═╝    ██║   █████╗  ███████╗   ██║\n \
			\t\t\t\t\t\t██║     ██║████████║██║          ██║   ██╔══╝  ╚════██║   ██║\n \
			\t\t\t\t\t\t██║     ██║██╔═══██║██║          ██║   ███████╗███████║   ██║\n \
			\t\t\t\t\t\t╚═╝     ╚═╝╚═╝   ╚═╝╚═╝          ╚═╝   ╚══════╝╚══════╝   ╚═╝\n \
					\t\t\t\t\t\tby dalba-de			\n\n\033[0m");
}

void	checkMapContinue()
{
	std::cout << std::endl;
	std::string input;
	while (input != "c")
	{
		std::cout << ORANGE"Press 'c' to continue..." << RESET << std::endl;
		std::getline(std::cin, input);
	}
	printMapBanner();
}

struct cmpByStringLength {
    bool operator()(const std::string& a, const std::string& b) const {
        return a.length() < b.length();
    }
};

void	mapElementAccessTest()
{
	std::cout << RED"Starting element access test" << RESET << std::endl;
	std::cout << ORANGE"\n\nChecking operator[]:" << RESET << std::endl;
	std::cout << BLUE"\nCreating map<char, std::string>:\n" << RESET << std::endl;

	std::map<char,std::string> map;

	map['a']="an element";
	map['b']="another element";
	map['c']=map['b'];

	std::cout << GREEN"map['a'] is " << map['a'] << '\n';
	std::cout << "map['b'] is " << map['b'] << '\n';
	std::cout << "map['c'] is " << map['c'] << '\n';
	std::cout << "map['d'] is " << map['d'] << '\n';

	std::cout << std::endl;
	std::cout << GREEN"map now contains " << RESET << map.size() << GREEN" elements.\n" << RESET;
	std::cout << std::endl;

	ft::Map<char,std::string> mymap;
	mymap['a']="an element";
	mymap['b']="another element";
	mymap['c']=mymap['b'];

	std::cout << GREEN"mymap['a'] is " << mymap['a'] << '\n';
	std::cout << "mymap['b'] is " << mymap['b'] << '\n';
	std::cout << "mymap['c'] is " << mymap['c'] << '\n';
	std::cout << "mymap['d'] is " << mymap['d'] << '\n';

	std::cout << std::endl;
	std::cout << GREEN"mymap now contains " << RESET << mymap.size() << GREEN" elements.\n" << RESET;
	std::cout << std::endl;
}

void	mapCapacityTest()
{
	std::cout << RED"Starting capacity test" << RESET << std::endl;
	std::map<char, int>	map;
	ft::Map<char, int>	mymap;
	std::map<char, int>	map1;
	ft::Map<char, int>	mymap1;
	std::cout << BLUE"\nCreating map<char, int> with some values and empty map1:\n" << RESET << std::endl;
	map['b'] = 100;
	map['a'] = 200;
	map['c'] = 300;
	mymap['b'] = 100;
	mymap['a'] = 200;
	mymap['c'] = 300;
	std::cout << "\n\033[1;33mPrinting filled list:\n" << RESET << std::endl;
	printMaps(map, mymap);
	std::cout << "\n\033[1;33mPrinting empty list:\n" << RESET << std::endl;
	printMaps(map1, mymap1);

	std::cout << BLUE"\nChecking empty() function with map:\n" << RESET << std::endl;
	if (map.empty())
		std::cout << GREEN"list is empty" << RESET << std::endl;
	else
		std::cout << GREEN"list is not empty" << RESET << std::endl;
	if (mymap.empty())
		std::cout << GREEN"mylist is empty" << RESET << std::endl;
	else
		std::cout << GREEN"mylist is not empty" << RESET << std::endl;

	std::cout << BLUE"\nChecking empty() function with map1:\n" << RESET << std::endl;
	if (map1.empty())
		std::cout << GREEN"list1 is empty" << RESET << std::endl;
	else
		std::cout << GREEN"list1 is not empty" << RESET << std::endl;
	if (mymap1.empty())
		std::cout << GREEN"mylist1 is empty" << RESET << std::endl;
	else
		std::cout << GREEN"mylist1 is not empty" << RESET << std::endl;

	std::cout << BLUE"\nChecking size() function:\n" << RESET << std::endl;
	std::cout << GREEN"map size: " << RESET << map.size() << GREEN". map1 size: " << RESET << map1.size() << RESET << std::endl;
	std::cout << GREEN"mymap size: " << RESET << mymap.size() << GREEN". mymap1 size: " << RESET << mymap1.size() << RESET << std::endl;

	std::cout << BLUE"\nChecking max_size() function:\n" << RESET << std::endl;
	std::cout << ORANGE"Checking with <char,int>: " << RESET << std::endl;
	std::cout << GREEN"map<char, int> max_size: " << RESET << map.max_size() << RESET << std::endl;
	std::cout << GREEN"mymap<char, int> max_size: " << RESET << mymap.max_size() << RESET << std::endl;
	std::map<std::string, int> map2;
	ft::Map<std::string, int> mymap2;
	std::cout << ORANGE"\nChecking with std::string: " << RESET << std::endl;
	std::cout << GREEN"map<std::string, int> max_size: " << RESET << map2.max_size() << RESET << std::endl;
	std::cout << GREEN"mymap<std::string, int> max_size: " << RESET << mymap2.max_size() << RESET << std::endl;
	std::map<mapfoo*, int> map3;
	ft::Map<mapfoo*, int> mymap3;
	std::cout << ORANGE"\nChecking with another class: " << RESET << std::endl;
	std::cout << GREEN"map<foo*, int> max_size: " << RESET << map3.max_size() << RESET << std::endl;
	std::cout << GREEN"mymap<foo*, int> max_size: " << RESET << mymap3.max_size() << RESET << std::endl;
	checkMapContinue();
}

void	constMapIteratorsTest(const std::map<char, int>& map, const ft::Map<char, int>& mymap)
{
	std::map<char,int>::const_iterator cit = map.begin();
	ft::Map<char, int>::const_iterator mycit = mymap.begin();
	std::map<char, int>::const_reverse_iterator rcit = map.rbegin();
	ft::Map<char, int>::const_reverse_iterator myrcit = mymap.rbegin();
	std::cout << BLUE"\nIterating from begin() to end() with const iterators:\n" << RESET << std::endl;
	std::cout << GREEN"In vector: \n" << RESET;
	for (; cit != map.end(); cit++)
		std::cout << cit->first << ' ';
	std::cout << RESET << std::endl;
	std::cout << GREEN"In myvector: \n" << RESET;
	for (; mycit != mymap.end(); mycit++)
		std::cout << mycit->first << ' ';
	std::cout << RESET << std::endl;

	std::cout << BLUE"\nIterating from rbegin() to rend() with const iterators:\n" << RESET << std::endl;
	std::cout << GREEN"In map: \n" << RESET;
	for (; rcit != map.rend(); rcit++)
		std::cout << rcit->first << ' ';
	std::cout << RESET << std::endl;
	std::cout << GREEN"In mymap: \n" << RESET;
	for (; myrcit != mymap.rend(); myrcit++)
		std::cout << myrcit->first << ' ';
	std::cout << RESET << std::endl;
}

void	mapIteratorsTest()
{
	std::cout << RED"Starting iterators test" << RESET << std::endl;
	std::map<char, int>	map;
	ft::Map<char, int>	mymap;
	std::cout << BLUE"\nCreating map<char, int> with some values:\n" << RESET << std::endl;
	map['b'] = 100;
	map['a'] = 200;
	map['c'] = 300;
	mymap['b'] = 100;
	mymap['a'] = 200;
	mymap['c'] = 300;

	std::map<char, int>::iterator it = map.begin();
	ft::Map<char, int>::iterator myit = mymap.begin();
	std::cout << GREEN"map begin() points to: " << RESET << it->first << std::endl;
	std::cout << GREEN"mymap begin() points to: " << RESET << myit->first << std::endl;
	std::cout << std::endl;

	std::map<char, int>::reverse_iterator rit = map.rbegin();
	ft::Map<char, int>::reverse_iterator myrit = mymap.rbegin();
	std::cout << GREEN"map rbegin() points to: " << RESET << rit->first << std::endl;
	std::cout << GREEN"mymap rbegin() points to: " << RESET << myrit->first << std::endl;
	std::cout << std::endl;

	std::cout << BLUE"\nIterating from begin() to end():\n" << RESET << std::endl;
	std::cout << GREEN"In vector: \n" << RESET;
	for (; it != map.end(); it++)
		std::cout << it->first << ' ';
	std::cout << RESET << std::endl;
	std::cout << GREEN"In myvector: \n" << RESET;
	for (; myit != mymap.end(); myit++)
		std::cout << myit->first << ' ';
	std::cout << RESET << std::endl;

	std::cout << BLUE"\nIterating from rbegin() to rend():\n" << RESET << std::endl;
	std::cout << GREEN"In vector: \n" << RESET;
	for (; rit != map.rend(); rit++)
		std::cout << rit->first << ' ';
	std::cout << RESET << std::endl;
	std::cout << GREEN"In myvector: \n" << RESET;
	for (; myrit != mymap.rend(); myrit++)
		std::cout << myrit->first << ' ';
	std::cout << RESET << std::endl;

	std::cout << BLUE"\nTrying with const iterators:\n" << RESET << std::endl;
	constMapIteratorsTest(map, mymap);
	checkMapContinue();
}

void	mapConstructorsTest()
{
	std::cout << RED"Starting constructor test" << RESET << std::endl;
	std::cout << BLUE"Create first map<char, int> and add some values:\n" << RESET << std::endl;
	std::map<char, int> first;
	ft::Map<char, int> myfirst;
	first['a']=10;
	first['b']=30;
	first['c']=50;
	first['d']=70;
	myfirst['a']=10;
	myfirst['b']=30;
	myfirst['c']=50;
	myfirst['d']=70;
	printMaps(first, myfirst);

	std::cout << BLUE"\nCreate second map with range of first:\n" << RESET << std::endl;
	std::map<char, int> second(first.begin(), first.end());
	ft::Map<char, int> mysecond(myfirst.begin(), myfirst.end());
	printMaps(second, mysecond);

	std::cout << BLUE"\nCreate third map as a copy of second:\n" << RESET << std::endl;
	std::map<char, int> third(second);
	ft::Map<char, int> mythird(mysecond);
	printMaps(third, mythird);

	std::cout << BLUE"\nCreate fourth map<string, int> with string lenght as compare:\n" << RESET << std::endl;
	std::map<std::string, int, cmpByStringLength> fourth;
	std::map<std::string, int>::iterator it;
	fourth["aaaa"]=10;
	fourth["bbb"]=30;
	fourth["cc"]=50;
	fourth["d"]=70;
	it = fourth.begin();
	std::cout << GREEN"Map output:\n" << RESET << std::endl;
	for ( ; it != fourth.end(); it++)
			std::cout << it->first << ' ' << it->second << std::endl;
	ft::Map<std::string, int, cmpByStringLength> myfourth;
	ft::Map<std::string, int>::iterator myit;
	myfourth["aaaa"]=10;
	myfourth["bbb"]=30;
	myfourth["cc"]=50;
	myfourth["d"]=70;
	myit = myfourth.begin();
	std::cout << GREEN"My Map output:\n" << RESET << std::endl;
	for ( ; myit != myfourth.end(); myit++)
			std::cout << myit->first << ' ' << myit->second << std::endl;

	std::cout << BLUE"\nTrying operator =. Create five map equal to first, and first equal to new map:\n" << RESET << std::endl;
	std::map<char, int>	five;
	ft::Map<char, int>	myfive;

	five = first;
	first = std::map<char, int>();
	myfive = myfirst;
	myfirst = ft::Map<char, int>();
	std::cout << BLUE"\nPrint first:\n" << RESET << std::endl;
	printMaps(first, myfirst);
	std::cout << BLUE"\nPrint five:\n" << RESET << std::endl;
	printMaps(five, myfive);

	checkMapContinue();	
}

int /*testMap()*/main()
{
	printMapBanner();
	/*mapConstructorsTest();
	mapIteratorsTest();
	mapCapacityTest();*/
	mapElementAccessTest();
	
	return 0;
}