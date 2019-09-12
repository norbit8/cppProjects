// HashMap.hpp

#include <iostream>
#include <vector>
#include <exception>

static const int STARTING_VALUE = 16; /** The default size of the table */
static const double DEFAULT_ULOAD_FACTOR = 0.25; /** Default upper load factor */
static const double DEFAULT_LLOAD_FACTOR = 0.75; /** Default lower load factor */
static const int INCREASE_SIZE = 2;
static const double DECREASE_SIZE = 0.5;
static const char *BAD_SIZE_VEC = "Invalid input\n";

/**
 * BadVecInputException exception
 */
class BadVecInputException : public std::exception
{
    /**
     * The what function override
     * @return const char *
     */
    const char *what() const noexcept override
    {
        return BAD_SIZE_VEC;
    }
};

using std::vector;

/**
 * Generic HashMap
 * @tparam KeyT Some key.
 * @tparam ValueT Some value.
 */
template<class KeyT , class ValueT>
class HashMap
{

private:
    using bucket = vector<std::pair<KeyT , ValueT>>;
    vector<bucket> _table; /** The main hash map table */
    double _lowerLoadFactor; /** The lower load factor of the hash map */
    double _upperLoadFactor; /** The upper load factor of the hash map */
    int _size; /** The number of elements in the table */
    int _capacity; /** The capacity of the table */

    /**
     * Hash function
     * @param key the key to hash.
     * @return the hashed res.
     */
    int _getHash(KeyT key , int) const;

    /**
     * This private function resizes the table and re-hashes all the items
     */
    void _resizeTable(bool);

    /**
     * re-hashing the elements of the table.
     */
    void _reHash(double);

public:
    /**
    * Default ctor, init's an empty hash map.
    * @tparam KeyT Some Key.
    * @tparam ValueT Some Value.
    */
    HashMap() : HashMap(DEFAULT_LLOAD_FACTOR , DEFAULT_ULOAD_FACTOR)
    {}

    /**
     * Ctor with upper and lower load factor as arguments.
     * @param upperLoadFactor Upper load factor of the hash map.
     * @param lowerLoadFactor Lower load factor of the hash map.
     */
    HashMap(double lowerLoadFactor , double upperLoadFactor);

    /**
     * Ctor which takes two vectors, one for keys and one for values
     * and saves them inside the map by order.
     * @param keys Keys.
     * @param values Values.
     */
    HashMap(vector<KeyT> keys , vector<ValueT> values);

    /**
     * Dtor.
     */
    ~HashMap() = default;

    /**
     * Getter to size, the amount of items in the map.
     * @return _size.
     */
    const int &size() const;

    /**
     * Gets the capacity of the table.
     * @return capacity of the table, (table.size()).
     */
    const int& capacity() const;

    /**
     * Getter for the load factor.
     * @return the current load factor of the hash map.
     */
    double getLoadFactor() const;

    /**
     * The function checks if the map is empty.
     * @return true if its empty, false otherwise.
     */
    bool empty() const;

    /**
     * This method saves the key and the value.
     * @param key key.
     * @param value value.
     * @return true for success, false otherwise.
     */
    bool insert(KeyT key , ValueT value);

    /**
    * Contains key is a method which returns true if the key is inside the table.
    * @tparam KeyT template key.
    * @tparam ValueT template val.
    * @param key the given key.
    * @return true if the key is inside the table, false otherwise.
    */
    bool containsKey(const KeyT &key) const;

    /**
     * gets a key and checks if it exists in the map it returns it.
     * @param key a key.
     * @return
     */
    ValueT at(const KeyT &key) const;

    /**
    * Erases a pair from the bucket.
    * Time complexity is linear on the number of elements erased
    * (destructions) plus the number of elements after the last element deleted (moving).
    * @tparam KeyT template key.
    * @tparam ValueT template val
    * @param key key.
    * @return true for success, false otherwise.
    */
    bool erase(KeyT key);

    /**
     * Getter for the size of a specific bucket.
     * @param key a key.
     * @return integer which is the size of the bucket (vector).
     */
    int bucketSize(KeyT key) const;

    /**
     * clears the table (erasing all the tables values)
     * BUT(!) it won't change the capacity of the table.
     * https://moodle2.cs.huji.ac.il/nu18/mod/forum/discuss.php?d=75102
     */
    void clear();

    /**
    * const forward iterator implementation
    */
    class iterator
    {
    public:
        iterator(vector<bucket> tbl = nullptr) : _tbl(tbl)
        {
            if (_tbl != nullptr)
            {
                for (auto index : _tbl.begin()).
            }
        }

        const std::pair<KeyT , ValueT> &operator*()
        { return *_pairPtr; }

        iterator &operator++()
        {
            for (int index = _i; index < _tbl.end(); ++index)
            {
                for ()
            }
        }

        // pre
        iterator &operator++(std::pair<KeyT , ValueT>);

        bool operator==(iterator const &rhs) const
        {
            return this->_pointer == rhs._pointer;
        }

        bool operator!=(iterator const &rhs) const
        {
            return this->_pointer != rhs._pointer;
        }

    private:
        int _i;
        int _j;
        vector<bucket> _tbl;
        std::pair<KeyT , ValueT> *_pairPtr;
    };

    iterator begin()
    { return iterator(, _table); }

    iterator end()
    { return iterator(nullptr); }

};

/**
 * Ctor with upper and lower load factor as arguments.
 * @param upperLoadFactor Upper load factor of the hash map.
 * @param lowerLoadFactor Lower load factor of the hash map.
 */
template<class KeyT , class ValueT>
HashMap<KeyT , ValueT>::HashMap(double lowerLoadFactor , double upperLoadFactor):
        _table(STARTING_VALUE) ,
        _lowerLoadFactor(lowerLoadFactor) ,
        _upperLoadFactor(upperLoadFactor) ,
        _size(0) ,
        _capacity(STARTING_VALUE)
{
    // TODO: check if the lower load factor and upper load factor are valid (negative or weird)
    if (lowerLoadFactor > upperLoadFactor) // revert order
    {
        _lowerLoadFactor = upperLoadFactor;
        _upperLoadFactor = lowerLoadFactor;
    }
}

/**
 * Ctor which takes two vectors, one for keys and one for values
 * and saves them inside the map by order.
 * @param keys Keys.
 * @param values Values.
 */
template<class KeyT , class ValueT>
HashMap<KeyT , ValueT>::HashMap(vector<KeyT> keys , vector<ValueT> values)
{
    if (keys.size() != values.size())
    {
        throw BadVecInputException();
    }
    for (int i = 0; i < keys.size(); ++i)
    {
        insert(keys[i] , values[i]);
    }
}

/**
 * Getter to size, the amount of items in the map.
 * @return _size.
 */
template<class KeyT , class ValueT>
const int &HashMap<KeyT , ValueT>::size() const
{
    return _size;
}

/**
 * Gets the capacity of the table.
 * @return capacity of the table, (table.size()).
 */
template<class KeyT , class ValueT>
const int &HashMap<KeyT , ValueT>::capacity() const
{
    return _capacity;
}

/**
 * Getter for the load factor.
 * @return the current load factor of the hash map.
 */
template<class KeyT , class ValueT>
double HashMap<KeyT , ValueT>::getLoadFactor() const
{
    return ((double) size() / (double) capacity());
}

/**
 * The function checks if the map is empty.
 * @return true if its empty, false otherwise.
 */
template<class KeyT , class ValueT>
bool HashMap<KeyT , ValueT>::empty() const
{
    return size() == 0;
}

/**
 * This method saves the key and the value.
 * @param key key.
 * @param value value.
 * @return true for success, false otherwise.
 */
template<class KeyT , class ValueT>
bool HashMap<KeyT , ValueT>::insert(KeyT key , ValueT value)
{
    if (containsKey(key)) // https://moodle2.cs.huji.ac.il/nu18/mod/forum/discuss.php?d=75091
    {
        return false;
    }
    _size++;
    if (getLoadFactor() > _upperLoadFactor) // check that the current load factor is OK
    {
        _resizeTable(true);
    }
    int index = _getHash(key , capacity());
    _table[index].push_back(std::pair<KeyT , ValueT>(key , value)); // pushing the pair to the map
    return true;
}

/**
 * Hash function
 * @param key the key to hash.
 * @return the hashed res.
 */
template<class KeyT , class ValueT>
int HashMap<KeyT , ValueT>::_getHash(KeyT key , int capacity) const
{
    return (std::hash<KeyT>{}(key) & (capacity - 1));
}

/**
 * Contains key is a method which returns true if the key is inside the table.
 * @tparam KeyT template key.
 * @tparam ValueT template val.
 * @param key the given key.
 * @return true if the key is inside the table, false otherwise.
 */
template<class KeyT , class ValueT>
bool HashMap<KeyT , ValueT>::containsKey(const KeyT &key) const
{
    int index = _getHash(key , capacity());
    for (auto i = _table[index].begin(); i != _table[index].end(); i++)
    {
        if (i->first == key) return true;
    }
    return false;
}

/**
 * gets a key and checks if it exists in the map it returns it.
 * @param key a key.
 * @return
 */
template<class KeyT , class ValueT>
ValueT HashMap<KeyT , ValueT>::at(const KeyT &key) const
{
    if (!containsKey(key))
    {
        throw (std::out_of_range(""));
    }
    int index = _getHash(key , capacity());
    for (auto i = _table[index].begin(); i != _table[index].end(); i++)
    {
        if (i->first == key)
        {
            return i->second;
        }
    }
}

/**
 * Erases a pair from the bucket.
 * Time complexity is linear on the number of elements erased
 * (destructions) plus the number of elements after the last element deleted (moving).
 * @tparam KeyT template key.
 * @tparam ValueT template val
 * @param key key.
 * @return true for success, false otherwise.
 */
template<class KeyT , class ValueT>
bool HashMap<KeyT , ValueT>::erase(KeyT key)
{
    int index = _getHash(key , capacity());
    for (auto i = _table[index].begin(); i != _table[index].end(); i++)
    {
        if (i->first == key)
        {
            _table[index].erase(i , i + 1);
            _size--;
            if (getLoadFactor() > _upperLoadFactor) // check that the current load factor is OK
            {
                _resizeTable(false);
            }
            return true;
        }
    }
    return false;
}

/**
 * Getter for the size of a specific bucket.
 * @param key a key.
 * @return integer which is the size of the bucket (vector).
 */
template<class KeyT , class ValueT>
int HashMap<KeyT , ValueT>::bucketSize(KeyT key) const
{
    int index = _getHash(key , capacity());
    return _table[index].size();
}

/**
 * clears the table (erasing all the tables values)
 * BUT(!) it won't change the capacity of the table.
 * https://moodle2.cs.huji.ac.il/nu18/mod/forum/discuss.php?d=75102
 */
template<class KeyT , class ValueT>
void HashMap<KeyT , ValueT>::clear()
{
    for (auto i = _table.begin(); i != _table.end(); ++i)
    {
        *i.clear(); // clearing each bucket.
    }
    _size = 0; // 0 elements in the table right now.
}

template<class KeyT , class ValueT>
void HashMap<KeyT , ValueT>::_reHash(double resizeFactor)
{
    int newSize = (int) (capacity() * resizeFactor);
    vector<bucket> tempTable((unsigned long) (newSize));
    for (auto i = _table.begin(); i != _table.end(); ++i)
    {
        for (auto j = (*i).begin(); j != (*i).end(); ++j)
        {
            int hashIndex = _getHash(j->first , newSize);
            tempTable[hashIndex].push_back(std::pair<KeyT , ValueT>(j->first , j->second));
        }
    }
    _table = tempTable;
    _capacity = newSize;
}

/**
 * This private function resizes the table and re-hashes all the items
 */
template<class KeyT , class ValueT>
void HashMap<KeyT , ValueT>::_resizeTable(bool increase)
{
    if (increase) // increase the size
    {
        _reHash(INCREASE_SIZE);
    }
    else // decrease size
    {
        _reHash(DECREASE_SIZE);
    }
}