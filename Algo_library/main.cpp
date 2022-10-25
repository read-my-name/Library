#include "include.h"
#include "Algo_lib1.h"

int main()
{
	std::cout << "Hello world" << std::endl;
	int nRes;
	Algo_lib1 obj;
	nRes = obj.nAdd(10, 20);
	obj.~Algo_lib1();
	//nRes = nAdd(10, 20);
	return 0;
}