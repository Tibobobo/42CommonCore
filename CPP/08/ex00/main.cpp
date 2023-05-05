# include "easyfind.hpp"
# include <iostream>
# include <vector>
# include <list>

int	main(void) {

	std::cout << "Vector test" << std::endl << std::endl;

	std::vector<int> vect;
	for (int i= 0; i < 10; i++)
		vect.push_back(i);
	for (std::vector<int>::iterator it = vect.begin(); it != vect.end(); ++it)
		std::cout << *it << std::endl;

	std::cout << std::endl << "--------------------------------------" << std::endl << std::endl;

	try {
		std::cout << *easyfind(vect, 4) << std::endl;
		std::cout << *easyfind(vect, 0) << std::endl;
		std::cout << *easyfind(vect, 9) << std::endl;
		std::cout << *easyfind(vect, 10) << std::endl;
	}
	catch (std::exception &e) {
		std::cout <<e.what() << std::endl;
	}

	std::cout << std::endl << "--------------------------------------" << std::endl;
	std::cout <<  "--------------------------------------" << std::endl << std::endl;

	std::cout << "List test" << std::endl << std::endl;

	std::list<int> lst;
	for (int i= 0; i < 10; i++)
		lst.push_back(i);
	for (std::list<int>::iterator it2 = lst.begin(); it2 != lst.end(); ++it2)
		std::cout << *it2 << std::endl;

	std::cout << std::endl << "--------------------------------------" << std::endl << std::endl;

	try {
		std::cout << *easyfind(lst, 4) << std::endl;
		std::cout << *easyfind(lst, 0) << std::endl;
		std::cout << *easyfind(lst, 9) << std::endl;
		std::cout << *easyfind(lst, 10) << std::endl;
	}
	catch (std::exception &e) {
		std::cout <<e.what() << std::endl;
	}
	return (0);
}