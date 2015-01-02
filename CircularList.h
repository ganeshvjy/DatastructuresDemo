#include "Interfaces03.h"

class CircularList :public ICircularList{
public:
	CircularList();
	~CircularList();
	void addHead(int number);
	ISingleNode03 * getTail();
	void setTail(ISingleNode03 * tail);
	int size();
private:
	ISingleNode03 * Tail;
	int Size;
};