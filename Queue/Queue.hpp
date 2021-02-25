#ifndef	QUEUE_HPP
# define QUEUE_HPP
# include "../List/List.hpp"

namespace ft
{
	template <class T, class Container = ft::List<T> >
	class Queue
	{
		
/*
** ------------------------------- MEMBER TYPES -------------------------------
*/

		public:
			typedef T					value_type;
			typedef Container			container_type;
			typedef std::size_t			size_type;

		protected:
			container_type	c;

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

		public:
			

	};
}

#endif