/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ListTest.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalba-de <dalba-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 12:57:21 by dalba-de          #+#    #+#             */
/*   Updated: 2021/01/08 18:40:42 by dalba-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <list>
#include <vector>

void	printList(std::list<int> list)
{
	std::list<int>::iterator it;

	it = list.begin();
	for (it = list.begin() ; it != list.end(); it++)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

int	main()
{
	std::list<int>	list;
	std::list<int>	list2;

	for (int i = 1; i <= 5; i++)
		list.push_back(i);

	for (int i = 1; i <= 5; i++)
		list2.push_back(i*10);
	
	printList(list);
	printList(list2);

	list2.swap(list);

	printList(list);
	printList(list2);

}