/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ListIterator.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalba-de <dalba-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 16:21:20 by dalba-de          #+#    #+#             */
/*   Updated: 2020/12/26 21:01:58 by dalba-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LISTITERATOR_HPP
# define LISTITERATOR_HPP
# include <iostream>

namespace ft
{
	template <typename T>
	struct link
	{
		T		value;
		link<T>	*prev;
		link<T>	*next;

		link (const T &d = T{}, link* p = nullptr, link* n = nullptr)
		: value(d), prev(p), next(n) { }
	};

	template <typename T, class Category = std::bidirectional_iterator_tag>
	class ListIterator
	{
		public:
			typedef ListIterator self_type;
			typedef T value_type;
			typedef T& reference;
			typedef T* pointer;
			typedef Category iterator_category;
			typedef std::ptrdiff_t difference_type;
			ListIterator(): ptr_(nullptr) {}
			ListIterator(link<T> *ptr) : ptr_(ptr) { }
			self_type operator=(const self_type& other) { ptr_ = other.ptr_; return *this; }
			self_type operator++() 
			{ 
				if (ptr_ && ptr_->next)
					ptr_ = ptr_->next;
				return *this;
			} // PREFIX
			self_type operator++(int)
			{
				self_type i = *this;
				this->operator++();
				return i;
			} // POSTFIX
			self_type operator--()
			{ 
				if (ptr_ && ptr_->prev)
					ptr_ = ptr_->prev;
				return *this;
			}
			self_type operator--(int)
			{ 
				self_type i = *this;
				this->operator--();
				return i;
			}
			value_type& operator*() { return ptr_->value; }
			value_type* operator->() { return &ptr_->value; }
			bool operator==(const self_type& rhs) { return ptr_ == rhs.ptr_; }
			bool operator!=(const self_type& rhs) { return ptr_ != rhs.ptr_; }
			link<T>*	getList() const { return ptr_; }
		protected:
			link<T>* ptr_;
	};

	template <typename T, class Category = std::bidirectional_iterator_tag>
	class const_ListIterator
	{
		public:
			typedef const_ListIterator self_type;
			typedef T value_type;
			typedef T& reference;
			typedef T* pointer;
			typedef Category iterator_category;
			typedef std::ptrdiff_t difference_type;
			const_ListIterator(): ptr_(nullptr) {}
			const_ListIterator(link<T> *ptr) : ptr_(ptr) { }
			const_ListIterator(const const_ListIterator& src)
			{
				ptr_ = (src.getList());
			}
			const_ListIterator(const ListIterator<T>& src)
			{
				ptr_ = (src.getList());
			}
			self_type operator=(const self_type& other) { ptr_ = other.ptr_; return *this; }
			self_type operator++() 
			{ 
				if (ptr_ && ptr_->next)
					ptr_ = ptr_->next;
				return *this;
			} // PREFIX
			self_type operator++(int)
			{
				self_type i = *this;
				this->operator++();
				return i;
			} // POSTFIX
			self_type operator--()
			{ 
				if (ptr_ && ptr_->prev)
					ptr_ = ptr_->prev;
				return *this;
			}
			self_type operator--(int)
			{ 
				self_type i = *this;
				this->operator--();
				return i;
			}
			value_type& operator*() { return ptr_->value; }
			const value_type* operator->() { return &ptr_->value; }
			bool operator==(const self_type& rhs) { return ptr_ == rhs.ptr_; }
			bool operator!=(const self_type& rhs) { return ptr_ != rhs.ptr_; }
			link<T>*	getList() const { return ptr_; }
		protected:
			link<T>* ptr_;
	};

	template <typename It>
	class List_reverse_iterator : public It
	{
		public:
			typedef typename It::value_type value_type;
			typedef typename It::reference reference;
			typedef typename It::pointer pointer;
			typedef typename It::iterator_category iterator_category;
			typedef typename It::difference_type difference_type;

			List_reverse_iterator() : iter_() { }
			List_reverse_iterator(It it) : iter_(it) { }
			template <class Iter>
                List_reverse_iterator (const List_reverse_iterator<Iter>& rev_it)
                :
                    iter_(rev_it.base())
                {}
			List_reverse_iterator & operator=(List_reverse_iterator const & rhs) { this->ptr_ = rhs.ptr_; return *this; }

			It base() const { return (iter_); }

			reference operator*() const
			{
				It tmp = iter_;
				return (*(--tmp));
			}

			List_reverse_iterator & operator++ ()
			{
				--iter_;
				return *this;
			}

			List_reverse_iterator operator++ ( int )
			{
				List_reverse_iterator old = *this;
				++( *this );
				return old;
			}

			List_reverse_iterator & operator-- ()
			{
				++iter_;
				return *this;
			}

			List_reverse_iterator & operator-- (int)
			{
				List_reverse_iterator old = *this;
				--( *this );
				return old;
			}
		private:
			It iter_;
	};

	template <class Iterator>
        bool operator!= (const List_reverse_iterator<Iterator>& lhs,
                        const List_reverse_iterator<Iterator>& rhs) { return (lhs.base() != rhs.base()); }

	template <class Iterator_L, class Iterator_R>
        bool operator!= (const List_reverse_iterator<Iterator_L>& lhs,
                        const List_reverse_iterator<Iterator_R>& rhs) { return (lhs.base() != rhs.base()); }

	
}

#endif