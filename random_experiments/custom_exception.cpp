#include <exception>
#include <iostream>

//Custom exception class
struct CustomException : public std::exception
{
    const char* what() const throw()
    {
        return "Exception thrown";
    }
};

//Driver code
int main()
{
    try
    {
        throw CustomException();
    }
    catch(CustomException& e)
    {
        std::cout << e.what();
    }
}