//
// EPITECH PROJECT, 2020
// abstractVM
// File description:
// main.cpp
//

#include "../inc/Exception/Exception.hpp"
#include "../inc/Parsing.hpp"

int main(int ac, char **av)
{
    Chipset p;
    try {
        p.errorCli(ac, av);
        p.VM(ac, av);
    }
    catch (MyException &msg) {
        cerr << msg.what() << endl;
        return (84);
    }
    return (0);
}
