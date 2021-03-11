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
			\t\t\t\t\t\t███████╗███████╗████████╗ ████████╗███████╗███████╗████████╗\n \
			\t\t\t\t\t\t██╔════╝██╔════╝╚══██╔══╝ ╚══██╔══╝██╔════╝██╔════╝╚══██╔══╝\n \
			\t\t\t\t\t\t███████╗█████╗     ██║       ██║   █████╗  ███████╗   ██║\n \
			\t\t\t\t\t\t╚════██║██╔══╝     ██║       ██║   ██╔══╝  ╚════██║   ██║\n \
			\t\t\t\t\t\t███████║███████╗   ██║       ██║   ███████╗███████║   ██║\n \
			\t\t\t\t\t\t╚══════╝╚══════╝   ╚═╝       ╚═╝   ╚══════╝╚══════╝   ╚═╝\n \
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

void	setRelationalOperatorsTest()
{
	std::cout << RED"Starting relational operators test" << RESET << std::endl;
	std::cout << BLUE"\nCreating sets foo and bar:\n" << RESET << std::endl;
	std::set<int> foo,bar;
	foo.insert(100);
	foo.insert(200);
	bar.insert(10);
	bar.insert(1000);

	ft::Set<int> myfoo,mybar;
	myfoo.insert(100);
	myfoo.insert(200);
	mybar.insert(10);
	mybar.insert(1000);
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
	std::cout << BLUE"\nCreate set<int> and insert single values:\n" << RESET << std::endl;
	int myints[]= {10,20,30,40,50};
	std::set<int> set(myints, myints + 5);
	std::set<int>::iterator it;

	ft::Set<int> myset(myints, myints + 5);
	ft::Set<int>::iterator myit;

	printsets(set, myset);

	std::cout << BLUE"\nFind '20' with function and erase it:\n" << RESET << std::endl;

	it = set.find(20);
	if (it != set.end())
		set.erase (it);
	myit = myset.find(20);
	if (myit != myset.end())
		myset.erase (myit);
	printsets(set, myset);

	std::cout << ORANGE"\nChecking count() function:" << RESET << std::endl;
	std::cout << BLUE"\nUse count to find elements in set:\n" << RESET << std::endl;
	if (set.count(25))
		std::cout << GREEN"'25' is an element of set" << std::endl;
	else
		std::cout << GREEN"'25' is not an element of set" << std::endl << std::endl;
	if (myset.count(25))
		std::cout << GREEN"'25' is an element of myset" << std::endl;
	else
		std::cout << GREEN"'25' is not an element of myset" << std::endl << std::endl;

	if (set.count(30))
		std::cout << GREEN"'30' is an element of set" << std::endl << std::endl;
	else
		std::cout << GREEN"'30' is not an element of set" << std::endl << std::endl;
	if (myset.count(30))
		std::cout << GREEN"'30' is an element of myset" << std::endl;
	else
		std::cout << GREEN"'30' is not an element of myset" << std::endl;

	std::cout << ORANGE"\nChecking upper_bound() and lowe_bound functions:" << RESET << std::endl;
	std::cout << BLUE"\nInserting some new elements in set:\n" << RESET << std::endl;
	set.insert(20);
	set.insert(60);
	myset.insert(20);
	myset.insert(60);
	printsets(set, myset);

	std::cout << BLUE"\nUse functions to erase from '20' to '40':\n" << RESET << std::endl;
	std::set<int>::iterator itlow, itup;
	ft::Set<int>::iterator myitlow, myitup;

	itlow = set.lower_bound(20);
	itup = set.upper_bound(40);
	set.erase(itlow, itup);
	myitlow = myset.lower_bound(20);
	myitup = myset.upper_bound(40);
	myset.erase(myitlow, myitup);
	printsets(set, myset);

	std::cout << ORANGE"\nChecking upper_bound() and lower_bound functions:" << RESET << std::endl;
	std::cout << BLUE"\nChecking upper and lower range with '50':\n" << RESET << std::endl;
	std::pair<std::set<int>::iterator,std::set<int>::iterator> ret;
	std::pair<ft::Set<int>::iterator,ft::Set<int>::iterator> myret;

	ret = set.equal_range(50);
	myret = myset.equal_range(50);

	std::cout << GREEN"In set lower bound points to: " << RESET;
	std::cout << *ret.first << '\n';

	std::cout << GREEN"In set upper bound points to: " << RESET;
	std::cout << *ret.second << '\n';

	std::cout << GREEN"In myset lower bound points to: " << RESET;
	std::cout << *myret.first << '\n';

	std::cout << GREEN"In myset upper bound points to: " << RESET;
	std::cout << *myret.second << '\n';
	checksetContinue();
}

void	setObserversTest()
{
	std::cout << RED"Starting observers test" << RESET << std::endl;
	std::cout << ORANGE"\nChecking key_comp() anda value_comp() functions:" << RESET << std::endl << std::endl;
	std::set<int> set;

	std::set<int>::key_compare comp = set.key_comp();

	for (int i=0; i<=5; i++) set.insert(i);

	std::cout << GREEN"set contains:\n" << RESET;

	char highest = *set.rbegin();

	std::set<int>::iterator it = set.begin();
	do {
		std::cout << *it << '\n';
	} while ( comp(*(++it), highest) );

	std::cout << '\n';

	ft::Set<int> myset;

	ft::Set<int>::key_compare mycomp = myset.key_comp();

	for (int i=0; i<=5; i++) myset.insert(i);

	std::cout << GREEN"myset contains:\n" << RESET;

	highest = *myset.rbegin();

	ft::Set<int>::iterator myit = myset.begin();
	do {
		std::cout << *myit << '\n';
	} while ( mycomp(*(++myit), highest) );

	std::cout << '\n';

	checksetContinue();
}

void	setModifiersTest()
{
	std::cout << RED"Starting modifiers test" << RESET << std::endl;
	std::cout << ORANGE"\n\nChecking insert() function:" << RESET << std::endl;
	std::cout << BLUE"\nCreate set<int> and insert single values:\n" << RESET << std::endl;
	std::set<int>	set;
	ft::Set<int>	myset;

	std::cout << std::boolalpha;
	set.insert(6);
	set.insert(2);
	set.insert(1);
	set.insert(9);
	set.insert(8);
	set.insert(15);
	set.insert(13);
	set.insert(11);
	std::cout << GREEN"Trying to insert new value in map: " << RESET << set.insert(18).second << std::endl;

	myset.insert(6);
	myset.insert(2);
	myset.insert(1);
	myset.insert(9);
	myset.insert(8);
	myset.insert(15);
	myset.insert(13);
	myset.insert(11);
	std::cout << GREEN"Trying to insert new value in map: " << RESET << myset.insert(18).second << std::endl;

	
	std::cout << GREEN"\ntrying to insert already known value in set: " << RESET << (set.insert(11)).second << std::endl;
	std::cout << GREEN"trying to insert already known value in set: " << RESET << (myset.insert(11)).second << std::endl << std::endl;
	printsets(set, myset);

	std::cout << BLUE"\nInsert new value with hint (max efficiency):\n" << RESET << std::endl;
	std::set<int>::iterator it = set.find(18);
	ft::Set<int>::iterator myit = myset.find(18);
	set.insert(it, (20));
	myset.insert(myit, (20));
	printsets(set, myset);

	std::cout << BLUE"\nInsert new value with hint (no max efficiency):\n" << RESET << std::endl;
	it = set.find(6);
	myit = myset.find(6);
	set.insert(it, (12));
	myset.insert(myit, (12));
	printsets(set, myset);

	std::cout << BLUE"\nCreate new set with range insert:\n" << RESET << std::endl;
	std::set<int>	anotherset;
	ft::Set<int>	myanotherset;
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
	std::set<int>::iterator bit = anotherset.begin();
	std::set<int>::iterator eit = anotherset.end();
	anotherset.erase(bit, eit);
	ft::Set<int>::iterator mybit = myanotherset.begin();
	ft::Set<int>::iterator myeit = myanotherset.end();
	myanotherset.erase(mybit, myeit);
	printsets(anotherset, myanotherset);

	std::cout << ORANGE"\n\nChecking erase() function:" << RESET << std::endl;
	std::cout << BLUE"\nInsert some values in anotherset and swap with set:\n" << RESET << std::endl;
	anotherset.insert((42));
	anotherset.insert((43));
	myanotherset.insert((42));
	myanotherset.insert((43));
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

void	setCapacityTest()
{
	std::cout << RED"Starting capacity test" << RESET << std::endl;
	int myints[]= {10,20,30,40,50};
	std::set<int>	set(myints, myints + 5);
	ft::Set<int>	myset(myints, myints + 5);
	std::set<int>	set1;
	ft::Set<int>	myset1;
	std::cout << BLUE"\nCreating set<int> with some values and empty set1:\n" << RESET << std::endl;
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
	std::set<std::string> set2;
	ft::Set<std::string> myset2;
	std::cout << ORANGE"\nChecking with std::string: " << RESET << std::endl;
	std::cout << GREEN"set<std::string> max_size: " << RESET << set2.max_size() << RESET << std::endl;
	std::cout << GREEN"myset<std::string> max_size: " << RESET << myset2.max_size() << RESET << std::endl;
	std::set<setfoo*> set3;
	ft::Set<setfoo*> myset3;
	std::cout << ORANGE"\nChecking with another class: " << RESET << std::endl;
	std::cout << GREEN"set<foo*> max_size: " << RESET << set3.max_size() << RESET << std::endl;
	std::cout << GREEN"myset<foo*> max_size: " << RESET << myset3.max_size() << RESET << std::endl;
	checksetContinue();
}

void	constsetIteratorsTest(const std::set<int>& set, const ft::Set<int>& myset)
{
	std::set<int>::const_iterator cit = set.begin();
	ft::Set<int>::const_iterator mycit = myset.begin();
	std::set<int>::const_reverse_iterator rcit = set.rbegin();
	ft::Set<int>::const_reverse_iterator myrcit = myset.rbegin();
	std::cout << BLUE"\nIterating from begin() to end() with const iterators:\n" << RESET << std::endl;
	std::cout << GREEN"In vector: \n" << RESET;
	for (; cit != set.end(); cit++)
		std::cout << *cit << ' ';
	std::cout << RESET << std::endl;
	std::cout << GREEN"In myvector: \n" << RESET;
	for (; mycit != myset.end(); mycit++)
		std::cout << *mycit << ' ';
	std::cout << RESET << std::endl;

	std::cout << BLUE"\nIterating from rbegin() to rend() with const iterators:\n" << RESET << std::endl;
	std::cout << GREEN"In set: \n" << RESET;
	for (; rcit != set.rend(); rcit++)
		std::cout << *rcit << ' ';
	std::cout << RESET << std::endl;
	std::cout << GREEN"In myset: \n" << RESET;
	for (; myrcit != myset.rend(); myrcit++)
		std::cout << *myrcit << ' ';
	std::cout << RESET << std::endl;
}

void	setIteratorsTest()
{
	std::cout << RED"Starting iterators test" << RESET << std::endl;
	std::cout << BLUE"\nCreating set<int> with some values:\n" << RESET << std::endl;
	int myints[]= {10,20,30,40,50};
	std::set<int> set(myints, myints + 5);
	ft::Set<int> myset(myints, myints + 5);

	std::set<int>::iterator it = set.begin();
	ft::Set<int>::iterator myit = myset.begin();
	std::cout << GREEN"set begin() points to: " << RESET << *it << std::endl;
	std::cout << GREEN"myset begin() points to: " << RESET << *myit << std::endl;
	std::cout << std::endl;

	std::set<int>::reverse_iterator rit = set.rbegin();
	ft::Set<int>::reverse_iterator myrit = myset.rbegin();
	std::cout << GREEN"set rbegin() points to: " << RESET << *rit << std::endl;
	std::cout << GREEN"myset rbegin() points to: " << RESET << *myrit << std::endl;
	std::cout << std::endl;

	std::cout << BLUE"\nIterating from begin() to end():\n" << RESET << std::endl;
	std::cout << GREEN"In vector: \n" << RESET;
	for (; it != set.end(); it++)
		std::cout << *it << ' ';
	std::cout << RESET << std::endl;
	std::cout << GREEN"In myvector: \n" << RESET;
	for (; myit != myset.end(); myit++)
		std::cout << *myit << ' ';
	std::cout << RESET << std::endl;

	std::cout << BLUE"\nIterating from rbegin() to rend():\n" << RESET << std::endl;
	std::cout << GREEN"In vector: \n" << RESET;
	for (; rit != set.rend(); rit++)
		std::cout << *rit << ' ';
	std::cout << RESET << std::endl;
	std::cout << GREEN"In myvector: \n" << RESET;
	for (; myrit != myset.rend(); myrit++)
		std::cout << *myrit << ' ';
	std::cout << RESET << std::endl;

	std::cout << BLUE"\nTrying with const iterators:\n" << RESET << std::endl;
	constsetIteratorsTest(set, myset);
	checksetContinue();
}

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

int testSet()
{
	printsetBanner();
	setConstructorsTest();
	setIteratorsTest();
	setCapacityTest();
	setModifiersTest();
	setObserversTest();
	setOperationsTest();
	setRelationalOperatorsTest();
	
	return 0;
}