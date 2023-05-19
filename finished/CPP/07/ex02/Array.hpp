#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>

template<typename T>
class Array {

    public:

        Array(void) : _size(0), _array(NULL) {

        }

        Array(unsigned int n) : _size(n) {

            _array = new T[n];
        }
        Array(Array const &src) {

            _size = src.size();
            if (_size == 0)
                _array = NULL;
            else
            {
                _array = new T[_size];
                for (unsigned int i = 0; i < _size; i++)
                    _array[i] = src[i];
            }
        }

        virtual ~Array(void) {

            if (_size > 0)
                delete [] _array;
        }

        Array   &operator=(Array const &rhs) {

            if (this == &rhs)
                return (*this);
            if (_size > 0)
                delete [] _array;
            _size = rhs.size();
            if (_size == 0)
                _array = NULL;
            else
            {
                _array = new T[_size];
                for (unsigned int i = 0; i < _size; i++)
                    _array[i] = rhs[i];
            }
            return (*this);
        }

        T   &operator[](int const i) const {

            if (i < 0 || i >= _size)
                throw (Array::OutOfArrayException());
            else
                return (_array[i]);
        }

        unsigned int size(void) const {

            return (this->_size);
        }

        class OutOfArrayException : public std::exception {
            public:
		        virtual const char *what() const throw() {
                    return ("Array Exception : index out of array");
                }
        };

    private:

        T               *_array;
        unsigned int    _size;
};

#endif