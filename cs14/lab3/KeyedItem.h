#include <string>
using namespace std;

#ifndef KEYEDITEM_H_
#define KEYEDITEM_H_

typedef int KeyType;

class KeyedItem
{
public:
   KeyedItem() {};
   KeyedItem(const KeyType& keyValue)
            : searchKey(keyValue) { }

   KeyType getKey() const
   {
      return searchKey;
   } // end getKey

private:
   KeyType searchKey;
}; // end class
#endif /* KEYEDITEM_H_ */
