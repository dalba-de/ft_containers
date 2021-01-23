#ifndef ITERATOR_HPP
# define ITERATOR_HPP
# include <iostream>

namespace ft
{
	template <typename T, class Category = std::random_access_iterator_tag>
	class iterator
	{
		public:
			typedef iterator self_type;
			typedef T value_type;
			typedef T& reference;
			typedef T* pointer;
			typedef Category iterator_category;
			typedef std::ptrdiff_t difference_type;
			iterator() {}
			iterator(pointer ptr) : ptr_(ptr) { }
			self_type operator=(const self_type& other) { ptr_ = other.ptr_; return *this; }
			self_type operator++() { ptr_++; return *this; } // PREFIX
			self_type operator++(int) { self_type i = *this; ptr_++; return i; } // POSTFIX
			self_type operator--() { ptr_--; return *this; }
			self_type operator--(int) { self_type i = *this; ptr_--; return i; }
			self_type operator+=(int value) { this->ptr_ += value; return (*this); }
			self_type operator+(int value) { self_type i = *this; return (i += value); }
			self_type operator-=(int value) { this->ptr_ -= value; return (*this); }
			self_type operator-(int value) { self_type i = *this; return (i -= value); }
			value_type& operator*() { return *ptr_; }
			value_type* operator->() { return ptr_; }
			bool operator==(const self_type& rhs) { return ptr_ == rhs.ptr_; }
			bool operator!=(const self_type& rhs) { return ptr_ != rhs.ptr_; }
		protected:
			pointer ptr_;
	};

	template <typename T, class Category = std::random_access_iterator_tag>
	class const_iterator
	{
		public:
			typedef const_iterator self_type;
			typedef T value_type;
			typedef T& reference;
			typedef T* pointer;
			typedef int difference_type;
			typedef Category iterator_category;
			const_iterator() {}
			const_iterator(pointer ptr) : ptr_(ptr) { }
			self_type operator=(const self_type& other) { ptr_ = other.ptr_; return *this; }
			self_type operator++() { ptr_++; return *this; } // PREFIX
			self_type operator++(int) { self_type i = *this; ptr_++; return i; } // POSTFIX
			self_type operator--() { ptr_--; return *this; }
			self_type operator--(int) { self_type i = *this; ptr_--; return i; }
			self_type operator+=(int value) { this->ptr_ += value; return (*this); }
			self_type operator+(int value) { self_type i = *this; return (i += value); }
			self_type operator-=(int value) { this->ptr_ -= value; return (*this); }
			self_type operator-(int value) { self_type i = *this; return (i -= value); }
			const value_type& operator*() { return *ptr_; }
			const value_type* operator->() { return ptr_; }
			bool operator==(const self_type& rhs) const { return ptr_ == rhs.ptr_; }
			bool operator!=(const self_type& rhs) const { return ptr_ != rhs.ptr_; }
		protected:
			pointer ptr_;
	};

	template <typename It>
	class reverse_iterator : public It
	{
		public:
			typedef typename It::value_type value_type;
			typedef typename It::reference reference;
			typedef typename It::pointer pointer;
			typedef typename It::iterator_category iterator_category;
			typedef typename It::difference_type difference_type;

			reverse_iterator() : It() { }
			reverse_iterator(It const & it) : It(it) { }
			reverse_iterator(reverse_iterator const & rhs) : It(rhs.ptr_) { }
			reverse_iterator & operator=(reverse_iterator const & rhs) { this->ptr_ = rhs.ptr_; return *this; }
			reference operator*()
			{
				It tmp(*this);
				return (*--tmp);
			}

			reverse_iterator & operator++ ()
			{
				this->It::operator--();
				return *this;
			}

			reverse_iterator operator++ ( int )
			{
				reverse_iterator old = *this;
				++( *this );
				return old;
			}

			reverse_iterator & operator-- ()
			{
				this->It::operator++();
				return *this;
			}

			reverse_iterator operator-- ( int )
			{
				reverse_iterator old = *this;
				--( *this );
				return old;
			}
	};

	template <typename It>
	class const_reverse_iterator : public It
	{
		public:
			typedef typename It::value_type value_type;
			typedef typename It::reference reference;
			typedef typename It::pointer pointer;
			typedef typename It::iterator_category iterator_category;
			typedef typename It::difference_type difference_type;

			const_reverse_iterator() : It() { }
			const_reverse_iterator(It const & it) : It(it) { }
			const_reverse_iterator(const_reverse_iterator const & rhs) : It(rhs.ptr_) { }
			const_reverse_iterator & operator=(const_reverse_iterator const & rhs) { this->ptr_ = rhs.ptr_; return *this; }
			reference operator*()
			{
				It tmp(*this);
				return (*--tmp);
			}

			const_reverse_iterator & operator++ ()
			{
				this->It::operator--();
				return *this;
			}

			const_reverse_iterator operator++ ( int )
			{
				const_reverse_iterator old = *this;
				++( *this );
				return old;
			}

			const_reverse_iterator & operator-- ()
			{
				this->It::operator++();
				return *this;
			}

			const_reverse_iterator operator-- ( int )
			{
				const_reverse_iterator old = *this;
				--( *this );
				return old;
			}
	};
}

#endif