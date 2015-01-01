#include "DoubleNode.h"

void DoubleNode::setValue(int value){
	Data = value;
}
int DoubleNode::getValue(){
	return Data;
}
IDoubleNode * DoubleNode::getPrev(){
	return Prev;
}
IDoubleNode * DoubleNode::getNext(){
	return Next;
}
void DoubleNode::setPrev(IDoubleNode * prev){
	Prev = prev;
}
void DoubleNode::setNext(IDoubleNode * next){
	Next = next;
}
