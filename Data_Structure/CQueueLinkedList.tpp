#ifndef CQUEUELINKEDLIST_TPP
#define CQUEUELINKEDLIST_TPP

#include "CQueueLinkedList.h"

template <class DataType>
void CQueueLinkedList<DataType>::vEnqueue(const DataType& newData)
{// Enqueue the item to the queue in O(1)
	this->m_iCount++;

	stNode *curNode					= this->m_stLastNode;
	//std::unique_ptr<stNode> ptrLast = std::make_unique<stNode>(newData);
	//this->m_stLastNode			  = std::move(ptrLast); // transfer ownership
	auto ptrLast					= std::make_unique<stNode>(newData);
	this->m_stLastNode				= ptrLast.get(); // get is for raw pointer

	// For the 1st node, it is the 1st as well as the last node
	if (IsEmpty())
	{
		this->m_ptrHead		= std::move(ptrLast);
	}
	else
	{// If not empty, update the reference
		curNode->ptrNext	= std::move(ptrLast);
	}
}

template <class DataType>
DataType CQueueLinkedList<DataType>::dtDequeue()
{// Dequeue the item in O(1)
	if (IsEmpty())
	{// If it is empty, return error
		throw std::out_of_range("Queue is empty.");
	}
	this->m_iCount--;

	// Remove the 1st Node and update the reference
	DataType dtItemDequeue		= std::move(this->m_ptrHead->m_data);
	std::unique_ptr<stNode> tmp = std::move(this->m_ptrHead->ptrNext);
	this->m_ptrHead				= std::move(tmp);

	// If we call dequeue when there's just 1 item in the queue
	if (IsEmpty())
	{
		this->m_ptrHead = nullptr;
	}
	return dtItemDequeue;
}

template <class DataType>
int CQueueLinkedList<DataType>::iSize() const
{
	return this->m_iCount;
}

template <class DataType>
bool CQueueLinkedList<DataType>::IsEmpty()
{
	return nullptr == this->m_ptrHead;
}

#endif