#include <iostream>

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
    }
    
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
    }
    
    public:
    
    Stack()
    :size(0),cap(0),stack(NULL)
    {}
    

    Stack(unsigned s, T value)
    :size(s),cap(s),stack(new T[s])
    {
    for(unsigned i = 0; i < s; i++)
        stack[i] = value;
    }
    

    void push(const T& x)
    {
        if(cap == 0) this->expand(5);
        else if(size == cap) this->expand();
        unsigned i = 0;
        for(; i < (size); i++);
    
    
        stack[i] = x;
        size++;
    }
    
    T& top() const
    {
        if (this->is_empty())
        {
            cout << "Error: Empty stack" << endl;
            exit(0);
        }
    
        else return stack[size-1];
        
    }
    
    void pop()
    {
        if (this->is_empty())
        {
            cout << "Error: Empty stack" << endl;
            exit(0);
        }
    
        stack[size - 1] = 0;
        size--;
        
    }
    
    bool is_empty() const
    {
        return (size == 0);

    }
    
    void print() const
    {
        for(unsigned i = 0; i < this->size; i++)
        cout << stack[i] << endl;
    }

};
#endif
