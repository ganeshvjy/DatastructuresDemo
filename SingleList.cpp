#include "SingleNode.h"
#include "SingleList.h"

SingleList::SingleList(){
	Head = NULL;
}

SingleList::~SingleList(){

}

ISingleNode * SingleList::getHead(){
	return Head;
}
void SingleList::setHead(ISingleNode * head){
	Head = head;
}
void SingleList::addHead(int value){
	ISingleNode * newnode = new SingleNode();
	newnode->setValue(value);
	if (Head == NULL){
		setHead(newnode);
	}
	else{
		newnode->setNext(Head);
		setHead(newnode);
	}	
}
void SingleList::orderSort2(){
	
	ISingleNode * cur = getHead();
	// Change the Head to the Node next to the head
	if (cur != NULL){
		if (cur->getNext() != NULL){
			setHead(cur->getNext());
		}
		while (cur->getNext() != NULL){
			ISingleNode* next = cur->getNext();
			ISingleNode* odd = next->getNext();
			next->setNext(cur);
			if (odd != NULL){
				ISingleNode* even = odd->getNext();
				cur->setNext(even);
			}
			else{
				cur->setNext(odd);
			}
			if (odd != NULL)cur = odd;
		}
	}
}

void SingleList::orderSort3(){
	ISingleNode * next = getHead();

	if (next != NULL){
		if (next->getNext() != NULL && next->getNext()->getNext() != NULL){
			setHead(next->getNext()->getNext());
		}
	}
	
	while (next!= NULL){
		ISingleNode * curr = next->getNext();
		ISingleNode * prev = curr->getNext();
		ISingleNode * temp = prev->getNext();
		prev->setNext(curr);
		curr->setNext(next);
		if (temp == NULL || temp->getNext() == NULL || temp->getNext()->getNext() == NULL){
			if (temp == NULL){
				next->setNext(NULL);
			}
			else if(temp->getNext() == NULL){
				next->setNext(temp);
			}
			else{
				next->setNext(temp->getNext());
				next->getNext()->setNext(temp);
				temp->setNext(NULL);
			}
			break;
		}
		else{
			next->setNext(temp->getNext()->getNext());
		}
		next = temp;
//		curr = next->getNext();
//		prev = curr->getNext();
	}
}
void SingleList::sequenceOrderSort(){

}
void SingleList::reverse(){
	ISingleNode * curr = getHead();
	ISingleNode * prev = NULL;
	ISingleNode * next = NULL;

	while (curr != NULL){
		next = curr->getNext();
		curr->setNext(prev);
		prev = curr;
		curr = next;
	}
	setHead(prev);
}

