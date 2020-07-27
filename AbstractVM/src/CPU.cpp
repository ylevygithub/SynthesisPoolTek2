//
// EPITECH PROJECT, 2020
// abstractVM
// File description:
// CPU.cpp
//

#include "../inc/Exception/Exception.hpp"
#include "../inc/Parsing.hpp"
#include "math.h"

int CPU::getType(string type)
{
    int i = 0;

    while (type[i+1] != '\0')
        i++;
    switch (type[i]) {
        case '8':return (0);break;
        case '6':return (1);break;
        case '2':return (2);break;
        case 't':return (3);break;
        case 'e':return (4);break;
        default:return (5);break;
    }
}
void CPU::push(string line)
{
    string type = recupTypePush(line);
    string value = recupValue(line);

    if (verifType(type, stold(value)) == 1) {
        if (getType(type) == 0 || getType(type) == 1 || getType(type) == 2) {
            int i862 = stoi(value);
            s.push(i862);
        }
        else if (getType(type) == 3) {
            float f = stof(value);
            s.push(f);
        }
        else if (getType(type) == 4) {
            double d = stod(value);
            s.push(d);
        }
        else if (getType(type) == 5) {
            long double bigdec = stold(value);
            s.push(bigdec);
        }
    }
    t.push(type);
}
void CPU::assert(string line)
{
    string typeas = recupTypeAssert(line);
    string valueas = recupValue(line);
    string value = to_string(s.top());

    if (!valueas.compare(value))
        throw MyException("ERROR : assert didn't work, the value passed and the one in the stack are not the same.");
    else if (typeas != t.top())
        throw MyException("ERROR : the type given by assert is not the same than the top of stack");
    else if (s.empty())
        throw MyException("ERROR : cannot assert, the stack is empty");
}
void CPU::pop()
{
    if (s.size() > 0) {
        s.pop();
        t.pop();
    }
    else
        throw MyException("ERROR : the program try to pop the stack but she is already empty");
}
int CPU::verifType(string type, long double v)
{
    if (getType(type) == 0) {
        if ((int)v > 127 || (int)v < -128)
            throw MyException("ERROR : Value of type int8 cannot exceed 127 and be less than -128.");
        return (1);
    }
    else if (getType(type) == 1) {
        if ((int)v > 32767 || (int)v < -32768)
            throw MyException("ERROR : Value of type int16 cannot exceed 32767 and be less than -32768.");
        return (1);
    }
    else if (getType(type) == 2) {
        if (v > 2147483647 || v < -2147483648)
            throw MyException("ERROR : Value of type int32 cannot exceed 2147483647 and be less than -2147483648.");
        return (1);
    }
    else if (getType(type) == 3) {
        if (v > pow(3.4*10, 38) || v < -9000000000)
            throw MyException("ERROR : Value of type float cannot exceed 3.4*10e+38 and be less than -3.4*10e-38.");
        return (1);
    }
    else if (getType(type) == 4) {
        if ((double)v > pow(1.7*10, 308) || (double)v < -900000000000000)
            throw MyException("ERROR : Value of type double cannot exceed 1.7*10e+308 and be less than -1.7*10e-308.");
        return (1);
    }
    else
        return (1);
}
int CPU::biggerInt(string type1, string type2)
{
    int a = getType(type1);
    int b = getType(type2);

    if (a > b)
        return (a);
    else
        return (b);
}
void CPU::add()
{
    if (s.empty() == true || s.size() < 2)
        throw MyException("ERROR : don't have enough members in the stack for a addition");
    else {
        string str1 = t.top();
        t.pop();
        string str2 = t.top();
        if (biggerInt(str1, str2) == 0 || biggerInt(str1, str2) == 1 ||
            biggerInt(str1, str2) == 2) {
            int v1 = (int)s.top();
            s.pop();
            int v2 = (int)s.top();
            if (verifType(str1, v1) == 1 && verifType(str2, v2) == 1) {
                s.pop();
                t.pop();
                int final = v2 + v1;
                s.push((int)final);
                int bigger = biggerInt(str1, str2);
                switch (bigger) {
                    case 0:t.push("int8");break;
                    case 1:t.push("int16");break;
                    case 2:t.push("int32");break;
                }
            }
        }
        else if (biggerInt(str1, str2) == 3) {
            float v1f = (float)s.top();
            s.pop();
            float v2f = (float)s.top();
            if (verifType(str1, v1f) == 1 && verifType(str2, v2f) == 1) {
                s.pop();
                t.pop();
                float final = v2f + v1f;
                s.push((float)final);
                t.push("float");
            }
        }
        else if (biggerInt(str1, str2) == 4) {
            double v1d = (double)s.top();
            s.pop();
            double v2d = (double)s.top();
            if (verifType(str1, v1d) == 1 && verifType(str2, v2d) == 1) {
                s.pop();
                t.pop();
                double final = v2d + v1d;
                s.push((double)final);
                t.push("double");
            }
        }
        else if (biggerInt(str1, str2) == 5) {
            long double v1ld = (long double)s.top();
            s.pop();
            long double v2ld = (long double)s.top();
            if (verifType(str1, v1ld) == 1 && verifType(str2, v2ld) == 1) {
                s.pop();
                t.pop();
                long double final = v2ld + v1ld;
                s.push((long double)final);
                t.push("bigdecimal");
            }
        }
    }
}
void CPU::sub()
{
    if (s.empty() == true || s.size() < 2)
        throw MyException("ERROR : don't have enough members in the stack for a sub");
    else {
        string str1 = t.top();
        t.pop();
        string str2 = t.top();
        if (biggerInt(str1, str2) == 0 || biggerInt(str1, str2) == 1 ||
            biggerInt(str1, str2) == 2) {
            int v1 = (int)s.top();
            s.pop();
            int v2 = (int)s.top();
            if (verifType(str1, v1) == 1 && verifType(str2, v2) == 1) {
                s.pop();
                t.pop();
                int final = v2 - v1;
                s.push((int)final);
                int bigger = biggerInt(str1, str2);
                switch (bigger) {
                    case 0:t.push("int8");break;
                    case 1:t.push("int16");break;
                    case 2:t.push("int32");break;
                }
            }
        }
        else if (biggerInt(str1, str2) == 3) {
            float v1f = (float)s.top();
            s.pop();
            float v2f = (float)s.top();
            if (verifType(str1, v1f) == 1 && verifType(str2, v2f) == 1) {
                s.pop();
                t.pop();
                float final = v2f - v1f;
                s.push((float)final);
                t.push("float");
            }
        }
        else if (biggerInt(str1, str2) == 4) {
            double v1d = (double)s.top();
            s.pop();
            double v2d = (double)s.top();
            if (verifType(str1, v1d) == 1 && verifType(str2, v2d) == 1) {
                s.pop();
                t.pop();
                double final = v2d - v1d;
                s.push((double)final);
                t.push("double");
            }
        }
        else if (biggerInt(str1, str2) == 5) {
            long double v1ld = (long double)s.top();
            s.pop();
            long double v2ld = (long double)s.top();
            if (verifType(str1, v1ld) == 1 && verifType(str2, v2ld) == 1) {
                s.pop();
                t.pop();
                long double final = v2ld - v1ld;
                s.push((long double)final);
                t.push("bigdecimal");
            }
        }
    }
}
void CPU::mul()
{
    if (s.empty() == true || s.size() < 2)
        throw MyException("ERROR : don't have enough members in the stack for a mul");
    else {
        string str1 = t.top();
        t.pop();
        string str2 = t.top();
        if (biggerInt(str1, str2) == 0 || biggerInt(str1, str2) == 1 ||
            biggerInt(str1, str2) == 2) {
            int v1 = (int)s.top();
            s.pop();
            int v2 = (int)s.top();
            if (verifType(str1, v1) == 1 && verifType(str2, v2) == 1) {
                s.pop();
                t.pop();
                int final = v2 * v1;
                s.push((int)final);
                int bigger = biggerInt(str1, str2);
                switch (bigger) {
                    case 0:t.push("int8");break;
                    case 1:t.push("int16");break;
                    case 2:t.push("int32");break;
                }
            }
        }
        else if (biggerInt(str1, str2) == 3) {
            float v1f = (float)s.top();
            s.pop();
            float v2f = (float)s.top();
            if (verifType(str1, v1f) == 1 && verifType(str2, v2f) == 1) {
                s.pop();
                t.pop();
                float final = v2f * v1f;
                s.push((float)final);
                t.push("float");
            }
        }
        else if (biggerInt(str1, str2) == 4) {
            double v1d = (double)s.top();
            s.pop();
            double v2d = (double)s.top();
            if (verifType(str1, v1d) == 1 && verifType(str2, v2d) == 1) {
                s.pop();
                t.pop();
                double final = v2d * v1d;
                s.push((double)final);
                t.push("double");
            }
        }
        else if (biggerInt(str1, str2) == 5) {
            long double v1ld = (long double)s.top();
            s.pop();
            long double v2ld = (long double)s.top();
            if (verifType(str1, v1ld) == 1 && verifType(str2, v2ld) == 1) {
                s.pop();
                t.pop();
                long double final = v2ld * v1ld;
                s.push((long double)final);
                t.push("bigdecimal");
            }
        }
    }
}
void verifDivisor(double v)
{
    if (v == 0)
        throw MyException("ERROR : the divisor cannot be equal to 0");
}
void CPU::div()
{
    if (s.empty() == true || s.size() < 2)
        throw MyException("ERROR : don't have enough members in the stack for a division");
    else {
        string str1 = t.top();
        t.pop();
        string str2 = t.top();
        if (biggerInt(str1, str2) == 0 || biggerInt(str1, str2) == 1 ||
            biggerInt(str1, str2) == 2) {
            int v1 = (int)s.top();
            s.pop();
            int v2 = (int)s.top();
            if (verifType(str1, v1) == 1 && verifType(str2, v2) == 1) {
                verifDivisor(v1);
                s.pop();
                t.pop();
                int final = v2 / v1;
                s.push((int)final);
                int bigger = biggerInt(str1, str2);
                switch (bigger) {
                    case 0:t.push("int8");break;
                    case 1:t.push("int16");break;
                    case 2:t.push("int32");break;
                }
            }
        }
        else if (biggerInt(str1, str2) == 3) {
            float v1f = (float)s.top();
            s.pop();
            float v2f = (float)s.top();
            if (verifType(str1, v1f) == 1 && verifType(str2, v2f) == 1) {
                verifDivisor(v1f);
                s.pop();
                t.pop();
                float final = v2f / v1f;
                s.push((float)final);
                t.push("float");
            }
        }
        else if (biggerInt(str1, str2) == 4) {
            double v1d = (double)s.top();
            s.pop();
            double v2d = (double)s.top();
            if (verifType(str1, v1d) == 1 && verifType(str2, v2d) == 1) {
                verifDivisor(v1d);
                s.pop();
                t.pop();
                double final = v2d / v1d;
                s.push((double)final);
                t.push("double");
            }
        }
        else if (biggerInt(str1, str2) == 5) {
            long double v1ld = (long double)s.top();
            s.pop();
            long double v2ld = (long double)s.top();
            if (verifType(str1, v1ld) == 1 && verifType(str2, v2ld) == 1) {
                verifDivisor(v1ld);
                s.pop();
                t.pop();
                long double final = v2ld / v1ld;
                s.push((long double)final);
                t.push("bigdecimal");
            }
        }
    }
}
void CPU::mod()
{
    if (s.empty() == true || s.size() < 2)
        throw MyException("ERROR : don't have enough members in the stack for a modulo");
    else {
        int v1 = s.top();
        s.pop();
        int v2 = s.top();
        string str1 = t.top();
        t.pop();
        string str2 = t.top();
        if (getType(str1) > 2 || getType(str2) > 2) {
            cout << str1 << endl;
            cout << str2 << endl;
            throw MyException("ERROR : modulo between doubles or floats is not possible.");
        }
        else if (verifType(str1, v1) == 1 && verifType(str2, v2) == 1) {
            verifDivisor(v1);
            int final = v2 % v1;
            s.pop();
            t.pop();
            s.push(final);
            int bigger = biggerInt(str1, str2);
            switch (bigger) {
                case 0:t.push("int8");break;
                case 1:t.push("int16");break;
                case 2:t.push("int32");break;
            }
        }
    }
}
void CPU::clear()
{
    while (!s.empty())
        s.pop();
}
void CPU::dup()
{
    long double value = s.top();
    string type = t.top();
    s.push(value);
    t.push(type);
}
void CPU::swap()
{
    long double d1 = s.top();
    s.pop();
    long double d2 = s.top();
    s.pop();
    string type1 = t.top();
    t.pop();
    string type2 = t.top();
    t.pop();
    s.push(d1);
    s.push(d2);
    t.push(type1);
    t.push(type2);
}
void CPU::dump()
{
    vector<double> vec;
    vector<string> vecT;
    int i = s.size();

    while (s.empty() == false) {
        if (t.top() == "int8")
            cout << (int)s.top() << endl;
        else if (t.top() == "int16")
            cout << (int)s.top() << endl;
        else if (t.top() == "int32")
            cout << (int)s.top() << endl;
        else if (t.top() == "double")
            cout << s.top() << endl;
        else if (t.top() == "float")
            cout << (float)s.top() << endl;
        else if (t.top() == "bigdecimal")
            cout << (long double)s.top() << endl;
        vec.push_back(s.top());
        vecT.push_back(t.top());
        s.pop();
        t.pop();
    }
    while (i > 0) {
        s.push(vec[i-1]);
        t.push(vecT[i-1]);        
        i--;
    }
    vec.empty();
}
void CPU::load(string line)
{
    string valueload = recupValue(line);
    int val = stoi(valueload);

    if (val > 15 || val < 0)
        throw MyException("ERROR : store v where v can only be between 0 to 15");
    if (reg[val] == 0)
        throw MyException("ERROR : The register doesn't contain a value");
    int valueReg = reg[val];
    string type = recupTypeLoad(line);
    s.push((double)valueReg);
    t.push(type);
}
void CPU::store(string line)
{
    string valueload = recupValue(line);
    int val = stoi(valueload);
    double d = s.top();
    int n = (int)d;
    if (!s.empty()) {
        s.pop();
        t.pop();
        reg[val] = n;
    }
    else
        throw MyException("ERROR : cannot store, the stack is empty");
}
void CPU::print()
{
    string type = t.top();
    char asciVal;

    if (type != "int8")
        throw MyException("ERROR : cannot print, the type of the top of the stack is not int8.");
    else {
        asciVal = uint8_t(s.top());
        cout << asciVal << endl;
    }
}
