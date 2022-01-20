//Stupid questions about custom deleter of smart ptr.
//Demo code use unique_ptr but this should also apply to shared_ptra
#include <iostream>
#include <memory>

void destroy1()
{
    std::cout << "Deleting unique ptr 1\n";
}

void destroy2(int* p, int x)
{
    std::cout << "Deleting unique ptr 2\n";
}

void destroy3(float* p)
{
    std::cout << "Deleting unique ptr 3\n";
}

void destroy4(int* p)
{
    std::cout << "Deleting unique ptr 4\n";
    delete p;
}

void destroy5(int* p)
{
    std::cout << "Pretending to delete unique ptr 5\n";
}

//Q1: Is it possible to use any function as the custom deleter?
//Answer: No. Custom deleter must have this exact signature: [return_type] [func_name]([ptr_type]* [param_name])
// std::unique_ptr<int, decltype(&destroy1)> p1(new int(5), destroy1); <- Compile error
// std::unique_ptr<int, decltype(&destroy2)> p1(new int(5), destroy2); <- Compile error
// std::unique_ptr<int, decltype(&destroy3)> p1(new int(5), destroy3); <- Compile error
std::unique_ptr<int, decltype(&destroy4)> p1(new int(5), destroy4); //Works

//Q2: Is it possible to pass a custom deleter that does not actually delete the pointer?
//Answer: Yes. In fact, all sort of thing can happen in the custom deleter
std::unique_ptr<int, decltype(&destroy5)> p2(new int(5), destroy5); //Memory leak

int main()
{
    return 0;
}