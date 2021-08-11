#pragma once
//#include "ClassB.hpp" <- needed if we only declare some member function of ClassB as friend

class ClassA
{
public:
    ClassA();
    ~ClassA();
    
//    friend void ClassB::printX(const ClassA&); <- only works if ClassA.hpp is included in ClassB.cpp
    friend class ClassB;

private:
    int x;
};

