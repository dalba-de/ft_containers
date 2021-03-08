#ifndef STACK_HPP
# define STACK_HPP
# include "../List/List.hpp"

namespace ft
{
    template <class T, class Container = ft::List<T> >
    class Stack
    {

/*
** ------------------------------- MEMBER TYPES -------------------------------
*/
        public:
            typedef T                   value_type;
            typedef Container           container_type;
            typedef std::size_t         size_type;

        protected:
            container_type  c;

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

        public:
            explicit Stack      (const container_type& cntr = container_type())
            : c(cntr) {}

/*
** ----------------------------- MEMBER FUNCTIONS -----------------------------
*/

        bool                empty() const
        {
            return (this->c.empty());
        }

        size_type           size() const
        {
            return (this->c.size());
        }

        value_type&         top()
        {
            return (this->c.back());
        }

        const value_type&   top() const
        {
            return (this->c.back());
        }

        void                push(const value_type& val)
        {
            this->c.push_back(val);
        }

        void                pop()
        {
            this->c.pop_back();
        }

/*
** ----------------------- NON-MEMBER FUNCTION OVERLOADS ------------------------
*/

        template <class value, class underlyingc>
        friend bool    operator==(const Stack<value, underlyingc>& lhs, const Stack<value, underlyingc>& rhs);

        template <class value, class underlyingc>
        friend bool    operator!=(const Stack<value, underlyingc>& lhs, const Stack<value, underlyingc>& rhs);

        template <class value, class underlyingc>
        friend bool    operator<(const Stack<value, underlyingc>& lhs, const Stack<value, underlyingc>& rhs);

        template <class value, class underlyingc>
        friend bool    operator<=(const Stack<value, underlyingc>& lhs, const Stack<value, underlyingc>& rhs);

        template <class value, class underlyingc>
        friend bool    operator>(const Stack<value, underlyingc>& lhs, const Stack<value, underlyingc>& rhs);

        template <class value, class underlyingc>
        friend bool    operator>=(const Stack<value, underlyingc>& lhs, const Stack<value, underlyingc>& rhs);
    };

/*
** ---------------------------- RELATIONAL OPERATORS ----------------------------
*/

    template <class T, class Container>
    bool    operator==(const Stack<T, Container>& lhs, const Stack<T, Container>& rhs)
    {
        return (lhs.c == rhs.c);
    }

    template <class T, class Container>
    bool    operator!=(const Stack<T, Container>& lhs, const Stack<T, Container>& rhs)
    {
        return (lhs.c != rhs.c);
    }

    template <class T, class Container>
    bool    operator<(const Stack<T, Container>& lhs, const Stack<T, Container>& rhs)
    {
        return (lhs.c < rhs.c);
    }

    template <class T, class Container>
    bool    operator<=(const Stack<T, Container>& lhs, const Stack<T, Container>& rhs)
    {
        return (lhs.c <= rhs.c);
    }

    template <class T, class Container>
    bool    operator>(const Stack<T, Container>& lhs, const Stack<T, Container>& rhs)
    {
        return (lhs.c > rhs.c);
    }

    template <class T, class Container>
    bool    operator>=(const Stack<T, Container>& lhs, const Stack<T, Container>& rhs)
    {
        return (lhs.c >= rhs.c);
    }

}

#endif