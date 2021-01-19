#include <iostream>
#include <string>
#include "Vector.hpp"
#include "../Tools/Shared_functions.hpp"
#include <vector>

int main()
{
	std::cout << "\n\033[1;31m Vector Original\n \033[0m" << std::endl;

	std::vector<int> ovector(5, 42);

	ft::printoVector(ovector);

	std::cout << ovector.empty() << std::endl;
	std::cout << ovector.size() << std::endl;
	std::cout << ovector.capacity() << std::endl;

	ovector.reserve(10);

	ft::printoVector(ovector);
	std::cout << ovector.capacity() << std::endl;

	for (int i = 0; i <= 5; i++)
		ovector.push_back(55);
	ft::printoVector(ovector);
	std::cout << ovector.capacity() << std::endl;

	for (int i = 0; i <= 10; i++)
		ovector.push_back(66);
	ft::printoVector(ovector);
	std::cout << ovector.capacity() << std::endl;	

	std::cout << "\n\033[1;33m My Vector\n \033[0m" << std::endl;

	ft::Vector<int> vector(5, 42);

	ft::printVector(vector);

	std::cout << vector.empty() << std::endl;
	std::cout << vector.size() << std::endl;
	std::cout << vector.capacity() << std::endl;

	vector.reserve(10);

	ft::printVector(vector);
	std::cout << vector.capacity() << std::endl;

	for (int i = 0; i <= 5; i++)
		vector.push_back(55);
	ft::printVector(vector);
	std::cout << vector.capacity() << std::endl;

	for (int i = 0; i <= 10; i++)
		vector.push_back(66);
	ft::printVector(vector);
	std::cout << vector.capacity() << std::endl;


}