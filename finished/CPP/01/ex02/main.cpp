#include <iostream>
#include <string>

int main(void) {

    std::string s = "HI THIS IS BRAIN";
    std::string *stringPTR = &s;
    std::string &stringREF = s;

    std::cout << "Address of string s : " << &s <<std::endl;
    std::cout << "Address stocked in stringPTR : " << stringPTR << std::endl;
    std::cout << "Address stocked in stringREF : " << &stringREF << std::endl << std::endl;
    std::cout << "Value of string s : " << s <<std::endl;
    std::cout << "Value pointed by stringPTR : " << *stringPTR <<std::endl;
    std::cout << "Value pointed by stringREF : " << stringREF <<std::endl;
    
    return (0);
}