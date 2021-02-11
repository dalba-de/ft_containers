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

	std::vector<int> ovec;

	for (int i = 1; i <= 10; i++)
		ovec.push_back(i);
	ft::printoVector(ovec);

	std::cout << *(ovec.erase(ovec.begin())) << std::endl;
	std::cout << ovec.size() << std::endl;
	ft::printoVector(ovec);

	std::cout << "\n\033[1;33m My Vector\n \033[0m" << std::endl;

	ft::Vector<int> vec;

	for (int i = 1; i <= 10; i++)
		vec.push_back(i);
	ft::printVector(vec);

	std::cout << *(vec.erase(vec.begin())) << std::endl;
	std::cout << vec.size() << std::endl;
	ft::printVector(vec);
}