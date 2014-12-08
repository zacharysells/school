#include <iostream>
#define MAX_CIN_BUF 1000
using namespace std;


class String
{
	public:
    /// Both constructors should construct
    /// from the parameter s
    String( const char * s = "");//Done
    String( const String & s );//Done
    String operator = ( const String & s );//Done
    char & operator [] ( const int index );//Done
    int length() const;//Done
    int indexOf( char c ) const;//Done Returns -1 if not found
    bool operator == ( const String & s ) const;//Done
    /// concatenates this and s
    String operator + ( const String & s ) const;//Done
    /// concatenates s onto end of this
    String operator += ( const String & s );//Done
    void print( ostream & out );//Done
    void read( istream & in );
    ~String();
	//private:
    bool inBounds( int i )
    {
      return i >= 0 && i < length();
    }
    struct ListNode
    {
		char info;
		ListNode * next;
		ListNode(char newInfo, ListNode * newNext)
        : info( newInfo ), next( newNext )
		{
		}
		
		ListNode operator=(const ListNode &rhs)
		{
			this->next = new ListNode(rhs.info, rhs.next);
			this->info = rhs.info;
		}
      
      // you may add static methods here
    };
    ListNode * head;
};
ostream & operator << ( ostream & out, String str );//Done
istream & operator >> ( istream & in, String & str );

