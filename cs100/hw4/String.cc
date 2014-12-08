#include "String.h"


using namespace std;


String::String(const char * s)
{
	head = new ListNode(*s,NULL);
	ListNode * currNode = head;
	for(int i = 1; s[i] != '\0'; ++i)
	{
		currNode->next = new ListNode(s[i],NULL);
		currNode = currNode->next;
	}
}

String::String( const String & s )
{
	head = new ListNode(s.head->info,NULL);
	ListNode * currNode = head;
	for(ListNode * it = s.head->next; it != NULL; it = it->next)
	{
		currNode->next = new ListNode(it->info, it->next);
		currNode = currNode->next;
	}
}

String String::operator = ( const String & s )
{
	head = new ListNode(s.head->info,NULL);
	ListNode * currNode = head;
	for(ListNode * it = s.head->next; it != NULL; it = it->next)
	{
		currNode->next = new ListNode(it->info, it->next);
		currNode = currNode->next;
	}
	return *this;
}

char & String::operator [] ( const int index )
{
	ListNode * it = head;
	for(int i = 0; i < index; ++i)
	{
		it = it->next;
	}
	return it->info;
}

int String::length() const
{
	if(head->info == '\0') return 0;
	int i = 0;
	for(ListNode * it = head; it != NULL; it = it->next)
		++i;
		
	return i;
}

int String::indexOf( char c ) const
{
	int i = 0;
	for(ListNode * it = head; it != NULL; it = it->next)
	{
		if(it->info == c) return i;
		++i;
	}
	return -1;
}

bool String::operator == ( const String & s ) const
{
	ListNode * currNode = head;
	for(ListNode * it = s.head; it != NULL; it = it->next)
	{
		if(currNode->info != it->info) return false;
		currNode = currNode->next;
	}
	return true;
}

String String::operator + ( const String & s ) const
{
	String str;
	str.head = new ListNode(head->info,NULL);
	ListNode * currNode = str.head;
	for(ListNode * it = head->next; it != NULL; it = it->next)
	{
		currNode->next = new ListNode(it->info, it->next);
		currNode = currNode->next;
	}
	for(ListNode * et = s.head; et != NULL; et = et->next)
	{
		currNode->next = new ListNode(et->info, et->next);
		currNode = currNode->next;
	}
	return str;
}

String String::operator += ( const String & s )
{
	ListNode * it = head;
	for(; it->next != NULL; it = it->next);
	for(ListNode * et = s.head; et != NULL; et = et->next)
	{
		it->next = new ListNode(et->info, et->next);
		it = it->next;
	}
	return *this;
}

void String::print( ostream & out )
{
	for(ListNode * it = head; it != NULL; it = it->next)
	{
		out << it->info;
	}
}

void String::read( istream & in )
{
	int size = 0;
	
	char c[MAX_CIN_BUF];
	in >> c;
	while(c[size] != '\0')
	{
		++size;
	}
	head = new ListNode(c[0], NULL);
	ListNode * currNode = head;
	for(int e = 1; e < size; ++e)
	{
		currNode->next = new ListNode(c[e], NULL);
		currNode = currNode->next;
	}
}

String::~String()
{
	for(ListNode * it = head; it != NULL; it = it->next)
	{
		delete it;
	}
}

ostream & operator << ( ostream & out, String str )
{
	str.print(out);
	return out;
}
	
istream & operator >> ( istream & in, String & str )
{
	str.read(in);
	return in;
}
