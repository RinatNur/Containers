//
// Created by Jamis Heat on 5/19/21.
//

#ifndef CONT_MY_ALGORITHM_HPP
#define CONT_MY_ALGORITHM_HPP

namespace ft {
	template <class InputIterator1, class InputIterator2>
	bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1,
								  InputIterator2 first2, InputIterator2 last2){
		if (first1 == first2)
			return false;
		while (first1 != last1)
		{
			if (*first2 < *first1)
				return false;
			else if (*first1 < *first2)
				return true;
			++first1;
			++first2;
		}
		if (first2 != last2)
			return true;
	}

	template<typename T>
	struct less: public std::binary_function<T, T, bool>
	{
		bool operator()(const T& x, const T& y) const {
			return (x < y);
		}
	};

	template<bool B, class T = void>
	struct enable_if {};

	template<class T>
	struct enable_if<true, T> { typedef T type; };

	template<class It>
	int distance(It const & first, It const & last)
	{
		int counter = 0;
		It tmp = first;

		for (; tmp != last; ++tmp)
			++counter;
		return counter;
	}


	template <class value_type>
	bool isEqual(value_type const &lhs, value_type const &rhs)
	{
		return lhs == rhs;
	}

	template <class value_type>
	bool less_than(value_type const &lhs, value_type const &rhs)
	{
		return lhs < rhs;
	}

	template <class value_type>
	bool more_than(value_type const &lhs, value_type const &rhs)
	{
		return lhs > rhs;
	}

	template<class value_type>
	value_type const &min(value_type const &a, value_type const &b) {
		return (a < b ? a : b);
	}

	template<class value_type>
	void swap_alg(value_type &a, value_type &b) {
		value_type tmp(a);
		a = b;
		b = tmp;
	}

}

#endif //CONT_MY_ALGORITHM_HPP
