#include "Matrix.h"
using namespace std;

template< class T >
void fillMatrix(Matrix <T> & m )
{
  int i, j;
  for ( i = 0; i < m.numRows(); i++ )
    m[i][0] = T();
  for ( j = 0; j < m.numCols(); j++ )
    m[0][j] = T();
  for ( i = 1; i < m.numRows(); i++ )
    for ( j = 1; j < m.numCols()+1; j++ )
    {
      m[i][j] = T(i * j);
    }
}
int main()
{
	 try
	 {
		 Matrix < int > m(10,5);
		 fillMatrix( m );
		 cout << m << endl;
		 Matrix < double > M(8,10);
		 fillMatrix( M );
		 cout << M;
	 }
	 catch(IndexOutOfBoundsException &e)
	 {
		 cout << "IndexOutOfBoundsException Caught!" << endl;
	 }
	 
	 return 0;
}
