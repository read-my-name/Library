#pragma once
#include "include.h"
class Algo_lib1
{
	//friend main;
	public:
		Algo_lib1();
		~Algo_lib1();

	//private:
		int nAdd(int nA, int nB);
		int lengthOfLongestSubstring(std::string szMsg); //All lower case
		bool checkInclusion(std::string sz1, std::string sz2);
};

