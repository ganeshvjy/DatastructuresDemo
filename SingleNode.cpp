#include "SingleNode.h"

SingleNode::SingleNode(){
	Next = NULL;
}

SingleNode::~SingleNode(){

}

void SingleNode::setValue(int value){
	Data = value;
}
int SingleNode::getValue(){
	return Data;
}
ISingleNode * SingleNode::getNext(){
	return Next;
}
void SingleNode::setNext(ISingleNode * next){
	Next = next;
}
