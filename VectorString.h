#include "Interfaces02.h"

class VectorString:public IVectorString{
public:
	VectorString();
	~VectorString();
	void push_back(std::string item);
	void pop_back();
	std::string get(int index);
	void set(int index, std::string item);
	size_t size();
private:
	size_t VSsize;
	int VScapacity;
	std::string * VSstart;
};