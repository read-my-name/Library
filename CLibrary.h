#pragma once
#include "include.h"

#ifdef DEBUG

#elif RELEASE

#else

#endif

class CLibrary
{
public:
	CLibrary();
	~CLibrary();

    //  Template function to print a vector on console
    template <typename T>
    void print_vector(const std::vector<T>& vec, std::string sSep = " ")
    {
        for (auto element : vec)
        {
            std::cout << element << sSep;
        }
        std::cout << "\n";
    }

    template <typename doubleVec>
    void print_double_vector(const std::vector<std::vector<doubleVec>>& vec, std::string sSep = " ")
    {
        for (auto element1 : vec)
        {
            std::cout << "[";
            for (auto element2 : element1)
            {
                std::cout << element2 << sSep;
            }
            std::cout << "]";
        }
        std::cout << "\n";
    }

    int print_char_array(std::ostream& os, char* string);
    bool is_digit(std::string& sIn);
    std::string num2roman(int number);
    int roman2num(std::string sIn);
    std::string sSortLower(std::string s);
    std::string sSortUpper(std::string s);

private:

};

