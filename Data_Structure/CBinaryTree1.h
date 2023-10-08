#pragma once

#ifndef CBINARYTREE1_H
#define CBINARYTREE1_H

#include <exception>
#include "CTree.h"
#include <stdexcept>
#include <memory>
#include <iostream>

class EmptyTreeException : std::exception
{
public:
	EmptyTreeException() {};
	const char* what() const noexcept override
	{
		return "Binary Search Tree is empty().";
	}
};

template<typename DataType>
class CBinaryTree1 : public CTree<DataType>
{
public:
	virtual void Traversal() const;
	virtual void Insert(const DataType& newData);
	virtual void Remove(const DataType& newData);
	virtual const DataType& GetMaxValue() const;
	virtual const DataType& GetMinValue() const;
private:
	struct stNode
	{
		DataType m_data;
		std::unique_ptr<stNode> pLeft;
		std::unique_ptr<stNode> pRight;

		stNode(const DataType& data)
			: m_data(data)
		{}
	};
	std::unique_ptr<stNode> m_pRoot;

	void vInOrderTraversal(stNode* node) const;
	void vInsertNode(const DataType& newData, stNode* node);
	//std::unique_ptr is used since requires ownership
	void vRemove(const DataType& dataRef, std::unique_ptr<stNode>& nodeRef);
	std::unique_ptr<stNode> pGetRightMost(std::unique_ptr<stNode>& nodeRef);
	std::unique_ptr<stNode>& pGetLeftMost(std::unique_ptr<stNode>& nodeRef);
	//Here use raw pointer since don't need to modify the ownership
	const DataType& dtGetMax(stNode* node) const;
	const DataType& dtGetMin(stNode* node) const;
};

#include "CBinaryTree1.tpp"

#endif //! CBINARYTREE1_H