/**
 * Course: CS 14 Fall 2012
 *
 * First Name: Zachary
 * Last Name: Sells
 * Username: zsell001
 * email address: zsell001@ucr.edu
 *
 *
 * Assignment: Assignment 4
 * Filename : hashmap.h
 *
 * I hereby certify that the contents of this file represent
 * my own original individual work. Nowhere herein is there 
 * code from any outside resources such as another individual,
 * a website, or publishings unless specifically designated as
 * permissible by the instructor or TA.
 */ 


#ifndef HASHMAP_H
#define HASHMAP_H

#include <string>
#include <vector>
#include <iostream>
using namespace std; 
template <typename T >
class hashmap
{
	struct Node 
	{
		const string key;
		mutable T payload;
		Node( string keyy, T t = T() ) 
		:key(keyy),payload(t)
		{}
	};
	
	private:
	
	static const int INITIAL_BUCKET_COUNT = 103;
	vector<Node*> map;
	
//----------------------------------------------------------------------
	
	void copyInternalData(const hashmap & rhs) 
	{
	  vector<Node *> tmp(INITIAL_BUCKET_COUNT,NULL);
      for (int i = 0; i < rhs.map.size(); i++) 
      {
		 if(rhs.map.at(i) == NULL)
		 {
			 tmp.at(i) = NULL;
			 continue;
		 }
		 Node * np = new Node(rhs.map.at(i)->key);
		 np->payload = rhs.map.at(i)->payload;
		 tmp.at(i) = np;
      }
      map = tmp;
	}//end copyInternalData()
	
//----------------------------------------------------------------------
	
	int hashcode(string s) 
	{
		const long MULTIPLIER = -1664117991L;
		unsigned long hashcode = 0;
		for (int i = 0; i < s.length(); i++) 
		{
			hashcode = hashcode * MULTIPLIER + s[i];
		}
		return hashcode & ((unsigned) -1 >> 1);
	}//end hashcode()
	
//----------------------------------------------------------------------

	int hashcode2(string key)
	{
		int r = 7;
		return r - (hashcode(key) % r);
	}//end hashcode2()
	
//----------------------------------------------------------------------
	
	public:
	
	hashmap()
	{
		vector<Node *> tmp(INITIAL_BUCKET_COUNT,NULL);
		map = tmp;
	}//end default constructor
	
//----------------------------------------------------------------------
	
	hashmap(const hashmap& rhs)
	{
		copyInternalData(rhs);
	}//end copy constructor
	
//----------------------------------------------------------------------
	
	~hashmap()
	{
		for(unsigned i = 0; i < this->map.size(); i++)
		{
			delete map.at(i);
		}
	}//end desctructor
	
//----------------------------------------------------------------------
	
	hashmap& operator=(const hashmap& rhs)
	{
		for(unsigned i = 0; i < this->map.size(); i++)
		{
			delete map.at(i);
		}
		copyInternalData(rhs);
	}//end operator=()
	
//----------------------------------------------------------------------
	
	T& operator[](string key)
	{	
		int code = hashcode(key) % map.size();
		
		
		if(map.at(code) == NULL)
		{
			
			Node * np = new Node(key);
			map.at(code) = np;
			
			return np->payload;
		}
		
		if(map.at(code)->key == key) return map.at(code)->payload;
		
		else do
		{
			code = hashcode2(key) % 103;
		}while(map.at(code) != NULL);
		
		Node * np = new Node(key);
		map.at(code) = np;

		return map.at(code)->payload;
	}//end operator[]()
	
//----------------------------------------------------------------------

	Node* find(const string &key)
	{
		int code = hashcode(key) % map.size();
		return map.at(code);
		
	}//end find()
	
//----------------------------------------------------------------------	
	
	int size()
	{
		int count = 0;
		for(unsigned i = 0; i < map.size(); i++)
		{
			if(map.at(i) == NULL) continue;
			else count ++;
		}
		return count;
	}//end size()
	
//----------------------------------------------------------------------
	
};//end hashmap class


#endif
