#include "Interfaces03.h"

class DoubleList03 :public IDoubleList03{

public:
	DoubleList03();
	~DoubleList03();
	IDoubleNode03 * getHead();
	IDoubleNode03 * getTail();
	void setHead(IDoubleNode03 * head);
	void setTail(IDoubleNode03 * tail);
	void addBack(int value);
	int size();

private:
	IDoubleNode03 * Head;
	IDoubleNode03 * Tail;
	int Size;
};