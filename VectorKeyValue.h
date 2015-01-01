#include "Interfaces02.h"


class VectorKeyValue:public IVectorKeyValue{
public:
	VectorKeyValue();
	~VectorKeyValue();
	void push_back(IKeyValue * item);
	void pop_back();
	IKeyValue * get(int index);
	void set(int index, IKeyValue * item);
	size_t size();
private:
	IKeyValue** start;
	size_t Vsize;
	int capacity;
};