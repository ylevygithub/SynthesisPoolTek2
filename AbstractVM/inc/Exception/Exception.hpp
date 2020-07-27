//
// EPITECH PROJECT, 2020
// Exception.hpp
// File description:
// Exception.hpp
//

#ifndef EXCEPTION_HPP_
#define EXCEPTION_HPP_

#include <iostream>
#include <string>
#include <memory>
#include <exception>

class MyException {
    protected :
        std::string _msg;
    public :
        MyException(const std::string &msg) noexcept;
        ~MyException();
    public :
        const char *what() const noexcept {return (_msg.data());}
};

#endif
