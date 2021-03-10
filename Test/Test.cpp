# include <iostream>
# include <iomanip>
# include <string>
# include "Test.hpp"
# define RESET		"\033[0m"
# define RED		"\033[1;31m"
# define GREEN		"\033[1;32m"
# define ORANGE		"\033[1;33m"
# define PURPLE		"\033[35m"
# define CYAN		"\033[1;36m"
# define BLUE       "\033[1;34m"
# define GREY		"\033[1;30m"
# define UNDER		"\033[4m"

void	banner()
{
	std::cout << std::endl;
	std::cout << PURPLE"Please press the key of the desired test or 'EXIT':" << RESET << std::endl << std::endl;
	std::cout << std::setw(15) << "\033[1;35mKey" << std::setw(15) << "Test" << RESET << std::endl;
	std::cout << CYAN" ___________________________ " << std::endl;
	std::cout << CYAN"|                           |" << std::endl;
	std::cout << CYAN"|" << std::setw(12) << GREEN << "L" << std::setw(18) << "List Test" << std::setw(10) << CYAN << "|\n";
	std::cout << CYAN"|" << std::setw(12) << GREEN << "V" << std::setw(18) << "Vector Test" << std::setw(10) << CYAN << "|\n";
	std::cout << CYAN"|" << std::setw(12) << GREEN << "M" << std::setw(18) << "Map Test" << std::setw(10) << CYAN << "|\n";
	std::cout << CYAN"|" << std::setw(12) << GREEN << "Q" << std::setw(18) << "Queue Test" << std::setw(10) << CYAN << "|\n";
	std::cout << CYAN"|" << std::setw(12) << GREEN << "S" << std::setw(18) << "Stack Test" << std::setw(10) << CYAN << "|\n";
	std::cout << CYAN"|" << std::setw(12) << GREEN << "MM" << std::setw(17) << "Multimap Test" << std::setw(10) << CYAN << "|\n";
	std::cout << CYAN"|" << std::setw(12) << GREEN << "ST" << std::setw(17) << "Set Test" << std::setw(10) << CYAN << "|\n";
	std::cout << CYAN"|___________________________|" << std::endl;
}

int main()
{
	system("clear");
	std::cout << std::endl;
	std::cout << GREEN"*********************************" << std::endl;
	std::cout << "* Welcome to ft_containers Test *" << std::endl;
	std::cout << "*********************************" << std::endl << RESET << std::endl;
	std::string input;

	while (1)
	{
		banner();
		std::cout << PURPLE"\nEnter your key: " << RESET;
		std::getline(std::cin, input);
		if (input == "L")
		{
			testList();
			system("clear");
		}
		else if (input == "V")
		{
			testVector();
			system("clear");
		}
		else if (input == "M")
		{
			testMap();
			system("clear");
		}
		else if (input == "Q")
		{
			testQueue();
			system("clear");
		}
		else if (input == "S")
		{
			testStack();
			system("clear");
		}
		else if (input == "MM")
		{
			testMultimap();
			system("clear");
		}
		else if (input == "ST")
		{
			testSet();
			system("clear");
		}
		else if(input == "EXIT")
			break ;
		else
			std::cout << RED"\nInvalid input" << RESET << std::endl;
	}
	
	return 0;
}

