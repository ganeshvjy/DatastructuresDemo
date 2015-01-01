#include "VectorString.h"


VectorString::VectorString(){
	VSsize = 0;
	VScapacity = 10;
	VSstart = new std::string[VScapacity];
}

VectorString::~VectorString(){
	delete[] VSstart;
}
void VectorString::push_back(std::string item){
	if (VSsize == VScapacity){
		int limit = VScapacity;
		VScapacity *= 2;
		std::string * temp = new std::string[VScapacity];
		for (int i = 0; i < limit; i++){
			temp[i] = VSstart[i];
		}
		delete[] VSstart;
		VSstart = temp;
	}
	VSstart[VSsize] = item;
	VSsize++;
}

void VectorString::pop_back(){
	VSsize--;
}

std::string VectorString::get(int index){
	if (index < VScapacity ){
		return VSstart[index];
	}
	return 0;
}

void VectorString::set(int index, std::string item){
	VSstart[index] = item;
}

size_t VectorString::size(){
	return VSsize;
}