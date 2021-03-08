#include "Stack.hpp"
#include "../List/List.hpp"
#include "../Vector/Vector.hpp"
#include <list>
#include <iostream>
#include <string>
#include <stack>

int main()
{
    std::cout << "\n\033[1;31m Original Stack\n \033[0m" << std::endl;

    std::stack<int> stack;

    stack.push(1);
    stack.push(2);
    stack.push(4);

    std::stack<int> stack1;

    stack1.push(1);
    stack1.push(2);
    stack1.push(3);

    if (stack == stack1)
        std::cout << "Equal\n";
    else
        std::cout << "Not Equal\n";

    std::cout << "\n\033[1;33m My Stack\n \033[0m" << std::endl;

    

    ft::Vector<int> vector(3, 100);

    ft::Stack<int, ft::Vector<int> > mystack(vector);

    std::cout << mystack.size() << std::endl;

    std::cout << mystack.top() << std::endl;

    mystack.push(13);

    std::cout << mystack.top() << std::endl;

    std::cout << mystack.size() << std::endl;

}