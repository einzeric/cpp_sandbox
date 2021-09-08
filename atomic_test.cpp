//Small test of C++ atomic variable.

#include <iostream>
#include <atomic>
#include <thread>
#include <chrono>

int x = 0;
std::atomic<int> atomX = 0;

void incX()
{
    std::this_thread::sleep_for(std::chrono::seconds(1));
    x++;
    std::cout << "x=" << x << "\n";
}

void incAtomX()
{
    std::this_thread::sleep_for(std::chrono::seconds(1));
    atomX++; //Can this be used for thread synchronization instead of mutex?
    std::cout << "atomX=" << atomX << "\n";
}

int main()
{
    std::thread threadArr[10];
    //Increment x
    for(int i = 0; i < 10; i++)
    {
        threadArr[i] = std::thread(incX);
    }
    for(int i = 0; i < 10; i++)
    {
        threadArr[i].join();
    }
    
    // Increment atomX
    for(int i = 0; i < 10; i++)
    {
        threadArr[i] = std::thread(incAtomX);
    }
    for(int i = 0; i < 10; i++)
    {
        threadArr[i].join();
    }
    
    return 0;
}