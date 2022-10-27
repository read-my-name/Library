#include "Algo_lib1.h"

Algo_lib1::Algo_lib1()
{
	std::cout << "Algo_lib1 Created" << "\n";
}

Algo_lib1::~Algo_lib1()
{
	std::cout << "Algo_lib1 Destroyed" << "\n";
}

int Algo_lib1::nAdd(int nA, int nB)
{
	std::cout << nA + nB << "\n";
	return nA + nB;
}

int Algo_lib1::lengthOfLongestSubstring(std::string szMsg) //All is lower case
{
    int nErase = 0;
    int nInsert = 0;
    int nLongest = 0;
    std::unordered_set<char> us;

    while (nInsert < szMsg.length())
    {
        if (us.find(szMsg[nInsert]) == us.end())
        { //will only enter when there's no same char inside, Eg: null
            us.insert(szMsg[nInsert]);
            nLongest = nLongest > nInsert - nErase + 1 ? nLongest : nInsert - nErase + 1; //max(nLongest, nInsert - nErase + 1)
            ++nInsert;
        }
        else
        { //enter here if found same char
            us.erase(szMsg[nErase]);
            ++nErase;
        }
    }
    return nLongest;
}

bool Algo_lib1::checkInclusion(std::string sz1, std::string sz2)
{
    int nMap[26] = { 0 };
    int j = 0, i = 0, nCount_chars = sz1.size();

    for (char c : sz1)
    { // convert char into ascii value (a = 97)
        nMap[c - 'a']++;
    }
    while (j < sz2.size())
    {
        if (nMap[sz2.at(j++) - 'a']-- > 0)
        {
            nCount_chars--;
        }
        if (nCount_chars == 0)
        {
            return true;
        }
        if (j - i == sz1.size() && nMap[sz2.at(i++) - 'a']++ >= 0)
        {
            nCount_chars++;
        }
    }
    return false;
}