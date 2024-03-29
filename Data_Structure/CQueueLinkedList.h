#pragma once

#ifndef CQUEUELINKEDLIST_H
#define CQUEUELINKEDLIST_H

#include <stdexcept>
#include <memory>

template <class DataType>
class CQueueLinkedList
{
public:
	struct stNode
	{
		DataType m_data;
		std::unique_ptr<stNode> ptrNext;
		stNode(const DataType& data)
			: m_data(data)
		{}
	};

	void vEnqueue(const DataType& data);
	DataType dtDequeue();
	int iSize() const;

private:
	DataType m_data;
	// Use to access the head node (1st Node)
	// head and tail implementation is used to deploy O(1) running time. 
	// Ensure the dequeue/enqueue operation runs in O(1)
	std::unique_ptr<stNode> m_ptrHead;
	stNode* m_stLastNode	= nullptr;
	int m_iCount			= 0;
	
	bool IsEmpty();
};

#include "CQueueLinkedList.tpp"

#endif
