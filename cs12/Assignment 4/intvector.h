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
#ifndef _INTVECTOR_H
#define _INTVECTOR_H

using namespace std;

class IntVector
{
    private:
    
    unsigned vsize;
    unsigned vcapacity;
    int * data;
    
    void expand();
    
    void expand(unsigned amount);
    
    
    public:
    
    IntVector();
    
    IntVector(unsigned s);
    
    IntVector(unsigned s, int value);
    
    ~IntVector();
    
    unsigned size() const;
    
    unsigned capacity() const;
    
    bool empty() const;
    
    const int &at(unsigned index) const;
    
    const int & operator[](unsigned index)const;
    
    const int& front() const;
    
    const int& back() const;
    
    
    //Mutators
    void insert(unsigned index, int data);
    
    void erase(unsigned index);
    
    void push_back(int data);
    
    void pop_back();
    
    void clear();
    
    void resize(unsigned sz);
    
    void resize(unsigned sz,int value);
    
    void reserve(unsigned n);
    
    void assign(unsigned n, int value);
    
    int & at(unsigned index);
    
    int & operator[](unsigned index);
    
    int & front();
    
    int & back();
    
    IntVector operator+(const IntVector rhs);
    
};
#endif
    
    
    
