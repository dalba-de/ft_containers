#ifndef LIST_HPP
# define LIST_HPP
# include <memory>
# include <limits>
# include "IteratorList.hpp"

namespace ft
{
	template < typename T, class Alloc = std::allocator<T> >
	class List
	{
		private:
			link<T>	*head;
			link<T>	*tail;
			size_t	size_;
/*
** ------------------------------- MEMBER TYPES -------------------------------
*/
		public:
			typedef T									value_type;
			typedef Alloc								allocator_type;
			typedef T&									reference;
			typedef const T&							const_reference;
			typedef T*									pointer;
			typedef const T*							const_pointer;
			typedef ft::ListIterator<T>					iterator;
			typedef ft::ConstListIterator<T>			const_iterator;
			typedef ft::ReverseListIterator<T>			reverse_iterator;
			typedef ft::ConstReverseListIterator<T>		const_reverse_iterator;
			typedef std::ptrdiff_t						difference_type;
			typedef std::size_t							size_type;


/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/
		public:

			List()
			{
				size_ = 0;
				head = new link<T>;
				tail = new link<T>;
				head->next = tail;
				tail->prev = head;
			}
			List( List const & src ) : size_(0)
			{
				head = new link<T>;
				tail = new link<T>;
				head->next = tail;
				tail->prev = head;
				this->assign(src.begin(), src.end());
			}

			List(size_type n, const value_type& val = value_type())
			{
				(void)n;
				(void)val;
			}

/*
** ------------------------------- DESTRUCTOR --------------------------------
*/
			~List() { clear(); delete head; delete tail; };

/*
** --------------------------------- OVERLOAD ---------------------------------
*/
			List &		operator=( List const & rhs )
			{
				this->assign(rhs.begin(), rhs.end());
				return *this;
			}

/*
** --------------------------------- ITERATORS ---------------------------------
*/

			iterator				begin() { return iterator (this->head->next); }

			const_iterator			begin() const { return const_iterator (this->head->next); }

			iterator				end() { return iterator (tail); }

			const_iterator			end() const { return const_iterator (tail); }

			reverse_iterator		rend() { return reverse_iterator(this->head); }

			const_reverse_iterator	rend() const { return const_reverse_iterator(this->head); }

			reverse_iterator		rbegin() { return reverse_iterator(tail->prev); }

			const_reverse_iterator	rbegin() const { return const_reverse_iterator(tail->prev); }

/*
** ------------------------------- CAPACITY --------------------------------
*/

			bool		empty() const
			{
				if (size_ == 0)
					return 0;
				return 1;
			}

			size_type	size() const { return (size_); }

			size_type	max_size() const 
			{ return std::numeric_limits<size_type>::max()/sizeof(link<T>); }

/*
** ---------------------------- ELEMENT ACCESS -----------------------------
*/

			reference	front()
			{
				return head->next->value;
			}

			const_reference	front() const
			{
				return head->next->value;
			}

			reference	back()
			{
				return tail->prev->value;
			}

			const_reference	back() const
			{
				return tail->prev->value;
			}


/*
** --------------------------------- MODIFIERS ---------------------------------
*/

			template<class InputIterator>
			void		assign(InputIterator first, InputIterator last)
			{
				clear();
				while (first != last)
				{
					push_back(*(first));
					first++;
				}
			}

			void		assign(size_type n, const value_type& val)
			{
				clear();
				while (n > 0)
				{
					push_back(val);
					n--;
				}
			}

			void		push_front(const value_type& val) { insert (begin(), val); }

			void		pop_front() { erase(begin()); }

			void		push_back(const value_type& val) { insert (end(), val);	}

			void		pop_back() { erase(--end()); }

			iterator	insert(iterator position, const value_type& val)
			{
				link<T> *aux = position.getList();
				size_++;
				return (aux->prev = aux->prev->next = new link<T>{ val, aux->prev, aux } );
			}

			void		insert(iterator position, size_type n, const value_type& val)
			{
				while (n > 0)
				{
					insert(position, val);
					n--;
				}
			}

			template <class InputIterator>
			void		insert(iterator position, InputIterator first, InputIterator last)
			{
				while (first != last)
				{
					position = insert(position, *(first));
					first++;
					position++;
				}
			}

			iterator	erase(iterator position)
			{
				link<T> *aux = position.getList();
				aux->prev->next = aux->next;
				aux->next->prev = aux->prev;

				iterator ret = aux->next;
				delete aux;
				size_--;
				return ret;
			}

			iterator	erase(iterator first, iterator last)
			{
				while (first != last)
				{
					erase(first);
					first++;
				}
				return (last);
			}

			void		swap(List& x)
			{
				List	ret;

				ret.assign(this->begin(), this->end());
				this->assign(x.begin(), x.end());
				x.assign(ret.begin(), ret.end());
			}

			void		resize(size_type n, value_type val = value_type())
			{
				if (n <= this->size_)
				{
					size_type aux = size_;
					while (aux > n)
					{
						pop_back();
						aux--;
					}
				}
				else
				{
					size_type aux = size_;
					while (aux < n)
					{
						push_back(val);
						aux++;
					}
				}
			}

			void		clear()
			{
				while (empty())
					pop_front();
			}
	};

}

#endif /* ************************************************************ LIST_H */