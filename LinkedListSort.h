#include "Interfaces03.h"

class LinkedListSort :public ILinkedListSort{
public:
	LinkedListSort();
	~LinkedListSort();
	LinkedListNode * sort(LinkedListNode * list);
	void QuickSort(LinkedListNode ** Head);
	LinkedListNode * _Sort(LinkedListNode * Head, LinkedListNode * Tail);
	LinkedListNode * partition(LinkedListNode * Head, LinkedListNode* Tail, LinkedListNode **newHead, LinkedListNode **newTail);

};