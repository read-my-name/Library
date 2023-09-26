#ifndef CSTACKARRAY_TPP
#define CSTACKARRAY_TPP

#include "CStackArray.h"

template <class DataType>
CStackArray<DataType>::CStackArray()
{
	this->m_stack = new DataType[1];
	this->m_iCapacity = 1;
}

template <class DataType>
CStackArray<DataType>::~CStackArray()
{
	delete[] this->m_stack;
	//std::cout << "//Destructor\n";
}

// o(1) if no need to resize
template <class DataType>
void CStackArray<DataType>::vPush(const DataType& item)
{
	//O(N) Sometimes need to resize the array
	if (this->m_iNumItem == this->m_iCapacity)
	{
		vResize(2 * this->m_iCapacity);
	}
	this->m_stack[this->m_iNumItem++] = item;
}

//O(1) if no need to resize
template <class DataType>
DataType CStackArray<DataType>::dtPop()
{
	if (IsEmpty())
	{
		throw std::out_of_range("Stack is empty.");
	}

	//Item which want to pop
	DataType dtItem = this->m_stack[--this->m_iNumItem];

	//O(N) if we have pop too many item, we have to resize the array
	if (this->m_iNumItem > 0 && this->m_iNumItem == this->m_iCapacity / 4)
	{
		vResize(this->m_iCapacity / 2);
	}

	//return the item itself
	return dtItem;
}

template <class DataType>
bool CStackArray<DataType>::IsEmpty() const
{// O(1) operation
	return 0 == this->m_iNumItem;
}

template <class DataType>
int CStackArray<DataType>::iSize() const
{// O(1) operation
	return this->m_iNumItem;
}

template <class DataType>
void CStackArray<DataType>::vResize(int iCapacity)
{
	DataType* dtStack	= new DataType[iCapacity];

	for (int i = 0; i < this->m_iNumItem; i++)
	{
		dtStack[i] = this->m_stack[i];
	}

	delete[]this->m_stack;
	this->m_stack		= dtStack;
	this->m_iCapacity	= iCapacity;
}

#endif // CSTACKARRAY_H.tpp
