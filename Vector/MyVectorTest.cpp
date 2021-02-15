#include <iostream>
#include <string>
#include "Vector.hpp"
#include "../Tools/Shared_functions.hpp"
#include <vector>

void	pruebaprint(ft::Vector<int> const & vec)
{
	ft::Vector<int>::const_iterator it = vec.begin();

	for ( ; it != vec.end(); it++)
		std::cout << *it << ' ';
	std::cout << std::endl;
}

int main()
{
	std::cout << "\n\033[1;31m Vector Original\n \033[0m" << std::endl;

	std::vector<bool> mask;

	mask.push_back(true);
	mask.push_back(false);
	mask.push_back(false);
	mask.push_back(true);

	std::cout << std::boolalpha;
	ft::printoVector(mask);
	
	std::cout << "\n\033[1;33m My Vector\n \033[0m" << std::endl;

	ft::Vector<bool> vec;
		
	vec.push_back(true);
	vec.push_back(false);
	vec.push_back(false);
	vec.push_back(true);

	std::cout << std::boolalpha;
	ft::printVector(vec);
}