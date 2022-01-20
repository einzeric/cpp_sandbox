#include <iostream>
#include <memory>

//Can unique_ptr be returned and passed as arguments?

class A
{
public:
    A() : x(new int(13)) {}
    // std::unique_ptr<int> getptr() <- Return a copy, doesn't work
    std::unique_ptr<int>& getptr() //Return a reference, work
    {
        return x;
    }
    
private:
    std::unique_ptr<int> x;
};

void printptr(const std::unique_ptr<int>& ptr)
{
    std::cout << *ptr << "\n"; //This is definitely not thread-safe
}

int main()
{
    A objA;
    // auto ref =  objA.getptr(); <- Doesn't work, returned reference cannot be bound to a lvalue
    printptr(objA.getptr()); //Bind returned reference to a rvalue, work
    
    return 0;
}