#include <iostream>
#include <thread>
#include <chrono>

int instanceCount = 0;

//Naive singleton implementation, not thread-safe
class Singleton
{
public:
    static Singleton* getInstance()
    {
        if(!instance)
        {
            instance = new Singleton();
        }
        return instance;
    }
    
private:
    static Singleton* instance;
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

Singleton* Singleton::instance = nullptr;

int main()
{
    //10 threads ready to race
    //Output varies, but most likely will be greater than 1
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