#pragma once
#include <vector>
template<typename T>
//以大顶堆为例
class Heap
{
public:
	Heap() = default;
	explicit Heap(std::vector<T>& data);
	///弹出堆顶元素
	T pop();
	///插入元素
	void push(T& value);
	///堆是否为空
	bool empty();
	~Heap() = default;
private:
	///交换两个下标的值
	void swap(size_t left, size_t right);
	///从指定下标位置开始自上而下堆话
	void heapify(size_t index);
private:
	std::vector<T> _datas;
};

template<typename T>
inline Heap<T>::Heap(std::vector<T>& data)
{
	_datas.assign(data.begin(), data.end());
	size_t i = (_datas.size() - 1) / 2;
	while (true)
	{
		heapify(i);
		if (--i == 0)
		{
			heapify(i);
			break;
		}
	}
}

template<typename T>
inline T Heap<T>::pop()
{
	T head = _datas[0];
	T tailValue = _datas[_datas.size() - 1];
	_datas.pop_back();
	if (_datas.empty())
	{
		return head;
	}
	_datas[0] = tailValue;
	heapify(0);
	return head;
}

template<typename T>
inline void Heap<T>::push(T& value)
{
	_datas.push_back(value);
	if (_datas.empty())
	{
		return;
	}
	//自下而上比较交换
	for (size_t i = _datas.size() - 1; i > 0;)
	{
		size_t parentIndex = (i - 1) / 2;
		if (_datas[i] > _datas[parentIndex])
		{
			swap(parentIndex, i);
			i = parentIndex;
		}
		else
		{
			break;
		}
		
	}

}

template<typename T>
inline bool Heap<T>::empty()
{
	return _datas.empty();
}

template<typename T>
inline void Heap<T>::swap(size_t left, size_t right)
{
	T temp = _datas[left];
	_datas[left] = _datas[right];
	_datas[right] = temp;
}

template<typename T>
inline void Heap<T>::heapify(size_t index)
{
	while (true)
	{
		size_t maxPos = index;
		size_t leftSubIndex = 2 * index + 1;
		size_t rightSubIndex = 2 * index + 2;
		if (leftSubIndex < _datas.size()
			&& _datas[leftSubIndex] > _datas[index])
		{
			maxPos = leftSubIndex;
		}
		if (rightSubIndex < _datas.size()
			&& _datas[rightSubIndex] > _datas[maxPos])
		{
			maxPos = rightSubIndex;
		}
		if (maxPos == index)
		{
			break;
		}
		swap(maxPos, index);
		index = maxPos;
	}
}
