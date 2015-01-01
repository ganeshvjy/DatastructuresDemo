#include "DoubleNode.h"
#include "DoubleList.h"


IDoubleNode * DoubleList::getHead(){
	return Head;
}
IDoubleNode * DoubleList::getTail(){
	return Tail;
}
void DoubleList::setHead(IDoubleNode * head){
	Head = head;
}
void DoubleList::setTail(IDoubleNode * tail){
	Tail = tail;
}
void DoubleList::addSorted(int value){
	IDoubleNode * newNode = new DoubleNode();

	newNode->setValue(value);

	if (Head == NULL){
		Head = newNode;
		Tail = newNode;
	}
	else
	{
		IDoubleNode * prev = NULL;
		IDoubleNode * curr = Head;
		while (curr != NULL && curr->getValue() <= value){
			prev = curr;
			curr = curr->getNext();
		}
		if (prev == NULL){
			newNode->setNext(curr);
			curr->setPrev(newNode);
			Head = newNode;
		}
		else if (curr == NULL){
			prev->setNext(newNode);
			newNode->setPrev(prev);
			newNode->setNext(NULL);
			Tail = newNode;
		}
		else
		{
			prev->setNext(newNode);
			newNode->setPrev(prev);
			newNode->setNext(curr);
			curr->setPrev(newNode);
		}
	}
}

void DoubleList::orderSort2(){
	IDoubleNode * curr = getHead();
	IDoubleNode * temp = NULL;
	IDoubleNode * prev = NULL;

	if (curr != NULL && curr->getNext() != NULL){
		Head = curr->getNext();
	}

	while (curr != NULL && curr->getNext() != NULL){
		temp = curr;
		curr = curr->getNext();
		temp->setNext(curr->getNext());
		temp->setPrev(curr);
		curr->setNext(temp);
		curr->setPrev(prev);

		if (curr != NULL && curr->getNext() != NULL)
		{
			temp->setNext(curr->getNext());
		}
		curr = temp->getNext();
		prev = temp;
	}
	
}

//void DoubleList::orderSort2(){
//	IDoubleNode * curr = Head;
//	IDoubleNode * temp = NULL;
//	IDoubleNode * prev = NULL;
//
//	if (curr != NULL && curr->getNext() != NULL){
//		Head = curr->getNext();
//	}
//
//	while (curr != NULL){
//		temp = curr;
//
//		curr = curr->getNext();
//
//		if (curr!=NULL && curr->getNext() != NULL){
//			if (curr->getNext()->getNext() != NULL){
//				temp->setNext(curr->getNext()->getNext());
//			}
//			else{
//				temp->setNext(curr->getNext());
//			}
//		}
//		else{
//			temp->setNext(curr);
//		}
//
//		temp->setPrev(curr);
//
//		curr->setNext(temp);
//		curr->setPrev(prev);
//
//		curr = temp->getNext();
//		prev = temp;
//
//		if (curr == NULL){
//			Tail = prev->getNext();
//		}
//	}
//}
void DoubleList::orderSort3(){
	IDoubleNode * next = getHead();
	IDoubleNode * curr = next->getNext();
	IDoubleNode * prev = curr->getNext();

	if (next != NULL){
		if (next->getNext() != NULL && next->getNext()->getNext() != NULL){
			setHead(next->getNext()->getNext());
		}
	}
	while (next != NULL){
		IDoubleNode * last = prev->getNext();
		IDoubleNode * temp = next;
		next = prev;
		prev = temp;
		next->setNext(last);

	}

}
void DoubleList::sequenceOrderSort(){

}
void DoubleList::reverse(){
	IDoubleNode * temp = NULL;
	IDoubleNode * curr = Head;

	
	//Swap the previous and next pointers of each node
	while (curr != NULL)
	{
		curr->setPrev(curr->getNext());
		curr->setNext(temp);
		temp = curr;
		curr = curr->getPrev();
	}

	//Swap the pointers of Head and Tail
	temp = Head;
	Head = Tail;
	Tail = temp;

}
