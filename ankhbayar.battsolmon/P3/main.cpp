#include <iostream>
#include <print>
#include <string>
#include <iomanip>
#include <cctype>
#include "shr_sym.hpp"
#include "dif_lat.hpp"

void printArr(char* arr, size_t size)
{
    for (size_t i = 0; i < size; i++)
    {
        std::cout << arr[i];
    }
    std::cout << '\n';
}

void cleanBuffer(char* buffer, size_t buffSize)
{
    for (size_t i = 0; i < buffSize; i++)
    {
        buffer[i] = 0;
    }
}

size_t copyBufferToString(char* buffer, size_t buffSize, size_t startIndex, char* str, size_t& strSize);

size_t extendString(char* str, size_t strSize, size_t buffSize)
{
    size_t sizeExtended = strSize + buffSize;
    char* temp = new char[sizeExtended];
    copyBufferToString(str, strSize, 0, temp, sizeExtended);
    str = temp;
    temp = nullptr;
    return sizeExtended;
}

size_t copyBufferToString(char* buffer, size_t buffSize, size_t startIndex, char* str, size_t& strSize)
{
    if (startIndex + buffSize > strSize)
    {
        strSize = extendString(str, strSize, buffSize);
    }
    size_t indexOfLastFree = startIndex;
    while (indexOfLastFree < startIndex + buffSize && buffer[indexOfLastFree - startIndex])
    {
        std::cout << buffer[indexOfLastFree - startIndex] << '\n';
        str[indexOfLastFree] = buffer[indexOfLastFree - startIndex];;
        indexOfLastFree++;
    }
    return indexOfLastFree;
}

bool cinToBuffer(char* buffer, size_t buffSize)
{
    printArr(buffer, buffSize);
    std::cin >> std::noskipws;
    size_t buffIndex = 0;
    char c = 0;
    while (std::cin >> c)
    {
        std::cout << "c = " << c << '\n';
        buffer[buffIndex++] = c;
        if (c == '\n')
        {
            buffer[buffIndex - 1] = 0;
            break;
        }
        if (buffIndex >= buffSize)
        {
            printArr(buffer, buffSize);
            return false;
        }
    }
    std::cin >> std::skipws;
    return true;
}

int main()
{
    std::cin >> std::noskipws;
    size_t readStr1 = 0;
    size_t readStr2 = 0;
    char* string1 = new char[25];
    char* string2 = new char[25];
    try
    {
    }
    catch (const std::bad_alloc& e)
    {
        std::cerr << "Unable to allocate memory\n";
        return 1;
    }
    char outputShrSym[26] = {};
    tsomo::missingChar(string1, outputShrSym, readStr1);
    std::cout << outputShrSym << "\n";

    std::cin >> std::skipws;
    delete[] string1;
    delete[] string2;

    using namespace tsomo;
    const size_t BUFF_SIZE = 5;
    Buffer buffer(BUFF_SIZE);
    std::string str;

    bool isEnd = false;
    while (!isEnd)
    {
        buffer.clean();
        isEnd = buffer.fillFromCin();
    }
    return 0;
}
