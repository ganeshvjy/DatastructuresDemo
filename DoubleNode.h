#include "Interfaces01.h"

class DoubleNode:public IDoubleNode{
private:
	int Data;
	IDoubleNode * Next;
	IDoubleNode * Prev;
public:
	DoubleNode::DoubleNode() {
		Prev = NULL;
		Next = NULL;
	}
	~DoubleNode() {}
	void setValue(int value);
	int getValue();
	IDoubleNode * getPrev();
	IDoubleNode * getNext();
	void setPrev(IDoubleNode * prev);
	void setNext(IDoubleNode * next);

};