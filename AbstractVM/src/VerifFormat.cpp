//
// EPITECH PROJECT, 2020
// abstractVM
// File description:
// VerifFormat.cpp
//

#include "../inc/Parsing.hpp"

int Chipset::verifFileFormat(char *file)
{
    int i = 0;

    while (file[i] != '.' && file[i] != '\0')
        i++;
    if (file[i] == '\0')
        return (84);
    if (file[i] == '.' && file[i+1] == 'a' &&
        file[i+2] == 'v' && file[i+3] == 'm')
        return (0);
    return (84);
}
