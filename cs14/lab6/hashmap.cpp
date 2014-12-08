/*
 * hashmap.cpp
 *
 */

//   #ifdef _hashmap_h
#include "hashmap.h"
#include <iostream>
#include <utility>

using namespace std;

   template <typename KeyType,typename ValueType>
   HashMap<KeyType,ValueType>::HashMap() {
      createBuckets(INITIAL_BUCKET_COUNT);
   }

   template <typename KeyType,typename ValueType>
      HashMap<KeyType,ValueType>::HashMap(const HashMap & rhs) {
      copyInternalData(rhs);
   }

   template <typename KeyType,typename ValueType>

    HashMap<KeyType,ValueType> & HashMap<KeyType,ValueType>::operator=(const HashMap & rhs) 
    {
        copyInternalData(rhs);
    }

   template <typename KeyType,typename ValueType>
   HashMap<KeyType,ValueType>::~HashMap() {
      deleteBuckets(buckets);
   }

   template <typename KeyType,typename ValueType>
   int HashMap<KeyType,ValueType>::size() const {
      return numEntries;
   }

   template <typename KeyType,typename ValueType>
   bool HashMap<KeyType,ValueType>::isEmpty() const {
      return size() == 0;
   }

   template <typename KeyType,typename ValueType>
   void HashMap<KeyType,ValueType>::put(KeyType key, ValueType value) 
   {
        int code = hashCode(key) % nBuckets;
        Cell * cp = buckets.at(code);
        
        if(cp == NULL)
        {
            Cell * np = new Cell;
            np->key = key;
            np->value = value;
            np->next = NULL;
            buckets.at(code) = np;
        }
        
        else 
        {
			code = hashCode2(key) % nBuckets;
            Cell * np = new Cell;
            np->key = key;
            np->value = value;
            np->next = NULL;
        }
        numEntries++;
   }

   template <typename KeyType,typename ValueType>
   ValueType HashMap<KeyType,ValueType>::get(KeyType key) const 
   {
        if(containsKey(key))
        {
            int code = hashCode(key) % nBuckets;
            Cell * cp = buckets.at(code);
            while(cp != NULL)
            {
                if(cp->key == key) return cp->value;
            
                else cp = cp->next;
            }
        } 
        else return ValueType();
   }

   template <typename KeyType,typename ValueType>
   bool HashMap<KeyType,ValueType>::containsKey(KeyType key) const 
   {
        int code = hashCode(key) % nBuckets;
        if(buckets.at(code) == NULL) return false;
        
        else return true;
   }

   template <typename KeyType,typename ValueType>
   void HashMap<KeyType,ValueType>::remove(KeyType key) 
   {
        int code = hashCode(key) % nBuckets;
        if(buckets.at(code) == NULL) return;
        
        else
        {
            Cell * cp = buckets.at(code);
            Cell *np = cp->next;
            while (cp != NULL) 
            {
                np = cp->next;
                delete cp;
                cp = np;
                numEntries--;
            }
            buckets[code] = NULL;
        }
   }

   template <typename KeyType,typename ValueType>
   void HashMap<KeyType,ValueType>::clear() 
   {
        deleteBuckets(buckets);
        nBuckets = 0;
        numEntries = 0;
   }

   template <typename KeyType,typename ValueType>
   ValueType & HashMap<KeyType,ValueType>::operator[](KeyType key) 
   {
        int code = hashCode(key) % nBuckets;
        Cell * cp = buckets.at(code);
        while(cp != NULL)
        {
            if(cp->key == key) return cp->value;
            
            else cp = cp->next;
        }
        put(key,ValueType());
   }


   template <typename KeyType, typename ValueType>
   int HashMap<KeyType,ValueType>::hashCode(const KeyType& key) const 
   {
        int hashcode = 0;
        KeyType k = (string)key;
        int long Mult = -166411791L;
        for(int i = 0; i < k.size(); i++)
            hashcode = hashcode * Mult + k[i];
        
        return hashcode & ((unsigned)-1) >> 1;
   }
   
   template <typename KeyType, typename ValueType>
   int HashMap<KeyType,ValueType>::hashCode2(KeyType key)
	{
	int r = 97; //assuming the initial vector size is 100
	return (r – (hashCode(key) % r));
	}
   
   

   template <typename KeyType, typename ValueType>
   void HashMap<KeyType,ValueType>::print() 
    {
        for (int i = 0; i < buckets.size(); i++) 
        {
            Cell *cp = buckets[i];
            while (cp != NULL) 
            {
                Cell *np = cp->next;
                cout << "Key: " << i << " Value: " << cp->value << " " << " || ";
                cp = np;
            }
	   	}
    }


//   #endif
