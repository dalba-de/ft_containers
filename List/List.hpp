#ifndef LIST_HPP
# define LIST_HPP
# include <memory>
# include <limits>
# include "../Iterators/IteratorList.hpp"
# include "../Tools/Algorithm.hpp"

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

			explicit List(const allocator_type& = allocator_type())
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

			explicit List(size_type n, const value_type& val = value_type(), const allocator_type& = allocator_type())
			{
				size_ = 0;
				head = new link<T>;
				tail = new link<T>;
				head->next = tail;
				tail->prev = head;
				assign(n, val);
			}

			template<class InputIterator>
			List(InputIterator first, InputIterator last,
			typename std::enable_if<!std::is_integral<InputIterator>::value>::type * = 0)
			{
				size_ = 0;
				head = new link<T>;
				tail = new link<T>;
				head->next = tail;
				tail->prev = head;
				while (first != last)
				{
					push_back(*(first));
					first++;
				}
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
					return 1;
				return 0;
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
			void		assign(InputIterator first, InputIterator last,
						typename std::enable_if<!std::is_integral<InputIterator>::value>::type * = 0)
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
				return (aux->prev = aux->prev->next = new link<T>( val, aux->prev, aux ) );
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
			void		insert(iterator position, InputIterator first, InputIterator last, 
						typename std::enable_if<!std::is_integral<InputIterator>::value>::type * = 0)
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
				while (!empty())
					pop_front();
			}

/*
** --------------------------------- OPERATIONS ---------------------------------
*/

			void		splice(iterator position, List& x)
			{
				iterator it = x.begin();

				while (it != x.end())
				{
					this->insert(position, *(it));
					it++;
				}
				x.clear();
			}

			void		splice(iterator position, List& x, iterator i)
			{
				this->insert(position, *(i));
				x.erase(i);
			}

			void		splice(iterator position, List& x, iterator first, iterator last)
			{
				iterator ret = first;

				while (ret != last)
				{
					this->insert(position, *(ret));
					ret++;
				}
				x.erase(first, last);
			}

			void		remove(const value_type& val)
			{
				iterator it = this->begin();

				while (it != this->end())
				{
					if (*it == val)
						this->erase(it);
					it++;
				}
			}

			template<class Predicate>
			void		remove_if (Predicate pred)
			{
				iterator it = this->begin();

				while (it != this->end())
				{
					if (pred(*(it)))
						this->erase(it);
					it++;
				}
			}

			void		unique()
			{
				iterator it = this->begin();
				iterator next = it;

				while (it != this->end())
				{
					next++;
					if (next == this->end())
						return ;
					if (*(it) == *(next))
					{
						erase(next);
						next = it;
						continue ;
					}
					it++;
					next = it;
				}
			}

			template<class BinaryPredicate>
			void		unique(BinaryPredicate binary_pred)
			{
				iterator it = this->begin();
				iterator next = it;

				while (it != this->end())
				{
					next++;
					if (next == this->end())
						return ;
					if (binary_pred(*(it), *(next)))
					{
						erase(next);
						next = it;
						continue ;
					}
					it++;
					next = it;
				}
			}

			void		merge(List& x)
			{
				iterator it = x.begin();
				iterator first = this->begin();

				if (&x == this)
					return ;
				while (first != this->end() && it != x.end())
				{
					if (*(it) < *(first))
					{
						insert(first, *(it));
						it++;
					}
					else	
						first++;						
				}
				if (it != x.end())
				{
					while (it != x.end())
					{
						this->push_back(*(it));
						it++;
					}
				}
				x.clear();
			}

			template<class Compare>
			void		merge(List& x, Compare comp)
			{
				iterator it = x.begin();
				iterator first = this->begin();

				if (&x == this)
					return ;
				while (first != this->end() && it != x.end())
				{
					if (comp(*(it), *(first)))
					{
						insert(first, *(it));
						it++;
					}
					else	
						first++;						
				}
				if (it != x.end())
				{
					while (it != x.end())
					{
						this->push_back(*(it));
						it++;
					}
				}
				x.clear();
			}

			void		sort()
			{
				iterator it = this->begin();
				iterator next = it;

				while (it != this->end())
				{
					next++;
					if (next == this->end())
						return ;
					if (*(next) < *(it))
					{
						splice(it, *this, next);
						it = this->begin();
						next = it;
					}
					else
						it++;
				}
			}

			template<class Compare>
			void		sort(Compare comp)
			{
				iterator it = this->begin();
				iterator next = it;

				while (it != this->end())
				{
					next++;
					if (next == this->end())
						return ;
					if (comp(*(next), *(it)))
					{
						splice(it, *this, next);
						it = this->begin();
						next = it;
					}
					else
						it++;
				}
			}

			void		reverse()
			{
				iterator	it = this->begin();
				List<T>		temp;

				while (it != this->end())
				{
					temp.push_front(*(it));
					it++;
				}
				*this = temp;
			}
	};

	template<class T, class Alloc>
	bool	operator==(const List<T, Alloc>& lhs, const List<T, Alloc>& rhs)
	{
		if (lhs.size() != rhs.size())
			return (false);
		return (ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
	}

	template<class T, class Alloc>
	bool	operator!=(const List<T, Alloc>& lhs, const List<T, Alloc>& rhs)
	{
		return(!(lhs == rhs));
	}

	template<class T, class Alloc>
  	bool	operator<(const List<T, Alloc>& lhs, const List<T, Alloc>& rhs)
	{
		return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	}

	template<class T, class Alloc>
  	bool	operator<=(const List<T, Alloc>& lhs, const List<T, Alloc>& rhs)
	{
		return (!(rhs < lhs));
	}

	template<class T, class Alloc>
  	bool	operator>(const List<T, Alloc>& lhs, const List<T, Alloc>& rhs)
	{
		return (rhs < lhs);
	}

	template<class T, class Alloc>
  	bool	operator>=(const List<T, Alloc>& lhs, const List<T, Alloc>& rhs)
	{
		return (!(lhs < rhs));
	}

	template<class T, class Alloc>
  	void	swap(List<T, Alloc>& x, List<T, Alloc>& y)
	{
		x.swap(y);
	}

}

#endif /* ************************************************************ LIST_H */