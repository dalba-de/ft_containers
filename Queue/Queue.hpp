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
			explicit Queue		(const container_type& ctnr = container_type())
			: c(ctnr) {}

/*
** ----------------------------- MEMBER FUNCTIONS -----------------------------
*/

			bool				empty() const
			{
				return (this->c.empty());
			}

			size_type			size() const
			{
				return (this->c.size());
			}

			value_type&			front()
			{
				return (this->c.front());
			}

			const value_type&	front() const
			{
				return (this->c.front());
			}

			value_type&			back()
			{
				return (this->c.back());
			}

			const value_type&	back() const
			{
				return (this->c.back());
			}

			void				push(const value_type& val)
			{
				this->c.push_back(val);
			}

			void				pop()
			{
				this->c.pop_front();
			}

/*
** ----------------------- NON-MEMBER FUNCTION OVERLOADS ------------------------
*/

        template <class value, class underlyingc>
        friend bool    operator==(const Queue<value, underlyingc>& lhs, const Queue<value, underlyingc>& rhs);

        template <class value, class underlyingc>
        friend bool    operator!=(const Queue<value, underlyingc>& lhs, const Queue<value, underlyingc>& rhs);

        template <class value, class underlyingc>
        friend bool    operator<(const Queue<value, underlyingc>& lhs, const Queue<value, underlyingc>& rhs);

        template <class value, class underlyingc>
        friend bool    operator<=(const Queue<value, underlyingc>& lhs, const Queue<value, underlyingc>& rhs);

        template <class value, class underlyingc>
        friend bool    operator>(const Queue<value, underlyingc>& lhs, const Queue<value, underlyingc>& rhs);

        template <class value, class underlyingc>
        friend bool    operator>=(const Queue<value, underlyingc>& lhs, const Queue<value, underlyingc>& rhs);			

	};

/*
** ---------------------------- RELATIONAL OPERATORS ----------------------------
*/

    template <class T, class Container>
    bool    operator==(const Queue<T, Container>& lhs, const Queue<T, Container>& rhs)
    {
        return (lhs.c == rhs.c);
    }

    template <class T, class Container>
    bool    operator!=(const Queue<T, Container>& lhs, const Queue<T, Container>& rhs)
    {
        return (lhs.c != rhs.c);
    }

    template <class T, class Container>
    bool    operator<(const Queue<T, Container>& lhs, const Queue<T, Container>& rhs)
    {
        return (lhs.c < rhs.c);
    }

    template <class T, class Container>
    bool    operator<=(const Queue<T, Container>& lhs, const Queue<T, Container>& rhs)
    {
        return (lhs.c <= rhs.c);
    }

    template <class T, class Container>
    bool    operator>(const Queue<T, Container>& lhs, const Queue<T, Container>& rhs)
    {
        return (lhs.c > rhs.c);
    }

    template <class T, class Container>
    bool    operator>=(const Queue<T, Container>& lhs, const Queue<T, Container>& rhs)
    {
        return (lhs.c >= rhs.c);
    }
	
}

#endif