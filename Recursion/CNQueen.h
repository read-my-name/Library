#pragma once
#include <vector>
#include <iostream>

class CNQueen
{
public:
	
	CNQueen(int iNumOfQueen);
	~CNQueen();

	void vSolve();
	int iGetNumOfQueen();

private:
	std::vector<std::vector<int>> vChessTable;
	int m_iNumOfQueen;

	bool bSetQueen(int iCol);
	bool IsValidPlace(int iRow, int iCol) const;
	void vPrint() const;

};

