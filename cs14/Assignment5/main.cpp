#include "heapsort.h"

int main()
{
	vector<int> v;
	v.push_back(6);
	v.push_back(5);
	v.push_back(3);
	v.push_back(1);
	v.push_back(8);
	v.push_back(7);
	v.push_back(2);
	v.push_back(4);
	
	heapSort(v);
	print(v);
	
	
}
