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

/*int		testVector()
{
	printVectorBanner();
	vectorConstructorsTest();
	return 0;
}*/

int		main()
{
	printVectorBanner();
	vectorConstructorsTest();
	return 0;
}