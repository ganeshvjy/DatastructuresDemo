#include "DoubleNode03.h"

DoubleNode03::DoubleNode03(){
	Prev = NULL;
	Next = NULL;
}

DoubleNode03::~DoubleNode03(){

}

void DoubleNode03::setValue(int value){
	Data = value;
}

int DoubleNode03::getValue(){
	return Data;
}

IDoubleNode03 * DoubleNode03::getPrev(){
	return Prev;
}

IDoubleNode03 * DoubleNode03::getNext(){
	return Next;
}

void DoubleNode03::setPrev(IDoubleNode03 * prev){
	Prev = prev;
}

void DoubleNode03::setNext(IDoubleNode03 * next){
	Next = next;
}
