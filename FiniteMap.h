#pragma once
#include <memory>
#include <queue>

template <typename T>
class FiniteMap
{
public:
	FiniteMap(int _size)
		: 
		size(_size),
		arr(std::make_unique<T[]>(_size))
	{
		
		for (int i = 0; i < size; i++)
		{
			freeIndices.push(i);
		}
	}
	//If you want to ADD or DELETE, you must use the Add and Delete functions
	T& operator [](int index)
	{
#ifndef DEBUG
		if (arr[index] == nullptr)
		{
			throw("Trying to access a null pointer");
		}
#endif
		return arr[index];
	}
	int Add(T& value)
	{
		int t = freeIndices.front();
		arr[t] = value;
		freeIndices.pop();
		return t;
	}
	void DeleteSmart(int index)
	{
		if (arr[index] != nullptr)
		{
			arr[index].reset();
			arr[index] = nullptr;
			freeIndices.push(index);
		}
	}
	void DeleteDumb(int index)
	{
		if (arr[index] != 0)
		{
			arr[index] = 0;
			freeIndices.push(index);
		}
	}
	void Clear()
	{
		std::queue<int> emptyQ;
		std::swap(freeIndices, emptyQ);
		for (int i = 0; i < size; i++)
		{
			freeIndices.push(i);
		}
		arr.reset();
		arr = std::make_unique<T[]>(size);
	}
private:
	std::unique_ptr<T[]> arr = nullptr;
	std::queue<int> freeIndices;
	int size;
};