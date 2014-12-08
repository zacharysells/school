template <typename T>
Array<T>::Array( int newLen )
:len( newLen ), buf( new T[newLen] )
{
}

template <typename T>
Array<T>::Array( Array<T> & l )
:len( l.len ), buf( new T[l.len] )
{
	for ( int i = 0; i < l.len; i++ )
		buf[i] = l.buf[i];
}

template <typename T>
int Array<T>::length()
{
	return len;
}

template<typename T>
T & Array<T>::operator [] ( int i ) 
throw(IndexOutOfBoundsException)
{
	if(!(0 <= i && i < len ))
	{
		throw IndexOutOfBoundsException("OutOfBoundsException Caught!");
	}
	return buf[i];
}

template<typename T>
void Array<T>::print( ostream & out )
{
	for (int i = 0; i < len; i++)
		out << setw(5) << buf[i];
}

