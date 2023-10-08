#ifndef CBINARYTREE1_TPP
#define CBINARYTREE1_TPP

#include "CBinaryTree1.h"

template<typename DataType>
void CBinaryTree1<DataType>::Traversal() const
{
	if (!m_pRoot)
	{
		return;
	}
	vInOrderTraversal(m_pRoot.get());
	std::cout << "\n";
}

template<typename DataType>
void CBinaryTree1<DataType>::Insert(const DataType &newData)
{// Insert into tree in O(logN) complexity
	if (m_pRoot)
	{// Not the root
		vInsertNode(newData, m_pRoot.get());
	}
	else
	{
		m_pRoot = std::make_unique<stNode>(newData);
	}
}

template<typename DataType>
void CBinaryTree1<DataType>::Remove(const DataType& newData)
{
	if (!m_pRoot)
	{
		return;
	}
	vRemove(newData, m_pRoot);
}

template<typename DataType>
const DataType& CBinaryTree1<DataType>::GetMaxValue() const
{
	if (!m_pRoot)
	{
		throw EmptyTreeException{};
	}
	return dtGetMax(m_pRoot.get());
}

template<typename DataType>
const DataType& CBinaryTree1<DataType>::GetMinValue() const
{
	if (!m_pRoot)
	{
		throw EmptyTreeException{};
	}
	return dtGetMin(m_pRoot.get());
}

template<typename DataType>
void CBinaryTree1<DataType>::vInOrderTraversal(stNode* nodeRef) const
{
	if (nodeRef->pLeft)
	{
		vInOrderTraversal(nodeRef->pLeft.get());
	}
	std::cout << nodeRef->m_data << " --> ";
	if (nodeRef->pRight)
	{
		vInOrderTraversal(nodeRef->pRight.get());
	}
}

template<typename DataType>
void CBinaryTree1<DataType>::vInsertNode(const DataType& newData, stNode* nodeRef)
{// insert new node into the tree in O(logN)
	if (newData < nodeRef->m_data)
	{// if smaller then go left
		if (nodeRef->pLeft)
		{
			vInsertNode(newData, nodeRef->pLeft.get());
		}
		else
		{// if left is empty, insert at the spot
			nodeRef->pLeft = std::make_unique<stNode>(newData);
		}
	}
	else
	{//else go right
		if (nodeRef->pRight)
		{
			vInsertNode(newData, nodeRef->pRight.get());
		}
		else
		{// if no right insert at the spot
			nodeRef->pRight = std::make_unique<stNode>(newData);
		}
	}
}

template<typename DataType>
void CBinaryTree1<DataType>::vRemove(const DataType& dataRef, std::unique_ptr<stNode>& nodeRef)
{
	//Search the node to remove
	if (dataRef < nodeRef->m_data)
	{
		if (nodeRef->pLeft)
		{
			vRemove(dataRef, nodeRef->pLeft);
		}
	}
	else if (dataRef > nodeRef->m_data)
	{
		if (nodeRef->pRight)
		{
			vRemove(dataRef, nodeRef->pRight);
		}
	}
	else
	{// found the node to remove
		if (!nodeRef->pLeft && !nodeRef->pRight)
		{
			std::cout << "Removing a leaf node...\n";
			nodeRef.reset();
			return;
		}
		if (!nodeRef->pLeft)
		{// remove a right child
			std::cout << "Removing the right child...\n";
			std::unique_ptr<stNode> pTemp	= std::move(nodeRef->pRight);
			nodeRef.reset();
			nodeRef							= std::move(pTemp);
			return;
		}
		else if (!nodeRef->pRight)
		{
			std::cout << "Removing the left child...\n";
			std::unique_ptr<stNode> pTemp	= std::move(nodeRef->pLeft);
			nodeRef.reset();
			nodeRef							= std::move(pTemp);
			return;
		}

		// The node above without children case
		// Remove a node with 2 children case!!!
		std::cout << "Remove item with 2 children...\n";

		//find the largest item in the left subtree 
		std::unique_ptr<stNode> pTemp		= pGetRightMost(nodeRef->pLeft);
		pTemp->pRight						= std::move(nodeRef->pRight);
		std::unique_ptr<stNode>& pLeftMost	= pGetLeftMost(pTemp);
		pLeftMost->pLeft					= std::move(nodeRef->pLeft);

		//Destroys the object currently managed by the unique_ptr
		//Calling reset() to release ownership and set the pointer to nullptr
		nodeRef.reset();
		nodeRef								= std::move(pTemp);
	}
}

template<typename DataType>
std::unique_ptr<typename CBinaryTree1<DataType>::stNode> CBinaryTree1<DataType>::pGetRightMost(std::unique_ptr<stNode>& nodeRef)
{
	if (nodeRef->pRight)
	{
		return pGetRightMost(nodeRef->pRight);
	}
	return std::move(nodeRef);
}

template<typename DataType>
std::unique_ptr<typename CBinaryTree1<DataType>::stNode> &CBinaryTree1<DataType>::pGetLeftMost(std::unique_ptr<stNode>& nodeRef)
{
	if (nodeRef->pLeft)
	{
		return pGetLeftMost(nodeRef->pLeft);
	}
	//return std::move(nodeRef);
	return nodeRef;
}

template<typename DataType>
const DataType& CBinaryTree1<DataType>::dtGetMax(stNode* nodeRef) const
{// Get the largest item in the tree in O(logN)
	if (nodeRef->pRight)
	{// Using get since it is raw pointer
		return dtGetMax(nodeRef->pRight.get());
	}
	return nodeRef->m_data;
}

template<typename DataType>
const DataType& CBinaryTree1<DataType>::dtGetMin(stNode* nodeRef) const
{// Get the smallest item in the tree in O(logN)
	if (nodeRef->pLeft)
	{
		return dtGetMax(nodeRef->pLeft.get());
	}
	return nodeRef->m_data;
}

#endif // !CBINARYTREE1_TPP

