#include "CLibrary.h"

CLibrary::CLibrary()
{

}

CLibrary::~CLibrary()
{

}

int CLibrary::print_char_array(std::ostream& os, char* string)
{
	int iRes = 1;
    // faster than an ostream_iterator and std::copy
	int iLen = int(strlen(string));
    os.write(string, iLen);
	return iRes;
}

bool CLibrary::is_digit(std::string& sInput)
{
	bool bRes;
	bRes = true;
	for (char ch : sInput)
	{
		if (!(ch >= 48 && ch <= 57))
		{
			bRes = false;
			break;
		}
	}
	return bRes;
}

std::string CLibrary::num2roman(int iNum)
{
	std::string sOut = "";
	if (iNum > INT_MAX || iNum < INT_MIN)
	{
		return "F";
	}
	/*std::vector<std::pair<int, std::string>> storeintroman = {
		{1000, "m"}, {900, "cm"}, {500, "d"},
		{400, "cd"}, {100, "c"}, {90, "xc"}, 
		{50, "L"}, {40, "XL"}, {10, "X"}, {9, "IX"}, 
		{5, "V"}, {4, "IV"}, {1, "I"}};*/

	std::string ones[] = { "","I","II","III","IV","V","VI","VII","VIII","IX" };
	std::string tens[] = { "","X","XX","XXX","XL","L","LX","LXX","LXXX","XC" };
	std::string hrns[] = { "","C","CC","CCC","CD","D","DC","DCC","DCCC","CM" };
	std::string ths[] = { "","M","MM","MMM" };

	sOut = ths[iNum / 1000] + hrns[(iNum % 1000) / 100] + tens[(iNum % 100) / 10] + ones[iNum % 10];
	return sOut;
}

int CLibrary::roman2num(std::string& sIn)
{
	int iOut = 0;


	return iOut;
}

