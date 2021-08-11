#include "ClassB.hpp"
//#include "ClassA.hpp" <- used in the event we only declare printX as a friend function and not the whole class

ClassB::ClassB()
{
}

ClassB::~ClassB()
{
}

void ClassB::printX(const ClassA& objA)
{
    std::cout << objA.x << "\n";
}
