#include "Array.h"
template < class Element >
class Matrix
{
	private:
	int rows, cols;
	Array< Array<Element>* > m;
	public:
	
	Matrix( int newRows, int newCols );
	
	int numRows();
	
	int numCols();
	
	Array < Element > & operator [] ( int row ) throw(IndexOutOfBoundsException);
	
	void print( ostream & out );
	
	friend ostream & operator << ( ostream & out, Matrix & m )
	{
		m.print( out );
		return out;
	}
};

#include "Matrix.cpp"
