#include <list>
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


template <class T>
void	printLists(std::list<T> list, ft::List<T> mylist)
{
	std::cout << GREEN"List output:\n" << RESET << std::endl;
	ft::printoList(list);
	std::cout << GREEN"\nMy List output:\n" << RESET << std::endl;
	ft::printList(mylist);
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
	/*constructorTest();
	iteratorsTest();
	capacityTest();
	elementAccessTest();*/
	modifiersTest();
	
	return 0;
}