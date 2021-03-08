#ifndef	SET_HPP
# define SET_HPP
# include "../Tools/Algorithm.hpp"
# include "../Iterators/SetIterator.hpp"
# include <iostream>
# include <limits>
# include <memory>

namespace ft
{
	template <class T, class Compare = std::less<T>, class Alloc = std::allocator<T> >
	class Set
	{
/*
** ------------------------------- MEMBER TYPES -------------------------------
*/
		public:
			typedef T												key_type;
			typedef T												value_type;
			typedef Compare											key_compare;
			typedef Compare											value_compare;
			typedef Alloc											allocator_type;
			typedef T&												reference;
			typedef const T&										const_reference;
			typedef T*												pointer;
			typedef const T*										const_pointer;
			typedef ft::SetIterator<T>								iterator;
			typedef ft::ConstSetIterator<T>							const_iterator;
			typedef ft::ReverseSetIterator<T>						reverse_iterator;
			typedef ft::ConstReverseSetIterator<T>					const_reverse_iterator;
			typedef std::ptrdiff_t									difference_type;
			typedef std::size_t										size_type;
			typedef SNode<T>										node;

/*
** -------------------------------- NODE TYPES --------------------------------
*/

		private:
			node*		root;
			size_type	size_;
			key_compare	m_comp;

			node*		findMax(node* n) const
			{
				node* current = n;

				if (!current)
					return current;

				while (current->right != NULL)
					current = current->right;
				return current;
			}

			node*		findMin(node* n) const
			{
				node* current = n;

				while (current->left != NULL)
					current = current->left;
				return current;
			}

			node*		node_insert(value_type value, node* n)
			{
				if (n == NULL)
				{
					n = new node;
					n->data = value;
					n->left = n->right = n->parent = NULL;
				}
				else
				{
					if (m_comp(value, n->data))
					{
						if (!n->left)
						{
							n->left = node_insert(value, n->left);
							n->left->parent = n;
							return (n->left);
						}
						else
							return (node_insert(value, n->left));
					}
					else
					{
						if (!n->right)
						{
							n->right = node_insert(value, n->right);
							n->right->parent = n;
							return (n->right);
						}
						else
							return (node_insert(value, n->right));
					}
				}
				return n;
			}

			node*		search(node* n, key_type k) const
			{
				if (!n || n->data == k)
					return n;

				if (m_comp(n->data, k))
					return search(n->right, k);

				return  search(n->left, k);
			}

			void		deleteNode(node* n)
			{
				node *	curr = n;
				node *	parent;

				if (!curr->left && !curr->right)
				{
					if (curr == root)
						root = nullptr;
					else
					{
						parent = curr->parent;
						if (parent->left == curr)
							parent->left = nullptr;
						else if (parent->right == curr)
							parent->right = nullptr;
					}
					delete n;
					return ;
				}
				if (!curr->left && curr->right)
				{
					if (curr == root)
					{
						root = root->right;
						root->parent = nullptr;
						delete curr;
						return ;
					}
					parent = curr->parent;
					if (parent->left == curr)
					{
						parent->left = curr->right;
						curr->right->parent = parent;
					}
					else
					{
						parent->right = curr->right;
						curr->right->parent = parent;
					}
					delete n;
					return ;
				}
				if (curr->left && !curr->right)
				{
					if (curr == root)
					{
						root = root->left;
						root->parent = nullptr;
						delete curr;
						return ;
					}
					parent = curr->parent;
					if (parent->left == curr)
					{
						parent->left = curr->left;
						curr->left->parent = parent;
					}
					else
					{
						parent->right = curr->left;
						curr->left->parent = parent;
					}
					delete n;
					return ;
				}
				if (curr->left && curr->right)
				{
					if (!curr->right->left)
					{
						curr->data =  curr->right->data;
						node*	freep = curr->right;
						curr->right = curr->right->right;
						if (curr->right)
							curr->right->parent = curr;

						delete freep;
						return ;
					}
					node * 	succ = findMin(curr->right);
					node *	succParent = succ->parent;

					curr->data = succ->data;

					succParent->left = succ->right;
					if (succ->right)
						succ->right->parent = succParent;
					delete succ;
					return ;
				}
			}

			void		freeSet(node* n)
			{
				if (!n)
				{
					delete n;
					return ;
				}
				if (n->right)
					freeSet(n->right);
				if (n->left)
					freeSet(n->left);
				delete n;
			}

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/
		public:

			explicit Set	(const key_compare& comp = key_compare(),
							const allocator_type& = allocator_type())
							: root(nullptr), size_(0), m_comp(comp) {}

			Set				(const Set & x) : root(nullptr), size_(0)
			{
				m_comp = x.key_comp();
				*this = x;
				return ;
			}

			template <class InputIterator>
			Set				(InputIterator first, InputIterator last,
							const key_compare& = key_compare(),
							const allocator_type& = allocator_type())
							: root(nullptr), size_(0)
			{
				this->insert(first, last);
			}

/*
** ------------------------------- DESTRUCTOR --------------------------------
*/

		virtual ~Set() { freeSet(root); }

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

		Set&		operator=(Set const& rhs) 
		{
			if (!rhs.empty())
			{
				this->clear();
				this->insert(rhs.begin(), rhs.end());
			}
			else
				this->clear();
			return *this;
		}

/*
** --------------------------------- ITERATORS ---------------------------------
*/

		iterator				begin()
		{
			if (!root)
				return this->end();
			return iterator(findMin(root), root);
		}

		const_iterator			begin() const
		{
			return const_iterator(findMin(root), root);
		}

		iterator				end()
		{
			if (!root)
				return NULL;
			node *	aux = findMax(root);
			return iterator(aux->right, root);
		}

		const_iterator			end() const
		{
			node *	aux = findMax(root);
			return const_iterator(aux->right, root);
		}

		reverse_iterator		rbegin()
		{
			return reverse_iterator(findMax(root), root);
		}

		const_reverse_iterator	rbegin() const
		{
			return const_reverse_iterator(findMax(root), root);
		}

		reverse_iterator		rend()
		{
			node *	aux = findMin(root);
			return reverse_iterator(aux->left, root);
		}

		const_reverse_iterator	rend() const
		{
			node *	aux = findMin(root);
			return const_reverse_iterator(aux->left, root);
		}

/*
** ------------------------------- CAPACITY --------------------------------
*/

		bool		empty() const
		{
			if (size_ == 0)
				return 1;
			return 0;
		}

		size_type	size() const
		{ return size_; }

		size_type	max_size() const
		{ return (std::numeric_limits<size_type>::max()/(sizeof(node) + sizeof(pointer))); }

/*
** -------------------------------- MODIFIERS ---------------------------------
*/

		std::pair<iterator, bool>		insert(const value_type& val)
		{
			iterator tmp;

			tmp = find(val);
			if (tmp != this->end())
				return (std::make_pair(tmp, false));
			size_++;
			if (!root)
			{
				root = node_insert(val, root);
				return (std::make_pair(iterator(root), true));
			}
			return (std::make_pair(iterator(node_insert(val, root)), true));
		}

		iterator						insert(iterator position, const value_type& val)
		{
			iterator tmp;

			tmp = find(val);
			if (tmp != this->end())
				return (tmp);
			size_++;
			if (!root)
			{
				root = node_insert(val, position.getNode());
				return (iterator(root));
			}
			return (iterator(node_insert(val, position.getNode())));
		}

		template <class InputIterator>
		void	insert(InputIterator first, InputIterator last,
				typename ft::enable_if<!std::is_integral<InputIterator>::value>::type * = 0)
		{
			while (first != last)
			{
				insert(*first);
				first++;
			}
		}

		void		erase(iterator position)
		{
			node*	aux = position.getNode();

			deleteNode(aux);
			size_--;
		}

		size_type	erase(const key_type& k)
		{
			iterator	it;

			it = find(k);
			if (it == this->end())
				return (0);
			erase(it);
			return (1);
		}

		void		erase(iterator first, iterator last)
		{
			iterator	position(first.getNode(), root);

			while (first != last)
			{
				position--;
				erase(first);
				if (position.getNode() != nullptr)
					position++;
				else
				{
					if (root)
						position = this->begin();
					else
						position = this->end();
				}
					
				first = position;
			}
		}

		void		swap(Set& x)
		{
			ft::swap(size_, x.size_);
			ft::swap(root, x.root);
		}

		void		clear()
		{
			if (!root)
				return  ;
			iterator it = this->begin();
			while (it != this->end())
				erase(it++);
		}

/*
** --------------------------------- OBSERVERS ---------------------------------
*/

		key_compare		key_comp() const
		{
			return m_comp;
		}

		value_compare	value_comp() const
		{
			return m_comp;
		}

/*
** --------------------------------- OPERATIONS ---------------------------------
*/

		iterator		find(const key_type& k)
		{
			node* tmp = search(root, k);

			if (!tmp)
				return (this->end());
			return (iterator(tmp));
		}

		const_iterator	find(const key_type& k) const
		{
			node* tmp = search(root, k);

			if (!tmp)
				return (this->end());
			return (const_iterator(tmp));
		}

		size_type		count(const value_type& val) const
		{
			const_iterator it;

			it = find(val);
			if (it != this->end())
				return (1);
			return (0);
		}

		iterator		lower_bound(const value_type& val)
		{
			for (iterator it = this->begin(); it != this->end(); it++)
			{
				if (!(m_comp(*it, val)))
					return (it);
			}
			return (end());
		}

		const_iterator	lower_bound(const value_type& val) const
		{
			for (const_iterator it = this->begin(); it != this->end(); it++)
			{
				if (!(m_comp(*it, val)))
					return (it);
			}
			return (end());
		}

		iterator		upper_bound(const key_type& val)
		{
			for (iterator it = this->begin(); it != this->end(); it++)
			{
				if (!(m_comp(*it, val)))
				{
					if (*it == val)
						return (++it);
					return (it);
				}
			}
			return (end());
		}

		const_iterator	upper_bound(const key_type& val) const
		{
			for (const_iterator it = this->begin(); it != this->end(); it++)
			{
				if (!(m_comp(*it, val)))
				{
					if (*it == val)
						return (++it);
					return (it);
				}
			}
			return (end());
		}

		std::pair<iterator, iterator>	equal_range(const key_type& k)
		{
			iterator itlow, itup;

			itlow = lower_bound(k);
			itup = upper_bound(k);
			return (std::make_pair(itlow, itup));
		}

		std::pair<const_iterator, const_iterator>	equal_range(const key_type& k) const
		{
			const_iterator itlow, itup;

			itlow = lower_bound(k);
			itup = upper_bound(k);
			return (std::make_pair(itlow, itup));
		}
	};

/*
** ---------------------------- RELATIONAL OPERATORS ----------------------------
*/

		template <class T, class Compare, class Alloc>
		bool	operator==(const Set<T, Compare, Alloc>& lhs,
							const Set<T, Compare, Alloc>& rhs)
		{
			if (lhs.size() != rhs. size())
				return false;
			return (ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
		}

		template <class T, class Compare, class Alloc>
		bool	operator!=(const Set<T, Compare, Alloc>& lhs,
							const Set<T, Compare, Alloc>& rhs)	
		{
			return (!(lhs == rhs));
		}

		template <class T, class Compare, class Alloc>
		bool	operator<(const Set<T, Compare, Alloc>& lhs,
							const Set<T, Compare, Alloc>& rhs)
		{
			return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
		}

		template <class T, class Compare, class Alloc>
		bool	operator<=(const Set<T, Compare, Alloc>& lhs,
							const Set<T, Compare, Alloc>& rhs)
		{
			return (!(rhs < lhs));
		}

		template <class T, class Compare, class Alloc>
		bool	operator>(const Set<T, Compare, Alloc>& lhs,
							const Set<T, Compare, Alloc>& rhs)
		{
			return (rhs < lhs);
		}

		template <class T, class Compare, class Alloc>
		bool	operator>=(const Set<T, Compare, Alloc>& lhs,
							const Set<T, Compare, Alloc>& rhs)
		{
			return (!(lhs < rhs));
		}

		template <class T, class Compare, class Alloc>
		void	swap(Set<T, Compare, Alloc>& x, Set<T, Compare, Alloc>& y)
		{
			x.swap(y);
		}
}

#endif