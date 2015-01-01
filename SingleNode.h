#pragma once
#include "Interfaces01.h"

class SingleNode : public ISingleNode{
private:
	int Data;
	ISingleNode * Next;
public:
	SingleNode();
	~SingleNode();
	void setValue(int value);
	int getValue();
	ISingleNode * getNext();
	void setNext(ISingleNode * next);
};