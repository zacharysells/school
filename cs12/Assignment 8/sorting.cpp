// Course: CS 12 Spring 2012
//
// First Name: Zachary 
// Last Name: Sells
// Course username: zsell001
// email address: zsell001@ucr.edu
//
// Lecture Section: 001
// Lab Section: 025
// TA: Mirebrahim, Seyed Hamid
//
// Assignment: assn8
//
// I hereby certify that the code in this file
// is ENTIRELY my own original work.
//
// =================================================================
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>
#include <vector>
#include <algorithm>

#include "sorting.h"

using namespace std;



void stl_sort( vector<int> &v )
{
    sort(v.begin(),v.end());
}

unsigned find_min(vector<int> &v, unsigned s)
{
    unsigned min = s;
    for(unsigned i = s; i < v.size(); i++)
    {
        if(v.at(i) < v.at(min)) min = i;
    }
    return min;
}

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}


void selection_sort( vector<int> & v )
{
	//EXERCISE 2: Implement Selection Sort
    for(unsigned s = 0; s < v.size(); s++)
        swap(v.at(s),v.at(find_min(v,s)));
        
}


void insertion_sort( vector<int> & v )
{
    int current = 0;
    unsigned pos = 0;
	//EXERCISE 3: Implement Insertion Sort
    for(unsigned i = 1; i < v.size(); i++)
    {
        current = v.at(i);
        pos = i;
        while(pos > 0 && v.at(pos-1) > current)
        {
            v.at(pos) = v.at(pos-1);
            pos = pos - 1;
        }
        v.at(pos) = current;
    }
}


void bubble_sort( vector<int> & v )
{
	//EXERCISE 4: Implement Bubble Sort
    for(unsigned e = 0; e < v.size(); e++)
    {
        for(unsigned i = 0; i < v.size() - 1; i++)
        {
            if(v.at(i+1) < v.at(i)) swap(v.at(i+1),v.at(i));
        }
    }
}

void op_bubble_sort( vector<int> & v )
{
	//EXERCISE 5: Optimize the Bubble Sort Function
    for(unsigned e = 0; e < v.size(); e++)
    {
        for(unsigned i = 0; i < v.size() - e - 1; i++)
        {
            if(v.at(i+1) < v.at(i)) swap(v.at(i+1),v.at(i));
        }
    }
}

vector<int> merge(vector<int> &left, vector<int> &right)
{
	vector<int> v;//Final result of merging.
	while(left.size() > 0 || right.size() > 0)
	{
		if(left.size() > 0 && right.size() > 0)
		{ 
            if(left.at(0) <= right.at(0))
			{
				v.push_back(left.at(0));
                left.erase(left.begin());
			}
			else if(left.at(0) > right.at(0))
			{
				v.push_back(right.at(0));
                right.erase(right.begin());			}
		}
		else if(left.size() > 0)
		{
			v.push_back(left.at(0));
            left.erase(left.begin());
		}
		else if(right.size() > 0)
		{
			v.push_back(right.at(0));
            right.erase(right.begin());
		}
	}
	return v;
}
		
void merge_sort( vector<int> & v )
{
	if(v.size() <= 1) return;
	unsigned mid = v.size() / 2;
	vector<int> left;
	vector<int> right;
	for(unsigned i = 0; i < mid; i++)
		left.push_back(v.at(i));
		
	for(unsigned i = mid; i < v.size(); i++)
		right.push_back(v.at(i));
        
	merge_sort(left);
	merge_sort(right);
    
    v = merge(left,right);
    
}

int binary_search2(const vector<int> &v, int start, int end, int target)
{
    if(end < start) return -1;
    
    int mid = (end + start) / 2;
    if(target > v.at(mid)) return binary_search2(v,mid+1,end,target);
    
    if(target < v.at(mid)) return binary_search2(v,start,mid-1,target);
    
    else return mid;
}

int binary_search( const vector<int> & v, int target )
{
	if(v.size() == 0) return -1;
    
    int mid = v.size() / 2;
    
    if(target > v.at(mid)) return binary_search2(v,mid+1,v.size()-1,target);
    
    if(target < v.at(mid)) return binary_search2(v,0,mid-1,target);
    
    else return mid;
}
