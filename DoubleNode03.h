#include "Interfaces03.h"


class DoubleNode03 :public IDoubleNode03{
public:
	DoubleNode03();
	~DoubleNode03();
	void setValue(int value);
	int getValue();
	IDoubleNode03 * getPrev();
	IDoubleNode03 * getNext();
	void setPrev(IDoubleNode03 * prev);
	void setNext(IDoubleNode03 * next);

private:
	int Data;
	IDoubleNode03 * Next;
	IDoubleNode03 * Prev;
};