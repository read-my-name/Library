#pragma once
#include "include.h"


class CTemplate
{
public:
	CTemplate();
	~CTemplate();
    friend class CLibrary;

private:
    // Function template to print 1d vector
    template <typename vec1D>
    void print_1Dvector(const std::vector<vec1D>& vec, std::string sSep = " ")
    {
        for (auto element : vec)
        {
            std::cout << element << sSep;
        }
        std::cout << "\n";
    }

    // Function template to print 2d vector
    template <typename vec2D>
    void print_2Dvector(const std::vector<std::vector<vec2D>>& vec, std::string sSep = " ")
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
};

