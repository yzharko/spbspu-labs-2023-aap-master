#include <iostream>
#include "findlocalmax.hpp"

int main()
{
    size_t value = 0;
    bool verify = true;
    using namespace lisitsyna;
    FindLocalMax findLocalMax;
    try
    {
        std::cin >> value;
        if (std::cin.fail())
        {
            throw std::invalid_argument("Invalid Input");
        }
        if (value == 0) {
            std::cerr << "Error output (return code 2)" << "\n";
            return 2;
        }
    }
    catch (const std::exception& ex)
    {
        std::cerr << "Invalid input!";
        return 1;
    }
    while (value != 0)
    {
        if (!verify)
        {
            std::cerr << "Error output (return code 2)" << "\n";
            return 2;
        }
        else
        {
            findLocalMax(value);
        }
        try
        {
            std::cin >> value;
            if (std::cin.fail())
            {
                throw std::invalid_argument("Invalid Input");
            }
            if (value == 0) {
                verify = false;
            }
            else
            {
                verify = true;
            }
        }
        catch (const std::exception& ex)
        {
            std::cerr << "Invalid input!";
            return 1;
        }
    }
    std::cout << findLocalMax() << "\n";
    return 0;
}
