#include "Array.hpp"
#include <iostream>

int main(void) {

    Array<char> emptyCharArray;

    try {
        std::cout << emptyCharArray[0];
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << std::endl << "---------------------------------------------------------------" << std::endl << std::endl;

    Array<int> intArray(5);

    try {
        for (int i = 0; i < 5; i++)
        {
            intArray[i] = i * 2;
            std::cout << intArray[i] << std::endl;
        }
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    std::cout << std::endl << "---------------------------------------------------------------" << std::endl << std::endl;

    try {
        intArray[2] = 42;
        for (int i = 0; i < 5; i++)
            std::cout << intArray[i] << std::endl;
        std::cout << std::endl;
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    try {
        Array<int> intCopy(intArray);
        for (int i = 0; i < 5; i++)
            std::cout << intCopy[i] << std::endl;
        std::cout << std::endl;
        intCopy[2] = 4;
        for (int i = 0; i < 5; i++)
            std::cout << intCopy[i] << std::endl;
        std::cout << std::endl;
        for (int i = 0; i < 5; i++)
            std::cout << intArray[i] << std::endl;
        std::cout << std::endl;
        intArray = intCopy;
        for (int i = 0; i < 5; i++)
            std::cout << intArray[i] << std::endl;
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    std::cout << std::endl << "---------------------------------------------------------------" << std::endl << std::endl;

    Array<std::string> stringArray(3);
    try {
        stringArray[0] = "Salut";
        stringArray[1] = "ca";
        stringArray[2] = "va ?";
        for (int i = 0; i < 3; i++)
            std::cout << stringArray[i] << std::endl;
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    std::cout << std::endl << "---------------------------------------------------------------" << std::endl << std::endl;

    try {
        stringArray[42] = "Out or array";
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    try {
        intArray[-1] = -1;
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    return (0);
}