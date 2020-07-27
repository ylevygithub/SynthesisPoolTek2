//
// EPITECH PROJECT, 2020
// abstractVM
// File description:
// Parsing.hpp
//

#ifndef PARSING_HPP_
#define PARSING_HPP_

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <stack>
using namespace std;

class Chipset
{
    public :
        Chipset(){}
        ~Chipset(){}
    public :
        std::vector<std::string> content_file;
    public :
        int verifFileFormat(char *file);
        void errorCli(int ac, char **av);
        int openFile(char *);
        int withFile(int, char *);
        int VM(int, char **);
        int readInput();
        int withFile(int);
        int verifContent();
        string instruction(string line);
};

class CPU : public Chipset
{
    public :
        stack<long double> s;
        stack<string> t;
        int reg[15];
    public :
        void push(string line);
        void pop();
        void dump();
        void clear();
        void dup();
        void swap();
        void assert(string line);
        void add();
        void sub();
        void mul();
        void div();
        void mod();
        void load(string line);
        void store(string line);
        void print();
        string recupValue(string line);
        string recupTypeAssert(string line);
        string recupTypePush(string line);
        string recupTypeLoad(string line);
        string recupType(string line);
        int getType(string type);
        int verifType(string type, long double v);
        int biggerInt(string type1, string type2);
};

#endif
