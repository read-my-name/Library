#pragma once

#ifndef CSTACKARRAY_H
#define CSTACKARRAY_H

#include <memory>
#include <stdexcept>
#include <iostream>

template <class DataType>
class CStackArray
{
public:
	CStackArray();
	~CStackArray();
	void vPush(const DataType &item);
	DataType dtPop();
	int iSize() const;
	

private:
	DataType* m_stack = nullptr;
	int m_iNumItem;
	int m_iCapacity;
	bool IsEmpty() const;
	void vResize(int iCapacity);
};

#include "CStackArray.tpp"

#endif

