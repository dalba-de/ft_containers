#ifndef	MULTIMAP_HPP
# define MULTIMAP_HPP
# include "../Iterators/MapIterator.hpp"
# include "../Tools/Algorithm.hpp"
# include <iostream>
# include <string>
# include <limits>
# include <memory>

namespace ft
{
	template <class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<std::pair<const Key, T> > >
	class Multimap
	{

/*
** ------------------------------- MEMBER TYPES -------------------------------
*/

		public:
			typedef Key													key_type;
			typedef T													mapped_type;
			typedef std::pair<const key_type, mapped_type>				value_type;
			typedef Compare												key_compare;
			typedef Alloc												allocator_type;
			typedef mapped_type&										reference;
			typedef const mapped_type&									const_reference;
			typedef mapped_type*										pointer;
			typedef const mapped_type*									const_pointer;
			typedef ft::MapIterator<key_type, mapped_type>				iterator;
			typedef ft::ConstMapIterator<key_type, mapped_type>			const_iterator;
			typedef ft::ReverseMapIterator<key_type, mapped_type>		reverse_iterator;
			typedef ft::ConstReverseMapIterator<key_type, mapped_type>	const_reverse_iterator;
			typedef std::ptrdiff_t										difference_type;
			typedef std::size_t											size_type;
			typedef ft::MNode<Key, T>									node;
			class value_compare
			{
				friend class Multimap;
				protected:
				Compare comp;
				value_compare (Compare c) : comp(c) {}
				public:
				typedef bool result_type;
				typedef value_type first_argument_type;
				typedef value_type second_argument_type;
				bool operator() (const value_type& x, const value_type& y) const
				{
					return comp(x.first, y.first);
				}
			};

		private:
			node*		root;
			size_type	size_;
			key_compare	m_comp;

/*
** -------------------------------- NODE TYPES --------------------------------
*/

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

			node*		node_insert(key_type key, mapped_type value, node* n)
			{
				if (n == NULL)
				{
					n = new node;
					n->pair = std::make_pair(key, value);
					n->left = n->right = n->parent = NULL;
				}
				else
				{
					if (m_comp(key, n->pair.first))
					{
						if (!n->left)
						{
							n->left = node_insert(key, value, n->left);
							n->left->parent = n;
							return (n->left);
						}
						else
							return (node_insert(key, value, n->left));
					}
					else
					{
						if (!n->right)
						{
							n->right = node_insert(key, value, n->right);
							n->right->parent = n;
							return (n->right);
						}
						else
							return (node_insert(key, value, n->right));
					}
				}
				return n;
			}

			node*		search(node* n, key_type k)
			{
				if (!n || n->pair.first == k)
					return n;

				if (m_comp(n->pair.first, k))
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
						curr->pair.first =  curr->right->pair.first;
						curr->pair.second = curr->right->pair.second;
						node* freep = curr->right;
						curr->right = curr->right->right;
						if (curr->right)
							curr->right->parent = curr;

						delete freep;
						return ;
					}
					node * 	succ = findMin(curr->right);
					node *	succParent = succ->parent;

					curr->pair.first = succ->pair.first;
					curr->pair.second = succ->pair.second;

					succParent->left = succ->right;
					if (succ->right)
						succ->right->parent = succParent;
					delete succ;
					return ;
				}
			}

			void		freeMap(node* n)
			{
				if (n->right)
					freeMap(n->right);
				if (n->left)
					freeMap(n->left);
				delete n;
			}

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/
		public:

			explicit Multimap	(const key_compare& comp = key_compare(),
								const allocator_type& = allocator_type())
								: root(nullptr), size_(0), m_comp(comp) {}

/*
** ------------------------------- DESTRUCTOR --------------------------------
*/

		~Multimap() { freeMap(root); }


/*
** --------------------------------- ITERATORS ---------------------------------
*/

		iterator				begin()
		{
			return iterator(findMin(root), root);
		}

		const_iterator			begin() const
		{
			return const_iterator(findMin(root));
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
			return const_iterator(aux->right);
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

		iterator	insert(const value_type& val)
		{
			size_++;
			if (!root)
				return (iterator(root = node_insert(val.first, val.second, root)));
			return (iterator(node_insert(val.first, val.second, root)));
		}


		iterator	insert(iterator position, const value_type& val)
		{
			size_++;
			if (!root)
				return (iterator(root = node_insert(val.first, val.second, position.getNode())));
			return (iterator(node_insert(val.first, val.second, position.getNode())));
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
			int			i = 0;

			while ((it = find(k)) != this->end())
			{
				erase(it);
				i++;
			}
			return (i);
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

	};
}

#endif