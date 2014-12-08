#include <iostream>
#include <cstdlib>
#define MAX_CIN_BUF 1024
using namespace std;
class String
{
	public:
    /// Both constructors should construct
    /// this String from the parameter s
    String( const char * s = "");//Done
    String( const String & s );//Done
    String operator = ( const String & s );//Done
    char & operator [] ( int index );//Done
    int size();//Done
    String reverse(); // does not modify this String //Done
    int indexOf( char c );//Done
    int indexOf( String pattern );//Done
    bool operator == ( String s );//Done
    bool operator != ( String s );//Done
    bool operator > ( String s );//Done
    bool operator < ( String s );//Done
    bool operator <= ( String s );//Done
    bool operator >= ( String s );//Done
    
    /// concatenates this and s to return result
    String operator + ( String s );//Done
    
    /// concatenates s onto end of this
    String operator += ( String s );//Done
    
    void print( ostream & out );//Done
    void read( istream & in );//Done
    ~String();
    
    
	private:
	
    bool inBounds( int i )
    {
      return i >= 0 && i < len;
    }
    char * buf;
    int len; // the number of chars in buf not including NULL char.
};
ostream & operator << ( ostream & out, String str );//Done
istream & operator >> ( istream & in, String & str );//Done
