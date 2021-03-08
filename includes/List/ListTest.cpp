/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ListTest.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalba-de <dalba-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 12:57:21 by dalba-de          #+#    #+#             */
/*   Updated: 2021/02/15 11:03:13 by dalba-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <list>
#include <vector>
#include <cmath>
#include <string>
#include <cctype>
#include "List.hpp"
#include "../Tools/Shared_functions.hpp"

// compare only integral part:
bool mycomparison (double first, double second)
{ return ( int(first)<int(second) ); }

// a binary predicate implemented as a function:
bool same_integral_part (double first, double second)
{ return ( int(first)==int(second) ); }

// a binary predicate implemented as a class:
struct is_near {
  bool operator() (double first, double second)
  { return (fabs(first-second)<5.0); }
};

bool compare_nocase (const std::string& first, const std::string& second)
{
  unsigned int i=0;
  while ( (i<first.length()) && (i<second.length()) )
  {
    if (tolower(first[i])<tolower(second[i])) return true;
    else if (tolower(first[i])>tolower(second[i])) return false;
    ++i;
  }
  return ( first.length() < second.length() );
}

template <class T>
void	printList(std::list<T> list)
{
	typename std::list<T>::iterator it;

	it = list.begin();
	for (it = list.begin() ; it != list.end(); it++)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

int	main()
{
	std::cout << "\n\033[1;31m Original List\n \033[0m" << std::endl;

	std::list<int> olist;

	olist.assign(3, 42);
	ft::printoList(olist);

	std::cout << "\n\033[1;33m My List\n \033[0m" << std::endl;

	ft::List<int> list;

	list.assign(3, 42);
	ft::printList(list);

	return 0;
}