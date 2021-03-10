#include <set>
#include "../includes/Set/Set.hpp"
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

class setfoo
{
private:
	/* data */
public:
	setfoo(/* args */);
	~setfoo();
};

setfoo::setfoo(/* args */)
{
}

setfoo::~setfoo()
{
}


template <class T>
void	printsets(std::set<T> set, ft::Set<T> myset)
{
	std::cout << GREEN"set output:\n" << RESET << std::endl;
	ft::printoSet(set);
	std::cout << GREEN"\nMy set output:\n" << RESET << std::endl;
	ft::printSet(myset);
}

void	printsetBanner()
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

void	checksetContinue()
{
	std::cout << std::endl;
	std::string input;
	while (input != "c")
	{
		std::cout << ORANGE"Press 'c' to continue..." << RESET << std::endl;
		std::getline(std::cin, input);
	}
	printsetBanner();
}

struct cmpByStringLength {
    bool operator()(const std::string& a, const std::string& b) const {
        return a.length() < b.length();
    }
};

/*void	setRelationalOperatorsTest()
{
	std::cout << RED"Starting relational operators test" << RESET << std::endl;
	std::cout << BLUE"\nCreating sets foo and bar:\n" << RESET << std::endl;
	std::set<char,int> foo,bar;
	foo['a']=100;
	foo['b']=200;
	bar['a']=10;
	bar['z']=1000;

	ft::Set<char,int> myfoo,mybar;
	myfoo['a']=100;
	myfoo['b']=200;
	mybar['a']=10;
	mybar['z']=1000;
	std::cout << BLUE"\nPrint foo:\n" << RESET << std::endl;
	printsets(foo, myfoo);
	std::cout << BLUE"\nPrint bar:\n" << RESET << std::endl;
	printsets(bar, mybar);

	std::cout << ORANGE"\n\nChecking relational operators:" << RESET << std::endl;
	std::cout << GREEN"\n\nset output:" << RESET << std::endl;
	if (foo==bar) std::cout << "foo and bar are equal\n";
	if (foo!=bar) std::cout << "foo and bar are not equal\n";
	if (foo< bar) std::cout << "foo is less than bar\n";
	if (foo> bar) std::cout << "foo is greater than bar\n";
	if (foo<=bar) std::cout << "foo is less than or equal to bar\n";
	if (foo>=bar) std::cout << "foo is greater than or equal to bar\n";

	std::cout << GREEN"\n\nMyset output:" << RESET << std::endl;
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
	printsets(foo, myfoo);
	std::cout << BLUE"\nPrint bar:\n" << RESET << std::endl;
	printsets(bar, mybar);
	checksetContinue();
}

void	setOperationsTest()
{
	std::cout << RED"Starting operations test" << RESET << std::endl;
	std::cout << ORANGE"\nChecking find() function:" << RESET << std::endl;
	std::cout << BLUE"\nCreate set<char, int> and insert single values:\n" << RESET << std::endl;
	std::set<char,int> set;
	std::set<char,int>::iterator it;
	set['a']=50;
	set['b']=100;
	set['c']=150;
	set['d']=200;

	ft::Set<char,int> myset;
	ft::Set<char,int>::iterator myit;

	myset['a']=50;
	myset['b']=100;
	myset['c']=150;
	myset['d']=200;

	printsets(set, myset);

	std::cout << BLUE"\nFind 'b' with function and erase it:\n" << RESET << std::endl;

	it = set.find('b');
	if (it != set.end())
		set.erase (it);
	myit = myset.find('b');
	if (myit != myset.end())
		myset.erase (myit);
	printsets(set, myset);

	std::cout << ORANGE"\nChecking count() function:" << RESET << std::endl;
	std::cout << BLUE"\nUse count to find elements in set:\n" << RESET << std::endl;
	if (set.count('f'))
		std::cout << GREEN"'f' is an element of set" << std::endl;
	else
		std::cout << GREEN"'f' is not an element of set" << std::endl << std::endl;
	if (myset.count('f'))
		std::cout << GREEN"'f' is an element of myset" << std::endl;
	else
		std::cout << GREEN"'f' is not an element of myset" << std::endl << std::endl;

	if (set.count('c'))
		std::cout << GREEN"'c' is an element of set" << std::endl << std::endl;
	else
		std::cout << GREEN"'c' is not an element of set" << std::endl << std::endl;
	if (myset.count('c'))
		std::cout << GREEN"'c' is an element of myset" << std::endl;
	else
		std::cout << GREEN"'c' is not an element of myset" << std::endl;

	std::cout << ORANGE"\nChecking upper_bound() and lowe_bound functions:" << RESET << std::endl;
	std::cout << BLUE"\nInserting some new elements in set:\n" << RESET << std::endl;
	set['b']=100;
	set['e']=250;
	set['f']=300;
	myset['b']=100;
	myset['e']=250;
	myset['f']=300;
	printsets(set, myset);

	std::cout << BLUE"\nUse functions to erase from 'b' to 'd':\n" << RESET << std::endl;
	std::set<char, int>::iterator itlow, itup;
	ft::Set<char, int>::iterator myitlow, myitup;

	itlow = set.lower_bound('b');
	itup = set.upper_bound('d');
	set.erase(itlow, itup);
	myitlow = myset.lower_bound('b');
	myitup = myset.upper_bound('d');
	myset.erase(myitlow, myitup);
	printsets(set, myset);

	std::cout << ORANGE"\nChecking upper_bound() and lowe_bound functions:" << RESET << std::endl;
	std::cout << BLUE"\nChecking upper and lower range with 'e':\n" << RESET << std::endl;
	std::pair<std::set<char,int>::iterator,std::set<char,int>::iterator> ret;
	std::pair<ft::Set<char,int>::iterator,ft::Set<char,int>::iterator> myret;

	ret = set.equal_range('e');
	myret = myset.equal_range('e');

	std::cout << GREEN"In set lower bound points to: " << RESET;
	std::cout << ret.first->first << " => " << ret.first->second << '\n';

	std::cout << GREEN"In set upper bound points to: " << RESET;
	std::cout << ret.second->first << " => " << ret.second->second << '\n';

	std::cout << GREEN"In myset lower bound points to: " << RESET;
	std::cout << myret.first->first << " => " << myret.first->second << '\n';

	std::cout << GREEN"In myset upper bound points to: " << RESET;
	std::cout << myret.second->first << " => " << myret.second->second << '\n';
	checksetContinue();
}

void	setObserversTest()
{
	std::cout << RED"Starting observers test" << RESET << std::endl;
	std::cout << ORANGE"\nChecking key_comp() function:" << RESET << std::endl << std::endl;
	std::set<char,int> set;

	std::set<char,int>::key_compare comp = set.key_comp();

	set['a']=100;
	set['b']=200;
	set['c']=300;

	std::cout << GREEN"set contains:\n" << RESET;

	char highest = set.rbegin()->first;

	std::set<char,int>::iterator it = set.begin();
	do {
		std::cout << it->first << " => " << it->second << '\n';
	} while ( comp((*it++).first, highest) );

	std::cout << '\n';

	ft::Set<char,int> myset;

	ft::Set<char,int>::key_compare mycomp = myset.key_comp();

	myset['a']=100;
	myset['b']=200;
	myset['c']=300;

	std::cout << GREEN"myset contains:\n" << RESET;

	highest = myset.rbegin()->first;

	ft::Set<char,int>::iterator myit = myset.begin();
	do {
		std::cout << myit->first << " => " << myit->second << '\n';
	} while ( mycomp((*myit++).first, highest) );

	std::cout << '\n';

	std::cout << ORANGE"\nChecking value_comp() function:" << RESET << std::endl << std::endl;

	std::set<char,int> set1;

	set1['x']=1001;
	set1['y']=2002;
	set1['z']=3003;

	std::cout << GREEN"set1 contains:\n" << RESET;

	std::pair<char,int> highest1 = *set1.rbegin();

	std::set<char,int>::iterator it1 = set1.begin();
	do {
		std::cout << it1->first << " => " << it1->second << '\n';
	} while ( set1.value_comp()(*it1++, highest1) );

	ft::Set<char,int> myset1;

	myset1['x']=1001;
	myset1['y']=2002;
	myset1['z']=3003;

	std::cout << GREEN"\nmyset1 contains:\n" << RESET;

	highest1 = *myset1.rbegin();

	ft::Set<char,int>::iterator myit1 = myset1.begin();
	do {
		std::cout << myit1->first << " => " << myit1->second << '\n';
	} while ( myset1.value_comp()(*myit1++, highest1) );
	checksetContinue();
}

void	setModifiersTest()
{
	std::cout << RED"Starting modifiers test" << RESET << std::endl;
	std::cout << ORANGE"\n\nChecking insert() function:" << RESET << std::endl;
	std::cout << BLUE"\nCreate set<int, string> and insert single values:\n" << RESET << std::endl;
	std::set<int, std::string>	set;
	ft::Set<int, std::string>	myset;

	std::cout << std::boolalpha;
	set.insert(std::pair<int, std::string>(6, "París"));
	set.insert(std::pair<int, std::string>(2, "Roma"));
	set.insert(std::pair<int, std::string>(1, "Luxemburgo"));
	set.insert(std::pair<int, std::string>(9, "Oslo"));
	set.insert(std::pair<int, std::string>(8, "Munich"));
	set.insert(std::pair<int, std::string>(15, "Lisboa"));
	set.insert(std::pair<int, std::string>(13, "Londres"));
	set.insert(std::pair<int, std::string>(11, "Praga"));
	std::cout << GREEN"Trying to insert new value in set: " << RESET << (set.insert(std::pair<int, std::string>(18, "Madrid"))).second << std::endl;

	myset.insert(std::pair<int, std::string>(6, "París"));
	myset.insert(std::pair<int, std::string>(2, "Roma"));
	myset.insert(std::pair<int, std::string>(1, "Luxemburgo"));
	myset.insert(std::pair<int, std::string>(9, "Oslo"));
	myset.insert(std::pair<int, std::string>(8, "Munich"));
	myset.insert(std::pair<int, std::string>(15, "Lisboa"));
	myset.insert(std::pair<int, std::string>(13, "Londres"));
	myset.insert(std::pair<int, std::string>(11, "Praga"));
	std::cout << GREEN"Trying to insert new value in myset: " << RESET << (myset.insert(std::pair<int, std::string>(18, "Madrid"))).second << std::endl;

	std::cout << GREEN"\ntrying to insert already known value in set: " << RESET << (set.insert(std::pair<int, std::string>(11, "Murcia"))).second << std::endl;
	std::cout << GREEN"trying to insert already known value in set: " << RESET << (myset.insert(std::pair<int, std::string>(11, "Murcia"))).second << std::endl << std::endl;
	printsets(set, myset);

	std::cout << BLUE"\nInsert new value with hint (max efficiency):\n" << RESET << std::endl;
	std::set<int, std::string>::iterator it = set.find(18);
	ft::Set<int, std::string>::iterator myit = myset.find(18);
	set.insert(it, std::pair<int, std::string>(20, "Moscú"));
	myset.insert(myit, std::pair<int, std::string>(20, "Moscú"));
	printsets(set, myset);

	std::cout << BLUE"\nInsert new value with hint (no max efficiency):\n" << RESET << std::endl;
	it = set.find(6);
	myit = myset.find(6);
	set.insert(it, std::pair<int, std::string>(12, "Dublin"));
	myset.insert(myit, std::pair<int, std::string>(12, "Dublin"));
	printsets(set, myset);

	std::cout << BLUE"\nCreate new set with range insert:\n" << RESET << std::endl;
	std::set<int, std::string>	anotherset;
	ft::Set<int, std::string>	myanotherset;
	anotherset.insert(set.begin(), set.find(13));
	myanotherset.insert(myset.begin(), myset.find(13));
	printsets(anotherset, myanotherset);

	std::cout << ORANGE"\n\nChecking erase() function:" << RESET << std::endl;
	std::cout << BLUE"\nErase single leaf:\n" << RESET << std::endl;
	it = set.find(12);
	myit = myset.find(12);
	set.erase(it);
	myset.erase(myit);
	printsets(set, myset);

	std::cout << BLUE"\nErase node with only left tree:\n" << RESET << std::endl;
	it = set.find(2);
	myit = myset.find(2);
	set.erase(it);
	myset.erase(myit);
	printsets(set, myset);

	std::cout << BLUE"\nErase node with only right tree:\n" << RESET << std::endl;
	it = set.find(18);
	myit = myset.find(18);
	set.erase(it);
	myset.erase(myit);
	printsets(set, myset);

	std::cout << BLUE"\nErase node with two childs:\n" << RESET << std::endl;
	it = set.find(9);
	myit = myset.find(9);
	set.erase(it);
	myset.erase(myit);
	printsets(set, myset);

	std::cout << BLUE"\nErase root:\n" << RESET << std::endl;
	it = set.find(6);
	myit = myset.find(6);
	set.erase(it);
	myset.erase(myit);
	printsets(set, myset);

	std::cout << BLUE"\nErase with key:\n" << RESET << std::endl;
	std::cout << GREEN"\nNumber of nodes erased in set: " << RESET << set.erase(13) << std::endl;
	std::cout << GREEN"\nNumber of nodes erased in myset: " << RESET << myset.erase(13) << std::endl << std::endl;
	printsets(set, myset);

	std::cout << BLUE"\nErase with range anotherset:\n" << RESET << std::endl;
	std::set<int, std::string>::iterator bit = anotherset.begin();
	std::set<int, std::string>::iterator eit = anotherset.end();
	anotherset.erase(bit, eit);
	ft::Set<int, std::string>::iterator mybit = myanotherset.begin();
	ft::Set<int, std::string>::iterator myeit = myanotherset.end();
	myanotherset.erase(mybit, myeit);
	printsets(anotherset, myanotherset);

	std::cout << ORANGE"\n\nChecking erase() function:" << RESET << std::endl;
	std::cout << BLUE"\nInsert some values in anotherset and swap with set:\n" << RESET << std::endl;
	anotherset.insert(std::pair<int, std::string>(42, "Madrid"));
	anotherset.insert(std::pair<int, std::string>(43, "Urduliz"));
	myanotherset.insert(std::pair<int, std::string>(42, "Madrid"));
	myanotherset.insert(std::pair<int, std::string>(43, "Urduliz"));
	std::cout << BLUE"\nPrint set before swap:\n" << RESET << std::endl;
	printsets(set, myset);
	std::cout << BLUE"\nPrint anotherset before swap:\n" << RESET << std::endl;
	printsets(anotherset, myanotherset);
	set.swap(anotherset);
	myset.swap(myanotherset);
	std::cout << BLUE"\nPrint set after swap:\n" << RESET << std::endl;
	printsets(set, myset);
	std::cout << BLUE"\nPrint anotherset after swap:\n" << RESET << std::endl;
	printsets(anotherset, myanotherset);

	std::cout << ORANGE"\n\nChecking clear() function:" << RESET << std::endl;
	std::cout << BLUE"\nClear set:\n" << RESET << std::endl;
	set.clear();
	myset.clear();
	printsets(set, myset);
	checksetContinue();
}

void	setElementAccessTest()
{
	std::cout << RED"Starting element access test" << RESET << std::endl;
	std::cout << ORANGE"\n\nChecking operator[]:" << RESET << std::endl;
	std::cout << BLUE"\nCreating set<char, std::string>:\n" << RESET << std::endl;

	std::set<char,std::string> set;

	set['a']="an element";
	set['b']="another element";
	set['c']=set['b'];

	std::cout << GREEN"set['a'] is " << set['a'] << '\n';
	std::cout << "set['b'] is " << set['b'] << '\n';
	std::cout << "set['c'] is " << set['c'] << '\n';
	std::cout << "set['d'] is " << set['d'] << '\n';

	std::cout << std::endl;
	std::cout << GREEN"set now contains " << RESET << set.size() << GREEN" elements.\n" << RESET;
	std::cout << std::endl;

	ft::Set<char,std::string> myset;
	myset['a']="an element";
	myset['b']="another element";
	myset['c']=myset['b'];

	std::cout << GREEN"myset['a'] is " << myset['a'] << '\n';
	std::cout << "myset['b'] is " << myset['b'] << '\n';
	std::cout << "myset['c'] is " << myset['c'] << '\n';
	std::cout << "myset['d'] is " << myset['d'] << '\n';

	std::cout << std::endl;
	std::cout << GREEN"myset now contains " << RESET << myset.size() << GREEN" elements.\n" << RESET;
	std::cout << std::endl;
}

void	setCapacityTest()
{
	std::cout << RED"Starting capacity test" << RESET << std::endl;
	std::set<char, int>	set;
	ft::Set<char, int>	myset;
	std::set<char, int>	set1;
	ft::Set<char, int>	myset1;
	std::cout << BLUE"\nCreating set<char, int> with some values and empty set1:\n" << RESET << std::endl;
	set['b'] = 100;
	set['a'] = 200;
	set['c'] = 300;
	myset['b'] = 100;
	myset['a'] = 200;
	myset['c'] = 300;
	std::cout << "\n\033[1;33mPrinting filled list:\n" << RESET << std::endl;
	printsets(set, myset);
	std::cout << "\n\033[1;33mPrinting empty list:\n" << RESET << std::endl;
	printsets(set1, myset1);

	std::cout << BLUE"\nChecking empty() function with set:\n" << RESET << std::endl;
	if (set.empty())
		std::cout << GREEN"list is empty" << RESET << std::endl;
	else
		std::cout << GREEN"list is not empty" << RESET << std::endl;
	if (myset.empty())
		std::cout << GREEN"mylist is empty" << RESET << std::endl;
	else
		std::cout << GREEN"mylist is not empty" << RESET << std::endl;

	std::cout << BLUE"\nChecking empty() function with set1:\n" << RESET << std::endl;
	if (set1.empty())
		std::cout << GREEN"list1 is empty" << RESET << std::endl;
	else
		std::cout << GREEN"list1 is not empty" << RESET << std::endl;
	if (myset1.empty())
		std::cout << GREEN"mylist1 is empty" << RESET << std::endl;
	else
		std::cout << GREEN"mylist1 is not empty" << RESET << std::endl;

	std::cout << BLUE"\nChecking size() function:\n" << RESET << std::endl;
	std::cout << GREEN"set size: " << RESET << set.size() << GREEN". set1 size: " << RESET << set1.size() << RESET << std::endl;
	std::cout << GREEN"myset size: " << RESET << myset.size() << GREEN". myset1 size: " << RESET << myset1.size() << RESET << std::endl;

	std::cout << BLUE"\nChecking max_size() function:\n" << RESET << std::endl;
	std::cout << ORANGE"Checking with <char,int>: " << RESET << std::endl;
	std::cout << GREEN"set<char, int> max_size: " << RESET << set.max_size() << RESET << std::endl;
	std::cout << GREEN"myset<char, int> max_size: " << RESET << myset.max_size() << RESET << std::endl;
	std::set<std::string, int> set2;
	ft::Set<std::string, int> myset2;
	std::cout << ORANGE"\nChecking with std::string: " << RESET << std::endl;
	std::cout << GREEN"set<std::string, int> max_size: " << RESET << set2.max_size() << RESET << std::endl;
	std::cout << GREEN"myset<std::string, int> max_size: " << RESET << myset2.max_size() << RESET << std::endl;
	std::set<setfoo*, int> set3;
	ft::Set<setfoo*, int> myset3;
	std::cout << ORANGE"\nChecking with another class: " << RESET << std::endl;
	std::cout << GREEN"set<foo*, int> max_size: " << RESET << set3.max_size() << RESET << std::endl;
	std::cout << GREEN"myset<foo*, int> max_size: " << RESET << myset3.max_size() << RESET << std::endl;
	checksetContinue();
}

void	constsetIteratorsTest(const std::set<char, int>& set, const ft::Set<char, int>& myset)
{
	std::set<char,int>::const_iterator cit = set.begin();
	ft::Set<char, int>::const_iterator mycit = myset.begin();
	std::set<char, int>::const_reverse_iterator rcit = set.rbegin();
	ft::Set<char, int>::const_reverse_iterator myrcit = myset.rbegin();
	std::cout << BLUE"\nIterating from begin() to end() with const iterators:\n" << RESET << std::endl;
	std::cout << GREEN"In vector: \n" << RESET;
	for (; cit != set.end(); cit++)
		std::cout << cit->first << ' ';
	std::cout << RESET << std::endl;
	std::cout << GREEN"In myvector: \n" << RESET;
	for (; mycit != myset.end(); mycit++)
		std::cout << mycit->first << ' ';
	std::cout << RESET << std::endl;

	std::cout << BLUE"\nIterating from rbegin() to rend() with const iterators:\n" << RESET << std::endl;
	std::cout << GREEN"In set: \n" << RESET;
	for (; rcit != set.rend(); rcit++)
		std::cout << rcit->first << ' ';
	std::cout << RESET << std::endl;
	std::cout << GREEN"In myset: \n" << RESET;
	for (; myrcit != myset.rend(); myrcit++)
		std::cout << myrcit->first << ' ';
	std::cout << RESET << std::endl;
}

void	setIteratorsTest()
{
	std::cout << RED"Starting iterators test" << RESET << std::endl;
	std::set<char, int>	set;
	ft::Set<char, int>	myset;
	std::cout << BLUE"\nCreating set<char, int> with some values:\n" << RESET << std::endl;
	set['b'] = 100;
	set['a'] = 200;
	set['c'] = 300;
	myset['b'] = 100;
	myset['a'] = 200;
	myset['c'] = 300;

	std::set<char, int>::iterator it = set.begin();
	ft::Set<char, int>::iterator myit = myset.begin();
	std::cout << GREEN"set begin() points to: " << RESET << it->first << std::endl;
	std::cout << GREEN"myset begin() points to: " << RESET << myit->first << std::endl;
	std::cout << std::endl;

	std::set<char, int>::reverse_iterator rit = set.rbegin();
	ft::Set<char, int>::reverse_iterator myrit = myset.rbegin();
	std::cout << GREEN"set rbegin() points to: " << RESET << rit->first << std::endl;
	std::cout << GREEN"myset rbegin() points to: " << RESET << myrit->first << std::endl;
	std::cout << std::endl;

	std::cout << BLUE"\nIterating from begin() to end():\n" << RESET << std::endl;
	std::cout << GREEN"In vector: \n" << RESET;
	for (; it != set.end(); it++)
		std::cout << it->first << ' ';
	std::cout << RESET << std::endl;
	std::cout << GREEN"In myvector: \n" << RESET;
	for (; myit != myset.end(); myit++)
		std::cout << myit->first << ' ';
	std::cout << RESET << std::endl;

	std::cout << BLUE"\nIterating from rbegin() to rend():\n" << RESET << std::endl;
	std::cout << GREEN"In vector: \n" << RESET;
	for (; rit != set.rend(); rit++)
		std::cout << rit->first << ' ';
	std::cout << RESET << std::endl;
	std::cout << GREEN"In myvector: \n" << RESET;
	for (; myrit != myset.rend(); myrit++)
		std::cout << myrit->first << ' ';
	std::cout << RESET << std::endl;

	std::cout << BLUE"\nTrying with const iterators:\n" << RESET << std::endl;
	constsetIteratorsTest(set, myset);
	checksetContinue();
}*/

void	setConstructorsTest()
{
	std::cout << RED"Starting constructor test" << RESET << std::endl;
	std::cout << BLUE"Create first set<int> and add some values:\n" << RESET << std::endl;
	int myints[]= {10,20,30,40,50};
	std::set<int> first(myints, myints + 5);
	ft::Set<int> myfirst(myints, myints + 5);
	
	printsets(first, myfirst);

	std::cout << BLUE"\nCreate second set with range of first:\n" << RESET << std::endl;
	std::set<int> second(first.begin(), first.end());
	ft::Set<int> mysecond(myfirst.begin(), myfirst.end());
	printsets(second, mysecond);

	std::cout << BLUE"\nCreate third set as a copy of second:\n" << RESET << std::endl;
	std::set<int> third(second);
	ft::Set<int> mythird(mysecond);
	printsets(third, mythird);

	std::cout << BLUE"\nCreate fourth set<string, int> with string lenght as compare:\n" << RESET << std::endl;
	std::string mystring[]= {"aaaa","bbb","cc","d"};
	std::set<std::string, cmpByStringLength> fourth (mystring, mystring + 4);
	std::set<std::string>::iterator it;

	it = fourth.begin();
	std::cout << GREEN"set output:\n" << RESET << std::endl;
	for ( ; it != fourth.end(); it++)
			std::cout << *it << std::endl;
	ft::Set<std::string, cmpByStringLength> myfourth(mystring, mystring + 4);
	ft::Set<std::string>::iterator myit;
	
	myit = myfourth.begin();
	std::cout << GREEN"My set output:\n" << RESET << std::endl;
	for ( ; myit != myfourth.end(); myit++)
			std::cout << *myit << std::endl;

	std::cout << BLUE"\nTrying operator =. Create five set equal to first, and first equal to new set:\n" << RESET << std::endl;
	std::set<int>	five;
	ft::Set<int>	myfive;

	five = first;
	first = std::set<int>();
	myfive = myfirst;
	myfirst = ft::Set<int>();
	std::cout << BLUE"\nPrint first:\n" << RESET << std::endl;
	printsets(first, myfirst);
	std::cout << BLUE"\nPrint five:\n" << RESET << std::endl;
	printsets(five, myfive);

	checksetContinue();	
}

int /*testSet()*/main()
{
	printsetBanner();
	setConstructorsTest();
	/*setIteratorsTest();
	setCapacityTest();
	setElementAccessTest();
	setModifiersTest();
	setObserversTest();
	setOperationsTest();
	setRelationalOperatorsTest();*/
	
	return 0;
}