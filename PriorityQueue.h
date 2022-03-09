#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H
#include <stdexcept>
#include <iostream>
using namespace std;
#include "Heap.cpp"


/// <summary>
/// defualt max queue size
/// </summary>
const int defMaxQueueSize = 10;   

/// <summary>
/// priority Queue subclass to the heap baseclass 
/// </summary>
/// <typeparam name="DataType"></typeparam>
/// <typeparam name="KeyType"></typeparam>
/// <typeparam name="Comparator"></typeparam>
template < typename DataType, typename KeyType = int, typename Comparator = Greater<KeyType> >
class PriorityQueue : public Heap<DataType>
{
public:

	/// Base constructor
	PriorityQueue(int maxNumber = defMaxQueueSize);

	/// <summary>
	/// Enqueues a data element
	/// </summary>
	/// <param name="newDataItem"></param>
	void enqueue(const DataType& newDataItem);  

	/// <summary>
	/// Dequeues a data element
	/// </summary>
	/// <returns></returns>
	DataType dequeue();                        
};
#endif
