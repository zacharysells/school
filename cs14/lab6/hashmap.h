/*
 * hashmap.h
 *
 */

#ifndef HASHMAP_H_
#define HASHMAP_H_
/*
 * File: hashmap.h
 * ---------------
 * This interface exports the HashMap class, which is identical to the Map
 * class except for the fact that it uses a hash table as its underlying
 * representation.  Although the HashMap class operates in constant time,
 * the iterator for HashMap returns the values in a seemingly random order.
 */

#include <cstdlib>
#include <string>
#include <vector>

using namespace std;

/*
 * Class: HashMap<KeyType,ValueType>
 * ---------------------------------
 * The HashMap class maintains an association between keys and values.
 */

template <typename KeyType, typename ValueType>
class HashMap {

public:

/*
 * Constructor: HashMap
 * Usage: HashMap<KeyType,ValueType> map;
 * --------------------------------------
 * Initializes a new empty map that associates keys and values of the
 * specified types.  The type used for the key must define the == operator,
 * and there must be a function with the following signature:
 *
 *    int hashCode(KeyType key);
 *
 * that returns a positive integer determined by the key.
 */

   HashMap();


/*
 * Deep copying support
 * --------------------
 * This copy constructor and operator= are defined to make a
 * deep copy, making it possible to pass/return maps by value
 * and assign from one map to another.
 */

   HashMap(const HashMap & rhs);


   HashMap & operator=(const HashMap & rhs);


/*
 * Destructor: ~HashMap
 * --------------------
 * Frees any heap storage associated with this map.
 */

   ~HashMap();

/*
 * Method: size
 * Usage: int nEntries = map.size();
 * ---------------------------------
 * Returns the number of entries in this map.
 */

   int size() const;

/*
 * Method: isEmpty
 * Usage: if (map.isEmpty()) . . .
 * -------------------------------
 * Returns true if this map contains no entries.
 */

   bool isEmpty() const;

/*
 * Method: put
 * Usage: map.put(key, value);
 * ---------------------------
 * Associates key with value in this map.  Any previous value associated
 * with key is replaced by the new value.
 */

   void put(KeyType key, ValueType value);

/*
 * Method: get
 * Usage: ValueType value = map.get(key);
 * --------------------------------------
 * Returns the value associated with key in this map.  If key is not found,
 * get returns the default value for ValueType.
 */

   ValueType get(KeyType key) const;

/*
 * Method: containsKey
 * Usage: if (map.containsKey(key)) . . .
 * --------------------------------------
 * Returns true if there is an entry for key in this map.
 */

   bool containsKey(KeyType key) const;

/*
 * Method: remove
 * Usage: map.remove(key);
 * -----------------------
 * Removes any entry for key from this map.
 */

   void remove(KeyType key);

/*
 * Method: clear
 * Usage: map.clear();
 * -------------------
 * Removes all entries from this map.
 */

   void clear();

/*
 * Operator: []
 * Usage: map[key]
 * ---------------
 * Selects the value associated with key.  This syntax makes it easy to
 * think of a map as an "associative array" indexed by the key type.  If
 * key is already present in the map, this function returns a reference to
 * its associated value.  If key is not present in the map, a new entry is
 * created whose value is set to the default for the value type.
 */

   ValueType & operator[](KeyType key);


/*
 * Function: hashCode
 * Usage: int hash = hashCode(key);
 * --------------------------------
 * Returns a hash code for the specified key, which is always a nonnegative
 * integer.
 */

   int hashCode(const KeyType& key) const;


/*
 * Function: print
 * Usage: map.print
 * -------------------------------
 * Prints the content of the map. The format should look like
 *  "{key1:value1}, "{key2:value2},...,"{keyN:valueN}
 */
   void print();

private:

/* Constant definitions */

   static const int INITIAL_BUCKET_COUNT = 103;
   static const int MAX_LOAD_PERCENTAGE = 70;

/* Type definition for cells in the bucket chain */

 struct Cell {
      KeyType key;
      ValueType value;
      Cell *next;
      
   };

/* Instance variables */

   vector <Cell *> buckets;
   int nBuckets;
   int numEntries;

/* Private methods */

/*
 * Private method: createBuckets
 * Usage: createBuckets(nBuckets);
 * -------------------------------
 * Sets up the vector of buckets to have nBuckets entries, each NULL.
 * If asked to make empty vector, makes one bucket just to simplify
 * handling elsewhere.
 */

   void createBuckets(int nBuckets) {
      if (nBuckets == 0) nBuckets = 1;
      buckets = vector<Cell *>(nBuckets, NULL);
      this->nBuckets = nBuckets;
      numEntries = 0;
   }

/*
 * Private method: deleteBuckets
 * Usage: deleteBuckets(buckets);
 * ------------------------------
 * Deletes all the cells in the linked lists contained in vector.
 */

   void deleteBuckets(vector <Cell *> & buckets) {
      for (int i = 0; i < buckets.size(); i++) {
         Cell *cp = buckets[i];
         while (cp != NULL) {
            Cell *np = cp->next;
            delete cp;
            cp = np;
         }
         buckets[i] = NULL;
      }
   }

/*
 * Private method: expandAndRehash
 * Usage: expandAndRehash();
 * -------------------------
 * This method is used to increase the number of buckets in the map
 * and then rehashes all existing entries and adds them into new buckets.
 * This operation is used when the load factor (i.e. the number of cells
 * per bucket) has increased enough to warrant this O(N) operation to
 * enlarge and redistribute the entries.
 */

   void expandAndRehash() {
      vector<Cell *>oldBuckets = buckets;
      createBuckets(oldBuckets.size() * 2 + 1);
      for (int i = 0; i < oldBuckets.size(); i++) {
         for (Cell *cp = oldBuckets[i]; cp != NULL; cp = cp->next) {
            put(cp->key, cp->value);
         }
      }
      deleteBuckets(oldBuckets);
   }

/*
 * Private method: findCell
 * Usage: Cell *cp = findCell(bucket, key);
 *        Cell *cp = findCell(bucket, key, parent);
 * ------------------------------------------------
 * Finds a cell in the chain for the specified bucket that matches key.
 * If a match is found, the return value is a pointer to the cell containing
 * the matching key.  If no match is found, the function returns NULL.
 * If the optional third argument is supplied, it is filled in with the
 * cell preceding the matching cell to allow the client to splice out
 * the target cell in the delete call.  If parent is NULL, it indicates
 * that the cell is the first cell in the bucket chain.
 */

   Cell *findCell(int bucket, KeyType key) const {
      Cell *dummy;
      return findCell(bucket, key, dummy);
   }

   Cell *findCell(int bucket, KeyType key, Cell * & parent) const {
      parent = NULL;
      Cell *cp = buckets[bucket];
      while (cp != NULL && key != cp->key) {
         parent = cp;
         cp = cp->next;
      }
      return cp;
   }

   void copyInternalData(const HashMap & rhs) {
      createBuckets(rhs.nBuckets);
      for (int i = 0; i < rhs.nBuckets; i++) {
         for (Cell *cp = rhs.buckets[i]; cp != NULL; cp = cp->next) {
            put(cp->key, cp->value);
         }
      }
   }

public:

/*
 * Iterator support
 * ----------------
 */

   class iterator : public std::iterator<std::input_iterator_tag,KeyType> {

   private:

      const HashMap *mp;           /* Pointer to the map           */
      int bucket;                  /* Index of current bucket      */
      Cell *cp;                    /* Current cell in bucket chain */

   public:

      iterator() {
        /* Empty */
      }

      iterator(const HashMap *mp, bool end) {
         this->mp = mp;
         if (end) {
            bucket = mp->nBuckets;
            cp = NULL;
         } else {
            bucket = 0;
            cp = mp->buckets[bucket];
            while (cp == NULL && ++bucket < mp->nBuckets) {
               cp = mp->buckets[bucket];
            }
         }
      }

      iterator(const iterator & it) {
         mp = it.mp;
         bucket = it.bucket;
         cp = it.cp;
      }

      iterator & operator++() {
         cp = cp->next;
         while (cp == NULL && ++bucket < mp->nBuckets) {
            cp = mp->buckets[bucket];
         }
         return *this;
      }

      iterator operator++(int) {
         iterator copy(*this);
         operator++();
         return copy;
      }

      bool operator==(const iterator & rhs) {
         return mp == rhs.mp && bucket == rhs.bucket && cp == rhs.cp;
      }

      bool operator!=(const iterator & rhs) {
         return !(*this == rhs);
      }

      KeyType operator*() {
         return cp->key;
      }

      KeyType *operator->() {
         return &cp->key;
      }

      friend class HashMap;

   };

   iterator begin() const {
      return iterator(this, false);
   }

   iterator end() const {
      return iterator(this, true);
   }

};

#endif /* HASHMAP_H_ */
