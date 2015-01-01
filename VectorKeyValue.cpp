#include "VectorKeyValue.h"

VectorKeyValue::VectorKeyValue(){
	Vsize = 0;
	capacity = 1000;
	start = new IKeyValue *[capacity];
}

VectorKeyValue::~VectorKeyValue(){
	delete[] start;
}

void VectorKeyValue::push_back(IKeyValue * item){
	if (Vsize == capacity){
		int limit = capacity;
		capacity *= 2;
		IKeyValue ** temp = new IKeyValue *[capacity];
		for (int i = 0; i < limit; i++){
			temp[i] = start[i];
		}
		delete[] start;
		start = temp;
	}
	start[Vsize] = item;
	Vsize++;
	
}

void VectorKeyValue::pop_back(){
	Vsize--;
}

IKeyValue * VectorKeyValue::get(int index){
	if (index < Vsize){
		return start[index];
	}
	return 0;
	
}

void VectorKeyValue::set(int index, IKeyValue * item){
		start[index] = item;
}

size_t VectorKeyValue::size(){
	return Vsize;
}