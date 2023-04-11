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
	int iLen = strlen(string);
    os.write(string, iLen);
	return iRes;
}

bool CLibrary::is_digit(std::string& sInput)
{
	bool bRes;
	bRes = true;
	for (char ch : sInput)
	{
		int nDec;
		if (!(ch >= 48 && ch <= 57))
		{
			bRes = false;
			break;
		}
	}
	return bRes;
}

