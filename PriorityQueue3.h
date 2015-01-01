#include "Interfaces02.h"

class PriorityQueue3:public IPriorityQueue{
private:
	IVectorKeyValue * Vector;

public:
	PriorityQueue3();
	~PriorityQueue3();
	void enqueue(IKeyValue * key_value);
	void merge(IPriorityQueue * input_queue);
	IVectorKeyValue * returnSorted();
	int lowestKey();
	IVectorString * lowestValues();
	void dequeue();
	size_t size();

	void fix_up(IVectorKeyValue * Vector, IKeyValue * key_value);
	void fix_down(IVectorKeyValue * Vector, int k, int size );
	void exchange(IVectorKeyValue * Vector,int x,int y);
};