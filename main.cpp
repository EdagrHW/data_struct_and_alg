#include<iostream>
#include"Heap.hpp"
using namespace std;
int main()
{
	Heap<int> heap;
	vector<int> array = {6,3,5,4,2,9,0,1,4};
	for (int i : array)
	{
		heap.push(i);
	}

	while (!heap.empty())
	{
		cout << heap.pop() << endl;
	}

	return 1;
}