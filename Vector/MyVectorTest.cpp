#include <iostream>
#include <string>
#include "Vector.hpp"
#include "../Tools/Shared_functions.hpp"
#include <vector>

int main()
{
	std::cout << "\n\033[1;31m Vector Original\n \033[0m" << std::endl;

	std::vector<int> ovec;

	for (int i = 1; i <= 10; i++)
		ovec.push_back(i);
	ft::printoVector(ovec);

	std::vector<int>::reverse_iterator orit = ovec.rend();

	orit--;
	std::cout << *orit << std::endl;
	/*ovec.erase(ovec.begin() + 5);
	ft::printoVector(ovec);*/

	std::cout << "\n\033[1;33m My Vector\n \033[0m" << std::endl;

	ft::Vector<int> vec;

	for (int i = 1; i <= 10; i++)
		vec.push_back(i);
	ft::printVector(vec);

	ft::Vector<int>::reverse_iterator rit = vec.rend();

	rit--;
	std::cout << *rit << std::endl;
	/*for ( ; rit != vec.end(); rit++)
		std::cout << *rit << ' ';
	std::cout << std::endl;*/
	
}