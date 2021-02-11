#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <iostream>
# include <string>
# include <memory>
# include <limits>
# include <exception>
# include <stdexcept>
# include <sstream>
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

			const_iterator			end() const { return const_iterator(&ptr_[size_]); }

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

			void					resize(size_type n, value_type val = value_type())
			{
				if (n <= size_)
				{
					size_type	auxSize = size_;
					for (; n < auxSize; n++)
						pop_back();
				}
				else if (n > size_ && n <= capacity_)
				{
					size_type	auxSize = size_;
					for (; n > auxSize; n--)
						push_back(val);
				}
				else if (n > size_ && n > capacity_)
				{
					reserve(n);
					size_type	auxSize = size_;
					for (; n > auxSize; n--)
						push_back(val);
				}
			}

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
** ---------------------------- ELEMENT ACCESS -----------------------------
*/

			reference				operator[] (size_type n) { return ptr_[n]; }
			
			const_reference			operator[] (size_type n) const { return ptr_[n]; }

			reference				at (size_type n)
			{
				if (n > size_)
				{
					std::ostringstream os;
					os << "vector::_M_range_check: __n (which is " << n << ") >= this->size() (which is " << size_ << ")";
					throw std::out_of_range(os.str());
				}
				return ptr_[n];
			}

			const_reference			at (size_type n) const
			{
				if (n > size_)
				{
					std::ostringstream os;
					os << "vector::_M_range_check: __n (which is " << n << ") >= this->size() (which is " << size_ << ")";
					throw std::out_of_range(os.str());
				}
				return ptr_[n];
			}

			reference				front() { return ptr_[0]; }

			const_reference			front() const { return ptr_[0]; }

			reference				back() { return ptr_[size_ - 1]; }

			const_reference			back() const { return ptr_[size_ - 1]; }

/*
** --------------------------------- MODIFIERS ---------------------------------
*/

			template<class InputIterator>
			void					assign(InputIterator first, InputIterator last,
									typename std::enable_if<!std::is_integral<InputIterator>::value>::type * = 0)
			{
				clear();
				if (capacity_ == 0)
					reserve(std::distance(first, last));
				while (first != last)
				{
					push_back(*(first));
					first++;
				}
			}

			void					assign(size_type n, const value_type& val)
			{
				clear();
				if (capacity_ == 0)
					reserve(n);
				while (n > 0)
				{
					push_back(val);
					n--;
				}
			}

			void					push_back(const value_type& val)
			{
				if (size_ >= capacity_)
				{
					if (capacity_ == 0)
						reserve(1);
					else
						reserve(capacity_ * 2);
				}
				ptr_[size_] = val;
				size_++;
			}

			void					pop_back()
			{
				size_type	cont = size_ - 1;
				pointer		aux = new T[capacity_];

				for (size_type i = 0; i < cont; i++)
					aux[i] = ptr_[i];
				delete [] ptr_;
				ptr_ = aux;
				size_--;		
			}

			iterator				insert(iterator position, const value_type& val)
			{
				size_type	i = 0;
				iterator	aux = this->begin();

				while (aux != position)
				{
					i++;
					aux++;
				}
				if (size_ >= capacity_)
				{
					if (capacity_ == 0)
						reserve(1);
					else
						reserve(capacity_ + 1);
				}
				size_type	j = size_;
				while (j > i)
				{
					ptr_[j] = ptr_[j - 1];
					j--;
				}
				ptr_[i] = val;
				size_++;
				return (iterator(&ptr_[i]));
			}

			void					insert(iterator position, size_type n, const value_type& val)
			{
				/*size_type	i = 0;
				iterator	aux = this->begin();

				while (aux != position)
				{
					i++;
					aux++;
				}
				i = i + n - 1;
				if (size_ >= capacity_)
				{
					if (capacity_ == 0)
						reserve(1);
					else if ((size_ + n) <= (capacity_ * 2))
						reserve(capacity_ * 2);
					else
						reserve(size_ + n);
				}
				size_type	j = size_ + n - 1;
				while (j > i)
				{
					ptr_[j] = ptr_[j - n];
					j--;
				}
				size_ += n;
				while (n > 0)
				{
					ptr_[i] = val;
					i--;
					n--;
				}*/
				while (n > 0)
				{
					position = insert(position, val);
					n--;
				}
			}

			template <class InputIterator>
			void					insert(iterator position, InputIterator first, InputIterator last,
									typename std::enable_if<!std::is_integral<InputIterator>::value>::type * = 0)
			{
				while (first != last)
				{
					position = insert(position, *(first));
					first++;
					position++;
				}
			}

			/*iterator				erase(iterator position)
			{

			}*/

			void					clear()
			{
				while (!empty())
					pop_back();
			}

		private:
			pointer 	ptr_;
			size_type	size_;
			size_type	capacity_;

	};
}


#endif /* ********************************************************** VECTOR_H */