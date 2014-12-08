#include <iostream>
#include <iomanip>
#include "exceptionClass.h"
using namespace std;

template <typename T>
class Array
{
	private:
	int len;
	T * buf;
	
	public:
	
	Array( int newLen = 0 );
	
	Array( Array<T> & l );
  
	int length();
  
	T & operator [] ( int i ) throw(IndexOutOfBoundsException);
  
	void print( ostream & out );
	
	friend ostream & operator << ( ostream & out, Array<T> & a )
	{
		a.print( out );
		return out;
	}
};

#include "Array.cpp"
