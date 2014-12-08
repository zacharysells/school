#include "String.h"

//Helper functions for comparison operators


String::String( const char * s)
{
	int i = 0;
	while(s[i] != '\0')
	{
		++i;
	}
	len = i;
	++i;
	buf = new char[i];
	for(int e = 0; e < i; ++e)
	{
		buf[e] = s[e];
	}
}

String::String( const String & s )
{
	buf = new char[s.len+1];
	for(int i = 0; i < s.len; ++i)
	{
		buf[i] = s.buf[i];
	}
	len = s.len;
	buf[len] = '\0';
}

String String::operator = ( const String & s )
{
	delete[] buf;
	buf = new char[s.len+1];
	for(int i = 0; i < s.len; ++i)
	{
		buf[i] = s.buf[i];
	}
	len = s.len;
	buf[len] = '\0';
	return *this;
}

char & String::operator [] ( int index )
{
	if(index >= len) 
	{
		cout << "Bounds error" << endl;
		exit(-1);
	}
	return buf[index];
}

int String::size()
{
	return len;
}

String String::reverse()
{
	char c[len+1];
	int i = 0;
	for(int e = len-1; e >= 0; --e)
	{
		c[i] = buf[e];
		i++;
	}
	c[len] = '\0';
	return String(c);
	
}

//Returns index of first instance of c. -1 if not found
int String::indexOf( char c )
{
	for(int i = 0; i < len; ++i)
	{
		if(buf[i] == c) return i;
	}
	return -1;
}

//Returns index of first instance of patter. -1 if not found.
int String::indexOf( String pattern )
{
	for(int i = 0; i < len; ++i)
	{
		if(buf[i] == pattern[0])
		{
			int e = i+1;
			for(int j = 1; j < pattern.size(); ++j)
			{
				if(buf[e] != pattern[j]) goto exit_loop;
				++e;
			}
			return i;
		}
		exit_loop:
		;
	}
	return -1;
}	

bool String::operator == ( String s )
{
	if(size() != s.size()) return false;
	for(int i = 0; i < size(); ++i)
	{
		if(buf[i] != s[i]) return false;
	}
	return true;
}

bool String::operator != ( String s )
{
	return !(this->operator==(s));
}

bool String::operator > ( String s )
{
	int bigger_len = 0;
	if(s.len > len) bigger_len = s.len;
	else bigger_len = len;
    for(int i = 0; i < bigger_len; ++i)
    {
        if(buf[i] > s.buf[i]) return true;
        if(buf[i] < s.buf[i]) return false;
    }
    return false;
}

bool String::operator < ( String s )
{
	if(this->operator==(s)) return false;
	
	else return !this->operator >(s);
}

bool String::operator <= ( String s )
{
	return (this->operator ==(s) || this->operator <(s));
}

bool String::operator >= ( String s )
{
	return (this->operator ==(s) || this->operator >(s));
}

String String::operator + ( String s )
{
	char ret[len + s.len + 1];
	for(int i = 0; i < len; ++i)
	{
		ret[i] = this->operator [](i);
	}
	int e = 0;
	for(int i = len; e < s.len; ++i)
	{
		ret[i] = s[e];
		++e;
	}
	ret[size() + s.size()] = '\0';
	return String(ret);
}

String String::operator += ( String s )
{
	String temp_this(*this);
	buf = new char[temp_this.size() + s.size() + 1];
	for(int i = 0; i < temp_this.size(); ++i)
	{
		buf[i] = temp_this[i];
	}
	int e = 0;
	for(int i = temp_this.len; e < s.size(); ++i)
	{
		buf[i] = s[e];
		++e;
	}
	buf[temp_this.size() + s.size()] = '\0';
	len = temp_this.size() + s.size();
	
	return *this;
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
	buf = new char[size+1];
	len = size;
	
	for(int e = 0; e < size; ++e)
	{
		buf[e] = c[e];
	}
	buf[len] = '\0';
}

void String::print(ostream &out)
{
	int i = 0;
	while(buf[i] != '\0')
	{
		out << buf[i];
		++i;
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

String::~String()
{
	delete[] buf;
}
