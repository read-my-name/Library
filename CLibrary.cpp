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

int CLibrary::roman2num(std::string sIn)
{
	std::unordered_map <char, int> umrtoi{
	{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000} };

	int iRes = 0;
	int iLen = int(sIn.size());
	for (int i = 0; i < iLen; i++)
	{
		if (umrtoi[sIn[i]] < umrtoi[sIn[i + 1]])
		{// if you wonder why sIn[i+1] will not error at here, because it creates a new key
			//which is {'\0',0} in map if the key doesn't exist.
			// Also, [i+1] returns the actual null terminator '\0'
			iRes = iRes - umrtoi[sIn[i]];
		}
		else
		{
			iRes = iRes + umrtoi[sIn[i]];
		}
	}

	return iRes;
}

std::string CLibrary::sSortLower(std::string s)
{
	std::string sRes = "";
	int iCount[26] = { 0 };
	for (char ch : s)
	{
		iCount[ch - 'a']++;
	}
	for (int i = 0; i < 26; i++)
	{
		sRes += std::string(iCount[i], i + 'a');
	}
	return sRes;
}

std::string CLibrary::sSortUpper(std::string s)
{
	std::string sRes = "";
	int iCount[26] = { 0 };
	for (char ch : s)
	{
		iCount[ch - 'A']++;
	}
	for (int i = 0; i < 26; i++)
	{
		sRes += std::string(iCount[i], i + 'A');
	}
	return sRes;
}

void CLibrary::trimLeft(std::string& s) 
{// trim from start (in place)
	s.erase
	(
		s.begin(), 
		std::find_if(s.begin(), 
		s.end(), [](unsigned char ch) { return !std::isspace(ch); }
	));
}

void CLibrary::trimRight(std::string& s) 
{// trim from end (in place)
	s.erase
	(
		std::find_if(s.rbegin(), 
		s.rend(), 
		[](unsigned char ch) { return !std::isspace(ch); }
	).base(), s.end());
}