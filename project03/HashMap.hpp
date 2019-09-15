// HashMap.hpp

#include <iostream>
#include <vector>
#include <exception>

static const int STARTING_VALUE = 16; /** The default size of the table */
static const double DEFAULT_ULOAD_FACTOR = 0.25; /** Default upper load factor */
static const double DEFAULT_LLOAD_FACTOR = 0.75; /** Default lower load factor */
static const int INCREASE_SIZE = 2; /** The size factor to increase the hash map */
static const double DECREASE_SIZE = 0.5; /** The size factor to decrease the hash map */
static const char *BAD_SIZE_VEC = "Invalid input\n"; /** Bad comparison exception string */
static const char *BAD_INPUT = "Invalid input\n"; /** Bad comparison exception string */

using std::vector;
using std::cout;
using std::endl;

/**
 * BadVecInputException exception,
 * bad comparison of two vectors.
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

/**
 * BadVecInputException exception,
 * bad comparison of two vectors.
 */
class badInputException : public std::exception
{
    /**
     * The what function override
     * @return const char *
     */
    const char *what() const noexcept override
    {
        return BAD_INPUT;
    }
};

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
     * Copy ctor
     * @param other other hash map.
     */
    HashMap(const HashMap &other);

    /**
     * Move ctor
     */
    HashMap(HashMap && other) noexcept = default;

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
    const int &capacity() const;

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
    bool containsKey(KeyT const &key) const;

    /**
     * gets a key and checks if it exists in the map it returns it.
     * can throw exception if the key is not found.
     * @param key a key.
     * @return the value for the key.
     */
    const ValueT &at(const KeyT &key) const;


    /**
     * gets a key and checks if it exists in the map it returns it.
     * can throw exception if the key is not found.
     * @param key a key.
     * @return A value.
     */
    ValueT &at(const KeyT &key);

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
        friend class HashMap<KeyT , ValueT>;

        /**
         * default ctor
         */
        iterator()
        {
            vector<bucket> emptyTable(1);
            emptyTable[0].push_back(std::pair<KeyT , ValueT>());
            _tbl = emptyTable;
            _current = 0;
        }


        /**
         * Dereference operator.
         * @return A pointer to the pair.
         */
        const std::pair<KeyT , ValueT> &operator*()
        {
            int counter = 0;
            for (auto i = _tbl.begin(); i != _tbl.end(); ++i)
            {
                for (auto j = i->begin(); j != i->end(); ++j)
                {
                    if (counter == _current)
                    {
                        return *j;
                    }
                    counter++;
                }
            }
            auto i = _tbl.begin();
            auto j = i->begin();
            return *j;
        }

        /**
         * Right Arrow operator
         * @return pointer to dereference of this.
         */
        const std::pair<KeyT , ValueT> *operator->() const
        {
            int counter = 0;
            for (auto i = _tbl.begin(); i != _tbl.end(); ++i)
            {
                for (auto j = i->begin(); j != i->end(); ++j)
                {
                    if (counter == _current)
                    {
                        return &(*j);
                    }
                    counter++;
                }
            }
        }

        /**
         * operator overloading ++
         * @return the updated iterator.(this)
         */
        iterator &operator++()
        {
            _current++;
            return *this;
        }

        /**
         * post ++ overloading
         * @return the older iterator (before incrementing)
         */
        iterator operator++(int)
        {
            iterator *oldIter = this;
            _current++;
            return *oldIter;
        }

        /**
         * == operator
         * @param rhs right hand side iterator.
         * @return true if they are equal, false otherwise.
         */
        bool operator==(iterator const &rhs) const
        {
            return (this->_current == rhs._current && this->_tbl == rhs._tbl);
        }

        /**
         * != operator
         * @param rhs right hand side iterator.
         * @return true if they are not equal, false otherwise.
         */
        bool operator!=(iterator const &rhs) const
        {
            return (this->_current != rhs._current || this->_tbl != rhs._tbl);
        }

    private:
        vector<bucket> _tbl; /** The hash map */
        int _current; /** Which elements we are probing right now */

        /**
         * ctor
         * @param table the hash map.
         * @param current which element to start from.
         */
        iterator(const vector<bucket> &table , int current) : _tbl(table) , _current(current)
        {}
    };

    /**
     * Begin iterator
     * @return a new iterator for HashMap
     */
    iterator begin() const
    {
        return iterator(_table , 0);
    }

    /**
     * End
     * @return An iterator with an end state.
     */
    iterator end() const
    {
        return iterator(_table , size());
    }

    /**
     * Begin iterator
     * @return a new iterator for HashMap
     */
    iterator cbegin() const
    {
        return iterator(_table , 0);
    }

    /**
     * End
     * @return An iterator with an end state.
     */
    iterator cend() const
    {
        return iterator(_table , size());
    }

    /**
     * Subscript operator
     * @param key any key
     * @return they value of the key, if the key does'nt exist it will add the key to the table
     * with a default value.
     */
    ValueT &operator[](KeyT key) noexcept;

    /**
    * Subscript operator
    * @param key any key
    * @return they value of the key, if the key does'nt exist it will add the key to the table
    * with a default value.
    */
    const ValueT &operator[](KeyT const &key) const noexcept;

    /**
     * == operator, checks if two sets has the same elements
     * @param rhs another hash map
     * @return true if they have the same elements, false otherwise.
     */
    bool operator==(HashMap const &rhs) const;

    /**
     * != operator, checks if two sets doesn't have the same elements
     * @param rhs another hash map
     * @return false if they have the same elements, true otherwise.
     */
    bool operator!=(HashMap const &rhs) const;

    /**
     * operator = with swap.
     * @return *this.
     */
    HashMap &operator=(HashMap);

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
HashMap<KeyT , ValueT>::HashMap(vector<KeyT> keys , vector<ValueT> values) :
        HashMap()
{
    if (keys.size() != values.size())
    {
        throw BadVecInputException();
    }
    for (int i = 0; i < keys.size(); ++i)
    {
        (*this)[keys[i]] = values[i]; // insert(keys[i] , values[i]); won't work because
        // they wanted to get the last element in.
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
bool HashMap<KeyT , ValueT>::containsKey(KeyT const &key) const
{
    int index = _getHash(key , capacity());
    if (index >= _table.capacity())
    {
        return false;
    }
    for (auto i = _table[index].begin(); i != _table[index].end(); i++)
    {
        if (i->first == key)
        {
            return true;
        }
    }
    return false;
}

/**
 * gets a key and checks if it exists in the map it returns it.
 * can throw exception if the key is not found.
 * @param key a key.
 * @return the value for the key.
 */
template<class KeyT , class ValueT>
const ValueT &HashMap<KeyT , ValueT>::at(const KeyT &key) const
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
            _table[index].erase(i);
            _size--;
            if (getLoadFactor() < _lowerLoadFactor) // check that the current load factor is OK
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
        (*i).clear(); // clearing each bucket.
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

/**
 * gets a key and checks if it exists in the map it returns it.
 * can throw exception if the key is not found.
 * @param key a key.
 * @return the value for the key.
 */
template<class KeyT , class ValueT>
ValueT &HashMap<KeyT , ValueT>::at(const KeyT &key)
{
    if (!containsKey(key))
    {
        throw (std::out_of_range(""));
    }
    else
    {
        int index = _getHash(key , capacity());
        for (auto i = _table[index].begin(); i != _table[index].end(); i++)
        {
            if (i->first == key)
            {
                return i->second;
            }
        }
    }
    auto i = _table[0].begin();
    return i->second;
}

/**
 * Subscript operator
 * @param key any key
 * @return they value of the key, if the key does'nt exist it will add the key to the table
 * with a default value.
 */
template<class KeyT , class ValueT>
ValueT &HashMap<KeyT , ValueT>::operator[](KeyT key) noexcept
{
    if (containsKey(key))
    {
        return at(key);
    }
    else
    {
        ValueT val; // default value
        insert(key , val);
        return at(key);
    }
}

/**
 * == operator, checks if two sets has the same elements
 * @param rhs another hash map
 * @return true if they have the same elements, false otherwise.
 */
template<class KeyT , class ValueT>
bool HashMap<KeyT , ValueT>::operator==(HashMap const &rhs) const
{
    // if the sizes are not the same
    if (rhs.size() != this->size() || rhs.capacity() != this->capacity())
    {
        return false;
    }
    if (rhs.size() == 0 && this->size() == 0)
    {
        return true;
    }
    bool flag = false;
    for (auto item : rhs)
    {
        flag = false;
        for (auto innerItem : *this)
        {
            if (item == innerItem)
            {
                flag = true;
            }
        }
        if (!flag)
        {
            return false;
        }
    }
    return flag;
}

/**
 * != operator, checks if two sets doesn't have the same elements
 * @param rhs another hash map
 * @return false if they have the same elements, true otherwise.
 */
template<class KeyT , class ValueT>
bool HashMap<KeyT , ValueT>::operator!=(HashMap const &rhs) const
{
    return !(*this == rhs);
}

/**
 * operator = with swap.
 * @return *this.
 */
template<class KeyT , class ValueT>
HashMap<KeyT , ValueT> &HashMap<KeyT , ValueT>::operator=(HashMap other)
{
    swap(*this , other);
    return *this;
}

/**
 * Copy ctor
 * @param other other hash map.
 */
template<class KeyT , class ValueT>
HashMap<KeyT , ValueT>::HashMap(const HashMap &other) :
        _table(other._table) ,
        _lowerLoadFactor(other._lowerLoadFactor) ,
        _upperLoadFactor(other._upperLoadFactor) ,
        _size(other.size()) ,
        _capacity(other.capacity())
{}

/**
 * Subscript operator
 * @param key any key
 * @return they value of the key, if the key does'nt exist it will add the key to the table
 * with a default value.
 */
template<class KeyT , class ValueT>
const ValueT &HashMap<KeyT , ValueT>::operator[](KeyT const &key) const noexcept
{
    if (containsKey(key))
    {
        return at(key);
    }
    else
    {
        ValueT val; // default value
        insert(key , val);
        return at(key);
    }
}