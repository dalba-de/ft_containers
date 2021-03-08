#include <list>
#include <cmath>
#include "../List/List.hpp"
#include "../Tools/Shared_functions.hpp"
# define RESET		"\033[0m"
# define RED		"\033[1;31m"
# define GREEN		"\033[1;32m"
# define ORANGE		"\033[1;33m"
# define PURPLE		"\033[35m"
# define CYAN		"\033[1;36m"
# define BLUE       "\033[1;34m"
# define GREY		"\033[1;30m"
# define UNDER		"\033[4m"

class foo
{
private:
	/* data */
public:
	foo(/* args */);
	~foo();
};

foo::foo(/* args */)
{
}

foo::~foo()
{
}

// compare only integral part:
bool mycomparison (double first, double second)
{ return ( int(first)<int(second) ); }

// a predicate implemented as a function:
bool single_digit (const int& value) 
{ return (value<10); }

// a predicate implemented as a class:
struct is_odd {
bool operator() (const int& value) { return (value%2)==1; }
};

// a binary predicate implemented as a function:
bool same_integral_part (double first, double second)
{ return ( int(first)==int(second) ); }

// a binary predicate implemented as a class:
struct is_near {
  bool operator() (double first, double second)
  { return (fabs(first-second)<5.0); }
};

template <class T>
void	printLists(std::list<T> list, ft::List<T> mylist)
{
	std::cout << GREEN"List output:\n" << RESET << std::endl;
	ft::printoList(list);
	std::cout << GREEN"\nMy List output:\n" << RESET << std::endl;
	ft::printList(mylist);
}

bool compare_nocase (const std::string& first, const std::string& second)
{
  unsigned int i=0;
  while ( (i<first.length()) && (i<second.length()) )
  {
    if (tolower(first[i])<tolower(second[i])) return true;
    else if (tolower(first[i])>tolower(second[i])) return false;
    ++i;
  }
  return ( first.length() < second.length() );
}

void	printBanner()
{
	system("clear");
	printf(CYAN"\n\n \
			\t\t\t\t\t\t██╗    ██╗███████╗████████╗ ████████╗███████╗███████╗████████╗\n \
			\t\t\t\t\t\t██║    ██║██╔════╝╚══██╔══╝ ╚══██╔══╝██╔════╝██╔════╝╚══██╔══╝\n \
			\t\t\t\t\t\t██║    ██║███████╗   ██║       ██║   █████╗  ███████╗   ██║\n \
			\t\t\t\t\t\t██║    ██║╚════██║   ██║       ██║   ██╔══╝  ╚════██║   ██║\n \
			\t\t\t\t\t\t██████╗██║███████║   ██║       ██║   ███████╗███████║   ██║\n \
			\t\t\t\t\t\t╚═════╝╚═╝╚══════╝   ╚═╝       ╚═╝   ╚══════╝╚══════╝   ╚═╝\n \
					\t\t\t\t\t\tby dalba-de			\n\n\033[0m");
}

void	checkContinue()
{
	std::cout << std::endl;
	std::string input;
	while (input != "c")
	{
		std::cout << ORANGE"Press 'c' to continue..." << RESET << std::endl;
		std::getline(std::cin, input);
	}
	printBanner();
}

void	relationalOperatorsTest()
{
	std::cout << RED"Starting relational operators test" << RESET << std::endl;
	std::cout << BLUE"\nCreating three int list:\n" << RESET << std::endl;
	int	intsa[] = {10, 20, 30};
	int	intsb[] = {30, 20, 10};	
	std::list<int> a(intsa, intsa + 3);
	std::list<int> b(intsa, intsa + 3);
	std::list<int> c(intsb, intsb + 3);
	ft::List<int> mya(intsa, intsa + 3);
	ft::List<int> myb(intsa, intsa + 3);
	ft::List<int> myc(intsb, intsb + 3);
	std::cout << BLUE"Print a: " << std::endl;
	printLists(a, mya);
	std::cout << BLUE"Print b: " << std::endl;
	printLists(b, myb);
	std::cout << BLUE"Print c: " << std::endl;
	printLists(c, myc);

	std::cout << ORANGE"\n\nChecking relational operators:" << RESET << std::endl;
	std::cout << GREEN"\n\nList output:" << RESET << std::endl;
	if (a==b) std::cout << "a and b are equal\n";
	if (b!=c) std::cout << "b and c are not equal\n";
	if (b<c) std::cout << "b is less than c\n";
	if (c>b) std::cout << "c is greater than b\n";
	if (a<=b) std::cout << "a is less than or equal to b\n";
	if (a>=b) std::cout << "a is greater than or equal to b\n";

	std::cout << GREEN"\n\nMy list output:" << RESET << std::endl;
	if (mya==myb) std::cout << "a and b are equal\n";
	if (myb!=myc) std::cout << "b and c are not equal\n";
	if (myb<myc) std::cout << "b is less than c\n";
	if (myc>myb) std::cout << "c is greater than b\n";
	if (mya<=myb) std::cout << "a is less than or equal to b\n";
	if (mya>=myb) std::cout << "a is greater than or equal to b\n";

	std::cout << ORANGE"\n\nChecking swap() function (no member overload):" << RESET << std::endl;
	std::cout << BLUE"\nCreating two int list:\n" << RESET << std::endl;
	std::list<int> foo (3,100);
	std::list<int> bar (5,200);
	ft::List<int> myfoo (3,100);
	ft::List<int> mybar (5,200);
	std::cout << BLUE"Print foo: " << std::endl;
	printLists(foo, myfoo);
	std::cout << BLUE"\nPrint bar: " << std::endl;
	printLists(bar, mybar);

	std::cout << BLUE"\nSwap lists:\n" << RESET << std::endl;
	std::swap(foo,bar);
	ft::swap(myfoo, mybar);
	std::cout << BLUE"Print foo: " << std::endl;
	printLists(foo, myfoo);
	std::cout << BLUE"\nPrint bar: " << std::endl;
	printLists(bar, mybar);
}

void	operationsTest()
{
	std::cout << RED"Starting operations test" << RESET << std::endl;
	std::cout << ORANGE"\n\nChecking splice() function:" << RESET << std::endl;
	std::cout << BLUE"\nSet some initial values to first and second list:\n" << RESET << std::endl;
	std::list<int> first;
  	std::list<int> second;
	ft::List<int> myfirst;
  	ft::List<int> mysecond;
	std::list<int>::iterator it;
	ft::List<int>::iterator myit;
	for (int i=1; i<=4; ++i)
	{
		first.push_back(i);
		myfirst.push_back(i);
	}
	for (int i=1; i<=3; ++i)
	{
		second.push_back(i*10);
		mysecond.push_back(i*10);
	}
	std::cout << BLUE"Print first: " << std::endl;
	printLists(first, myfirst);
	std::cout << BLUE"\nPrint second: " << std::endl;
	printLists(second, mysecond);
    
	it = first.begin();
	it++;
	myit = myfirst.begin();
	myit++;
    std::cout << BLUE"\nCreate iterator pointing to 2, and splice second in first (entire list):\n" << RESET << std::endl;
	first.splice(it, second);
	myfirst.splice(myit, mysecond);
	std::cout << BLUE"Print first: " << std::endl;
	printLists(first, myfirst);
	std::cout << BLUE"\nPrint second: " << std::endl;
	printLists(second, mysecond);

	std::cout << BLUE"\nTransferring 2 into second (single element):\n" << RESET << std::endl;
	second.splice(second.begin(), first, it);
	mysecond.splice(mysecond.begin(), myfirst, myit);
	std::cout << BLUE"Print first: " << std::endl;
	printLists(first, myfirst);
	std::cout << BLUE"\nPrint second: " << std::endl;
	printLists(second, mysecond);

	std::cout << BLUE"\nPointing iterator to '30' and moving elements (range element):\n" << RESET << std::endl;
	it = first.begin();
	std::advance(it, 3);
	myit = myfirst.begin();
	std::advance(myit, 3);
	first.splice(first.begin(), first, it, first.end());
	myfirst.splice(myfirst.begin(), myfirst, myit, myfirst.end());
	std::cout << BLUE"Print first: " << std::endl;
	printLists(first, myfirst);

	std::cout << ORANGE"\n\nChecking remove() function:" << RESET << std::endl;
	std::cout << BLUE"\nRemoving '30' and '4':\n" << RESET << std::endl;
	first.remove(30);
	first.remove(4);
	myfirst.remove(30);
	myfirst.remove(4);
	std::cout << BLUE"Print first: " << std::endl;
	printLists(first, myfirst);

	std::cout << ORANGE"\n\nChecking remove_if() function:" << RESET << std::endl;
	int myints[]= {15,36,7,17,20,39,4,1};
	std::cout << BLUE"\nAssign {15,36,7,17,20,39,4,1} to first:\n" << RESET << std::endl;
	first.assign(myints, myints + 8);
	myfirst.assign(myints, myints + 8);
	std::cout << BLUE"Print first: " << std::endl;
	printLists(first, myfirst);

	std::cout << BLUE"\nTry remove single-digit values:\n" << RESET << std::endl;
	first.remove_if(single_digit);
	myfirst.remove_if(single_digit);
	std::cout << BLUE"Print first: " << std::endl;
	printLists(first, myfirst);

	std::cout << BLUE"\nTry remove odd values:\n" << RESET << std::endl;
	first.remove_if(is_odd());
	myfirst.remove_if(is_odd());
	std::cout << BLUE"Print first: " << std::endl;
	printLists(first, myfirst);

	std::cout << ORANGE"\n\nChecking unique() function:" << RESET << std::endl;
	std::cout << BLUE"\nCreate double list with { 12.15,  2.72, 73.0,  12.77,  3.14, \
12.77, 73.35, 72.25, 15.3,  72.25 } values:\n" << RESET << std::endl;
	double mydoubles[]={ 12.15,  2.72, 73.0,  12.77,  3.14,
                       12.77, 73.35, 72.25, 15.3,  72.25 };
	std::list<double>	third(mydoubles, mydoubles+10);
	ft::List<double>	mythird(mydoubles, mydoubles+10);
	std::cout << BLUE"Print third: " << std::endl;
	printLists(third, mythird);

	std::cout << BLUE"\nSorting list and remove equal values:\n" << RESET << std::endl;
	third.sort();
	third.unique();
	mythird.sort();
	mythird.unique();
	std::cout << BLUE"Print third: " << std::endl;
	printLists(third, mythird);

	std::cout << BLUE"\nRemove values with same integral part:\n" << RESET << std::endl;
	third.unique(same_integral_part);
	mythird.unique(same_integral_part);
	std::cout << BLUE"Print third: " << std::endl;
	printLists(third, mythird);

	std::cout << BLUE"\nRemove values with difference < 5.0:\n" << RESET << std::endl;
	third.unique(is_near());
	mythird.unique(is_near());
	std::cout << BLUE"Print third: " << std::endl;
	printLists(third, mythird);

	std::cout << ORANGE"\n\nChecking merge() function:" << RESET << std::endl;
	std::cout << BLUE"\nCreate double list fourth with {3.1, 2.2, 2.9} values and list five with {3.7, 7.1, 1.4} values:\n" << RESET << std::endl;
	std::list<double>	fourth;
	std::list<double>	five;
	ft::List<double>	myfourth;
	ft::List<double>	myfive;
	fourth.push_back (3.1);
	fourth.push_back (2.2);
	fourth.push_back (2.9);
	five.push_back (3.7);
	five.push_back (7.1);
	five.push_back (1.4);
	myfourth.push_back (3.1);
	myfourth.push_back (2.2);
	myfourth.push_back (2.9);
	myfive.push_back (3.7);
	myfive.push_back (7.1);
	myfive.push_back (1.4);
	std::cout << BLUE"Print fourth: " << std::endl;
	printLists(fourth, myfourth);
	std::cout << BLUE"\nPrint five: " << std::endl;
	printLists(five, myfive);

	std::cout << BLUE"\nSorting lists and merge five into fourth:\n" << RESET << std::endl;
	fourth.sort();
	five.sort();
	myfourth.sort();
	myfive.sort();
	fourth.merge(five);
	myfourth.merge(myfive);
	std::cout << BLUE"Print fourth: " << std::endl;
	printLists(fourth, myfourth);
	std::cout << BLUE"\nPrint five: " << std::endl;
	printLists(five, myfive);

	std::cout << BLUE"\nPush '2.1' in five and merge comparing only integral part:\n" << RESET << std::endl;
	five.push_back(2.1);
	myfive.push_back(2.1);
	fourth.merge(five, mycomparison);
	myfourth.merge(myfive, mycomparison);
	std::cout << BLUE"Print fourth: " << std::endl;
	printLists(fourth, myfourth);
	std::cout << BLUE"\nPrint five: " << std::endl;
	printLists(five, myfive);

	std::cout << ORANGE"\n\nChecking sort() function:" << RESET << std::endl;
	std::cout << BLUE"\nCreating string list with 'one', 'two' and 'Three' values:\n" << RESET << std::endl;
	std::list<std::string> list;
	std::list<std::string>::iterator sit;
	list.push_back ("one");
	list.push_back ("two");
	list.push_back ("Three");
	ft::List<std::string> mylist;
	ft::List<std::string>::iterator mysit;
	mylist.push_back ("one");
	mylist.push_back ("two");
	mylist.push_back ("Three");

	std::cout << BLUE"\nSorting list:\n" << RESET << std::endl;
	list.sort();
	mylist.sort();
	printLists(list, mylist);

	std::cout << BLUE"\nSorting list comparing no case sensitive:\n" << RESET << std::endl;
	list.sort(compare_nocase);
	mylist.sort(compare_nocase);
	printLists(list, mylist);

	std::cout << ORANGE"\n\nChecking reverse() function:" << RESET << std::endl;
	std::cout << BLUE"\nAssign values from 1 to 9 to int list:\n" << RESET << std::endl;
	first.clear();
	myfirst.clear();
	for (int i=1; i<10; ++i)
	{
		first.push_back(i);
		myfirst.push_back(i);
	}
	std::cout << BLUE"\nPrint int list: " << std::endl;
	printLists(first, myfirst);
	std::cout << BLUE"\nReversing int list: " << std::endl;
	first.reverse();
	myfirst.reverse();
	printLists(first, myfirst);
	checkContinue();
}

void	modifiersTest()
{
	std::cout << RED"Starting modifiers test" << RESET << std::endl;
	std::cout << ORANGE"\n\nChecking assign() function:" << RESET << std::endl;
	int myints[]={1776,7,4};
	std::list<int> first;
  	std::list<int> second;
	ft::List<int> myfirst;
  	ft::List<int> mysecond;
	std::cout << BLUE"\nTrying fill assign() in first, with 7 ints of value 100:\n" << RESET << std::endl;
	first.assign(7, 100);
	myfirst.assign(7, 100);
	printLists(first, myfirst);
	std::cout << BLUE"\nTrying range assign() in second, from array {1776, 7, 4}:\n" << RESET << std::endl;
	second.assign(myints, myints + 3);
	mysecond.assign(myints, myints + 3);
	printLists(second, mysecond);
	std::cout << BLUE"\nReassign first with second:\n" << RESET << std::endl;
	std::cout << GREEN"Before reassign. first size: " << first.size() << ". myfirst size: " << myfirst.size() << RESET << std::endl;
	first.assign(second.begin(), second.end());
	myfirst.assign(mysecond.begin(), mysecond.end());
	std::cout << GREEN"After reassign. first size: " << first.size() << ". myfirst size: " << myfirst.size() << RESET << std::endl << std::endl;
	printLists(first, myfirst);

	std::cout << ORANGE"\n\nChecking push_front() function:" << RESET << std::endl;
	std::cout << BLUE"\nAdd {200, 300} to first:\n" << RESET << std::endl;
	first.push_front(200);
	first.push_front(300);
	myfirst.push_front(200);
	myfirst.push_front(300);
	printLists(first, myfirst);

	std::cout << ORANGE"\n\nChecking push_back() function:" << RESET << std::endl;
	std::cout << BLUE"\nAdd {42, 21} to first:\n" << RESET << std::endl;
	first.push_back(42);
	first.push_back(21);
	myfirst.push_back(42);
	myfirst.push_back(21);
	printLists(first, myfirst);

	std::cout << ORANGE"\n\nChecking pop_front() function:" << RESET << std::endl;
	std::cout << BLUE"\nRemoving front to first:\n" << RESET << std::endl;
	first.pop_front();
	myfirst.pop_front();
	printLists(first, myfirst);

	std::cout << ORANGE"\n\nChecking pop_back() function:" << RESET << std::endl;
	std::cout << BLUE"\nRemoving back to first:\n" << RESET << std::endl;
	first.pop_back();
	myfirst.pop_back();
	printLists(first, myfirst);

	std::cout << ORANGE"\n\nChecking insert() function:" << RESET << std::endl;
	std::cout << BLUE"\nInserting '73' in the second position (single element insert):\n" << RESET << std::endl;
	std::list<int>::iterator it = first.begin();
	it++;
	ft::List<int>::iterator myit = myfirst.begin();
	myit++;
	first.insert(it, 73);
	myfirst.insert(myit, 73);
	printLists(first, myfirst);

	std::cout << BLUE"\nInserting 2 int of value '20' after '73' (fill insert):\n" << RESET << std::endl;
	first.insert(it, 2, 20);
	myfirst.insert(myit, 2, 20);
	printLists(first, myfirst);

	int myints1[]={1,2,3,4,5};
	std::cout << BLUE"\nInserting {1,2,3,4,5} in penultimate position (range insert):\n" << RESET << std::endl;
	it = first.end();
	it--;
	myit = myfirst.end();
	myit--;
	second.assign(myints1, myints1 + 5);
	mysecond.assign(myints1, myints1 + 5);
	first.insert(it, second.begin(), second.end());
	myfirst.insert(myit, mysecond.begin(), mysecond.end());
	printLists(first, myfirst);

	std::cout << ORANGE"\n\nChecking erase() function:" << RESET << std::endl;
	std::cout << BLUE"\nErase second position (single erase):\n" << RESET << std::endl;
	it = first.begin();
	it++;
	myit = myfirst.begin();
	myit++; 
	first.erase(it);
	myfirst.erase(myit);
	printLists(first, myfirst);

	std::cout << BLUE"\nErase from fourth position to eight position (range erase):\n" << RESET << std::endl;
	it = first.begin();
	std::advance(it,4);
	std::list<int>::iterator it2 = first.begin();
	std::advance(it2, 8);
	myit = myfirst.begin();
	std::advance(myit, 4);
	ft::List<int>::iterator myit2 = myfirst.begin();
	std::advance(myit2, 8);
	first.erase(it, it2);
	myfirst.erase(myit, myit2);
	printLists(first, myfirst);

	std::cout << ORANGE"\n\nChecking swap() function:" << RESET << std::endl;
	std::cout << BLUE"\nSwaping content from first to second:\n" << RESET << std::endl;
	
	std::cout << BLUE"Print first before swap: " << std::endl;
	printLists(first, myfirst);
	std::cout << GREEN"\nfirst size: " << first.size() << ". myfirst size: " << myfirst.size() << RESET << std::endl;
	std::cout << BLUE"\nPrint second before swap: " << std::endl;
	printLists(second, mysecond);
	std::cout << GREEN"\nsecond size: " << second.size() << ". mysecond size: " << mysecond.size() << RESET << std::endl << std::endl;

	first.swap(second);
	myfirst.swap(mysecond);
	std::cout << BLUE"Print first after swap: " << std::endl;
	printLists(first, myfirst);
	std::cout << GREEN"\nfirst size: " << first.size() << ". myfirst size: " << myfirst.size() << RESET << std::endl;
	std::cout << BLUE"\nPrint second after swap: " << std::endl;
	printLists(second, mysecond);
	std::cout << GREEN"\nsecond size: " << second.size() << ". mysecond size: " << mysecond.size() << RESET << std::endl << std::endl;

	std::cout << ORANGE"\n\nChecking resize() function:" << RESET << std::endl;
	std::cout << BLUE"\nResize first to 7, with zero-initialized values:\n" << RESET << std::endl;
	first.resize(7);
	myfirst.resize(7);
	printLists(first, myfirst);

	std::cout << BLUE"\nResize first to 10, with val = 42:\n" << RESET << std::endl;
	first.resize(10, 42);
	myfirst.resize(10, 42);
	printLists(first, myfirst);

	std::cout << BLUE"\nResize first to 5::\n" << RESET << std::endl;
	first.resize(5);
	myfirst.resize(5);
	printLists(first, myfirst);

	std::cout << ORANGE"\n\nChecking clear() function:" << RESET << std::endl;
	first.clear();
	myfirst.clear();
	std::cout << BLUE"Print first after clear: " << std::endl;
	printLists(first, myfirst);
	std::cout << GREEN"\nfirst size: " << first.size() << ". myfirst size: " << myfirst.size() << RESET << std::endl;
	checkContinue();
}

void	elementAccessTest()
{
	std::cout << RED"Starting element access test" << RESET << std::endl;
	std::list<int> list;
	ft::List<int> mylist;

	list.push_back(77);
	list.push_back(22);
	mylist.push_back(77);
	mylist.push_back(22);
	std::cout << BLUE"\nCreating list with {77, 22}:\n" << RESET << std::endl;
	std::cout << GREEN"list front() points to: " << list.front() << RESET << std::endl;
	std::cout << GREEN"list back() points to: " << list.back() << RESET << std::endl;
	std::cout << std::endl;
	std::cout << GREEN"mylist front() points to: " << mylist.front() << RESET << std::endl;
	std::cout << GREEN"mylist back() points to: " << mylist.back() << RESET << std::endl;

	std::cout << BLUE"\nSubtracting back from front:\n" << RESET << std::endl;
	list.front() -= list.back();
	mylist.front() -= mylist.back();

	std::cout << GREEN"list.front() is now " << list.front() << '\n' << RESET;
	std::cout << GREEN"mylist.front() is now " << mylist.front() << '\n' << RESET;
	checkContinue();
}

void	capacityTest()
{
	std::cout << RED"Starting capacity test" << RESET << std::endl;
	int myints[] = {16,2,77,29};
	std::list<int> list(myints, myints + 4);
	ft::List<int> mylist(myints, myints + 4);
	std::list<int> list1;
	ft::List<int> mylist1;
	std::cout << BLUE"\nCreating list with {16,2,77,29} and empty list1:\n" << RESET << std::endl;
	std::cout << "\n\033[1;33mPrinting filled list:\n" << RESET << std::endl;
	printLists(list, mylist);
	std::cout << "\n\033[1;33mPrinting empty list:\n" << RESET << std::endl;
	printLists(list1, mylist1);

	std::cout << BLUE"\nChecking empty() function with list:\n" << RESET << std::endl;
	if (list.empty())
		std::cout << GREEN"list is empty" << RESET << std::endl;
	else
		std::cout << GREEN"list is not empty" << RESET << std::endl;
	if (mylist.empty())
		std::cout << GREEN"mylist is empty" << RESET << std::endl;
	else
		std::cout << GREEN"mylist is not empty" << RESET << std::endl;

	std::cout << BLUE"\nChecking empty() function with list1:\n" << RESET << std::endl;
	if (list1.empty())
		std::cout << GREEN"list1 is empty" << RESET << std::endl;
	else
		std::cout << GREEN"list1 is not empty" << RESET << std::endl;
	if (mylist1.empty())
		std::cout << GREEN"mylist1 is empty" << RESET << std::endl;
	else
		std::cout << GREEN"mylist1 is not empty" << RESET << std::endl;

	std::cout << BLUE"\nChecking size() function:\n" << RESET << std::endl;
	std::cout << GREEN"list size: " << list.size() << ". list1 size: " << list1.size() << RESET << std::endl;
	std::cout << GREEN"mylist size: " << mylist.size() << ". mylist1 size: " << mylist1.size() << RESET << std::endl;

	std::cout << BLUE"\nChecking max_size() function:\n" << RESET << std::endl;
	std::cout << ORANGE"Checking with int: " << RESET << std::endl;
	std::cout << GREEN"list<int> max_size: " << list.max_size() << RESET << std::endl;
	std::cout << GREEN"mylist<int> max_size: " << mylist.max_size() << RESET << std::endl;
	std::list<std::string> list2;
	ft::List<std::string> mylist2;
	std::cout << ORANGE"\nChecking with std::string: " << RESET << std::endl;
	std::cout << GREEN"list<std::string> max_size: " << list2.max_size() << RESET << std::endl;
	std::cout << GREEN"mylist<std::string> max_size: " << mylist2.max_size() << RESET << std::endl;
	std::list<bool> list3;
	ft::List<bool> mylist3;
	std::cout << ORANGE"\nChecking with bool: " << RESET << std::endl;
	std::cout << GREEN"list<bool> max_size: " << list3.max_size() << RESET << std::endl;
	std::cout << GREEN"mylist<bool> max_size: " << mylist3.max_size() << RESET << std::endl;
	std::list<foo*> list4;
	ft::List<foo*> mylist4;
	std::cout << ORANGE"\nChecking with another class: " << RESET << std::endl;
	std::cout << GREEN"list<foo*> max_size: " << list4.max_size() << RESET << std::endl;
	std::cout << GREEN"mylist<foo*> max_size: " << mylist4.max_size() << RESET << std::endl;
	checkContinue();
}

void	constIteratorsTest(const std::list<int>& list, const ft::List<int>& mylist)
{
	std::list<int>::const_iterator cit = list.begin();
	ft::List<int>::const_iterator mycit = mylist.begin();
	std::list<int>::const_reverse_iterator rcit = list.rbegin();
	ft::List<int>::const_reverse_iterator myrcit = mylist.rbegin();
	std::cout << BLUE"\nIterating from begin() to end() with const iterators:\n" << RESET << std::endl;
	std::cout << GREEN"In list: \n";
	for (; cit != list.end(); cit++)
		std::cout << *cit << ' ';
	std::cout << RESET << std::endl;
	std::cout << GREEN"In mylist: \n";
	for (; mycit != mylist.end(); mycit++)
		std::cout << *mycit << ' ';
	std::cout << RESET << std::endl;

	std::cout << BLUE"\nIterating from rbegin() to rend() with const iterators:\n" << RESET << std::endl;
	std::cout << GREEN"In list: \n";
	for (; rcit != list.rend(); rcit++)
		std::cout << *rcit << ' ';
	std::cout << RESET << std::endl;
	std::cout << GREEN"In mylist: \n";
	for (; myrcit != mylist.rend(); myrcit++)
		std::cout << *myrcit << ' ';
	std::cout << RESET << std::endl;
}

void	iteratorsTest()
{
	std::cout << RED"Starting iterators test" << RESET << std::endl;
	int myints[] = {16,2,77,29};
	std::list<int> list(myints, myints + 4);
	ft::List<int> mylist(myints, myints + 4);
	std::cout << BLUE"\nCreating list with {16,2,77,29}:\n" << RESET << std::endl;
	std::list<int>::iterator it = list.begin();
	ft::List<int>::iterator	myit = mylist.begin();
	std::cout << GREEN"list begin() points to: " << *it << RESET << std::endl;
	std::cout << GREEN"mylist begin() points to: " << *myit << RESET << std::endl;
	std::cout << std::endl;

	std::list<int>::reverse_iterator rit = list.rbegin();
	ft::List<int>::reverse_iterator myrit = mylist.rbegin();
	std::cout << GREEN"list rbegin() points to: " << *rit << RESET << std::endl;
	std::cout << GREEN"mylist rbegin() points to: " << *myrit << RESET << std::endl;
	std::cout << std::endl;

	std::cout << BLUE"\nIterating from begin() to end():\n" << RESET << std::endl;
	std::cout << GREEN"In list: \n";
	for (; it != list.end(); it++)
		std::cout << *it << ' ';
	std::cout << RESET << std::endl;
	std::cout << GREEN"In mylist: \n";
	for (; myit != mylist.end(); myit++)
		std::cout << *myit << ' ';
	std::cout << RESET << std::endl;

	std::cout << BLUE"\nIterating from rbegin() to rend():\n" << RESET << std::endl;
	std::cout << GREEN"In list: \n";
	for (; rit != list.rend(); rit++)
		std::cout << *rit << ' ';
	std::cout << RESET << std::endl;
	std::cout << GREEN"In mylist: \n";
	for (; myrit != mylist.rend(); myrit++)
		std::cout << *myrit << ' ';
	std::cout << RESET << std::endl;

	std::cout << BLUE"\nTrying with const iterators:\n" << RESET << std::endl;
	constIteratorsTest(list, mylist);
	checkContinue();
}

void	constructorTest()
{
	std::cout << RED"Starting constructor test" << RESET << std::endl;
	std::cout << BLUE"Trying fill constructor with (4, 100):\n" << RESET << std::endl;
	std::list<int>	first(4, 100);
	ft::List<int>	myfirst(4, 100);
	printLists(first, myfirst);
	
	int myints[] = {16,2,77,29};
	std::cout << BLUE"\nTrying construct from array {16,2,77,29}(iterator range):\n" << RESET << std::endl;
	std::list<int> second(myints, myints + 4);
	ft::List<int> mysecond(myints, myints + 4);
	printLists(second, mysecond);

	std::cout << BLUE"\nTrying to construct as a copy of second:\n" << RESET << std::endl;
	std::list<int> third(second);
	ft::List<int> mythird(mysecond);
	printLists(third, mythird);

	std::cout << BLUE"\nTrying operator =. First create a list of 5 zero-initialized ints:\n" << RESET << std::endl;
	std::list<int> fourth(5);
	ft::List<int> myfourth(5);
	printLists(fourth, myfourth);

	std::cout << BLUE"\nThen use operator = to copy third:\n" << RESET << std::endl;
	fourth = third;
	myfourth = mythird;
	printLists(fourth, myfourth);
	checkContinue();
}

int main()
{
	printBanner();
	constructorTest();
	iteratorsTest();
	capacityTest();
	elementAccessTest();
	modifiersTest();
	operationsTest();
	relationalOperatorsTest();
	
	return 0;
}