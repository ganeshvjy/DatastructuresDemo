# include "LinkedListSort.h"

LinkedListSort::LinkedListSort(){

}

LinkedListSort::~LinkedListSort(){

}

LinkedListNode * LinkedListSort::partition(LinkedListNode * Head,LinkedListNode* Tail, LinkedListNode **newHead, LinkedListNode **newTail){
	LinkedListNode * pivot = Tail;
	LinkedListNode * Curr = Head;
	LinkedListNode * Last = pivot;

	LinkedListNode * Prev = NULL;

	while (Curr != pivot){
		if (Curr->key < pivot->key){
			if (*newHead == NULL)
				(*newHead) = Curr;
			Prev = Curr;
			Curr = Curr->next;
		}
		else{
			if (Prev)
				Prev->next = Curr->next;
			LinkedListNode *  Temp = Curr->next;
			Curr->next = NULL;
			Last->next = Curr;
			Last = Curr;
			Curr = Temp;
		}
	}

	if ((*newHead) == NULL)
		(*newHead) = pivot;

	(*newTail) = Last;
	
	return pivot;
}
LinkedListNode * LinkedListSort::_Sort(LinkedListNode * Head, LinkedListNode * Tail){

	if (Head == NULL || Head == Tail){
		return Head;
	}

	LinkedListNode * newHead = NULL;
	LinkedListNode * newTail = NULL;
	LinkedListNode * pivot;

	pivot = partition(Head, Tail, &newHead, &newTail);


	if (newHead != pivot){
		LinkedListNode * Temp = newHead;
		while (Temp->next != pivot){
			Temp = Temp->next;
		}
		Temp->next = NULL;


		newHead = _Sort(newHead, Temp);

		LinkedListNode * Tail = newHead;
		while (Tail != NULL && Tail->next!=NULL){
			Tail = Tail->next;
		}
		Temp = Tail;
		Temp->next = pivot;
	}

	pivot->next = _Sort(pivot->next, newTail);

	return newHead;
}

void LinkedListSort::QuickSort(LinkedListNode ** Head){

	LinkedListNode * Tail = *Head;
	while (Tail != NULL&& Tail->next!=NULL){
		Tail = Tail->next;
	}
	(*Head) = _Sort(*Head, Tail);
}
LinkedListNode * LinkedListSort::sort(LinkedListNode * list){
	LinkedListNode * Head = list;

	QuickSort(&Head);
	return Head;
	
}