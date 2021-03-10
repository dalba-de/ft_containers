#include <stack>
#include "../includes/Stack/Stack.hpp"
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

void	printstackBanner()
{
	system("clear");
	printf(CYAN"\n\n \
			\t\t\t\t\t\t ██████═╗██╗  ██ ███████╗██╗  ██ ███████╗ ████████╗███████╗███████╗████████╗\n \
			\t\t\t\t\t\t██╔═══██║██║  ██║██╔════╝██║  ██║██╔════╝ ╚══██╔══╝██╔════╝██╔════╝╚══██╔══╝\n \
			\t\t\t\t\t\t██║   ██║██║  ██║█████╗  ██║  ██║█████╗      ██║   █████╗  ███████╗   ██║\n \
			\t\t\t\t\t\t██║   ██║██║  ██║██╔══╝  ██║  ██║██╔══╝      ██║   ██╔══╝  ╚════██║   ██║\n \
			\t\t\t\t\t\t ██████╔╝ █████╔╝███████╗ █████╔╝███████╗    ██║   ███████╗███████║   ██║\n \
			\t\t\t\t\t\t ╚═════╝  ╚════╝ ╚══════╝ ╚════╝ ╚══════╝    ╚═╝   ╚══════╝╚══════╝   ╚═╝\n \
					\t\t\t\t\t\tby dalba-de			\n\n\033[0m");
}

void	checkstackContinue()
{
	std::cout << std::endl;
	std::string input;
	while (input != "c")
	{
		std::cout << ORANGE"Press 'c' to continue..." << RESET << std::endl;
		std::getline(std::cin, input);
	}
	printstackBanner();
}

void	stackRelationalOperatorsTest()
{
	std::cout << RED"Starting relational operators test" << RESET << std::endl;
	std::cout << BLUE"\nCreating two int stacks:\n" << RESET << std::endl;
	std::stack<int>	foo;
	ft::Stack<int>	myfoo;
	std::stack<int>	bar;
	ft::Stack<int>	mybar;
	foo.push(21);
	foo.push(12);
	myfoo.push(21);
	myfoo.push(12);
	bar.push(32);
	bar.push(25);
	mybar.push(32);
	mybar.push(25);

	std::cout << ORANGE"\n\nChecking relational operators:" << RESET << std::endl;
	std::cout << GREEN"\n\nstack output:" << RESET << std::endl;
	if (foo==bar) std::cout << "foo and bar are equal\n";
	if (foo!=bar) std::cout << "foo and bar are not equal\n";
	if (foo< bar) std::cout << "foo is less than bar\n";
	if (foo> bar) std::cout << "foo is greater than bar\n";
	if (foo<=bar) std::cout << "foo is less than or equal to bar\n";
	if (foo>=bar) std::cout << "foo is greater than or equal to bar\n";

	std::cout << GREEN"\n\nMystack output:" << RESET << std::endl;
	if (myfoo==mybar) std::cout << "myfoo and mybar are equal\n";
	if (myfoo!=mybar) std::cout << "myfoo and mybar are not equal\n";
	if (myfoo< mybar) std::cout << "myfoo is less than mybar\n";
	if (myfoo> mybar) std::cout << "myfoo is greater than mybar\n";
	if (myfoo<=mybar) std::cout << "myfoo is less than or equal to mybar\n";
	if (myfoo>=mybar) std::cout << "myfoo is greater than or equal to mybar\n";
	checkstackContinue();
}

void	stackModifiersTest()
{
	std::cout << RED"Starting modifiers test" << RESET << std::endl;
	std::cout << ORANGE"\n\nChecking push() and pop() function:" << RESET << std::endl;
	std::cout << BLUE"\nCreating stack with {42, 37, 5} values:\n" << RESET << std::endl;
	std::stack<int>	stack;
	ft::Stack<int>	mystack;

	stack.push(42);
	stack.push(37);
	stack.push(5);
	mystack.push(42);
	mystack.push(37);
	mystack.push(5);

	std::cout << BLUE"\nPop next element:\n" << RESET << std::endl;
	stack.pop();
	mystack.pop();
	std::cout << GREEN"stack top() points to: " << RESET << stack.top() << RESET << std::endl;
	std::cout << GREEN"mystack top() points to: " << RESET << mystack.top() << RESET << std::endl;
	checkstackContinue();
}

void	stackElementAccessTest()
{
	std::cout << RED"Starting element access test" << RESET << std::endl;
	std::cout << ORANGE"\n\nChecking top() function:" << RESET << std::endl;
	std::cout << BLUE"\nCreating stack with {42, 37, 5} values:\n" << RESET << std::endl;
	std::stack<int>	stack;
	ft::Stack<int>	mystack;

	stack.push(42);
	stack.push(37);
	stack.push(5);
	mystack.push(42);
	mystack.push(37);
	mystack.push(5);

	std::cout << GREEN"stack top() points to: " << RESET << stack.top() << RESET << std::endl;
	std::cout << std::endl;
	std::cout << GREEN"mystack top() points to: " << RESET << mystack.top() << RESET << std::endl;
	checkstackContinue();
}

void	stackConstructorsTest()
{
	std::cout << RED"Starting constructor, empty and size test" << RESET << std::endl;
	std::cout << BLUE"\nCreating first empty stack:\n" << RESET << std::endl;
	std::list<int>	list(3, 100);
	ft::List<int>	mylist(3, 100);
	std::vector<int> vector(7, 100);
	ft::Vector<int>	myvector(7, 100);

	std::stack<int> first;
	ft::Stack<int> myfirst;
	std::cout << GREEN"first size: " << RESET << first.size() << std::endl;
	std::cout << GREEN"myfirst size: " << RESET << myfirst.size() << std::endl;
	if (first.empty())
		std::cout << GREEN"first is empty" << std::endl;
	else
		std::cout << GREEN"first is not empty" << std::endl;
	if (myfirst.empty())
		std::cout << GREEN"myfirst is empty" << std::endl;
	else
		std::cout << GREEN"myfirst is not empty" << std::endl;

	std::cout << BLUE"\nCreating second stack as copy of list (3, 100):\n" << RESET << std::endl;
	std::stack<int, std::list<int>> second(list);
	ft::Stack<int> mysecond(mylist);
	std::cout << GREEN"second size: " << RESET << second.size() << std::endl;
	std::cout << GREEN"mysecond size: " << RESET << mysecond.size() << std::endl;
	if (second.empty())
		std::cout << GREEN"secondfirst is empty" << std::endl;
	else
		std::cout << GREEN"second is not empty" << std::endl;
	if (mysecond.empty())
		std::cout << GREEN"mysecond is empty" << std::endl;
	else
		std::cout << GREEN"mysecond is not empty" <<  RESET << std::endl;

	std::cout << BLUE"\nCreating third stack with vector as underlying container:\n" << RESET << std::endl;
	std::stack<int, std::vector<int>> third(vector);
	ft::Stack<int, ft::Vector<int>> mythird(myvector);
	std::cout << GREEN"second size: " << RESET << third.size() << std::endl;
	std::cout << GREEN"mysecond size: " << RESET << mythird.size() << std::endl;
	checkstackContinue();
}

int	testStack()
{
	printstackBanner();
	stackConstructorsTest();
	stackElementAccessTest();
	stackModifiersTest();
	stackRelationalOperatorsTest();
	
	return 0;
}