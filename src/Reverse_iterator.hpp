//
// Created by Rinat Nurutdinow on 5/4/21.
//

#ifndef CONT_MY_REVERSE_ITERATOR_H
#define CONT_MY_REVERSE_ITERATOR_H

#include <iterator>
#include "Node.hpp"

namespace ft {
	template<class It>
	class Reverse_iterator : public It {
	public:
		using typename It::value_type;
		using typename It::pointer;
		using typename It::const_pointer;
		using typename It::reference;
		using typename It::const_reference;
		using typename It::difference_type;
	public:
		Reverse_iterator(): It() {}
		Reverse_iterator(It const &x): It(x) {}
		Reverse_iterator(Reverse_iterator const &rhs): It(rhs._ptr) {}
		virtual ~Reverse_iterator() {};

		Reverse_iterator &operator=(const Reverse_iterator &rhs) {
			this->_ptr = rhs._ptr;
			return *this;
		}

		Reverse_iterator operator++(int) {
			Reverse_iterator tmp(*this);
			operator++();
			return tmp;
		}

		It &operator++() {
			return (this->It::operator--());
		}

		Reverse_iterator operator--(int) {
			Reverse_iterator tmp(*this);
			operator--();
			return tmp;
		}

		It &operator--() {
			return (this->It::operator++());
		}

		reference operator*() {
			It tmp(*this);
			--tmp;
			return (*tmp);
		}
		const_reference operator*() const {
			It tmp(*this);
			--tmp;
			return (*tmp);
		}
	};
}

#endif //CONT_MY_REVERSE_ITERATOR_H
