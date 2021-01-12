/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ListTest.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalba-de <dalba-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 12:57:21 by dalba-de          #+#    #+#             */
/*   Updated: 2021/01/12 18:33:29 by dalba-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <list>
#include <vector>
#include <cmath>

// a binary predicate implemented as a function:
bool same_integral_part (double first, double second)
{ return ( int(first)==int(second) ); }

// a binary predicate implemented as a class:
struct is_near {
  bool operator() (double first, double second)
  { return (fabs(first-second)<5.0); }
};

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
	double mydoubles[]={ 12.15,  2.72, 73.0,  12.77,  3.14,
                       12.77, 73.35, 72.25, 15.3,  72.25 };
  	std::list<double> list (mydoubles,mydoubles+10);

	list.sort();
	list.unique();

	printList(list);
}