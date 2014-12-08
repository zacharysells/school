// Course: CS 12 <Winter 2012r>
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
// Assignment: assn4
//
// I hereby certify that the code in this file
// is ENTIRELY my own original work.
//
// =================================================================
#include <iostream>
#include "intvector.h"
#include <cstdlib>
using namespace std;

//Constructors/Destructors
IntVector::IntVector()
:vsize(0),vcapacity(0),data(NULL)//Default constructor.
{}

IntVector::IntVector(unsigned s)
:vsize(s),vcapacity(s),data(NULL)
{
	data = new int[s];
	for(unsigned i = 0; i < vcapacity; i++)
	{
		data[i] = 0;//Set all elements to zero.
	}
}

IntVector::IntVector(unsigned s, int value)
:vsize(s),vcapacity(s),data(NULL)
{
	data = new int[s];
    for(unsigned i = 0; i < vsize; i++)
    {
        data[i] = value;//Set elements according to 'value' parameter
    }
}

IntVector::~IntVector()
{
    delete[] data;//Deconstructor
}

void IntVector::expand()
{
	int * temp = new int[vcapacity * 2];//Double vector's capacity
	for(unsigned i = 0; i < vsize; i++)
	{
		temp[i] = data[i];
	}
	vcapacity = vcapacity * 2;
	delete[] data;
	data = temp;
}
	
void IntVector::expand(unsigned amount)//Expand vector's capacity by 'amount' parameter
{
	int * temp = new int[vcapacity + amount];
	for(unsigned i = 0; i < vsize; i++)
	{
		temp[i] = data[i];
	}
	vcapacity = vcapacity + amount;
	delete[] data;
	data = temp;
}

unsigned IntVector::size() const
{
    return vsize;//Return size of vector.
}

unsigned IntVector::capacity() const
{
    return vcapacity;//Return capacity of vector.
}

bool IntVector::empty() const
{
    return (vsize == 0);//Check if vector's size is zero.
}

const int & IntVector::operator[](unsigned index)const
{
    return data[index];
}

const int& IntVector::front() const
{
	return data[0];// Return value of last element.
}

const int& IntVector::back() const
{
	return *(data + (vsize - 1));//Return value of last element.
}

const int & IntVector::at(unsigned index) const
{
    if(index > vsize)
        exit(0);//Exit program if index is out of range of vector
    
    return data[index];//Return by value as R-value.
}

int & IntVector::at(unsigned index)
{
    if(index > vsize)
        exit(0);// Exit program if index is out of range of vector
        
    return data[index];//Return by reference as L-value.
}

void IntVector::insert(unsigned index, int data)
{
	if(index > vsize)//Make sure index isnt bigger than size.
	{
		exit(1);
	}
	if(vcapacity == 0)
	{
		expand(1);
	}
	if(vsize == vcapacity)//Increase capacity if size is equal to capacity.
	{
		expand();
	}
	
	for(unsigned i = vsize; i > index ; i--)
	{
		this->data[i] = this->data[i-1];//Shift all values up one.
	}
	this->data[index] = data;//Input 'data' parameter into new element.
	vsize++;//Increase size by one.
	
}

void IntVector::erase(unsigned index)
{
	if(index > vsize)//Make sure index isnt bigger than size.
	{
		exit(0);
	}
	for(unsigned i = index; i < vsize; i++)
	{
		data[i] = data[i+1];//Move all elements down one position.
	}
	vsize--;//Decrease size by one.
}

void IntVector::push_back(int data)
{
	if(vcapacity == 0)
	{
		expand(1);//If vector is empty, set capacity to 1.
	}
	
	else if (vsize == vcapacity)
	{
		expand();//Increase capacity if size is equal to capacity.
	}
	
	this->data[vsize] = data;//Input 'data' parameter into new element.
	
	vsize++;//Increase size by one. 
}

void IntVector::pop_back()
{
	if(vsize == 0)
		exit(0);//Exit program if size is zero
		
	vsize--;//Decrease size by one.
}

void IntVector::clear()
{
	vsize = 0;//Reduce size to zero.
}

void IntVector::resize(unsigned sz)
{
	if(sz < vsize)
	{
		vsize = sz;//Just reduce size to 'sz' parameter
	}
	
	else
	{
		if(sz > vcapacity)
		{
			if(vcapacity * 2 > sz)//Increase capacity by the bigger of the two.
			{
				expand();
			}
			else
			{
				expand(sz - vcapacity);
			}
		}
		vsize = sz;//Set new size.
	}
}

void IntVector::resize(unsigned sz, int value)
{
	if(sz < vsize)
	{
		vsize = sz;//Just change size to 'sz' parameter
	}
	
	else
	{
		if(sz > vcapacity)
		{
			if(vcapacity * 2 > sz)//Set capacity to greater of the two.
			{
				expand();
			}
			
			else
			{
				expand(sz - vcapacity);
			}
		}
		for(unsigned i = vsize; i < vcapacity; i++)
		{
			data[i] = value;//Assign elements to 'value' parameter
		}
		vsize = sz;//Set new size.
	}
}

void IntVector::reserve(unsigned n)
{
	if(n < vcapacity)
		return;
	if(vcapacity * 2 > n)//Change capacity to greater of the two.
		expand();
		
	else
		expand(n-vcapacity);
}

void IntVector::assign(unsigned n, int value)
{
	if(n > vcapacity)
	{
		if(vcapacity * 2 > n)//Change capacity to greater of two.
			expand();
		else
			expand(n-vcapacity);
			
		vsize = n;
		//Set all values in newly assigned size to 'value' paramater.
		for(unsigned i = 0; i < vsize; i++)
		{
			data[i] = value;
		}	
	}
	else
	{
		vsize = n;//set new size and assign new values according to parameter 'value'
		for(unsigned i = 0; i <vsize; i++)
		{
			data[i] = value;
		}
	}
	
}

int & IntVector::front()//L-value
{
	return data[0];
}

int & IntVector::back()//L-value
{
	return data[vsize - 1];
}

int & IntVector::operator[](unsigned index)//L-value
{
	return data[index];
}
	
