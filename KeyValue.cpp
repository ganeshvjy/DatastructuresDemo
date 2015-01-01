#include "KeyValue.h"

KeyValue::KeyValue(){

}
KeyValue::~KeyValue(){

}
void KeyValue::setKey(int key){
	Key = key;
}
void KeyValue::setValue(std::string value){
	Value = value;
}
int KeyValue::getKey(){
	return Key;
}
std::string KeyValue::getValue(){
	return Value;
}

