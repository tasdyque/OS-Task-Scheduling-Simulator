#include "Heap.h"


/// <summary>
/// Defualt constructor initializes all data members, and creates a heap array pointed to by dataItems
/// </summary>
/// <typeparam name="DataType"></typeparam>
/// <typeparam name="KeyType"></typeparam>
/// <typeparam name="Comparator"></typeparam>
/// <param name="maxNumber"></param>
template < typename DataType, typename KeyType, typename Comparator >
Heap<DataType, KeyType, Comparator>::Heap(int maxNumber)
{
    maxSize = maxNumber;
    size = 0;
    dataItems = new DataType[maxSize];
    isEmptyHelper = true;
}


/// <summary>
/// Copy constructor sets all data members equal to parameter object's data members and deep copies the array
/// </summary>
/// <typeparam name="DataType"></typeparam>
/// <typeparam name="KeyType"></typeparam>
/// <typeparam name="Comparator"></typeparam>
/// <param name="other"></param>
template < typename DataType, typename KeyType, typename Comparator >
Heap<DataType, KeyType, Comparator>::Heap(const Heap& other)
{
    this->maxSize = other.maxSize;
    this->size = other.size;

    for (int i = 0; i < size; i++)
    {
        this->dataItems[i] = other.dataItems[i];
    }
   
}

/// <summary>
///  Assignment operator overload sets all data members equal to parameter object's data members and deep copies the array
/// </summary>
/// <typeparam name="DataType"></typeparam>
/// <typeparam name="KeyType"></typeparam>
/// <typeparam name="Comparator"></typeparam>
/// <param name="other"></param>
/// <returns></returns>
template < typename DataType, typename KeyType, typename Comparator >
Heap<DataType, KeyType, Comparator>& Heap<DataType, KeyType, Comparator>::operator = (const Heap& other)
{
    this->maxSize = other.maxSize;
    this->size = other.size;
    
    for (int i = 0; i < size; i++)
    {
        this->dataItems[i] = other.dataItems[i];
    }
}

/// <summary>
/// Destructor deallocates Heap array
/// </summary>
/// <typeparam name="DataType"></typeparam>
/// <typeparam name="KeyType"></typeparam>
/// <typeparam name="Comparator"></typeparam>
template < typename DataType, typename KeyType, typename Comparator >
Heap<DataType, KeyType, Comparator>::~Heap()
{
    delete[] dataItems;
}


/// <summary>
/// Insert function throws logic error if heap is full , if heap is not full function checks if the heap size is 0 and inserts a data item while incrementing the size by 1. 
/// If heap size is greater than 0, function inserts the data member into the array and restores the integrity of the heap by swapping the item upward if the parents value
/// is less than the child, maintaining the max heap
/// 
/// </summary>
/// <typeparam name="DataType"></typeparam>
/// <typeparam name="KeyType"></typeparam>
/// <typeparam name="Comparator"></typeparam>
/// <param name="newDataItem"></param>
/// <returns></returns>
template < typename DataType, typename KeyType, typename Comparator >
void Heap<DataType, KeyType, Comparator>::insert(const DataType& newDataItem) throw (logic_error)
{
    if (isFull())
    {
        throw logic_error("Error: Heap is Full");
    }
    else
    {
        if (size == 0)
        {
            dataItems[size] = newDataItem;
            size++;
            isEmptyHelper = false;
        }
        else
        {
            dataItems[size] = newDataItem;

            for (int i = size; i >= 0; i--)
            {
                int parentIndex = (i - 1)/2;

                if (comparator(dataItems[i].getPriority(), dataItems[parentIndex].getPriority()))
                {
                    DataType temp = dataItems[i];
                    dataItems[i] = dataItems[parentIndex];
                    dataItems[parentIndex] = temp;
                }
            }
            size++;

           
        }
        
    }
}

/// <summary>
/// Recursive helper to the remove function, sets isEmptyHelper to true if size is already 0, and then restores the integrity of the max heap by swapping downwards. Inputs the
/// greatrest child index to the recursive fuction call after checking if the child is greater than its parent if the index is less than the heap size. 
/// call to the function 
/// </summary>
/// <typeparam name="DataType"></typeparam>
/// <typeparam name="KeyType"></typeparam>
/// <typeparam name="Comparator"></typeparam>
/// <param name="index"></param>
template < typename DataType, typename KeyType, typename Comparator >
void Heap<DataType, KeyType, Comparator>::removeHelper(int index)
{
    if (size == 0)
    {
        isEmptyHelper = true;

    }
    else
    {
        if (index < size)
        {

            int greatestChild = 0;
            int leftChild = (2 * index) + 1;
            int rightChild = leftChild + 1;
            if (leftChild < size)
            {
                if (comparator(dataItems[leftChild].getPriority(), dataItems[rightChild].getPriority()))
                {
                    greatestChild = leftChild;
                }
                else
                {
                    greatestChild = rightChild;
                }

                if (comparator(dataItems[greatestChild].getPriority(), dataItems[index].getPriority()))
                {
                    DataType temp = dataItems[index];
                    dataItems[index] = dataItems[greatestChild];;
                    dataItems[greatestChild] = temp;
                }
                removeHelper(greatestChild);
            }
         
        }
    }
    

}

/// <summary>
///Function throws a logic error if heap is empty, and if heap isn't empty the function removes the data item at index 0 and then returns that data item. If the heap only contains one
/// data item, a new array is assigned to the pointer. If the heap contains multiple data items, the root is stored in a temporary variable and then the heap integrity is restored 
/// with a call to the helper function after decrementing the size. 
/// </summary>
/// <typeparam name="DataType"></typeparam>
/// <typeparam name="KeyType"></typeparam>
/// <typeparam name="Comparator"></typeparam>
/// <returns></returns>
template < typename DataType, typename KeyType, typename Comparator >
DataType Heap<DataType, KeyType, Comparator>::remove() throw (logic_error)
{
    if (isEmpty())
    {
        throw logic_error("Error: Heap is Empty");
    }
    else
    {
        if (size == 0)
        {
            DataType temp = dataItems[0];
            dataItems = new DataType[maxSize];
            return temp;
        }
        else
        {
            DataType temp = dataItems[0];
            dataItems[0] = dataItems[size - 1];
            size = size - 1;

            removeHelper(0);
            
            return temp;
        }
    }
}

/// <summary>
/// Function deallocates the heap array memory
/// </summary>
/// <typeparam name="DataType"></typeparam>
/// <typeparam name="KeyType"></typeparam>
/// <typeparam name="Comparator"></typeparam>
template < typename DataType, typename KeyType, typename Comparator >
void Heap<DataType, KeyType, Comparator>::clear()
{
    delete[] dataItems;
}

/// <summary>
/// function returns true if heap is empty, and false if its not
/// </summary>
/// <typeparam name="DataType"></typeparam>
/// <typeparam name="KeyType"></typeparam>
/// <typeparam name="Comparator"></typeparam>
/// <returns></returns>
template < typename DataType, typename KeyType, typename Comparator >
bool Heap<DataType, KeyType, Comparator>::isEmpty() const
{
    if (isEmptyHelper)
    {
        return true;
    }
    else
    {
        return false;
    }
}

/// <summary>
/// function returns true if heap is full, false if its not. 
/// </summary>
/// <typeparam name="DataType"></typeparam>
/// <typeparam name="KeyType"></typeparam>
/// <typeparam name="Comparator"></typeparam>
/// <returns></returns>
template < typename DataType, typename KeyType, typename Comparator >
bool Heap<DataType, KeyType, Comparator>::isFull() const
{
    if (size >= maxSize)
    {
        return true;
    }
    else
    {
        return false;
    }
}


/// <summary>
/// Outputs data item priorities in tree and array form, returns Empty Heap if heap is empty. 
/// </summary>
/// <typeparam name="DataType"></typeparam>
/// <typeparam name="KeyType"></typeparam>
/// <typeparam name="Comparator"></typeparam>
template < typename DataType, typename KeyType, typename Comparator >
void Heap<DataType, KeyType, Comparator>::showStructure() const



{
    int j;   // Loop counter

    cout << endl;
    if (size == 0)
        cout << "Empty heap" << endl;
    else
    {
        cout << "size = " << size << endl;      
        for (j = 0; j < maxSize; j++)
            cout << j << "\t";
        cout << endl;
        for (j = 0; j < size; j++)
            cout << dataItems[j].getPriority() << "\t";
        cout << endl << endl;
        showSubtree(0, 0);                   
    }
}



/// <summary>
/// Recursive helper to the showStructure function. Outputs subtrees of a specified index as well as its level. 
/// </summary>
/// <typeparam name="DataType"></typeparam>
/// <typeparam name="KeyType"></typeparam>
/// <typeparam name="Comparator"></typeparam>
/// <param name="index"></param>
/// <param name="level"></param>
template < typename DataType, typename KeyType, typename Comparator >
void Heap<DataType, KeyType, Comparator>::showSubtree(int index, int level) const



{
    int j;   // Loop counter

    if (index < size)
    {
        showSubtree(2 * index + 2, level + 1);       
        for (j = 0; j < level; j++)   
            cout << "\t";
        cout << " " << dataItems[index].getPriority();   
        if (2 * index + 2 < size)             
            cout << "<";
        else if (2 * index + 1 < size)
            cout << "\\";
        cout << endl;
        showSubtree(2 * index + 1, level + 1);       
    }
}

