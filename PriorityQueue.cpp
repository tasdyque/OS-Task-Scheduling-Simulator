
#ifndef PRIORITYQUEUE_CPP
#define PRIORITYQUEUE_CPP
using namespace std;
#include "PriorityQueue.h"


/// <summary>
/// defualt constructor creates empty priority queue
/// </summary>
/// <typeparam name="DataType"></typeparam>
/// <typeparam name="KeyType"></typeparam>
/// <typeparam name="Comparator"></typeparam>
/// <param name="maxNumber"></param>
template < typename DataType, typename KeyType, typename Comparator >
PriorityQueue<DataType, KeyType, Comparator>::PriorityQueue(int maxNumber)

	: Heap<DataType, KeyType, Comparator>(maxNumber)
{
	
}

/// <summary>
/// Inserts a data item into the priority queueu
/// </summary>
/// <typeparam name="DataType"></typeparam>
/// <typeparam name="KeyType"></typeparam>
/// <typeparam name="Comparator"></typeparam>
/// <param name="newDataItem"></param>
template < typename DataType, typename KeyType, typename Comparator >
void PriorityQueue<DataType, KeyType, Comparator>::enqueue(const DataType& newDataItem)
	
{
	Heap<DataType, KeyType, Comparator>::insert(newDataItem);
}

/// <summary>
/// removes data item of highest priority and returns it
/// </summary>
/// <typeparam name="DataType"></typeparam>
/// <typeparam name="KeyType"></typeparam>
/// <typeparam name="Comparator"></typeparam>
/// <returns></returns>
template < typename DataType, typename KeyType, typename Comparator >
DataType PriorityQueue<DataType, KeyType, Comparator>::dequeue()
{
	return Heap<DataType, KeyType, Comparator>::remove();
}
#endif           
