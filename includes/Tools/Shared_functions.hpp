#ifndef SHARED_FUNCTIONS_HPP
# define SHARED_FUNCTIONS_HPP
# include "../List/List.hpp"
# include "../Vector/Vector.hpp"
# include "../Map/Map.hpp"
# include "../Multimap/Multimap.hpp"
# include "../Set/Set.hpp"
# include "../Multiset/Multiset.hpp"
# include <list>
# include <vector>
# include <map>
# include <set>

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

	template <class key, class T>
	void	printMultimap(ft::Multimap<key, T> map)
	{
		typename ft::Multimap<key, T>::iterator it;

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
	void	printSet(ft::Set<T> set)
	{
		typename ft::Set<T>::iterator it;

		it = set.begin();
		for (it = set.begin() ; it != set.end(); it++)
		{
			std::cout << *it << " ";
		}
		std::cout << std::endl;
	};

	template <class T>
	void	printMultiset(ft::Multiset<T> set)
	{
		typename ft::Multiset<T>::iterator it;

		it = set.begin();
		for (it = set.begin() ; it != set.end(); it++)
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

	template <class key, class T>
	void	printoMultimap(std::multimap<key, T> map)
	{
		typename std::multimap<key, T>::iterator it;

		it = map.begin();
		for ( ; it != map.end(); it++)
			std::cout << it->first << ' ' << it->second << std::endl;
	};

	template <class T>
	void	printoSet(std::set<T> set)
	{
		typename std::set<T>::iterator it;

		it = set.begin();
		for (it = set.begin() ; it != set.end(); it++)
		{
			std::cout << *it << " ";
		}
		std::cout << std::endl;
	};

	template <class T>
	void	printomMultiset(std::multiset<T> set)
	{
		typename std::multiset<T>::iterator it;

		it = set.begin();
		for (it = set.begin() ; it != set.end(); it++)
		{
			std::cout << *it << " ";
		}
		std::cout << std::endl;
	};
}

#endif