#include <iostream>
#include <fstream>
#include <iomanip>

int main(int ac, char **av) {

    if (ac != 4 || av[2][0] == '\0' || av[3][0] == '\0')
    {
        std::cerr << "Error\nProgram must be launched with 3 arguments : filename, s1 and s2\n";
        return (1);
    }
    std::ifstream   ifs(av[1]);
    if (ifs.is_open() == 0)
    {
        std::cerr << "Error\nFile " << av[1] << " couldn't be open or doesn't exist\n";
        return (1);
    }
    std::string buff = (std::string)av[1];
    buff += ".replace";
    std::ofstream ofs(buff);
    if (ofs.is_open() == 0)
    {
        std::cerr << "Error\nOutput file couldn't be open\n";
        return (1);
    }
    std::string to_rm = std::string(av[2]);
    std::string replacement = std::string(av[3]);
    size_t i = 0;
    while (getline(ifs, buff))
    {
        while(buff.find(to_rm, 0) != (size_t)-1)
        {
            i = buff.find(to_rm, 0);
            buff.erase(i, to_rm.length());
            buff.insert(i, replacement);
        }
        ofs << buff << std::endl;
    }
    ifs.close();
    ofs.close();
    return (0);
}