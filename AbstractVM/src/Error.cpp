//
// EPITECH PROJECT, 2020
// abstractVM
// File description:
// Error.cpp
//

#include "../inc/Exception/Exception.hpp"
#include "../inc/Parsing.hpp"

void Chipset::errorCli(int ac, char **av)
{
    if (ac > 2)
        throw MyException("ERROR : there is more than 2 arguments in the command line");
    if (ac == 2 && verifFileFormat(av[1]) == 84)
        throw MyException("ERROR : File format is wrong. Need to terminate with '.avm'");
}
