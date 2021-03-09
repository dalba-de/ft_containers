#include <vector>
#include "../includes/Vector/Vector.hpp"
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

class vectorfoo
{
private:
	/* data */
public:
	vectorfoo(/* args */);
	~vectorfoo();
};

vectorfoo::vectorfoo(/* args */)
{
}

vectorfoo::~vectorfoo()
{
}

template <class T>
void	printVectors(std::vector<T> list, ft::Vector<T> mylist)
{
	std::cout << GREEN"List output:\n" << RESET << std::endl;
	ft::printoVector(list);
	std::cout << GREEN"\nMy List output:\n" << RESET << std::endl;
	ft::printVector(mylist);
}

void	printVectorBanner()
{
	system("clear");
	printf(CYAN"\n\n \
			\t\t\t\t\t\t██╗   ╔██╗███████╗ ██████╗████████╗ ██████═╗██████╗  ████████╗███████╗███████╗████████╗\n \
			\t\t\t\t\t\t██╚╗ ╔╝██║██╔════╝██╔════╝╚══██╔══╝██╔═══██║██╔══██╗ ╚══██╔══╝██╔════╝██╔════╝╚══██╔══╝\n \
			\t\t\t\t\t\t ██║ ║██╔╝█████╗  ██║        ██║   ██║   ██║██████╔╝    ██║   █████╗  ███████╗   ██║\n \
			\t\t\t\t\t\t ███ ███║ ██╔══╝  ██║        ██║   ██║   ██║██╔══██╗    ██║   ██╔══╝  ╚════██║   ██║\n \
			\t\t\t\t\t\t  █████╔╝ ███████╗╚██████╗   ██║    ██████╔╝██║  ██║    ██║   ███████╗███████║   ██║\n \
			\t\t\t\t\t\t  ╚════╝  ╚══════╝ ╚═════╝   ╚═╝    ╚═════╝ ╚═╝  ╚═╝    ╚═╝   ╚══════╝╚══════╝   ╚═╝\n \
					\t\t\t\t\t\tby dalba-de			\n\n\033[0m");
}

void	checkVectorContinue()
{
	std::cout << std::endl;
	std::string input;
	while (input != "c")
	{
		std::cout << ORANGE"Press 'c' to continue..." << RESET << std::endl;
		std::getline(std::cin, input);
	}
	printVectorBanner();
}

void	vectorRelationalOperatorsTest()
{
	std::cout << RED"Starting relational operators test" << RESET << std::endl;
	std::cout << BLUE"\nCreating three int vector:\n" << RESET << std::endl;
	int	intsa[] = {10, 20, 30};
	int	intsb[] = {30, 20, 10};	
	std::vector<int> a(intsa, intsa + 3);
	std::vector<int> b(intsa, intsa + 3);
	std::vector<int> c(intsb, intsb + 3);
	ft::Vector<int> mya(intsa, intsa + 3);
	ft::Vector<int> myb(intsa, intsa + 3);
	ft::Vector<int> myc(intsb, intsb + 3);
	std::cout << BLUE"Print a: " << std::endl;
	printVectors(a, mya);
	std::cout << BLUE"\nPrint b: " << std::endl;
	printVectors(b, myb);
	std::cout << BLUE"\nPrint c: " << std::endl;
	printVectors(c, myc);

	std::cout << ORANGE"\n\nChecking relational operators:" << RESET << std::endl;
	std::cout << GREEN"\n\nVector output:" << RESET << std::endl;
	if (a==b) std::cout << "a and b are equal\n";
	if (b!=c) std::cout << "b and c are not equal\n";
	if (b<c) std::cout << "b is less than c\n";
	if (c>b) std::cout << "c is greater than b\n";
	if (a<=b) std::cout << "a is less than or equal to b\n";
	if (a>=b) std::cout << "a is greater than or equal to b\n";

	std::cout << GREEN"\n\nMy vector output:" << RESET << std::endl;
	if (mya==myb) std::cout << "a and b are equal\n";
	if (myb!=myc) std::cout << "b and c are not equal\n";
	if (myb<myc) std::cout << "b is less than c\n";
	if (myc>myb) std::cout << "c is greater than b\n";
	if (mya<=myb) std::cout << "a is less than or equal to b\n";
	if (mya>=myb) std::cout << "a is greater than or equal to b\n";

	std::cout << ORANGE"\n\nChecking swap() function (no member overload):" << RESET << std::endl;
	std::cout << BLUE"\nCreating two int vector:\n" << RESET << std::endl;
	std::vector<int> foo (3,100);
	std::vector<int> bar (5,200);
	ft::Vector<int> myfoo (3,100);
	ft::Vector<int> mybar (5,200);
	std::cout << BLUE"Print foo: " << std::endl;
	printVectors(foo, myfoo);
	std::cout << BLUE"\nPrint bar: " << std::endl;
	printVectors(bar, mybar);

	std::cout << BLUE"\nSwap vectors:\n" << RESET << std::endl;
	std::swap(foo,bar);
	ft::swap(myfoo, mybar);
	std::cout << BLUE"Print foo: " << std::endl;
	printVectors(foo, myfoo);
	std::cout << BLUE"\nPrint bar: " << std::endl;
	printVectors(bar, mybar);
	checkVectorContinue();
}

void	vectorModifiersTest()
{
	std::cout << RED"Starting modifiers test" << RESET << std::endl;
	std::cout << ORANGE"\n\nChecking assign() function:" << RESET << std::endl;
	int myints[]={1776,7,4};
	std::vector<int> first;
  	std::vector<int> second;
	ft::Vector<int> myfirst;
  	ft::Vector<int> mysecond;
	std::cout << BLUE"\nTrying fill assign() in first, with 7 ints of value 100:\n" << RESET << std::endl;
	first.assign(7, 100);
	myfirst.assign(7, 100);
	printVectors(first, myfirst);
	std::cout << BLUE"\nTrying range assign() in second, from array {1776, 7, 4}:\n" << RESET << std::endl;
	second.assign(myints, myints + 3);
	mysecond.assign(myints, myints + 3);
	printVectors(second, mysecond);
	std::cout << BLUE"\nReassign first with second:\n" << RESET << std::endl;
	std::cout << GREEN"Before reassign. first size: " << first.size() << ". myfirst size: " << myfirst.size() << RESET << std::endl;
	first.assign(second.begin(), second.end());
	myfirst.assign(mysecond.begin(), mysecond.end());
	std::cout << GREEN"After reassign. first size: " << first.size() << ". myfirst size: " << myfirst.size() << RESET << std::endl << std::endl;
	printVectors(first, myfirst);

	std::cout << ORANGE"\n\nChecking push_back() function:" << RESET << std::endl;
	std::cout << BLUE"\nAdd {42, 21} to first:\n" << RESET << std::endl;
	first.push_back(42);
	first.push_back(21);
	myfirst.push_back(42);
	myfirst.push_back(21);
	printVectors(first, myfirst);

	std::cout << ORANGE"\n\nChecking pop_back() function:" << RESET << std::endl;
	std::cout << BLUE"\nRemoving back to first:\n" << RESET << std::endl;
	first.pop_back();
	myfirst.pop_back();
	printVectors(first, myfirst);

	std::cout << ORANGE"\n\nChecking insert() function:" << RESET << std::endl;
	std::cout << BLUE"\nInserting '73' in the second position (single element insert):\n" << RESET << std::endl;
	std::vector<int>::iterator it = first.begin();
	it++;
	ft::Vector<int>::iterator myit = myfirst.begin();
	myit++;
	first.insert(it, 73);
	myfirst.insert(myit, 73);
	printVectors(first, myfirst);

	std::cout << BLUE"\nInserting 2 int of value '20' before '73' (fill insert):\n" << RESET << std::endl;
	first.insert(it, 2, 20);
	myfirst.insert(myit, 2, 20);
	printVectors(first, myfirst);

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
	printVectors(first, myfirst);

	std::cout << ORANGE"\n\nChecking erase() function:" << RESET << std::endl;
	std::cout << BLUE"\nErase second position (single erase):\n" << RESET << std::endl;
	it = first.begin();
	it++;
	myit = myfirst.begin();
	myit++; 
	first.erase(it);
	myfirst.erase(myit);
	printVectors(first, myfirst);

	std::cout << BLUE"\nErase from fourth position to eight position (range erase):\n" << RESET << std::endl;
	it = first.begin();
	std::advance(it,4);
	std::vector<int>::iterator it2 = first.begin();
	std::advance(it2, 8);
	myit = myfirst.begin();
	std::advance(myit, 4);
	ft::Vector<int>::iterator myit2 = myfirst.begin();
	std::advance(myit2, 8);
	first.erase(it, it2);
	myfirst.erase(myit, myit2);
	printVectors(first, myfirst);

	std::cout << ORANGE"\n\nChecking swap() function:" << RESET << std::endl;
	std::cout << BLUE"\nSwaping content from first to second:\n" << RESET << std::endl;
	
	std::cout << BLUE"Print first before swap: " << std::endl;
	printVectors(first, myfirst);
	std::cout << GREEN"\nfirst size: " << first.size() << ". myfirst size: " << myfirst.size() << RESET << std::endl;
	std::cout << BLUE"\nPrint second before swap: " << std::endl;
	printVectors(second, mysecond);
	std::cout << GREEN"\nsecond size: " << second.size() << ". mysecond size: " << mysecond.size() << RESET << std::endl << std::endl;

	first.swap(second);
	myfirst.swap(mysecond);
	std::cout << BLUE"Print first after swap: " << std::endl;
	printVectors(first, myfirst);
	std::cout << GREEN"\nfirst size: " << first.size() << ". myfirst size: " << myfirst.size() << RESET << std::endl;
	std::cout << BLUE"\nPrint second after swap: " << std::endl;
	printVectors(second, mysecond);
	std::cout << GREEN"\nsecond size: " << second.size() << ". mysecond size: " << mysecond.size() << RESET << std::endl << std::endl;

	std::cout << ORANGE"\n\nChecking clear() function:" << RESET << std::endl;
	first.clear();
	myfirst.clear();
	std::cout << BLUE"Print first after clear: " << std::endl;
	printVectors(first, myfirst);
	std::cout << GREEN"\nfirst size: " << first.size() << ". myfirst size: " << myfirst.size() << RESET << std::endl;
	checkVectorContinue();
}

void	vectorElementAccessTest()
{
	std::cout << RED"Starting element access test" << RESET << std::endl;
	std::cout << ORANGE"\n\nChecking operator[]:" << RESET << std::endl;
	std::cout << BLUE"\nCreating vector 10 zero-initialized ints:\n" << RESET << std::endl;
	std::vector<int> vector(10);
	ft::Vector<int> myvector(10);
	printVectors(vector, myvector);
	std::cout << BLUE"\nAssign values from 1 to 5:\n" << RESET << std::endl;
	for (unsigned i=0; i<5; i++)
	{
		vector[i]=i+1;
		myvector[i]=i+1;
	}
	printVectors(vector, myvector);

	std::cout << ORANGE"\n\nChecking at() function:" << RESET << std::endl;
	std::cout << BLUE"\nAssign values from 6 to 10:\n" << RESET << std::endl;
	for (unsigned i=5; i<10; i++)
	{
		vector.at(i)=i+1;
		myvector.at(i)=i+1;
	}
	printVectors(vector, myvector);

	std::vector<int> vector1;
	ft::Vector<int> myvector1;

	vector1.push_back(77);
	vector1.push_back(22);
	myvector1.push_back(77);
	myvector1.push_back(22);
	std::cout << BLUE"\nCreating vector with {77, 22}:\n" << RESET << std::endl;
	std::cout << GREEN"vector front() points to: " << RESET << vector1.front() << RESET << std::endl;
	std::cout << GREEN"vector back() points to: " << RESET << vector1.back() << RESET << std::endl;
	std::cout << std::endl;
	std::cout << GREEN"myvector front() points to: " << RESET << myvector1.front() << RESET << std::endl;
	std::cout << GREEN"myvector back() points to: " << RESET << myvector1.back() << RESET << std::endl;

	std::cout << BLUE"\nSubtracting back from front:\n" << RESET << std::endl;
	vector1.front() -= vector1.back();
	myvector1.front() -= myvector1.back();

	std::cout << GREEN"vector.front() is now " << RESET << vector1.front() << '\n' << RESET;
	std::cout << GREEN"myvector.front() is now " << RESET << myvector1.front() << '\n' << RESET;
	checkVectorContinue();
}

void	vectorCapacityTest()
{
	std::cout << RED"Starting capacity test" << RESET << std::endl;
	int myints[] = {16,2,77,29};
	std::vector<int> vector(myints, myints + 4);
	ft::Vector<int> myvector(myints, myints + 4);
	std::vector<int> vector1;
	ft::Vector<int> myvector1;
	std::cout << BLUE"\nCreating vector with {16,2,77,29} and empty vector1:\n" << RESET << std::endl;
	std::cout << "\n\033[1;33mPrinting filled vector:\n" << RESET << std::endl;
	printVectors(vector, myvector);
	std::cout << "\n\033[1;33mPrinting empty vector:\n" << RESET << std::endl;
	printVectors(vector1, myvector1);

	std::cout << BLUE"\nChecking empty() function with vector:\n" << RESET << std::endl;
	if (vector.empty())
		std::cout << GREEN"vector is empty" << RESET << std::endl;
	else
		std::cout << GREEN"vector is not empty" << RESET << std::endl;
	if (myvector.empty())
		std::cout << GREEN"myvector is empty" << RESET << std::endl;
	else
		std::cout << GREEN"myvector is not empty" << RESET << std::endl;

	std::cout << BLUE"\nChecking empty() function with vector1:\n" << RESET << std::endl;
	if (vector1.empty())
		std::cout << GREEN"vector1 is empty" << RESET << std::endl;
	else
		std::cout << GREEN"vector1 is not empty" << RESET << std::endl;
	if (myvector1.empty())
		std::cout << GREEN"myvector1 is empty" << RESET << std::endl;
	else
		std::cout << GREEN"myvector1 is not empty" << RESET << std::endl;

	std::cout << BLUE"\nChecking size() function:\n" << RESET << std::endl;
	std::cout << GREEN"vector size: " << RESET << vector.size() << GREEN". vector1 size: " << RESET << vector1.size() << RESET << std::endl;
	std::cout << GREEN"myvector size: " << RESET << myvector.size() << GREEN". myvector1 size: " << RESET << myvector1.size() << RESET << std::endl;

	std::cout << BLUE"\nChecking capacity() function:\n" << RESET << std::endl;
	std::cout << GREEN"vector capacity: " << RESET << vector.capacity() << GREEN". vector1 capacity: " << RESET << vector1.capacity() << RESET << std::endl;
	std::cout << GREEN"myvector capacity: " << RESET << myvector.capacity() << GREEN". myvector1 capacity: " << RESET << myvector1.capacity() << RESET << std::endl;
	std::cout << ORANGE"Add element '42' to vector: " << RESET << std::endl;
	vector.push_back(42);
	myvector.push_back(42);
	std::cout << GREEN"vector size: " << RESET << vector.size() << RESET << std::endl;
	std::cout << GREEN"vector capacity: " << RESET << vector.capacity() << RESET << std::endl;
	std::cout << GREEN"myvector size: " << RESET << myvector.size() << RESET << std::endl;
	std::cout << GREEN"myvector capacity: " << RESET << myvector.capacity() << RESET << std::endl;
	std::cout << ORANGE"Add element '87' to vector: " << RESET << std::endl;
	vector.push_back(87);
	myvector.push_back(87);
	std::cout << GREEN"vector size: " << RESET << vector.size() << RESET << std::endl;
	std::cout << GREEN"vector capacity: " << RESET << vector.capacity() << RESET << std::endl;
	std::cout << GREEN"myvector size: " << RESET << myvector.size() << RESET << std::endl;
	std::cout << GREEN"myvector capacity: " << RESET << myvector.capacity() << RESET << std::endl;
	std::cout << ORANGE"Add element '99' to vector: " << RESET << std::endl;
	vector.push_back(99);
	myvector.push_back(99);
	std::cout << GREEN"vector size: " << RESET << vector.size() << RESET << std::endl;
	std::cout << GREEN"vector capacity: " << RESET << vector.capacity() << RESET << std::endl;
	std::cout << GREEN"myvector size: " << RESET << myvector.size() << RESET << std::endl;
	std::cout << GREEN"myvector capacity: " << RESET << myvector.capacity() << RESET << std::endl;
	std::cout << ORANGE"Add element '134' to vector: " << RESET << std::endl;
	vector.push_back(134);
	myvector.push_back(134);
	std::cout << GREEN"vector size: " << RESET << vector.size() << RESET << std::endl;
	std::cout << GREEN"vector capacity: " << RESET << vector.capacity() << RESET << std::endl;
	std::cout << GREEN"myvector size: " << RESET << myvector.size() << RESET << std::endl;
	std::cout << GREEN"myvector capacity: " << RESET << myvector.capacity() << RESET << std::endl;
	std::cout << ORANGE"Add element '13' to vector: " << RESET << std::endl;
	vector.push_back(13);
	myvector.push_back(13);
	std::cout << GREEN"vector size: " << RESET << vector.size() << RESET << std::endl;
	std::cout << GREEN"vector capacity: " << RESET << vector.capacity() << RESET << std::endl;
	std::cout << GREEN"myvector size: " << RESET << myvector.size() << RESET << std::endl;
	std::cout << GREEN"myvector capacity: " << RESET << myvector.capacity() << RESET << std::endl;
	std::cout << ORANGE"Print vector: " << RESET << std::endl;
	printVectors(vector, myvector);

	std::cout << BLUE"\nChecking resize() function:\n" << RESET << std::endl;
	std::cout << ORANGE"Resize vector to 5: " << RESET << std::endl;
	vector.resize(5);
	myvector.resize(5);
	printVectors(vector, myvector);
	std::cout << ORANGE"\nResize vector to 8 with ints of value '100': " << RESET << std::endl;
	vector.resize(8, 100);
	myvector.resize(8, 100);
	printVectors(vector, myvector);
	std::cout << ORANGE"\nResize vector to 17: " << RESET << std::endl;
	vector.resize(17);
	myvector.resize(17);
	printVectors(vector, myvector);
	std::cout << GREEN"\nvector size: " << RESET << vector.size() << RESET << std::endl;
	std::cout << GREEN"vector capacity: " << RESET << vector.capacity() << RESET << std::endl;
	std::cout << GREEN"myvector size: " << RESET << myvector.size() << RESET << std::endl;
	std::cout << GREEN"myvector capacity: " << RESET << myvector.capacity() << RESET << std::endl;

	std::cout << BLUE"\nChecking reserve() function:\n" << RESET << std::endl;
	std::cout << ORANGE"Reserve 32 in vector: " << RESET << std::endl;
	vector.reserve(32);
	myvector.reserve(32);
	printVectors(vector, myvector);
	std::cout << GREEN"\nvector size: " << RESET << vector.size() << RESET << std::endl;
	std::cout << GREEN"vector capacity: " << RESET << vector.capacity() << RESET << std::endl;
	std::cout << GREEN"myvector size: " << RESET << myvector.size() << RESET << std::endl;
	std::cout << GREEN"myvector capacity: " << RESET << myvector.capacity() << RESET << std::endl;

	std::cout << BLUE"\nChecking max_size() function:\n" << RESET << std::endl;
	std::cout << ORANGE"Checking with int: " << RESET << std::endl;
	std::cout << GREEN"vector<int> max_size: " << RESET << vector.max_size() << RESET << std::endl;
	std::cout << GREEN"myvector<int> max_size: " << RESET << myvector.max_size() << RESET << std::endl;
	std::vector<std::string> vector2;
	ft::Vector<std::string> myvector2;
	std::cout << ORANGE"\nChecking with std::string: " << RESET << std::endl;
	std::cout << GREEN"vector<std::string> max_size: " << RESET << vector2.max_size() << RESET << std::endl;
	std::cout << GREEN"myvector<std::string> max_size: " << RESET << myvector2.max_size() << RESET << std::endl;
	std::vector<vectorfoo*> vector3;
	ft::Vector<vectorfoo*> myvector3;
	std::cout << ORANGE"\nChecking with another class: " << RESET << std::endl;
	std::cout << GREEN"vector<foo*> max_size: " << RESET << vector3.max_size() << RESET << std::endl;
	std::cout << GREEN"myvector<foo*> max_size: " << RESET << myvector3.max_size() << RESET << std::endl;
	checkVectorContinue();
}

void	constVectorIteratorsTest(const std::vector<int>& vector, const ft::Vector<int>& myvector)
{
	std::vector<int>::const_iterator cit = vector.begin();
	ft::Vector<int>::const_iterator mycit = myvector.begin();
	std::vector<int>::const_reverse_iterator rcit = vector.rbegin();
	ft::Vector<int>::const_reverse_iterator myrcit = myvector.rbegin();
	std::cout << BLUE"\nIterating from begin() to end() with const iterators:\n" << RESET << std::endl;
	std::cout << GREEN"In vector: \n" << RESET;
	for (; cit != vector.end(); cit++)
		std::cout << *cit << ' ';
	std::cout << RESET << std::endl;
	std::cout << GREEN"In myvector: \n" << RESET;
	for (; mycit != myvector.end(); mycit++)
		std::cout << *mycit << ' ';
	std::cout << RESET << std::endl;

	std::cout << BLUE"\nIterating from rbegin() to rend() with const iterators:\n" << RESET << std::endl;
	std::cout << GREEN"In vector: \n" << RESET;
	for (; rcit != vector.rend(); rcit++)
		std::cout << *rcit << ' ';
	std::cout << RESET << std::endl;
	std::cout << GREEN"In myvector: \n" << RESET;
	for (; myrcit != myvector.rend(); myrcit++)
		std::cout << *myrcit << ' ';
	std::cout << RESET << std::endl;
}

void	vectorIteratorsTest()
{
	std::cout << RED"Starting iterators test" << RESET << std::endl;
	int myints[] = {16,2,77,29};
	std::vector<int> vector(myints, myints + 4);
	ft::Vector<int> myvector(myints, myints + 4);
	std::cout << BLUE"\nCreating vector with {16,2,77,29}:\n" << RESET << std::endl;
	std::vector<int>::iterator it = vector.begin();
	ft::Vector<int>::iterator	myit = myvector.begin();
	std::cout << GREEN"vector begin() points to: " << RESET << *it << std::endl;
	std::cout << GREEN"myvector begin() points to: " << RESET << *myit << std::endl;
	std::cout << std::endl;

	std::vector<int>::reverse_iterator rit = vector.rbegin();
	ft::Vector<int>::reverse_iterator myrit = myvector.rbegin();
	std::cout << GREEN"vector rbegin() points to: " << RESET << *rit << std::endl;
	std::cout << GREEN"myvector rbegin() points to: " << RESET << *myrit << std::endl;
	std::cout << std::endl;

	std::cout << BLUE"\nIterating from begin() to end():\n" << RESET << std::endl;
	std::cout << GREEN"In vector: \n" << RESET;
	for (; it != vector.end(); it++)
		std::cout << *it << ' ';
	std::cout << RESET << std::endl;
	std::cout << GREEN"In myvector: \n" << RESET;
	for (; myit != myvector.end(); myit++)
		std::cout << *myit << ' ';
	std::cout << RESET << std::endl;

	std::cout << BLUE"\nIterating from rbegin() to rend():\n" << RESET << std::endl;
	std::cout << GREEN"In vector: \n" << RESET;
	for (; rit != vector.rend(); rit++)
		std::cout << *rit << ' ';
	std::cout << RESET << std::endl;
	std::cout << GREEN"In myvector: \n" << RESET;
	for (; myrit != myvector.rend(); myrit++)
		std::cout << *myrit << ' ';
	std::cout << RESET << std::endl;

	std::cout << BLUE"\nTrying with const iterators:\n" << RESET << std::endl;
	constVectorIteratorsTest(vector, myvector);
	checkVectorContinue();
}

void	vectorConstructorsTest()
{
	std::cout << RED"Starting constructor test" << RESET << std::endl;
	std::cout << BLUE"Trying fill constructor with (4, 100):\n" << RESET << std::endl;
	std::vector<int> first(4, 100);
	ft::Vector<int> myfirst(4, 100);
	printVectors(first, myfirst);

	int myints[] = {16,2,77,29};
	std::cout << BLUE"\nTrying construct from array {16,2,77,29}(iterator range):\n" << RESET << std::endl;
	std::vector<int> second(myints, myints + 4);
	ft::Vector<int> mysecond(myints, myints + 4);
	printVectors(second, mysecond);

	std::cout << BLUE"\nTrying to construct as a copy of second:\n" << RESET << std::endl;
	std::vector<int> third(second);
	ft::Vector<int> mythird(mysecond);
	printVectors(third, mythird);

	std::cout << BLUE"\nTrying operator =. First create a list of 5 zero-initialized ints:\n" << RESET << std::endl;
	std::vector<int> fourth(5);
	ft::Vector<int> myfourth(5);
	printVectors(fourth, myfourth);

	std::cout << BLUE"\nThen use operator = to copy third:\n" << RESET << std::endl;
	fourth = third;
	myfourth = mythird;
	printVectors(fourth, myfourth);
	checkVectorContinue();
}

int		testVector()
{
	printVectorBanner();
	vectorConstructorsTest();
	vectorIteratorsTest();
	vectorCapacityTest();
	vectorElementAccessTest();
	vectorModifiersTest();
	vectorRelationalOperatorsTest();
	return 0;
}