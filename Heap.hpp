#pragma once
#include <vector>
template<typename T>
//�Դ󶥶�Ϊ��
class Heap
{
public:
	Heap() = default;
	explicit Heap(std::vector<T>& data);
	///�����Ѷ�Ԫ��
	T pop();
	///����Ԫ��
	void push(T& value);
	///���Ƿ�Ϊ��
	bool empty();
	~Heap() = default;
private:
	void swap(size_t left, size_t right);
private:
	std::vector<T> _datas;
};

template<typename T>
inline Heap<T>::Heap(std::vector<T>& data)
{
	//�ѵĹ���
}

template<typename T>
inline T Heap<T>::pop()
{
	T head = _datas[0];
	//���϶��±Ƚ�
	T tailValue = _datas[_datas.size() - 1];
	_datas.pop_back();
	if (_datas.empty())
	{
		return head;
	}
	_datas[0] = tailValue;
	for (size_t i = 0; i < _datas.size(); )
	{
		//���ӽڵ�
		size_t leftIndex = 2 * i + 1;
		//���ӽڵ�
		size_t rightIndex = 2 * i + 2;

		size_t maxIndex = 0;

		//��ȡ���ҵ����ֵ
		if (leftIndex < _datas.size())
		{
			if (rightIndex < _datas.size())
			{
				if (_datas[leftIndex] > _datas[rightIndex])
				{
					maxIndex = leftIndex;
				}
				else
				{
					maxIndex = rightIndex;
				}
			}
			else
			{
				maxIndex = leftIndex;
			}
		}
		else
		{
			break;
		}

		if (_datas[maxIndex] > _datas[i])
		{
			swap(maxIndex, i);
			i = maxIndex;
		}
		else
		{
			break;
		}
	}
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
	//���¶��ϱȽϽ���
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
