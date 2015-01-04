#include "Interfaces03.h"

class HeapSort :public IHeapSort{

public:
	HeapSort();
	~HeapSort();
	void sort(std::vector<int>& vector);
	void fix_down(std::vector<int> & Vector, int  i, int size);
	void exchange(std::vector<int> & Vector, int index1, int index2);
};