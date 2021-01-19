#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <iostream>
# include <string>
# include <memory>
# include <limits>
# include "../Tools/Algorithm.hpp"
# include "../Iterators/Iterator.hpp"

namespace ft
{
	template <typename T, class Alloc = std::allocator<T> >
	class Vector
	{
/*
** ------------------------------- MEMBER TYPES -------------------------------
*/

		public:
			typedef T                                             value_type;
			typedef Alloc                                         allocator_type;
			typedef value_type&                                   reference;
			typedef const value_type&                             const_reference;
			typedef value_type*                                   pointer;
			typedef const value_type*                             const_pointer;
			typedef ft::iterator<T>                               iterator;
			typedef ft::const_iterator<T>                         const_iterator;
			typedef ft::reverse_iterator<iterator>                reverse_iterator;
			typedef ft::const_reverse_iterator<const_iterator>    const_reverse_iterator;
			typedef std::ptrdiff_t                                difference_type;
			typedef std::size_t                                   size_type;
		
/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

		public:

			explicit Vector(const allocator_type& = allocator_type()) : ptr_(nullptr), size_(0), capacity_(0) {}

			explicit Vector(size_type n, const value_type& val = value_type(),
							const allocator_type& = allocator_type())
			{
				ptr_ = new T[n];
				for (unsigned long i = 0; i < n; i++)
					ptr_[i] = val;
				size_ = n;
				capacity_ = n;
			}

			Vector( Vector const & src )
			{
				this->size_ = src.size_;
				this->capacity_ = src.capacity_;

				if (src.ptr_)
				{
					this->ptr_ = new T[this->size_];
					for (unsigned long i = 0; i < size_; i++)
						this->ptr_[i] = src.ptr_[i];
				}
				else
				{
					this->ptr_ = nullptr;
				}
			}

/*
** ------------------------------- DESTRUCTOR --------------------------------
*/

			virtual ~Vector()
			{
				delete [] ptr_;
			}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

			Vector &		operator=( Vector const & rhs );

/*
** --------------------------------- ITERATORS ---------------------------------
*/

			iterator				begin() { return iterator(&ptr_[0]); }

			const_iterator			begin() const { return const_iterator(&ptr_[0]); }

			iterator				end() { return iterator(&ptr_[size_]); }

			const_iterator			end() const { return iterator(&ptr_[size_]); }

			reverse_iterator		rbegin() { return reverse_iterator(this->end()); }

			const_reverse_iterator	rbegin() const { return reverse_iterator(this->end()); }

			reverse_iterator		rend() { return (reverse_iterator(this->begin())); }

			const_reverse_iterator	rend() const { return (reverse_iterator(this->begin())); }

/*
** ------------------------------- CAPACITY --------------------------------
*/

			size_type				size() const { return size_; }

			size_type				max_size() const
			{ return std::numeric_limits<size_type>::max() / sizeof(value_type); }

			size_type				capacity() const { return capacity_; }

			bool					empty() const
			{
				if (size_ == 0)
					return 1;
				return 0;
			}

			void					reserve(size_type n)
			{
				if (n <= capacity_)
					return ;
				pointer aux = new T[n];
				for (unsigned long i = 0; i < size_; i++)
					aux[i] = ptr_[i];
				delete [] ptr_;
				ptr_ = aux;
				capacity_ = n;
			}

/*
** --------------------------------- MODIFIERS ---------------------------------
*/

			void					push_back(const value_type& val)
			{
				if (size_ >= capacity_)
					reserve(capacity_ * 2);
				ptr_[size_] = val;
				size_++;
			}

		private:
			pointer 	ptr_;
			size_type	size_;
			size_type	capacity_;

	};
}


#endif /* ********************************************************** VECTOR_H */