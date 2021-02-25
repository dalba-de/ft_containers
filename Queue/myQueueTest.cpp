#include "Queue.hpp"

int main()
{
	ft::Queue<int>	queue;

	queue.push(4);
	queue.push(8);
	queue.push(12);
	queue.push(16);

	std::cout << "front: " << queue.front() << " back: " << queue.back() << std::endl;

	std::cout << "size: " << queue.size() << std::endl;

	queue.pop();

	std::cout << "front: " << queue.front() << " back: " << queue.back() << std::endl;

	std::cout << "size: " << queue.size() << std::endl;
}