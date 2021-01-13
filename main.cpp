#include <iostream>
#include <iomanip>
#include <list>
#include "List/List.hpp"
#include <vector>
#include <cmath>

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

template <class T>
void	printList(ft::List<T> list)
{
	typename ft::List<T>::iterator it;

	it = list.begin();
	for (it = list.begin() ; it != list.end(); it++)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

int main()
{
	/*std::list<int> list;

	for (int i = 0; i < 20; i++)
	{
		list.push_back(i);
	}

	std::list<int>::iterator it = list.begin();
	
	for ( ; it != list.end(); it++)
	{
		*it = 0;
		std::cout << *it << std::endl;
	}*/

	//ft::List<int> list;

	/*
	** --------------- MODIFIERS ----------------
	*/

	/*for (int i = 1; i <= 5; i++)
		list.push_back(i);*/

	/*
	** --------------- ITERATORS ----------------
	*/

	/*ft::List<int>::iterator it = list.begin();


	for ( ; it != list.end(); it++)
	{
		std::cout << *it << " ";
	}

	std::cout << std::endl;

	ft::List<int>::const_reverse_iterator rit = list.rbegin();

	for ( ; rit != list.rend(); rit++)
	{
		std::cout << *rit << " ";
	}

	std::cout << std::endl;*/

	/*
	** --------------- CAPACITY ----------------
	*/

	/*if (!list.empty())
		std::cout << "Está vacio" << std::endl;
	else
	{
		std::cout << "Está lleno" << std::endl;
	}
	
	std::cout << "El contenedor tiene tamaño: " << list.size() << std::endl;

	std::cout << "El tamaño máximo del contenedor es: " << list.max_size() << std::endl;*/

	/*
	** ------------ ELEMENT ACCESS -------------
	*/

	/*std::cout << list.front() << std::endl;

	std::cout << list.back() << std::endl;*/
	
	/*
	** -------------- MODIFIERS ---------------
	*/

	/*list.pop_front();
	list.pop_back();

	it = list.begin();

	for ( ; it != list.end(); it++)
	{
		std::cout << *it << " ";
	}

	std::cout << std::endl;

	for (int i = 0; i <= 5; i++)
	{
		list.push_front(i*10);
		list.push_back(i*5);
	}

	it = list.begin();

	for ( ; it != list.end(); it++)
	{
		std::cout << *it << " ";
	}

	std::cout << std::endl;

	list.clear();

	std::cout << list.size() << std::endl;

	for (int i = 1; i <= 5; i++)
		list.push_back(i);

	it = list.begin();
	it++;


	ft::List<int>::iterator it = list.begin();
	it++;
	list.insert(it, 4, 20);

	printList(list);

	it = list.begin();
	it++;

	ft::List<int> vector;

	for (int i = 1; i <=5; i++)
		vector.push_back(i*10);
	
	ft::List<int>::iterator vic = vector.begin();
	ft::List<int>::iterator vicend = vector.end();

	list.insert(it, vic, vicend);

	it = list.begin();

	for ( ; it != list.end(); it++)
	{
		std::cout << *it << " ";
	}

	std::cout << std::endl;

	it = list.begin();
	it++;
	ft::List<int>::iterator it2 = list.end();

	for (int i = 0; i < 4; i++)
		it2--;

	std::cout << *(list.erase(it, it2)) << std::endl;

	it = list.begin();
	for ( ; it != list.end(); it++)
	{
		std::cout << *it << " ";
	}

	std::cout << std::endl;

	ft::List<int> list2;

	for (int i = 1; i <= 5; i++)
		list2.push_back(i*10);

	printList(list);
	printList(list2);

	list.swap(list2);

	printList(list);
	printList(list2);*/

	/*
	** -------------- CONSTRUCTORS ---------------
	*/

	/*ft::List<int> list(8, 42);

	printList(list);

	std::vector<int> vector;

	for (int i = 1; i <= 5; i++)
		vector.push_back(i*10);

	ft::List<int> list2(vector.begin(), vector.end());

	printList(list2);*/

	/*
	** -------------- OPERATIONS ---------------
	*/

	//SPLICE
	/*ft::List<int> list1, list2;

	for (int i = 1; i < 5; i++)
		list1.push_back(i);

	for (int i = 1; i <= 3; i++)
		list2.push_back(i*10);

	ft::List<int>::iterator it = list1.begin();
	it++;

	list1.splice(it, list2);

	printList(list1);
	printList(list2);

	list2.splice(list2.begin(), list1, it);

	printList(list1);
	printList(list2);

	it = list1.begin();

	while (*it != 30)
		it++;
	
	list1.splice(list1.begin(), list1, it, list1.end());

	printList(list1);
	printList(list2);*/

	//REMOVE
	/*int myints[]= {17,89,7,14};
	ft::List<int> list (myints, myints + 4);

	list.remove(89);

	printList(list);*/

	//REMOVE IF	
	/*int myints[]= {15,36,7,17,20,39,4,1};
	ft::List<int> list (myints,myints+8);   // 15 36 7 17 20 39 4 1

	list.remove_if (single_digit);           // 15 36 17 20 39

	list.remove_if (is_odd());               // 36 20

	printList(list);*/

	//UNIQUE
	/*double mydoubles[]={ 2.72,  3.14, 12.15, 12.77, 12.77, 12.77,
                		15.3,  72.25, 72.25, 73.0,  73.35 };
  	ft::List<double> list (mydoubles,mydoubles+11);

	list.unique();

	printList(list);

	list.unique(same_integral_part);

	printList(list);

	list.unique(is_near());

	printList(list);*/

	//MERGE
	/*ft::List<double> first, second;

	first.push_back (2.2);
	first.push_back (2.9);
	first.push_back (3.1);

	second.push_back (1.4);
	second.push_back (3.7);
	second.push_back (7.1);

	first.merge(second);

	printList(first);*/

	// (second is now empty)

	/*second.push_back (2.1);

	first.merge(second,mycomparison);

	printList(first);*/

	//SORT
	/*ft::List<std::string> list;
	ft::List<std::string>::iterator it;
	list.push_back ("one");
	list.push_back ("two");
	list.push_back ("Three");

	list.sort();

	printList(list);

	list.sort(compare_nocase);

	printList(list);*/

	//REVERSE
	/*ft::List<int> list;

	for (int i=1; i<10; ++i) list.push_back(i);

	printList(list);

	list.reverse();

	printList(list);*/

	/*
	** --------- RELATIONAL OPERATORS ----------
	*/

	/*int myints[]= {10,20,30};
	ft::List<int> list1(myints, myints + 3);
	ft::List<int> list2(myints, myints + 3);
	int myints2[]= {30,20,10};
	ft::List<int> list3(myints2, myints2 + 3);*/
	

	//EQUAL
	
	/*if (list1 == list2)
		std::cout << "ambas listas son iguales" << std::endl;
	else
		std::cout << "ambas listas son diferentes" << std::endl;*/
	
	//NOT EQUAL

	/*if (list1 != list2)
		std::cout << "ambas listas son diferentes" << std::endl;
	else
		std::cout << "ambas listas son iguales" << std::endl;*/

	//LEXICOGRAPHICAL COMPARE (LESS-THAN)

	/*if (list1 < list2)
		std::cout << "list1 es menor que list2" << std::endl;
	else
		std::cout << "list1 no es menor que list2" << std::endl;*/
	
	//GREATER-THAN

	/*if (list3 > list2)
		std::cout << "list3 es mayor que list2" << std::endl;
	else
		std::cout << "list3 no es mayor que list2" << std::endl;*/

	//LESS-THAN OR EQUAL

	/*if (list1 <= list2)
		std::cout << "list1 es menor o igual que list2" << std::endl;
	else
		std::cout << "list1 es mayor que list2" << std::endl;*/
	
	//GREATER-THAN OR EQUAL

	/*if (list1 >= list2)
		std::cout << "list1 es mayor o igual que list2" << std::endl;
	else
		std::cout << "list1 es menor que list2" << std::endl;*/
	
	//SWAP (LIST OVERLOAD)

	ft::List<int> foo (3,100);  
  	ft::List<int> bar (5,200);

	std::cout << "foo contains: ";
	printList(foo);
	std::cout << "bar contains: ";
	printList(bar);

	ft::swap(foo, bar);

	std::cout << "foo contains: ";
	printList(foo);
	std::cout << "bar contains: ";
	printList(bar);

	return 0;
}