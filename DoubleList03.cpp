#include "DoubleNode03.h"
#include "DoubleList03.h"

DoubleList03::DoubleList03(){
	Head = NULL;
	Tail = NULL;
	Size = 0;
}

DoubleList03::~DoubleList03(){

}

IDoubleNode03 * DoubleList03::getHead(){
	return Head;
}

IDoubleNode03 * DoubleList03::getTail(){
	return Tail;
}

void DoubleList03::setHead(IDoubleNode03 * head){
	Head = head;
}

void DoubleList03::setTail(IDoubleNode03 * tail){
	Tail = tail;
}

void DoubleList03::addBack(int value){
	IDoubleNode03 * newNode = new DoubleNode03();

	newNode->setValue(value);

	if (Head == NULL){
		Head = newNode;
		Tail = newNode;
	}
	else
	{
		IDoubleNode03 * prev = NULL;
		IDoubleNode03 * curr = Head;
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
	//IDoubleNode03 * NewNode = new DoubleNode03();
	//NewNode->setValue(value);

	//if (Head == NULL && Tail == NULL){
	//	Head = NewNode;
	//	Tail = NewNode;
	//}
	//else{
	//	Tail->setNext(NewNode);
	//	Tail = NewNode;

	//}
	Size++;

}


int DoubleList03::size(){
	return Size;
}