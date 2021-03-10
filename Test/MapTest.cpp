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

void	mapRelationalOperatorsTest()
{
	std::cout << RED"Starting relational operators test" << RESET << std::endl;
	std::cout << BLUE"\nCreating maps foo and bar:\n" << RESET << std::endl;
	std::map<char,int> foo,bar;
	foo['a']=100;
	foo['b']=200;
	bar['a']=10;
	bar['z']=1000;

	ft::Map<char,int> myfoo,mybar;
	myfoo['a']=100;
	myfoo['b']=200;
	mybar['a']=10;
	mybar['z']=1000;
	std::cout << BLUE"\nPrint foo:\n" << RESET << std::endl;
	printMaps(foo, myfoo);
	std::cout << BLUE"\nPrint bar:\n" << RESET << std::endl;
	printMaps(bar, mybar);

	std::cout << ORANGE"\n\nChecking relational operators:" << RESET << std::endl;
	std::cout << GREEN"\n\nMap output:" << RESET << std::endl;
	if (foo==bar) std::cout << "foo and bar are equal\n";
	if (foo!=bar) std::cout << "foo and bar are not equal\n";
	if (foo< bar) std::cout << "foo is less than bar\n";
	if (foo> bar) std::cout << "foo is greater than bar\n";
	if (foo<=bar) std::cout << "foo is less than or equal to bar\n";
	if (foo>=bar) std::cout << "foo is greater than or equal to bar\n";

	std::cout << GREEN"\n\nMymap output:" << RESET << std::endl;
	if (myfoo==mybar) std::cout << "myfoo and mybar are equal\n";
	if (myfoo!=mybar) std::cout << "myfoo and mybar are not equal\n";
	if (myfoo< mybar) std::cout << "myfoo is less than mybar\n";
	if (myfoo> mybar) std::cout << "myfoo is greater than mybar\n";
	if (myfoo<=mybar) std::cout << "myfoo is less than or equal to mybar\n";
	if (myfoo>=mybar) std::cout << "myfoo is greater than or equal to mybar\n";

	std::cout << ORANGE"\n\nChecking swap function:" << RESET << std::endl;
	std::swap(foo, bar);
	ft::swap(myfoo, mybar);
	std::cout << BLUE"\nPrint foo:\n" << RESET << std::endl;
	printMaps(foo, myfoo);
	std::cout << BLUE"\nPrint bar:\n" << RESET << std::endl;
	printMaps(bar, mybar);
	checkMapContinue();
}

void	mapOperationsTest()
{
	std::cout << RED"Starting operations test" << RESET << std::endl;
	std::cout << ORANGE"\nChecking find() function:" << RESET << std::endl;
	std::cout << BLUE"\nCreate map<char, int> and insert single values:\n" << RESET << std::endl;
	std::map<char,int> map;
	std::map<char,int>::iterator it;
	map['a']=50;
	map['b']=100;
	map['c']=150;
	map['d']=200;

	ft::Map<char,int> mymap;
	ft::Map<char,int>::iterator myit;

	mymap['a']=50;
	mymap['b']=100;
	mymap['c']=150;
	mymap['d']=200;

	printMaps(map, mymap);

	std::cout << BLUE"\nFind 'b' with function and erase it:\n" << RESET << std::endl;

	it = map.find('b');
	if (it != map.end())
		map.erase (it);
	myit = mymap.find('b');
	if (myit != mymap.end())
		mymap.erase (myit);
	printMaps(map, mymap);

	std::cout << ORANGE"\nChecking count() function:" << RESET << std::endl;
	std::cout << BLUE"\nUse count to find elements in map:\n" << RESET << std::endl;
	if (map.count('f'))
		std::cout << GREEN"'f' is an element of map" << std::endl;
	else
		std::cout << GREEN"'f' is not an element of map" << std::endl << std::endl;
	if (mymap.count('f'))
		std::cout << GREEN"'f' is an element of mymap" << std::endl;
	else
		std::cout << GREEN"'f' is not an element of mymap" << std::endl << std::endl;

	if (map.count('c'))
		std::cout << GREEN"'c' is an element of map" << std::endl << std::endl;
	else
		std::cout << GREEN"'c' is not an element of map" << std::endl << std::endl;
	if (mymap.count('c'))
		std::cout << GREEN"'c' is an element of mymap" << std::endl;
	else
		std::cout << GREEN"'c' is not an element of mymap" << std::endl;

	std::cout << ORANGE"\nChecking upper_bound() and lowe_bound functions:" << RESET << std::endl;
	std::cout << BLUE"\nInserting some new elements in map:\n" << RESET << std::endl;
	map['b']=100;
	map['e']=250;
	map['f']=300;
	mymap['b']=100;
	mymap['e']=250;
	mymap['f']=300;
	printMaps(map, mymap);

	std::cout << BLUE"\nUse functions to erase from 'b' to 'd':\n" << RESET << std::endl;
	std::map<char, int>::iterator itlow, itup;
	ft::Map<char, int>::iterator myitlow, myitup;

	itlow = map.lower_bound('b');
	itup = map.upper_bound('d');
	map.erase(itlow, itup);
	myitlow = mymap.lower_bound('b');
	myitup = mymap.upper_bound('d');
	mymap.erase(myitlow, myitup);
	printMaps(map, mymap);

	std::cout << ORANGE"\nChecking upper_bound() and lowe_bound functions:" << RESET << std::endl;
	std::cout << BLUE"\nChecking upper and lower range with 'e':\n" << RESET << std::endl;
	std::pair<std::map<char,int>::iterator,std::map<char,int>::iterator> ret;
	std::pair<ft::Map<char,int>::iterator,ft::Map<char,int>::iterator> myret;

	ret = map.equal_range('e');
	myret = mymap.equal_range('e');

	std::cout << GREEN"In map lower bound points to: " << RESET;
	std::cout << ret.first->first << " => " << ret.first->second << '\n';

	std::cout << GREEN"In map upper bound points to: " << RESET;
	std::cout << ret.second->first << " => " << ret.second->second << '\n';

	std::cout << GREEN"In mymap lower bound points to: " << RESET;
	std::cout << myret.first->first << " => " << myret.first->second << '\n';

	std::cout << GREEN"In mymap upper bound points to: " << RESET;
	std::cout << myret.second->first << " => " << myret.second->second << '\n';
	checkMapContinue();
}

void	mapObserversTest()
{
	std::cout << RED"Starting observers test" << RESET << std::endl;
	std::cout << ORANGE"\nChecking key_comp() function:" << RESET << std::endl << std::endl;
	std::map<char,int> map;

	std::map<char,int>::key_compare comp = map.key_comp();

	map['a']=100;
	map['b']=200;
	map['c']=300;

	std::cout << GREEN"map contains:\n" << RESET;

	char highest = map.rbegin()->first;

	std::map<char,int>::iterator it = map.begin();
	do {
		std::cout << it->first << " => " << it->second << '\n';
	} while ( comp((*it++).first, highest) );

	std::cout << '\n';

	ft::Map<char,int> mymap;

	ft::Map<char,int>::key_compare mycomp = mymap.key_comp();

	mymap['a']=100;
	mymap['b']=200;
	mymap['c']=300;

	std::cout << GREEN"mymap contains:\n" << RESET;

	highest = mymap.rbegin()->first;

	ft::Map<char,int>::iterator myit = mymap.begin();
	do {
		std::cout << myit->first << " => " << myit->second << '\n';
	} while ( mycomp((*myit++).first, highest) );

	std::cout << '\n';

	std::cout << ORANGE"\nChecking value_comp() function:" << RESET << std::endl << std::endl;

	std::map<char,int> map1;

	map1['x']=1001;
	map1['y']=2002;
	map1['z']=3003;

	std::cout << GREEN"map1 contains:\n" << RESET;

	std::pair<char,int> highest1 = *map1.rbegin();

	std::map<char,int>::iterator it1 = map1.begin();
	do {
		std::cout << it1->first << " => " << it1->second << '\n';
	} while ( map1.value_comp()(*it1++, highest1) );

	ft::Map<char,int> mymap1;

	mymap1['x']=1001;
	mymap1['y']=2002;
	mymap1['z']=3003;

	std::cout << GREEN"\nmymap1 contains:\n" << RESET;

	highest1 = *mymap1.rbegin();

	ft::Map<char,int>::iterator myit1 = mymap1.begin();
	do {
		std::cout << myit1->first << " => " << myit1->second << '\n';
	} while ( mymap1.value_comp()(*myit1++, highest1) );
	checkMapContinue();
}

void	mapModifiersTest()
{
	std::cout << RED"Starting modifiers test" << RESET << std::endl;
	std::cout << ORANGE"\n\nChecking insert() function:" << RESET << std::endl;
	std::cout << BLUE"\nCreate map<int, string> and insert single values:\n" << RESET << std::endl;
	std::map<int, std::string>	map;
	ft::Map<int, std::string>	mymap;

	std::cout << std::boolalpha;
	map.insert(std::pair<int, std::string>(6, "París"));
	map.insert(std::pair<int, std::string>(2, "Roma"));
	map.insert(std::pair<int, std::string>(1, "Luxemburgo"));
	map.insert(std::pair<int, std::string>(9, "Oslo"));
	map.insert(std::pair<int, std::string>(8, "Munich"));
	map.insert(std::pair<int, std::string>(15, "Lisboa"));
	map.insert(std::pair<int, std::string>(13, "Londres"));
	map.insert(std::pair<int, std::string>(11, "Praga"));
	std::cout << GREEN"Trying to insert new value in map: " << RESET << (map.insert(std::pair<int, std::string>(18, "Madrid"))).second << std::endl;

	mymap.insert(std::pair<int, std::string>(6, "París"));
	mymap.insert(std::pair<int, std::string>(2, "Roma"));
	mymap.insert(std::pair<int, std::string>(1, "Luxemburgo"));
	mymap.insert(std::pair<int, std::string>(9, "Oslo"));
	mymap.insert(std::pair<int, std::string>(8, "Munich"));
	mymap.insert(std::pair<int, std::string>(15, "Lisboa"));
	mymap.insert(std::pair<int, std::string>(13, "Londres"));
	mymap.insert(std::pair<int, std::string>(11, "Praga"));
	std::cout << GREEN"Trying to insert new value in mymap: " << RESET << (mymap.insert(std::pair<int, std::string>(18, "Madrid"))).second << std::endl;

	std::cout << GREEN"\ntrying to insert already known value in map: " << RESET << (map.insert(std::pair<int, std::string>(11, "Murcia"))).second << std::endl;
	std::cout << GREEN"trying to insert already known value in map: " << RESET << (mymap.insert(std::pair<int, std::string>(11, "Murcia"))).second << std::endl << std::endl;
	printMaps(map, mymap);

	std::cout << BLUE"\nInsert new value with hint (max efficiency):\n" << RESET << std::endl;
	std::map<int, std::string>::iterator it = map.find(18);
	ft::Map<int, std::string>::iterator myit = mymap.find(18);
	map.insert(it, std::pair<int, std::string>(20, "Moscú"));
	mymap.insert(myit, std::pair<int, std::string>(20, "Moscú"));
	printMaps(map, mymap);

	std::cout << BLUE"\nInsert new value with hint (no max efficiency):\n" << RESET << std::endl;
	it = map.find(6);
	myit = mymap.find(6);
	map.insert(it, std::pair<int, std::string>(12, "Dublin"));
	mymap.insert(myit, std::pair<int, std::string>(12, "Dublin"));
	printMaps(map, mymap);

	std::cout << BLUE"\nCreate new map with range insert:\n" << RESET << std::endl;
	std::map<int, std::string>	anothermap;
	ft::Map<int, std::string>	myanothermap;
	anothermap.insert(map.begin(), map.find(13));
	myanothermap.insert(mymap.begin(), mymap.find(13));
	printMaps(anothermap, myanothermap);

	std::cout << ORANGE"\n\nChecking erase() function:" << RESET << std::endl;
	std::cout << BLUE"\nErase single leaf:\n" << RESET << std::endl;
	it = map.find(12);
	myit = mymap.find(12);
	map.erase(it);
	mymap.erase(myit);
	printMaps(map, mymap);

	std::cout << BLUE"\nErase node with only left tree:\n" << RESET << std::endl;
	it = map.find(2);
	myit = mymap.find(2);
	map.erase(it);
	mymap.erase(myit);
	printMaps(map, mymap);

	std::cout << BLUE"\nErase node with only right tree:\n" << RESET << std::endl;
	it = map.find(18);
	myit = mymap.find(18);
	map.erase(it);
	mymap.erase(myit);
	printMaps(map, mymap);

	std::cout << BLUE"\nErase node with two childs:\n" << RESET << std::endl;
	it = map.find(9);
	myit = mymap.find(9);
	map.erase(it);
	mymap.erase(myit);
	printMaps(map, mymap);

	std::cout << BLUE"\nErase root:\n" << RESET << std::endl;
	it = map.find(6);
	myit = mymap.find(6);
	map.erase(it);
	mymap.erase(myit);
	printMaps(map, mymap);

	std::cout << BLUE"\nErase with key:\n" << RESET << std::endl;
	std::cout << GREEN"\nNumber of nodes erased in map: " << RESET << map.erase(13) << std::endl;
	std::cout << GREEN"\nNumber of nodes erased in mymap: " << RESET << mymap.erase(13) << std::endl << std::endl;
	printMaps(map, mymap);

	std::cout << BLUE"\nErase with range anothermap:\n" << RESET << std::endl;
	std::map<int, std::string>::iterator bit = anothermap.begin();
	std::map<int, std::string>::iterator eit = anothermap.end();
	anothermap.erase(bit, eit);
	ft::Map<int, std::string>::iterator mybit = myanothermap.begin();
	ft::Map<int, std::string>::iterator myeit = myanothermap.end();
	myanothermap.erase(mybit, myeit);
	printMaps(anothermap, myanothermap);

	std::cout << ORANGE"\n\nChecking erase() function:" << RESET << std::endl;
	std::cout << BLUE"\nInsert some values in anothermap and swap with map:\n" << RESET << std::endl;
	anothermap.insert(std::pair<int, std::string>(42, "Madrid"));
	anothermap.insert(std::pair<int, std::string>(43, "Urduliz"));
	myanothermap.insert(std::pair<int, std::string>(42, "Madrid"));
	myanothermap.insert(std::pair<int, std::string>(43, "Urduliz"));
	std::cout << BLUE"\nPrint map before swap:\n" << RESET << std::endl;
	printMaps(map, mymap);
	std::cout << BLUE"\nPrint anothermap before swap:\n" << RESET << std::endl;
	printMaps(anothermap, myanothermap);
	map.swap(anothermap);
	mymap.swap(myanothermap);
	std::cout << BLUE"\nPrint map after swap:\n" << RESET << std::endl;
	printMaps(map, mymap);
	std::cout << BLUE"\nPrint anothermap after swap:\n" << RESET << std::endl;
	printMaps(anothermap, myanothermap);

	std::cout << ORANGE"\n\nChecking clear() function:" << RESET << std::endl;
	std::cout << BLUE"\nClear map:\n" << RESET << std::endl;
	map.clear();
	mymap.clear();
	printMaps(map, mymap);
	checkMapContinue();
}

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

int testMap()
{
	printMapBanner();
	mapConstructorsTest();
	mapIteratorsTest();
	mapCapacityTest();
	mapElementAccessTest();
	mapModifiersTest();
	mapObserversTest();
	mapOperationsTest();
	mapRelationalOperatorsTest();
	
	return 0;
}