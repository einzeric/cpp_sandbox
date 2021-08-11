#pragma once
#include <iostream>
#include "ClassA.hpp"

class ClassA;

class ClassB
{
public:
    ClassB();
    ~ClassB();

    void printX(const ClassA& objA);
};

