//
// Created by Jamis Heat on 6/2/21.
//

#ifndef CONT_MY_MAP_HPP
#define CONT_MY_MAP_HPP

namespace ft {
	template<class Key, class T, class Compare = std::less<Key> , class Alloc = std::allocator<std::pair<const Key,T> > >
	class Map {
	public:
		typedef Key	key_type;
		typedef T	mapped_type;
		typedef std::pair<const key_type , mapped_type> value_type;
		typedef Compare	key_compare;
		typedef Compare	value_compare;
		typedef
		typedef
		typedef
		typedef


	private:



	public:
		Map();
	};
}
#endif //CONT_MY_MAP_HPP
