#include <iostream>
#include <string>
#include <set>
#include "Set.hpp"

int	main()
{
	std::cout << "\n\033[1;31m Set Original\n \033[0m" << std::endl;

	//int myints[]= {10,20,30,40,50};

	std::set<int>	set;

	set.insert(6);
	set.insert(2);
	set.insert(1);
	set.insert(9);
	set.insert(8);
	set.insert(15);
	set.insert(13);
	set.insert(11);
	set.insert(18);

	for (std::set<int>::iterator it = set.begin(); it != set.end(); it++)
		std::cout << *it << ' ';
	std::cout << std::endl << std::endl;

	std::cout << "Lower bound: " << *(set.equal_range(9)).first << std::endl;
	std::cout << "Upper bound: " << *(set.equal_range(9)).second << std::endl;

	/*-----------------------------------------------------------------*/
	/*-----------------------------------------------------------------*/
	/*-----------------------------------------------------------------*/
	/*-----------------------------------------------------------------*/

	std::cout << "\n\033[1;33m My Set\n \033[0m" << std::endl;

	ft::Set<int>	myset;

	myset.insert(6);
	myset.insert(2);
	myset.insert(1);
	myset.insert(9);
	myset.insert(8);
	myset.insert(15);
	myset.insert(13);
	myset.insert(11);
	myset.insert(18);

	for (ft::Set<int>::iterator myit = myset.begin(); myit != myset.end(); myit++)
		std::cout << *myit << ' ';
	std::cout << std::endl << std::endl;

	std::cout << "Lower bound: " << *(myset.equal_range(9)).first << std::endl;
	std::cout << "Upper bound: " << *(myset.equal_range(9)).second << std::endl;

	return 0;
}