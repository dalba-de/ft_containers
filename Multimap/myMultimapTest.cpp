#include "Multimap.hpp"
#include <map>

int main()
{
	std::cout << "\n\033[1;31m Multimap Original\n \033[0m" << std::endl;

	std::multimap<int, std::string> multi;

	multi.insert(std::pair<int, std::string>(12, "Bali"));
	multi.insert(std::pair<int, std::string>(10, "Cancun"));
	multi.insert(std::pair<int, std::string>(20, "Croacia"));
	multi.insert(std::pair<int, std::string>(9, "Holanda"));
	multi.insert(std::pair<int, std::string>(11, "Chile"));
	multi.insert(std::pair<int, std::string>(10, "Suecia"));
	multi.insert(std::pair<int, std::string>(12, "Luxemburgo"));
	multi.insert(std::pair<int, std::string>(12, "Perú"));

	std::multimap<int, std::string>::iterator it = multi.find(11);

	multi.erase(it, multi.end());

	for (std::multimap<int, std::string>::iterator it = multi.begin(); it != multi.end(); it++)
		std::cout << it->first << ' ' << it->second << std::endl;

	std::cout << std::endl;

	std::cout << "\n\033[1;33m My Multimap\n \033[0m" << std::endl;

	ft::Multimap<int, std::string> mymulti;

	mymulti.insert(std::pair<int, std::string>(12, "Bali"));
	mymulti.insert(std::pair<int, std::string>(10, "Cancun"));
	mymulti.insert(std::pair<int, std::string>(20, "Croacia"));
	mymulti.insert(std::pair<int, std::string>(9, "Holanda"));
	mymulti.insert(std::pair<int, std::string>(11, "Chile"));
	mymulti.insert(std::pair<int, std::string>(10, "Suecia"));
	mymulti.insert(std::pair<int, std::string>(12, "Luxemburgo"));
	mymulti.insert(std::pair<int, std::string>(12, "Perú"));

	ft::Multimap<int, std::string>::iterator myit = mymulti.find(11);

	mymulti.erase(myit, mymulti.end());

	for (ft::Multimap<int, std::string>::iterator myit = mymulti.begin(); myit != mymulti.end(); myit++)
		std::cout << myit->first << ' ' << myit->second << std::endl;

	std::cout << std::endl;
}