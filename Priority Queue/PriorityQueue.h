//Priorityqueue.h - PriorityQueue template class declaration
//Written by Alexander Kohler

#include <Vector>
#pragma once
using namespace std;


template<typename DATA_TYPE>
class PriorityQueue
{
public:

	PriorityQueue(){}


	// Returns the first element from the queue
	const DATA_TYPE& Top() const
	{
		return QueueData.front();
	}

	// Returns true when the queue is empty
	bool IsEmpty() const
	{
		return QueueData.empty();
	}


	// Pops the first element from the queue and rearranges the QueueData to maintain priority
	void Pop()
	{
		//Replace the value of the top heap element with the value of the right most node from the bottom row of the tree and delete the right most node.


		//While the root has children and its value is smaller than the value of its largest child
		//Swap the root value with the value of its largest child thus moving the root value down the heap.
		//Referenced from Pg. 494, Objects, Abtractions... Koffman
		if (QueueData.size() == 1) {
			QueueData.pop_back();
			return;
		}
		swap(QueueData[0], QueueData[QueueData.size() - 1]);
		QueueData.pop_back();
		int parent = 0;
		while (true) {
			unsigned int left_child = 2 * parent + 1;
			if (left_child >= QueueData.size())
				break; // out of heap
			unsigned int right_child = left_child + 1;
			int max_child = left_child;
			if (right_child < QueueData.size() && QueueData[left_child] > QueueData[right_child])
				max_child = right_child;
			// assert: max_child is the index of the larger child
			if (QueueData[parent] > QueueData[max_child]) {
				swap(QueueData[max_child], QueueData[parent]);
				parent = max_child;
			}
			else
				break;
		}

	}
	// Pushes a new element into the queue and rearranges the QueueData to maintain priority

	
	void Push(const DATA_TYPE& newValue)
	{
		// Push new value to the end of the queue
		QueueData.push_back(newValue);
		// The index of the child node corresponding to the new value
		int child = QueueData.size() - 1;
		// Determine the index of it’s parent
		int parent = (child - 1)/2;

		// While we are not at the top and the child is smaller than the parent
		while ( (parent >= 0) && (QueueData[parent] > QueueData[child]) ) //had unresolved external likely from not defining operators needed for this function (symbolpriority operators)
		{
			// Swap the parent and the child to maintain order
			swap(QueueData[parent], QueueData[child]);
			// Now the parent becomes the new child
			child = parent;
			parent = (child - 1)/2;
		}

	}

private:
	// PriorityQueue: heap packaged into vector
	vector<DATA_TYPE> QueueData;
};






