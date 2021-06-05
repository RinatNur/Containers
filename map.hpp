//
// Created by Jamis Heat on 6/2/21.
//

#ifndef CONT_MY_MAP_HPP
#define CONT_MY_MAP_HPP

#include <map.hpp>

namespace ft {
	template<class Key, class T, class Compare = std::less<Key> , class Alloc = std::allocator<std::pair<const Key,T> > >
	class Map {
	public:

		typedef Key	key_type;
		typedef T	mapped_type;
		typedef std::pair<const key_type , mapped_type> value_type;
		typedef Compare	key_compare;
		typedef Compare	value_compare;
		typedef Alloc	allocator_type;
		typedef value_type&									reference;
		typedef const value_type&							const_reference;
		typedef value_type*									pointer;
		typedef const value_type*							const_pointer;
//		typedef ft::MapIterator<value_type>					iterator;
//		typedef ft::MapIterator<const value_type>			const_iterator;
//		typedef Reverse_iterator<iterator>					reverse_iterator;
//		typedef const reverse_iterator						const_reverse_iterator;
		typedef ptrdiff_t									difference_type;
		typedef unsigned long								size_type;
		typedef ft::MapNode<value_type>						node;
		typedef node*										node_pointer;

	private:

		node_pointer	root;
		node_pointer	nil;


	public:
		Map (const key_compare& comp = key_compare(),
			 const allocator_type& alloc = allocator_type()) : root (nullptr), nil(nullptr){}

		template <class InputIterator>
		Map (InputIterator first, InputIterator last,
		const key_compare& comp = key_compare(),
		const allocator_type& alloc = allocator_type()){}

		Map (const map& x){}

		pair<iterator,bool> insert (const value_type& val);

		iterator insert (iterator position, const value_type& val);

		template <class InputIterator>
		void insert (InputIterator first, InputIterator last);
	};
}
#endif //CONT_MY_MAP_HPP
