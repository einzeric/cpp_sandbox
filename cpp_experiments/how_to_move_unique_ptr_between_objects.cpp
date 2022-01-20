#include <iostream>
#include <memory>

struct classA
{
    std::unique_ptr<int> summonPtr()
    {
        return std::make_unique<int>(13);
    }
};

struct classB
{
    classB() : ptr(nullptr) {}
    std::unique_ptr<int> ptr;
    void setPtr(std::unique_ptr<int> p)
    {
        // ptr = p; <- Compile error, use of deleted copy constructor
        ptr = std::move(p); //Work
    }
    
    void printPtr()
    {
        if(ptr)
        {
            std::cout << *ptr << "\n";
        }
        else
        {
            std::cout << "Ptr is null\n";
        }
    }
};

int main()
{
    classA objA;
    classB objB;
    
    objB.setPtr(objA.summonPtr());
    objB.printPtr();
    
    return 0;
}