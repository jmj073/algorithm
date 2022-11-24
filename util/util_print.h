#ifndef _UTIL_PRINT_H_
#define _UTIL_PRINT_H_

#include <iostream>

template <typename I, typename T>
void print_seq(I first, I last, const T& separator) {
	for (; first != last; ++first) {
		std::cout << *first << separator;
	}
	std::cout << '\n';
}

#endif /* _UTIL_PRINT_H_ */