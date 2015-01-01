#include "VectorString.h"
#include "KeyValue.h"
#include "VectorKeyValue.h"
#include"PriorityQueue3.h"

PriorityQueue3::PriorityQueue3(){
	Vector = new VectorKeyValue();
}

PriorityQueue3::~PriorityQueue3(){

}

void PriorityQueue3::enqueue(IKeyValue * key_value){
	Vector->push_back(key_value);
	fix_up(Vector,key_value);
}

void PriorityQueue3::fix_up(IVectorKeyValue * Val, IKeyValue * key_value){
	int child = Val->size()-1;
	int parent = (child - 1) / 2;
	while (child!=0  > 0 && (key_value->getKey() < Val->get(parent)->getKey())){
		Val->set(child, Val->get(parent));
		child = parent;
		parent = (child - 1) / 2;
	}
	Val->set(child, key_value);
}

void PriorityQueue3::merge(IPriorityQueue * input_queue){
	int QueueSize = input_queue->size();
	for (int i = 0; i < QueueSize; i++){
		IKeyValue * KeyVal = new KeyValue();
		KeyVal->setKey(input_queue->lowestKey());
		KeyVal->setValue(input_queue->lowestValues()->get(0));
		enqueue(KeyVal);
		input_queue->dequeue();
	}
}

IVectorKeyValue * PriorityQueue3::returnSorted(){
	return Vector;
}

int PriorityQueue3::lowestKey(){
	return Vector->get(0)->getKey();
}

IVectorString * PriorityQueue3::lowestValues(){
	IVectorString * temp = new VectorString();
	std::string StringValue = Vector->get(0)->getValue();
	temp->push_back(StringValue);
	return temp;
}

void PriorityQueue3::dequeue(){
	exchange(Vector, 0, Vector->size() - 1);
	Vector->pop_back();
	fix_down(Vector, 0 , Vector->size());
}

void PriorityQueue3::fix_down(IVectorKeyValue * Vector, int k, int size){
	int leftchild = (2 * k) + 1;
	int rightchild = (2 * k) + 2;

	while (leftchild < size){
		int j = leftchild;
		if (rightchild < size && (Vector->get(rightchild)->getKey() < Vector->get(leftchild)->getKey())){
			j = rightchild;
		}
		if (Vector->get(k)->getKey() > Vector->get(j)->getKey()){
			exchange(Vector, k, j);
		}
		k = j;
		leftchild = (2 * k) + 1;
		rightchild = (2 * k) + 2;
	}
}

void PriorityQueue3::exchange(IVectorKeyValue * Vector, int x, int y){
	IKeyValue * temp = new KeyValue();
	temp->setKey(Vector->get(x)->getKey());
	std::string StringVal = Vector->get(x)->getValue();
	temp->setValue(StringVal);
	Vector->set(x, Vector->get(y));
	Vector->set(y, temp);
}

size_t PriorityQueue3::size(){
	return Vector->size();
}

