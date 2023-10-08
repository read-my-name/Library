#pragma once

#ifndef TREE_H
#define TREE_H

template <typename DataType>
class CTree
{
public:
	virtual void Traversal() const = 0;
	virtual void Insert(const DataType& newData) = 0;
	virtual void Remove(const DataType& newData) = 0;
	virtual const DataType& GetMaxValue() const = 0;
	virtual const DataType& GetMinValue() const = 0;
private:

};

#endif // !TREE_H