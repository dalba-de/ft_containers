#ifndef SHARED_FUNCTIONS_HPP
# define SHARED_FUNCTIONS_HPP
# include "../List/List.hpp"
# include "../Vector/Vector.hpp"
# include "../Map/Map.hpp"
# include <list>
# include <vector>
# include <map>

namespace ft
{
	template <class T>
	void	printList(ft::List<T> list)
	{
		typename ft::List<T>::iterator it;

		it = list.begin();
		for (it = list.begin() ; it != list.end(); it++)
		{
			std::cout << *it << " ";
		}
		std::cout << std::endl;
	};

	template <class T>
	void	printVector(ft::Vector<T> vector)
	{
		typename ft::Vector<T>::iterator it;

		it = vector.begin();
		for (it = vector.begin() ; it != vector.end(); it++)
		{
			std::cout << *it << " ";
		}
		std::cout << std::endl;
	};

	template <class key, class T>
	void	printMap(ft::Map<key, T> map)
	{
		typename ft::Map<key, T>::iterator it;

		it = map.begin();
		for ( ; it != map.end(); it++)
			std::cout << it->first << ' ' << it->second << std::endl;
	};

	template <class T>
	void	printoList(std::list<T> list)
	{
		typename std::list<T>::iterator it;

		it = list.begin();
		for (it = list.begin() ; it != list.end(); it++)
		{
			std::cout << *it << " ";
		}
		std::cout << std::endl;
	};

	template <class T>
	void	printoVector(std::vector<T> vector)
	{
		typename std::vector<T>::iterator it;

		it = vector.begin();
		for (it = vector.begin() ; it != vector.end(); it++)
		{
			std::cout << *it << " ";
		}
		std::cout << std::endl;
	};

	template <class key, class T>
	void	printoMap(std::map<key, T> map)
	{
		typename std::map<key, T>::iterator it;

		it = map.begin();
		for ( ; it != map.end(); it++)
			std::cout << it->first << ' ' << it->second << std::endl;
	};
}

#endif