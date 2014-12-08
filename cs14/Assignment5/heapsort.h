#include <vector>
#include <iostream>
using namespace std;

template<typename T>
vector<T>& swap(vector<T> &heap,unsigned i,unsigned e)
{
	T temp;
	temp = heap[i];
	heap[i] = heap[e];
	heap[e] = temp;
	return heap;
}	

template <typename T>
void heapSort(vector<T> &data)
{
    int start = (data.size() / 2) - 1;
    int end = data.size() - 1;
    
    while(start >= 0)
    {
		shift(data, start, data.size());
		start--;
	}
	while(end > 0)
	{
		swap(data, end, 0);
		shift(data, 0, end);
		end--;
	}
}

template<typename T>
void shift(vector<T> &data,int start, int count)
{
	int root = start;
	int child;
	while(root * 2 + 1 < count)
	{
		child = root * 2 + 1;
		if(child < count - 1 && data[child] < data[child + 1])
			child = child + 1;
		
		if(data[root] < data[child])
		{
			swap(data, root, child);
			root = child;
		}
		else return;
	}
	
}


template <typename T>
void print(const vector<T> &list)
{
	for(unsigned i = 0; i < list.size(); i++)
		cout << list[i] << endl;
		
}
