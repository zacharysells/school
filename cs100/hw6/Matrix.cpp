template<class Element>
Matrix<Element>::Matrix( int newRows, int newCols )
: rows( newRows ), cols( newCols ), m( rows )
{
	for (int i = 0; i < rows; i++ )
		m[i] = new Array<Element>(cols);
}

template<class Element>
int Matrix<Element>::numRows()
{
	return rows;
}

template<class Element>
int Matrix<Element>::numCols()
{
	return cols;
}

template<class Element>
Array <Element> & Matrix<Element>::operator [] ( int row )
throw(IndexOutOfBoundsException)
{
	if(!(0 <= row && row < rows ))
	{
		throw IndexOutOfBoundsException("IndexOutOfBoundsException Caught!");
	}
		
	return *m[row];
}

template <class Element>
void Matrix<Element>::print( ostream & out )
{
	for(int i = 0; i < rows; ++i)
	{
		out << *m[i];
		out << endl;
	}
}
