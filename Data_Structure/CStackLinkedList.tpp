#ifndef CSTACKLINKEDLIST_TPP
#define CSTACKLINKEDLIST_TPP

#include "CStackLinkedList.h"

template <class DataType>
void CStackLinkedList<DataType>::vPush(const DataType& newData)
{
	if (!this->m_ptrHead)
	{
		this->m_ptrHead = std::make_unique<stNode>(newData);
	}
	else
	{
		// Update the preference
		std::unique_ptr<stNode> tmpHead = std::move(this->m_ptrHead);
		this->m_ptrHead					= std::make_unique<stNode>(newData);
		this->m_ptrHead->ptrNext		= std::move(tmpHead);
	}
	this->m_iCount++;
}

template <class DataType>
DataType CStackLinkedList<DataType>::dtPop()
{// Remove item from a linked list takes O(1) thats why this operation is O(1)
	if (IsEmpty())
	{
		throw std::out_of_range("Stack is empty.");
	}
	// Compare to array, linked list do not need to resize. Do not need to shift
	// We have to remove the head node and update the references
	DataType dtItemPop				= this->m_ptrHead->m_data;
	std::unique_ptr<stNode> tmpNode = std::move(this->m_ptrHead->ptrNext);
	this->m_ptrHead					= std::move(tmpNode);
	this->m_iCount--;

	return dtItemPop;
}

template <class DataType>
bool CStackLinkedList<DataType>::IsEmpty()
{//if head is null will be true
	//O(1) operation
	return !this->m_ptrHead;
}

template <class DataType>
int CStackLinkedList<DataType>::iSize() const
{//O(1) operation
	return this->m_iCount;
}

#endif

