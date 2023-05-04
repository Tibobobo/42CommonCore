#ifndef TEMPLATES_HPP
# define TEMPLATES_HPP

template<typename T>
void    swap(T &a, T &b) {

    T temp = a;
    a = b;
    b = temp;
}

template<typename U>
U const  &min(U const &a, U const &b) {

    return ((a < b) ? a : b);
}

template<typename V>
V const  &max(V const &a, V const &b) {

    return ((a > b) ? a : b);
}

#endif