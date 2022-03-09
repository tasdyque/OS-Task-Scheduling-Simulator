
#ifndef HEAP_H
#define HEAP_H

#include <stdexcept>
#include <iostream>

using namespace std;

/// <summary>
/// Comparator that returns true if the first parameter is a greater value than the second parameter. Used to maintain the integrity of the Heap
/// </summary>
/// <typeparam name="KeyType"></typeparam>
template < typename KeyType = int >
class Greater {
public:
    bool operator()(const KeyType& a, const KeyType& b) const 
    { 
        return a > b; 
    }
};


/// <summary>
/// Heap base class
/// </summary>
/// <typeparam name="DataType"></typeparam>
/// <typeparam name="KeyType"></typeparam>
/// <typeparam name="Comparator"></typeparam>
template < typename DataType, typename KeyType = int, typename Comparator = Greater<KeyType> >
class Heap
{
public:

    /// <summary>
    /// default max size of the heap
    /// </summary>
    static const int DEFAULT_MAX_HEAP_SIZE = 10;    // Default maximum heap size

    /// <summary>
    /// Default constructor for the heap class, with default parameter 
    /// </summary>
    /// <param name="maxNumber"></param>
    Heap(int maxNumber = DEFAULT_MAX_HEAP_SIZE); 

    /// <summary>
    /// Copy constructor
    /// </summary>
    /// <param name="other"></param>
    Heap(const Heap& other);		    

    /// <summary>
    /// Assignment operator overload 
    /// </summary>
    /// <param name="other"></param>
    /// <returns></returns>
    Heap& operator= (const Heap& other);  

    /// Class destructor
    ~Heap();


    /// <summary>
    /// Insert function for the heap array 
    /// </summary>
    /// <param name="newDataItem"></param>
    /// <returns></returns>
    void insert(const DataType& newDataItem) throw (logic_error);            

    /// <summary>
    /// remove function for the heap array
    /// </summary>
    /// <returns></returns>
    DataType remove() throw (logic_error);  // Remove max priority element

    /// <summary>
    /// helper to the remove function
    /// </summary>
    /// <param name="index"></param>
    void removeHelper(int index);

    /// <summary>
    /// clear function for the heap array, clears the array
    /// </summary>
    void clear();                          

    /// <summary>
    /// function checks if heap is empty
    /// </summary>
    /// <returns></returns>
    bool isEmpty() const;                
    

    /// <summary>
    /// function checks if heap is full
    /// </summary>
    /// <returns></returns>
    bool isFull() const;                  


    /// <summary>
    /// function outputs the tree structure
    /// </summary>
    void showStructure() const;




private:

    /// <summary>
    /// recursive helper to the showStructure funtion
    /// </summary>
    /// <param name="index"></param>
    /// <param name="level"></param>
    void showSubtree(int index, int level) const;


    /// <summary>
    /// data member stores the max array size
    /// </summary>
    int maxSize;
    
    /// <summary>
    /// Number of elements in the heap
    /// </summary>
    int size;      

    /// <summary>
    ///   pointer to the heap array
    /// </summary>
    DataType* dataItems; 

    /// <summary>
    /// comparator, defualt is a greater-than comparison
    /// </summary>
    Comparator comparator;

    /// <summary>
    /// helper to the isEmpty function
    /// </summary>
    bool isEmptyHelper;
};

#endif	//#ifndef HEAP_H
