#include "CircularList.h"
#include "SingleNode03.h"

CircularList::CircularList(){
	Tail = NULL;
	Size = 0;
}

CircularList::~CircularList(){

}

void CircularList::addHead(int number){
	ISingleNode03 * newNode = new SingleNode03();
	newNode->setValue(number);

	Size++;

	if (Tail == NULL){
		Tail = newNode;
		newNode->setNext(Tail);
		
	}
	else if(Tail==Tail->getNext()){
		newNode->setNext(Tail);
		Tail->setNext(newNode);
		Tail = newNode;
	}
	else{
		ISingleNode03 *  temp = Tail->getNext();
		Tail->setNext(newNode);
		newNode->setNext(temp);
		Tail = newNode;
	}

}

ISingleNode03 * CircularList::getTail(){
	return Tail;
}

void CircularList::setTail(ISingleNode03 * tail){
	Tail = tail;
}

int CircularList::size(){
	return Size;
}