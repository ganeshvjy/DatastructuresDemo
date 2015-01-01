#include "PriorityQueue1.h"
#include "VectorKeyValue.h"
#include "VectorString.h"

PriorityQueue1::PriorityQueue1() {
	front = NULL;
	back = NULL;
	Qsize = 0;
}

PriorityQueue1::~PriorityQueue1() {

}

void PriorityQueue1::enqueue(IKeyValue * key_value){
	
    DoubleNode * doubleNode = new DoubleNode();
	doubleNode->setValue(key_value);
	Qsize++;
    
    //Sorted Insert with duplicate keys
    if (front == NULL)
	{
		front = doubleNode;
		back = doubleNode;
	}
	else
	{
		IDoubleNode * temp = front;
		IDoubleNode * prev = NULL;
		bool duplicate = false;
		while (temp != NULL && temp->getValue()->getKey() <= doubleNode->getValue()->getKey()){
			if (duplicate== false && temp->getValue()->getKey() == doubleNode->getValue()->getKey())
			{
				duplicate = true;
				Qsize--;
			}
			prev = temp;
			temp = temp->getNext();
		}

		if (prev == NULL){
			doubleNode->setNext(temp);
			temp->setPrev(doubleNode);
			doubleNode->setPrev(NULL);
			front = doubleNode;
		}
		else if (temp == NULL){
			prev->setNext(doubleNode);
			doubleNode->setPrev(prev);
			doubleNode->setNext(NULL);
			back = doubleNode;
		}
		else
		{
			prev->setNext(doubleNode);
			doubleNode->setPrev(prev);
			doubleNode->setNext(temp);
			temp->setPrev(doubleNode);
		}
	}
}

void PriorityQueue1::merge(IPriorityQueue * input_queue){

}

IVectorKeyValue * PriorityQueue1::returnSorted(){
	IVectorKeyValue * Sorted = new VectorKeyValue();
	IDoubleNode * Current = front;
	while (Current != NULL){
		Sorted->push_back(Current->getValue());
		Current = Current->getNext();
	}
	    
    return Sorted;
}

int PriorityQueue1::lowestKey(){
	return front->getValue()->getKey();
}

IVectorString * PriorityQueue1::lowestValues(){
	IVectorString * temp = new VectorString();
	IDoubleNode * DoubleTemp = new DoubleNode();
	DoubleTemp = front;
	int LowVal = front->getValue()->getKey();
	while (DoubleTemp != NULL && LowVal == DoubleTemp->getValue()->getKey()){
		std::string StringValue = DoubleTemp->getValue()->getValue();
		temp->push_back(StringValue);
		DoubleTemp = DoubleTemp->getNext();
    }

	return temp;
}

void PriorityQueue1::dequeue(){
    IDoubleNode * temp;
	IDoubleNode * start = front;
	IDoubleNode * end = front->getNext();
	IDoubleNode * prev;

	while (end != NULL && start->getValue()->getKey() == end->getValue()->getKey()){
		prev = end;
		end = end->getNext();
	}
    
	if (end == NULL)
	{
        // Only one key to delete
		IDoubleNode * temp2 = front;
		temp = temp2;
		front = NULL;
		back = NULL;
		delete temp2;
		Qsize = 0;
		Lowest = NULL;
	}
	else
	{
		front = end;
		Lowest = end;
		Qsize--;
		/*else{
			while (end != NULL && start->getValue()->getKey() == end->getValue()->getKey()){
				prev = end;
                end = end->getNext();
			}
			if (end == NULL){
				temp = back;
				back = back->getPrev();
				back->setNext(NULL);
				delete temp;
			}
			else{
				temp = prev;
				prev->getPrev()->setNext(prev->getNext());
				prev->getNext()->setPrev(prev->getPrev());
				delete temp;
			}
		}*/
	}
}

size_t PriorityQueue1::size(){
	return Qsize;
}
