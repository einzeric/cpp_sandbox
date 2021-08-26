#include <iostream>
#include <thread>
#include <chrono>

int instanceCount = 0;

//Thread safe singleton implementation with lazy evaluation
//Reference: https://stackoverflow.com/questions/1008019/c-singleton-design-pattern
class Singleton
{
public:
    static Singleton& getInstance()
    {
        static Singleton instance;
        return instance;
    }
    
    Singleton& operator=(const Singleton& s) = delete;
    Singleton(const Singleton& s) = delete;
    
private:
    Singleton()
    {
        instanceCount++;
    }
};

void InitializeSingleton()
{
    std::this_thread::sleep_for(std::chrono::seconds(3));
    Singleton::getInstance();
    std::cout << "Instance count=" << instanceCount << "\n";
}

int main()
{
    //10 threads ready to race
    //Line formatting might be messed up, but value of instanceCount is always guaranteed to be 1
    std::thread threadArray[10];
    for(int i = 0; i < 10; i++)
    {
        threadArray[i] = std::thread(InitializeSingleton);
    }
    
    for(int i = 0; i < 10; i++)
    {
        threadArray[i].join();
    }
    
    return 0;
}