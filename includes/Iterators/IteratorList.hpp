/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IteratorList.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalba-de <dalba-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 12:58:18 by dalba-de          #+#    #+#             */
/*   Updated: 2020/12/29 21:04:31 by dalba-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATORLIST_HPP
# define ITERATORLIST_HPP
# include <iostream>

namespace ft
{
	template <typename T>
	struct link
	{
		T		value;
		link<T>	*prev;
		link<T>	*next;

		link (const T &d = T(), link* p = nullptr, link* n = nullptr)
		: value(d), prev(p), next(n) { }
	};
	
	template <typename T, class Category = std::bidirectional_iterator_tag>
	class ListIterator
	{
		public:
			typedef T				value_type;
			typedef T&				reference;
			typedef link<T>*		pointer;
			typedef Category		iterator_category;
			typedef std::ptrdiff_t	difference_type;

		/*
		** ------------------ CONSTRUCTOR ------------------
		*/

		ListIterator() : node_(nullptr) {}

		ListIterator(pointer node) : node_(node) {}

		ListIterator(const ListIterator &src) { *this = src; }

		/*
		** ------------------ DESTRUCTOR ------------------
		*/

		virtual ~ListIterator() {}

		/*
		** ------------------ OPERATORS ------------------
		*/

		ListIterator & operator=(const ListIterator & rhs)
		{ this->node_ = rhs.node_; return *this; }

		ListIterator & operator++()
		{
			if (node_ && node_->next)
				node_ = node_->next;
			return *this;
		}

		ListIterator operator++(int)
		{
			ListIterator i = *this;
			this->operator++();
			return i;
		}

		ListIterator & operator--()
		{
			if (node_ && node_->prev)
				node_ = node_->prev;
			return *this;
		}

		ListIterator operator--(int)
		{
			ListIterator i = *this;
			this->operator--();
			return i;
		}

		bool			operator==(const ListIterator & rhs)
		{ return node_ == rhs.node_; }

		bool			operator!=(const ListIterator & rhs)
		{ return node_ != rhs.node_; }

		value_type&		operator*() { return node_->value; }

		value_type*		operator->() { return node_->value; }

		/*
		** ------------------ GETTERS ------------------
		*/

		pointer			getList() const { return node_; }

		protected:
			pointer		node_;
	};

	template <typename T, class Category = std::bidirectional_iterator_tag>
	class ConstListIterator
	{
		public:
			typedef T				value_type;
			typedef T&				reference;
			typedef link<T>*		pointer;
			typedef Category		iterator_category;
			typedef std::ptrdiff_t	difference_type;

		/*
		** ------------------ CONSTRUCTOR ------------------
		*/

		ConstListIterator() : node_(nullptr) {}

		ConstListIterator(pointer node) : node_(node) {}

		ConstListIterator(const ConstListIterator &src) { *this = src; }

		ConstListIterator(const ListIterator<T> & src) { node_ = src.getList(); }

		/*
		** ------------------ DESTRUCTOR ------------------
		*/

		virtual ~ConstListIterator() {}

		/*
		** ------------------ OPERATORS ------------------
		*/

		ConstListIterator & operator=(const ConstListIterator & rhs)
		{ this->node_ = rhs.node_; return *this; }

		ConstListIterator & operator++()
		{
			if (node_ && node_->next)
				node_ = node_->next;
			return *this;
		}

		ConstListIterator operator++(int)
		{
			ConstListIterator i = *this;
			this->operator++();
			return i;
		}

		ConstListIterator & operator--()
		{
			if (node_ && node_->prev)
				node_ = node_->prev;
			return *this;
		}

		ConstListIterator operator--(int)
		{
			ConstListIterator i = *this;
			this->operator--();
			return i;
		}

		bool			operator==(const ConstListIterator & rhs)
		{ return node_ == rhs.node_; }

		bool			operator!=(const ConstListIterator & rhs)
		{ return node_ != rhs.node_; }
		
		const value_type&	operator*() { return node_->value; }

		const value_type*	operator->() { return node_->value; }

		/*
		** ------------------ GETTERS ------------------
		*/

		pointer			getList() const { return node_; }

		protected:
			pointer		node_;
	};

	template <typename T, class Category = std::bidirectional_iterator_tag>
	class ReverseListIterator
	{
		public:
			typedef T				value_type;
			typedef T&				reference;
			typedef link<T>*		pointer;
			typedef Category		iterator_category;
			typedef std::ptrdiff_t	difference_type;

		/*
		** ------------------ CONSTRUCTOR ------------------
		*/

		ReverseListIterator() : node_(nullptr) {}

		ReverseListIterator(pointer node) : node_(node) {}

		ReverseListIterator(const ReverseListIterator &src) { *this = src; }

		/*
		** ------------------ DESTRUCTOR ------------------
		*/

		virtual ~ReverseListIterator() {}

		/*
		** ------------------ OPERATORS ------------------
		*/

		ReverseListIterator & operator=(const ReverseListIterator & rhs)
		{ this->node_ = rhs.node_; return *this; }

		ReverseListIterator & operator++()
		{
			if (node_ && node_->prev)
				node_ = node_->prev;
			return *this;
		}

		ReverseListIterator operator++(int)
		{
			ReverseListIterator i = *this;
			this->operator++();
			return i;
		}

		ReverseListIterator & operator--()
		{
			if (node_ && node_->next)
				node_ = node_->next;
			return *this;
		}

		ReverseListIterator operator--(int)
		{
			ReverseListIterator i = *this;
			this->operator--();
			return i;
		}

		bool			operator==(const ReverseListIterator & rhs)
		{ return node_ == rhs.node_; }

		bool			operator!=(const ReverseListIterator & rhs)
		{ return node_ != rhs.node_; }

		value_type&		operator*() { return node_->value; }

		value_type*		operator->() { return node_->value; }

		/*
		** ------------------ GETTERS ------------------
		*/

		pointer			getList() const { return node_; }

		protected:
			pointer		node_;
	};

	template <typename T, class Category = std::bidirectional_iterator_tag>
	class ConstReverseListIterator
	{
		public:
			typedef T				value_type;
			typedef T&				reference;
			typedef link<T>*		pointer;
			typedef Category		iterator_category;
			typedef std::ptrdiff_t	difference_type;

		/*
		** ------------------ CONSTRUCTOR ------------------
		*/

		ConstReverseListIterator() : node_(nullptr) {}

		ConstReverseListIterator(pointer node) : node_(node) {}

		ConstReverseListIterator(const ConstReverseListIterator &src) { *this = src; }

		ConstReverseListIterator(const ReverseListIterator<T> & src) { node_ = src.getList(); }

		/*
		** ------------------ DESTRUCTOR ------------------
		*/

		virtual ~ConstReverseListIterator() {}

		/*
		** ------------------ OPERATORS ------------------
		*/

		ConstReverseListIterator & operator=(const ConstReverseListIterator & rhs)
		{ this->node_ = rhs.node_; return *this; }

		ConstReverseListIterator & operator++()
		{
			if (node_ && node_->prev)
				node_ = node_->prev;
			return *this;
		}

		ConstReverseListIterator operator++(int)
		{
			ConstReverseListIterator i = *this;
			this->operator++();
			return i;
		}

		ConstReverseListIterator & operator--()
		{
			if (node_ && node_->next)
				node_ = node_->next;
			return *this;
		}

		ConstReverseListIterator operator--(int)
		{
			ConstReverseListIterator i = *this;
			this->operator--();
			return i;
		}

		bool			operator==(const ConstReverseListIterator & rhs)
		{ return node_ == rhs.node_; }

		bool			operator!=(const ConstReverseListIterator & rhs)
		{ return node_ != rhs.node_; }

		const value_type&		operator*() { return node_->value; }

		const value_type*		operator->() { return node_->value; }

		/*
		** ------------------ GETTERS ------------------
		*/

		pointer			getList() const { return node_; }

		protected:
			pointer		node_;
	};

}

#endif