#include <vector>
#include <iostream>
#include <string>

int main()
{
	std::vector<int> vector;

	for (int i = 1; i <= 5; i++)
		vector.push_back(i);

	std::vector<int>::iterator it = vector.begin();

	for ( ; it != vector.end(); it++)
		std::cout << *it << ' ';
	std::cout << std::endl;

	std::vector<int>::reverse_iterator rit = vector.rbegin();

	for ( ; rit != vector.rend(); rit++)
		std::cout << *rit << ' ';
	std::cout << std::endl;

	std::vector<int>::iterator pit = vector.begin();

	pit[2] = 9;

	for ( ; pit != vector.end(); pit++)
		std::cout << *pit << ' ';
	std::cout << std::endl;
	
	return 0;
}