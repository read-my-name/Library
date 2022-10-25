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
