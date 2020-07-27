//
// EPITECH PROJECT, 2020
// abstractVM
// File description:
// VM.cpp
//

#include "../inc/Exception/Exception.hpp"
#include "../inc/Parsing.hpp"
#include <cstring>
#include <cctype>
#include <algorithm>
string eraseSpace(string line)
{
    int i = 0;
    if (line[i] == ';' && line[i + 1] != ';')
        return (line);
	line.erase(remove_if(line.begin(), line.end(), ::isspace), line.end());
    return (line);
}

int Chipset::openFile(char *filename)
{
    ifstream file;
    string line;
    string line2;
    int i = 0;
    int verif = 0;

    file.open(filename);
    if (!file.is_open())
        throw MyException("ERROR : file cannot be open");
    while (getline(file, line)) {
        line2 = eraseSpace(line);
        content_file.push_back(eraseSpace(line2));
        if (line2 == "exit")
            verif++;
        // cout << "content : " << content_file[i++] << "\n";
    }
    // cout << "----------------" << endl;
    file.close();
    if (verif == 0) 
        throw MyException("ERROR : there is missing an exit instruction in the file");
    verifContent();
    return (0);
}

int Chipset::withFile(int ac)
{
    if (ac == 2)
        return (1);
    else
        return (0);
}

int Chipset::readInput()
{
    ofstream file;
    string line;
    string line2;
    ifstream f;

    file.open("z.txt", ios::out);
    if (!file.is_open())
        throw MyException("ERROR : file cannot be open");
    while (getline(cin, line) && line != ";;")
        file << line << endl;
    file.close();
    f.open("z.txt");
    while (getline(f, line)) {
        line2 = eraseSpace(line);
        content_file.push_back(eraseSpace(line2));
    }
    file.close();
    verifContent();
    return (0);
}

int Chipset::VM(int ac, char **av)
{
    if (withFile(ac) == 1)
        openFile(av[1]);
    else
        readInput();
    return (0);
}
