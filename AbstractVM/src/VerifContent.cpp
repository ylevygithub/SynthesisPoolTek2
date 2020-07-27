//
// EPITECH PROJECT, 2020
// abstractVM
// File description:
// VerifContent.cpp
//

#include "../inc/Exception/Exception.hpp"
#include "../inc/Parsing.hpp"

int Chipset::verifContent()
{
    vector<string> line;
    string myinstruction;
    string type;
    CPU cpu;

    for (auto it = content_file.begin(); it != content_file.end(); it++) {
        if (it[0][0] == 'p' && it[0][1] == 'u' && it[0][2] == 's' && it[0][3] == 'h')
            cpu.push(*it);
        else if (it[0][0] == 'a' && it[0][1] == 'd' && it[0][2] == 'd')
            cpu.add();
        else if (it[0][0] == 's' && it[0][1] == 'u' && it[0][2] == 'b')
            cpu.sub();
        else if (it[0][0] == 'm' && it[0][1] == 'u' && it[0][2] == 'l')
            cpu.mul();
        else if (it[0][0] == 'd' && it[0][1] == 'i' && it[0][2] == 'v')
            cpu.div();
        else if (it[0][0] == 'm' && it[0][1] == 'o' && it[0][2] == 'd')
            cpu.mod();
        else if (it[0][0] == 'p' && it[0][1] == 'o' && it[0][2] == 'p')
            cpu.pop();
        else if (it[0][0] == 'a' && it[0][1] == 's' && it[0][2] == 's' && it[0][3] == 'e' && it[0][4] == 'r' && it[0][5] == 't')
            cpu.assert(*it);
        else if (it[0][0] == 'c' && it[0][1] == 'l' && it[0][2] == 'e' && it[0][3] == 'a' && it[0][4] == 'r')
            cpu.clear();
        else if (it[0][0] == 'd' && it[0][1] == 'u' && it[0][2] == 'p')
            cpu.dup();
        else if (it[0][0] == 's' && it[0][1] == 'w' && it[0][2] == 'a' && it[0][3] == 'p')
            cpu.swap();
        else if (it[0][0] == 'd' && it[0][1] == 'u' && it[0][2] == 'm' && it[0][3] == 'p')
            cpu.dump();
        else if (it[0][0] == 'l' && it[0][1] == 'o' && it[0][2] == 'a' && it[0][3] == 'd')
            cpu.load(*it);
        else if (it[0][0] == 's' && it[0][1] == 't' && it[0][2] == 'o' && it[0][3] == 'r' && it[0][4] == 'e')
            cpu.store(*it);
        else if (it[0][0] == 'e' && it[0][1] == 'x' && it[0][2] == 'i' && it[0][3] == 't')
            exit(0);
        else if (it[0][0] == 'p' && it[0][1] == 'r' && it[0][2] == 'i' && it[0][3] == 'n' && it[0][4] == 't')
            cpu.print();
        else if (it[0][0] == ';' && it[0][1] != ';')
            continue;
        else if (it[0][0] == ';' && it[0][1] == ';' && it[0][2] != '\0')
            continue;
        else if (it[0][0] == '\0')
            continue;
        else {
            // cout << *it << endl;
            throw MyException("ERROR : unknown or missing instruction.");
        }
    }
    return (0);
}
