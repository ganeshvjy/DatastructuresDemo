#pragma once
#include "Interfaces02.h"

class KeyValue:public IKeyValue{
private:
	int Key;
	std::string Value;
public:
	KeyValue();
	~KeyValue();
	void setKey(int key);
	void setValue(std::string value);
	int getKey();
	std::string getValue();
};