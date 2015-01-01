#include "Interfaces02.h"
#include "DoubleNode.h"

class PriorityQueue1 :public IPriorityQueue{
public:
	PriorityQueue1();
	~PriorityQueue1();
	void enqueue(IKeyValue * key_value);
	void merge(IPriorityQueue * input_queue);
	IVectorKeyValue * returnSorted();
	int lowestKey();
	IVectorString * lowestValues();
	void dequeue();
	size_t size();
private:
	IDoubleNode * front;
	IDoubleNode * back;
	size_t Qsize;
	//IKeyValue * Lowest;
	IDoubleNode * Lowest;
};

