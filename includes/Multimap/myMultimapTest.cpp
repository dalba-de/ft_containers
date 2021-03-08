#include "Multimap.hpp"
#include <map>

void	pruebaConst(const ft::Multimap<int, std::string>& multi)
{
	std::cout << (multi.equal_range(12)).first->second << ' ' << (multi.equal_range(12)).second->second << std::endl << std::endl;
}

int main()
{
	std::cout << "\n\033[1;31m Multimap Original\n \033[0m" << std::endl;

	std::multimap<int, std::string> multi;
	std::multimap<int, std::string> multi1;

	multi.insert(std::pair<int, std::string>(12, "Bali"));
	multi.insert(std::pair<int, std::string>(10, "Cancun"));
	multi.insert(std::pair<int, std::string>(20, "Croacia"));
	multi.insert(std::pair<int, std::string>(7, "Holanda"));
	multi.insert(std::pair<int, std::string>(11, "Chile"));
	multi.insert(std::pair<int, std::string>(10, "Suecia"));
	multi.insert(std::pair<int, std::string>(12, "Luxemburgo"));
	multi.insert(std::pair<int, std::string>(12, "Perú"));

	multi1.insert(std::pair<int, std::string>(12, "Bali"));
	multi1.insert(std::pair<int, std::string>(10, "Cancun"));
	multi1.insert(std::pair<int, std::string>(20, "Croacia"));
	multi1.insert(std::pair<int, std::string>(7, "Holanda"));
	multi1.insert(std::pair<int, std::string>(11, "Chile"));
	multi1.insert(std::pair<int, std::string>(10, "Suecia"));
	multi1.insert(std::pair<int, std::string>(12, "Luxemburgo"));
	multi1.insert(std::pair<int, std::string>(12, "Perú"));

	if (multi == multi1)
		std::cout << "son iguales\n" << std::endl;
	else
		std::cout << "son distintos\n" << std::endl;
	

	for (std::multimap<int, std::string>::iterator it = multi.begin(); it != multi.end(); it++)
		std::cout << it->first << ' ' << it->second << std::endl;

	std::cout << std::endl;

	std::cout << "\n\033[1;33m My Multimap\n \033[0m" << std::endl;

	ft::Multimap<int, std::string> mymulti;
	ft::Multimap<int, std::string> mymulti1;

	mymulti.insert(std::pair<int, std::string>(12, "Bali"));
	mymulti.insert(std::pair<int, std::string>(10, "Cancun"));
	mymulti.insert(std::pair<int, std::string>(20, "Croacia"));
	mymulti.insert(std::pair<int, std::string>(7, "Holanda"));
	mymulti.insert(std::pair<int, std::string>(11, "Chile"));
	mymulti.insert(std::pair<int, std::string>(10, "Suecia"));
	mymulti.insert(std::pair<int, std::string>(12, "Luxemburgo"));
	mymulti.insert(std::pair<int, std::string>(12, "Perú"));

	mymulti1.insert(std::pair<int, std::string>(12, "Bali"));
	mymulti1.insert(std::pair<int, std::string>(10, "Cancun"));
	mymulti1.insert(std::pair<int, std::string>(20, "Croacia"));
	mymulti1.insert(std::pair<int, std::string>(7, "Holanda"));
	mymulti1.insert(std::pair<int, std::string>(11, "Chile"));
	mymulti1.insert(std::pair<int, std::string>(10, "Suecia"));
	mymulti1.insert(std::pair<int, std::string>(12, "Luxemburgo"));
	mymulti1.insert(std::pair<int, std::string>(12, "Perú"));	

	if (mymulti == mymulti1)
		std::cout << "son iguales\n" << std::endl;
	else
		std::cout << "son distintos\n" << std::endl;

	for (ft::Multimap<int, std::string>::iterator myit = mymulti.begin(); myit != mymulti.end(); myit++)
		std::cout << myit->first << ' ' << myit->second << std::endl;

	std::cout << std::endl;
}