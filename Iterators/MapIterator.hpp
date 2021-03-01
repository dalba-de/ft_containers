#ifndef MAPITERATOR_HPP
# define MAPITERATOR_HPP
# include <iostream>

namespace ft
{
	template <class Key, class T>
	struct MNode
	{
		std::pair<Key, T>	pair;
		MNode*				left;
		MNode*				right;
		MNode*				parent;
	};

	template <class Key, class T, class Category = std::bidirectional_iterator_tag>
	class MapIterator
	{
		public:
			typedef std::pair<Key, T>			value_type;
			typedef std::pair<Key, T>&			reference;
			typedef MNode<Key, T>*				pointer;
			typedef Category					iterator_category;
			typedef std::ptrdiff_t				difference_type;

		protected:
			pointer		node_;
			pointer		root_;

		private:

			pointer		findMax(pointer n)
			{
				pointer current = n;

				while (current->right != NULL)
					current = current->right;
				return current;
			}

			pointer		findMin(pointer n)
			{
				pointer current = n;

				while (current->left != NULL)
					current = current->left;
				return current;
			}

			pointer		inOrderSuccesor(pointer n)
			{
				if (!n)
					return (findMin(root_));
				if (n->right != NULL)
					return findMin(n->right);
				pointer p = n->parent;
				while (p != NULL && n == p->right)
				{
					n = p;
					p = p->parent;
				}
				return p;
			}

			pointer		inOrderPredecessor(pointer n)
			{
				if (!n)
					return (findMax(root_));
				if (n->left != NULL)
					return findMax(n->left);
				pointer p = n->parent;
				while (p != NULL && n == p->left)
				{
					n = p;
					p = p->parent;
				}
				return p;
			}

		/*
		** ------------------ CONSTRUCTOR ------------------
		*/

		public:

		MapIterator() : node_(nullptr), root_(nullptr) {}

		MapIterator(pointer node) : node_(node), root_(nullptr) {}

		MapIterator(pointer node, pointer root) : node_(node), root_(root) {}

		MapIterator(MapIterator const & src) { *this = src; }

		/*
		** ------------------ DESTRUCTOR ------------------
		*/

		virtual ~MapIterator() {}

		/*
		** ------------------ OPERATORS ------------------
		*/

		MapIterator&	operator=(MapIterator const & rhs)
		{ this->node_ = rhs.node_; return *this; }

		MapIterator&	operator++()
		{
			node_ = inOrderSuccesor(node_);
			return *this;
		}

		MapIterator		operator++(int)
		{
			MapIterator i = *this;
			this->operator++();
			return i;
		}

		MapIterator&	operator--()
		{
			node_ = inOrderPredecessor(node_);
			return *this;
		}

		MapIterator		operator--(int)
		{
			MapIterator i = *this;
			this->operator--();
			return i;
		}

		bool			operator==(MapIterator const & rhs)
		{ return node_ == rhs.node_; }

		bool			operator!=(MapIterator const & rhs)
		{ return node_ != rhs.node_; }

		value_type&		operator*() { return (node_->pair); }

		value_type*		operator->() { return (&node_->pair); }

		pointer			getNode() const { return node_; }

	};

	template <class Key, class T, class Category = std::bidirectional_iterator_tag>
	class ConstMapIterator
	{
		public:
			typedef std::pair<Key, T>			value_type;
			typedef std::pair<Key, T>&			reference;
			typedef MNode<Key, T>*				pointer;
			typedef Category					iterator_category;
			typedef std::ptrdiff_t				difference_type;

		protected:
			pointer		node_;
			pointer		root_;

		private:

			pointer		findMax(pointer n)
			{
				pointer current = n;

				while (current->right != NULL)
					current = current->right;
				return current;
			}

			pointer		findMin(pointer n)
			{
				pointer current = n;

				while (current->left != NULL)
					current = current->left;
				return current;
			}

			pointer		inOrderSuccesor(pointer n)
			{
				if (n->right != NULL)
					return findMin(n->right);
				pointer p = n->parent;
				while (p != NULL && n == p->right)
				{
					n = p;
					p = p->parent;
				}
				return p;
			}

			pointer		inOrderPredecessor(pointer n)
			{
				if (!n)
					return (findMax(root_));
				if (n->left != NULL)
					return findMax(n->left);
				pointer p = n->parent;
				while (p != NULL && n == p->left)
				{
					n = p;
					p = p->parent;
				}
				return p;
			}

		/*
		** ------------------ CONSTRUCTOR ------------------
		*/

		public:

		ConstMapIterator() : node_(nullptr), root_(nullptr) {}

		ConstMapIterator(pointer node) : node_(node), root_(nullptr) {}
		
		ConstMapIterator(pointer node, pointer root) : node_(node), root_(root) {}

		ConstMapIterator(ConstMapIterator const & src) { *this = src; }

		/*
		** ------------------ DESTRUCTOR ------------------
		*/

		virtual ~ConstMapIterator() {}

		/*
		** ------------------ OPERATORS ------------------
		*/

		ConstMapIterator&	operator=(ConstMapIterator const & rhs)
		{ this->node_ = rhs.node_; return *this; }

		ConstMapIterator&	operator++()
		{
			node_ = inOrderSuccesor(node_);
			return *this;
		}

		ConstMapIterator		operator++(int)
		{
			ConstMapIterator i = *this;
			this->operator++();
			return i;
		}

		ConstMapIterator&	operator--()
		{
			node_ = inOrderPredecessor(node_);
			return *this;
		}

		ConstMapIterator		operator--(int)
		{
			ConstMapIterator i = *this;
			this->operator--();
			return i;
		}

		bool			operator==(ConstMapIterator const & rhs)
		{ return node_ == rhs.node_; }

		bool			operator!=(ConstMapIterator const & rhs)
		{ return node_ != rhs.node_; }

		const value_type&		operator*() { return (node_->pair); }

		const value_type*		operator->() { return (&node_->pair); }

	};


	template <class Key, class T, class Category = std::bidirectional_iterator_tag>
	class ReverseMapIterator
	{
		public:
			typedef std::pair<Key, T>			value_type;
			typedef std::pair<Key, T>&			reference;
			typedef MNode<Key, T>*				pointer;
			typedef Category					iterator_category;
			typedef std::ptrdiff_t				difference_type;

		protected:
			pointer		node_;
			pointer		root_;

		private:

			pointer		findMax(pointer n)
			{
				pointer current = n;

				while (current->right != NULL)
					current = current->right;
				return current;
			}

			pointer		findMin(pointer n)
			{
				pointer current = n;

				while (current->left != NULL)
					current = current->left;
				return current;
			}

			pointer		inOrderSuccesor(pointer n)
			{
				if (!n)
					return (findMin(root_));
				if (n->right != NULL)
					return findMin(n->right);
				pointer p = n->parent;
				while (p != NULL && n == p->right)
				{
					n = p;
					p = p->parent;
				}
				return p;
			}

			pointer		inOrderPredecessor(pointer n)
			{
				if (n && n->left != NULL)
					return findMax(n->left);
				pointer p = n->parent;
				while (p != NULL && n == p->left)
				{
					n = p;
					p = p->parent;
				}
				return p;
			}

		/*
		** ------------------ CONSTRUCTOR ------------------
		*/

		public:

		ReverseMapIterator() : node_(nullptr) {}

		ReverseMapIterator(pointer node) : node_(node) {}
		
		ReverseMapIterator(pointer node, pointer root) : node_(node), root_(root) {}

		ReverseMapIterator(ReverseMapIterator const & src) { *this = src; }

		/*
		** ------------------ DESTRUCTOR ------------------
		*/

		virtual ~ReverseMapIterator() {}

		/*
		** ------------------ OPERATORS ------------------
		*/

		ReverseMapIterator&	operator=(ReverseMapIterator const & rhs)
		{ this->node_ = rhs.node_; return *this; }

		ReverseMapIterator&	operator++()
		{
			node_ = inOrderPredecessor(node_);
			return *this;
		}

		ReverseMapIterator		operator++(int)
		{
			ReverseMapIterator i = *this;
			this->operator++();
			return i;
		}

		ReverseMapIterator&	operator--()
		{
			node_ = inOrderSuccesor(node_);
			return *this;
		}

		ReverseMapIterator		operator--(int)
		{
			ReverseMapIterator i = *this;
			this->operator--();
			return i;
		}

		bool			operator==(ReverseMapIterator const & rhs)
		{ return node_ == rhs.node_; }

		bool			operator!=(ReverseMapIterator const & rhs)
		{ return node_ != rhs.node_; }

		value_type&		operator*() { return (node_->pair); }

		value_type*		operator->() { return (&node_->pair); }

	};

	template <class Key, class T, class Category = std::bidirectional_iterator_tag>
	class ConstReverseMapIterator
	{
		public:
			typedef std::pair<Key, T>			value_type;
			typedef std::pair<Key, T>&			reference;
			typedef MNode<Key, T>*				pointer;
			typedef Category					iterator_category;
			typedef std::ptrdiff_t				difference_type;

		protected:
			pointer		node_;
			pointer		root_;

		private:

			pointer		findMax(pointer n)
			{
				pointer current = n;

				while (current->right != NULL)
					current = current->right;
				return current;
			}

			pointer		findMin(pointer n)
			{
				pointer current = n;

				while (current->left != NULL)
					current = current->left;
				return current;
			}

			pointer		inOrderSuccesor(pointer n)
			{
				if (!n)
					return (findMin(root_));
				if (n->right != NULL)
					return findMin(n->right);
				pointer p = n->parent;
				while (p != NULL && n == p->right)
				{
					n = p;
					p = p->parent;
				}
				return p;
			}

			pointer		inOrderPredecessor(pointer n)
			{
				if (n && n->left != NULL)
					return findMax(n->left);
				pointer p = n->parent;
				while (p != NULL && n == p->left)
				{
					n = p;
					p = p->parent;
				}
				return p;
			}

		/*
		** ------------------ CONSTRUCTOR ------------------
		*/

		public:

		ConstReverseMapIterator() : node_(nullptr) {}

		ConstReverseMapIterator(pointer node) : node_(node) {}
		
		ConstReverseMapIterator(pointer node, pointer root) : node_(node), root_(root) {}

		ConstReverseMapIterator(ConstReverseMapIterator const & src) { *this = src; }

		/*
		** ------------------ DESTRUCTOR ------------------
		*/

		virtual ~ConstReverseMapIterator() {}

		/*
		** ------------------ OPERATORS ------------------
		*/

		ConstReverseMapIterator&	operator=(ConstReverseMapIterator const & rhs)
		{ this->node_ = rhs.node_; return *this; }

		ConstReverseMapIterator&	operator++()
		{
			node_ = inOrderPredecessor(node_);
			return *this;
		}

		ConstReverseMapIterator		operator++(int)
		{
			ConstReverseMapIterator i = *this;
			this->operator++();
			return i;
		}

		ConstReverseMapIterator&	operator--()
		{
			node_ = inOrderSuccesor(node_);
			return *this;
		}

		ConstReverseMapIterator		operator--(int)
		{
			ConstReverseMapIterator i = *this;
			this->operator--();
			return i;
		}

		bool			operator==(ConstReverseMapIterator const & rhs)
		{ return node_ == rhs.node_; }

		bool			operator!=(ConstReverseMapIterator const & rhs)
		{ return node_ != rhs.node_; }

		const value_type&		operator*() { return (node_->pair); }

		const value_type*		operator->() { return (&node_->pair); }

	};
}

#endif