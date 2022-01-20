#include <iostream>
#include <memory>

std::unique_ptr<int> p(nullptr);

int main()
{
    //Q: These checks work for raw ptr, but do they also work for smart ptr?
    //A: Yes
    if(!p)
    {
        std::cout << "null\n";
    }
    
    if(nullptr == p)
    {
        std::cout << "still null";
    }
    
    return 0;
}