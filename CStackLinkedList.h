#pragma once

#ifndef CSTACKLINKEDLIST_H
#define CSTACKLINKEDLIST_H

#include <memory>
#include <stdexcept>

template <class DataType>
class CStackLinkedList
{
public:
	struct stNode
	{
		DataType m_data;
		std::unique_ptr<stNode> ptrNext;
		stNode(const DataType &data)
			: m_data(data)
		{}
	};

	void vPush(const DataType& data);
	DataType dtPop();
	int iSize() const;

private:
	DataType m_data;
	// Use to access the head node (1st Node)
	std::unique_ptr<stNode> m_ptrHead;
	int m_iCount = 0;

	bool IsEmpty();
};

#include "CStackLinkedList.tpp"

#endif

