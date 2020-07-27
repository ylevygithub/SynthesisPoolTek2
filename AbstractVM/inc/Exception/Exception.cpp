//
// EPITECH PROJECT, 2020
// Exception.cpp
// File description:
// Exception.cpp
//

#include "Exception.hpp"

MyException::MyException(const std::string &msg) noexcept
{
    _msg = msg;
}

MyException::~MyException() {}
