#ifndef SETITERATOR_HPP
# define SETITERATOR_HPP
# include <iostream>

namespace ft
{
	template <class T>
	struct SNode
	{
		T		data;
		SNode*	left;
		SNode*	right;
		SNode*	parent;
	};

	template <class T, class Category = std::bidirectional_iterator_tag>
	class SetIterator
	{
		public:
			typedef T					value_type;
			typedef T&					reference;
			typedef SNode<T>*			pointer;
			typedef Category			iterator_category;
			typedef std::ptrdiff_t		difference_type;

		protected:
			pointer		node_;
			pointer		root_;
			pointer		noSegReturn;

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

			SetIterator() : node_(nullptr), root_(nullptr), noSegReturn(nullptr) {}

			SetIterator(pointer node) : node_(node), root_(nullptr), noSegReturn(nullptr) {}

			SetIterator(pointer node, pointer root) : node_(node), root_(root), noSegReturn(nullptr) {}

			SetIterator(SetIterator const & src) { *this = src; }

		/*
		** ------------------ DESTRUCTOR ------------------
		*/

			virtual ~SetIterator()
			{
				if (noSegReturn)
					delete noSegReturn;
			}

		/*
		** ------------------ OPERATORS ------------------
		*/

			SetIterator&	operator=(SetIterator const & rhs)
			{ this->node_ = rhs.node_; this->noSegReturn = rhs.noSegReturn; return *this ; }

			SetIterator&	operator++()
			{
				node_ = inOrderSuccesor(node_);
				return *this;
			}

			SetIterator		operator++(int)
			{
				SetIterator i = *this;
				this->operator++();
				return i;
			}

			SetIterator		operator--()
			{
				node_ = inOrderPredecessor(node_);
				return (*this);
			}

			SetIterator		operator--(int)
			{
				SetIterator	i = *this;
				this->operator--();
				return i;
			}

			bool			operator==(SetIterator const & rhs)
			{ return node_ == rhs.node_; }

			bool			operator!=(SetIterator const & rhs)
			{ return node_ != rhs.node_; }

			value_type&		operator*()
			{
				if (!node_)
				{
					noSegReturn = new SNode<T>;
					noSegReturn->data = 0;
					return (noSegReturn->data);
				}
				return (node_->data);
			}

			value_type*		operator->() { return (&node_->data); }

			pointer			getNode() const { return node_; }

	};

	template <class T, class Category = std::bidirectional_iterator_tag>
	class ConstSetIterator
	{
		public:
			typedef T					value_type;
			typedef T&					reference;
			typedef SNode<T>*			pointer;
			typedef Category			iterator_category;
			typedef std::ptrdiff_t		difference_type;

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

			ConstSetIterator() : node_(nullptr), root_(nullptr) {}

			ConstSetIterator(pointer node) : node_(node), root_(nullptr) {}

			ConstSetIterator(pointer node, pointer root) : node_(node), root_(root) {}

			ConstSetIterator(ConstSetIterator const & src) { *this = src; }

		/*
		** ------------------ DESTRUCTOR ------------------
		*/

			virtual ~ConstSetIterator() {}

		/*
		** ------------------ OPERATORS ------------------
		*/

			ConstSetIterator&	operator=(ConstSetIterator const & rhs)
			{ this->node_ = rhs.node_; return *this ; }

			ConstSetIterator&	operator++()
			{
				node_ = inOrderSuccesor(node_);
				return *this;
			}

			ConstSetIterator		operator++(int)
			{
				ConstSetIterator i = *this;
				this->operator++();
				return i;
			}

			ConstSetIterator		operator--()
			{
				node_ = inOrderPredecessor(node_);
				return (*this);
			}

			ConstSetIterator		operator--(int)
			{
				ConstSetIterator	i = *this;
				this->operator--();
				return i;
			}

			bool			operator==(ConstSetIterator const & rhs)
			{ return node_ == rhs.node_; }

			bool			operator!=(ConstSetIterator const & rhs)
			{ return node_ != rhs.node_; }

			const value_type&		operator*() { return (node_->data); }

			const value_type*		operator->() { return (&node_->data); }

			pointer			getNode() const { return node_; }

	};

	template <class T, class Category = std::bidirectional_iterator_tag>
	class ReverseSetIterator
	{
		public:
			typedef T					value_type;
			typedef T&					reference;
			typedef SNode<T>*			pointer;
			typedef Category			iterator_category;
			typedef std::ptrdiff_t		difference_type;

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

			ReverseSetIterator() : node_(nullptr), root_(nullptr) {}

			ReverseSetIterator(pointer node) : node_(node), root_(nullptr) {}

			ReverseSetIterator(pointer node, pointer root) : node_(node), root_(root) {}

			ReverseSetIterator(ReverseSetIterator const & src) { *this = src; }

		/*
		** ------------------ DESTRUCTOR ------------------
		*/

			virtual ~ReverseSetIterator() {}

		/*
		** ------------------ OPERATORS ------------------
		*/

			ReverseSetIterator&	operator=(ReverseSetIterator const & rhs)
			{ this->node_ = rhs.node_; return *this ; }

			ReverseSetIterator&	operator++()
			{
				node_ = inOrderPredecessor(node_);
				return *this;
			}

			ReverseSetIterator		operator++(int)
			{
				ReverseSetIterator i = *this;
				this->operator++();
				return i;
			}

			ReverseSetIterator		operator--()
			{
				node_ = inOrderSuccesor(node_);
				return (*this);
			}

			ReverseSetIterator		operator--(int)
			{
				ReverseSetIterator	i = *this;
				this->operator--();
				return i;
			}

			bool			operator==(ReverseSetIterator const & rhs)
			{ return node_ == rhs.node_; }

			bool			operator!=(ReverseSetIterator const & rhs)
			{ return node_ != rhs.node_; }

			value_type&		operator*() { return (node_->data); }

			value_type*		operator->() { return (&node_->data); }

			pointer			getNode() const { return node_; }

	};

	template <class T, class Category = std::bidirectional_iterator_tag>
	class ConstReverseSetIterator
	{
		public:
			typedef T					value_type;
			typedef T&					reference;
			typedef SNode<T>*			pointer;
			typedef Category			iterator_category;
			typedef std::ptrdiff_t		difference_type;

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

			ConstReverseSetIterator() : node_(nullptr), root_(nullptr) {}

			ConstReverseSetIterator(pointer node) : node_(node), root_(nullptr) {}

			ConstReverseSetIterator(pointer node, pointer root) : node_(node), root_(root) {}

			ConstReverseSetIterator(ConstReverseSetIterator const & src) { *this = src; }

		/*
		** ------------------ DESTRUCTOR ------------------
		*/

			virtual ~ConstReverseSetIterator() {}

		/*
		** ------------------ OPERATORS ------------------
		*/

			ConstReverseSetIterator&	operator=(ConstReverseSetIterator const & rhs)
			{ this->node_ = rhs.node_; return *this ; }

			ConstReverseSetIterator&	operator++()
			{
				node_ = inOrderPredecessor(node_);
				return *this;
			}

			ConstReverseSetIterator		operator++(int)
			{
				ConstReverseSetIterator i = *this;
				this->operator++();
				return i;
			}

			ConstReverseSetIterator		operator--()
			{
				node_ = inOrderSuccesor(node_);
				return (*this);
			}

			ConstReverseSetIterator		operator--(int)
			{
				ConstReverseSetIterator	i = *this;
				this->operator--();
				return i;
			}

			bool			operator==(ConstReverseSetIterator const & rhs)
			{ return node_ == rhs.node_; }

			bool			operator!=(ConstReverseSetIterator const & rhs)
			{ return node_ != rhs.node_; }

			const value_type&		operator*() { return (node_->data); }

			const value_type*		operator->() { return (&node_->data); }

			pointer			getNode() const { return node_; }

	};
}

#endif