#include "Span.hpp"
#include <iostream>

int	main(void) {

	Span sp = Span(5);

	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	std::cout << std::endl << "------------------------------------------" << std::endl << std::endl;

	Span sp2(3);

	try {
		std::cout << sp2.shortestSpan() << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	sp2.addNumber(6);
	sp2.addNumber(3);
	sp2.addNumber(17);
	try {
		sp2.addNumber(42);
	}
	catch (std::exception &e) {
		std::cout<< e.what() << std::endl;
	}

	std::cout << std::endl << "------------------------------------------" << std::endl << std::endl;

	Span sp3(10000);
	std::vector<int> test;
	for (int i = 0; i < 10000; i++)
		test.push_back(i * 2);
	sp3.addNumber(test.begin(), test.end());

	std::cout << sp3.shortestSpan() << std::endl;
	std::cout << sp3.longestSpan() << std::endl;

	try {
		sp3.addNumber(42);
	}
	catch (std::exception &e) {
		std::cout<< e.what() << std::endl;
	}

	return 0;
}