//
// EPITECH PROJECT, 2020
// abstractVM
// File description:
// Recup.cpp
//

#include "../inc/Exception/Exception.hpp"
#include "../inc/Parsing.hpp"

string CPU::recupType(string line)
{
    string type;
    size_t par1 = line.find('(');
    size_t space = line.find(' ');

    if (space != string::npos && par1 != string::npos) {
        int sp = space;
        int par = par1;
        type = line.substr(sp + 1, par - (sp+1));
    }
    return (type);
}

string CPU::recupTypeAssert(string line)
{
    string type;
    size_t par1 = line.find('(');
    size_t space = 5;

    if (space != string::npos && par1 != string::npos) {
        int sp = space;
        int par = par1;
        type = line.substr(sp + 1, par - (sp+1));
    }
    return (type);
}

string CPU::recupTypePush(string line)
{
    string type;
    size_t par1 = line.find('(');
    size_t space = 3;

    if (space != string::npos && par1 != string::npos) {
        int sp = space;
        int par = par1;
        type = line.substr(sp + 1, par - (sp+1));
    }
    return (type);
}

string CPU::recupTypeLoad(string line)
{
    string type;
    size_t par1 = line.find('(');
    size_t space = 3;

    if (space != string::npos && par1 != string::npos) {
        int sp = space;
        int par = par1;
        type = line.substr(sp + 1, par - (sp+1));
    }
    return (type);
}

string CPU::recupValue(string line)
{
    string value;
    size_t findPar1 = line.find('(');
    size_t findPar2 = line.find(')');

    if (findPar1 != string::npos && findPar2 != string::npos) {
        int par1 = findPar1;
        int par2 = findPar2;
        value = line.substr(par1 + 1, par2 - (par1+1));
    }
    return (value);
}
