#pragma once
#include "include.h"
#include "CTemplate.h"

#ifdef DEBUG

#elif RELEASE

#else

#endif

class CLibrary
{
public:
	CLibrary();
	~CLibrary();

    template <typename vec1d>
    void print_1Dvector(const std::vector<vec1d>& vec, std::string sSep = " ")
    {
        CTemplate cTmp;
        cTmp.print_1Dvector(vec, sSep);
    }
    template <typename vec2d>
    void print_2Dvector(const std::vector<vec2d>& vec, std::string sSep = " ")
    {
        CTemplate cTmp;
        cTmp.print_2Dvector(vec, sSep);
    }

    int print_char_array(std::ostream& os, char* string);
    bool is_digit(std::string& sIn);
    std::string num2roman(int number);
    int roman2num(std::string sIn);
    std::string sSortLower(std::string s);
    std::string sSortUpper(std::string s);

private:

};

