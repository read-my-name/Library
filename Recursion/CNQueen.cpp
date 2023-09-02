#include "CNQueen.h"

CNQueen::CNQueen(int iNumOfQueen)
	:m_iNumOfQueen(iNumOfQueen)
{
	// create a chess table in 2d array as many colimn and row
	vChessTable.resize(iNumOfQueen);
	for (std::vector<int>& vChessRow : vChessTable)
	{
		vChessRow.resize(iNumOfQueen);
	}
}

CNQueen::~CNQueen()
{
	std::cout << "Destructor\n";
}

void CNQueen::vSolve()
{ 
	if (bSetQueen(0))
	{
		vPrint();
	}
	else
	{
		std::cout << "There's no solution..\n";
	}
}

int CNQueen::iGetNumOfQueen()
{
	return this->m_iNumOfQueen;
}

bool CNQueen::bSetQueen(int iCol)
{
	//bool bRes = false;
	if (iCol == this->m_iNumOfQueen)
	{
		return true;
	}
	for (int iRow = 0; iRow < m_iNumOfQueen; ++iRow)
	{
		if (IsValidPlace(iRow, iCol))
		{
			vChessTable[iRow][iCol] = 1;
			if (bSetQueen(iCol + 1))
			{
				return true;
			}
			vChessTable[iRow][iCol] = 0;
		}
	}

	return false;
}

bool CNQueen::IsValidPlace(int iRow, int iCol) const
{
	// No queen is allowed in the same row
	for (int i = 0; i < iCol; i++)
	{
		if (vChessTable[iRow][i] == 1)
		{
			return false;
		}
	}
	// Diagonal : from top left
	for (int i = iRow, j = iCol; i >= 0 && j >= 0; i--,j--)
	{
		if (vChessTable[i][j])
		{
			return false;
		}
	}
	//Diagonal : from top right
	for (int i = iRow, j = iCol; i < m_iNumOfQueen && j >= 0; i++, j--)
	{
		if (vChessTable[i][j])
		{
			return false;
		}
	}
	return true;
}

void CNQueen::vPrint() const
{
	//* represents the queens and - represents an empty stats
	for (std::vector<int> i : vChessTable)
	{
		for (int j : i)
		{
			if (j == 1)
			{
				std::cout << "*";
			}
			else
			{
				std::cout << "-";
			}
		}
		std::cout << "\n";
	}
	std::cout << "\n";
}