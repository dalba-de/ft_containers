#include <iostream>
#include <iomanip>
#include <list>
#include "List.hpp"
#include <vector>

void	printList(ft::List<int> list)
{
	ft::List<int>::iterator it;

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

	ft::List<int> list;

	/*
	** --------------- MODIFIERS ----------------
	*/

	for (int i = 1; i <= 5; i++)
		list.push_back(i);

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

	list.insert(it, (std::size_t)4, 20);

	it = list.begin();

	for (it = list.begin() ; it != list.end(); it++)
	{
		std::cout << *it << " ";
	}

	std::cout << std::endl;

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

	std::cout << std::endl;*/

	ft::List<int> list2;

	for (int i = 1; i <= 5; i++)
		list2.push_back(i*10);

	printList(list);
	printList(list2);

	list.swap(list2);

	printList(list);
	printList(list2);

	return 0;
}