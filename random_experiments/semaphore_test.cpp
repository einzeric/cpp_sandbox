//Got rekt by an interview question about semaphore recently so I decided to try my hand at making one
//C++ does not have native semaphore support until C++20. This implementation uses condition variable
//Will try out the new countng_semaphore from C++20 later.

#include <iostream>
#include <condition_variable>
#include <thread>
#include <chrono>
#include <atomic>

class BinarySemaphore
{
public:
    void wait()
    {
        std::unique_lock<std::mutex> lck(m_mutex);
        m_cv.wait(lck, [this]{return m_count > 0;});
        m_count--;
    }
    void signal()
    {
        std::unique_lock<std::mutex> lck(m_mutex);
        m_count++;
        m_cv.notify_one();
    }
    
private:
    std::mutex m_mutex;
    std::condition_variable m_cv;
    int m_count = 0;
};

BinarySemaphore bsem;
std::atomic<int> producedCount = 0;
std::atomic<int> consumedCount = 0;

void produce()
{
    producedCount++;
    std::cout << "Produced " << producedCount << " breads.\n";
    bsem.signal();
}

void consume()
{
    bsem.wait();
    consumedCount++;
    std::cout << "Consumed " << consumedCount << " breads.\n";
}

int main()
{
    //Output can get mixed up, but consumed count will never exceed produced count
    
    std::thread consumerThreads[10];
    std::thread producerThreads[10];
    //Consume resources
    for(int i = 0; i < 10; i++)
    {
        consumerThreads[i] = std::thread(consume);
    }
    //Produce resources
    for(int i = 0; i < 10; i++)
    {
        producerThreads[i] = std::thread(produce);
    }
    
    //wait for threads to finish execution
    for(int i = 0; i < 10; i++)
    {
        consumerThreads[i].join();
    }
    for(int i = 0; i < 10; i++)
    {
        producerThreads[i].join();
    }

    return 0;
}