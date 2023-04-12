#include<iostream>
#include"Heap.hpp"
using namespace std;
int main()
{
	
	vector<int> array = {6,3,5,4,2,9,0,1,4};
	Heap<int> heap(array);

	while (!heap.empty())
	{
		cout << heap.pop() << endl;
	}

	return 1;
}