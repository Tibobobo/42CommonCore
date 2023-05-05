#include "iter.hpp"

template< typename T>
void    display(T &var) {

    std::cout << var << std::endl;
}

int main(void) {

    int test[5] = {1, 2, 3, 4, 5};
    std::string test2[3];

    test2[0] = "Salut";
    test2[1] = "ca";
    test2[2] = "va ?";

    iter(test, 5, display);
    std::cout << std::endl;
    iter(test2, 3, display);
    return (0);
}