#include <iostream>
#include <cstdlib>	
#include <fstream>
#include <sstream>
using namespace std;
#ifndef STACK_H
#define STACK_H

template <class T>
class Stack
{
    private:
    
    T * stack;
    int size;
    int cap;
    
//----------------------Functions---------------------------------------
    
    void expand()//helper
    {
        T * new_stack = new T[cap * 2];
        for(unsigned i = 0; i < this->size; i++)
        {
            new_stack[i] = this->stack[i];
        }

        cap = cap * 2;
        delete this->stack;
        stack = new_stack;
    }//end expand()
    
//----------------------------------------------------------------------

    void expand(int x)//helper
    {
        T * new_stack = new T[cap + x];
        for(unsigned i = 0; i < this->size; i++)
        {
            new_stack[i] = this->stack[i];
        }
        cap = cap + x;
        delete this->stack;
        stack= new_stack;
    }//end expand(int x)

//----------------------------------------------------------------------

    public:
    
    Stack()
    :size(0),cap(0),stack(NULL)
    {}//end default constructor
    
//----------------------------------------------------------------------
    
    Stack(unsigned s, T value)
    :size(s),cap(s),stack(new T[s])
    {
    for(unsigned i = 0; i < s; i++)
        stack[i] = value;
    }//end parameterized constructor
    
//----------------------------------------------------------------------
    
    void push(const T& x)
    {
        if(cap == 0) this->expand(5);
        else if(size == cap) this->expand();
        unsigned i = 0;
        for(; i < (size); i++);
    
    
        stack[i] = x;
        size++;
    }//end push()

//----------------------------------------------------------------------
    
    T& top() const
    {
        if (this->is_empty())
        {
            cout << "Error: Empty stack" << endl;
            exit(0);
        }
    
        else return stack[size-1];
        
    }//end top()
    
//----------------------------------------------------------------------
    
    void pop()
    {
        if (this->is_empty())
        {
            cout << "Error: Empty stack" << endl;
            exit(0);
        }
    
        stack[size - 1] = 0;
        size--;
        
    }//end pop()
    
//----------------------------------------------------------------------
    
    void postfix_eval(string file_name)
    {
		ifstream file;
		file.open(file_name.c_str());
		string line;
		string operation;
		int add1, add2;
		while(getline(file, line))
		{
			stringstream line_stream(line);
			line_stream >> add1;
			line_stream >> add2;
			line_stream >> operation;
			if(operation == "+") this->push(add1 + add2);
			
			if(operation == "-") this->push(add1 - add2);
			
			if(operation == "*") this->push(add1 * add2);
        
			if(operation == "/") this->push(add1 / add2);
		}	

	}//end postfix_eval()
	
//----------------------------------------------------------------------
    
    bool is_empty() const
    {
        return (size == 0);

    }//end is_empty()
    
//----------------------------------------------------------------------
    
    void print() const
    {
        for(unsigned i = 0; i < this->size; i++)
        cout << stack[i] << endl;
    }//end print()

//----------------------------------------------------------------------

};
#endif
