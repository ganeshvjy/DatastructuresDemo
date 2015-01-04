#include "HeapSort.h"

HeapSort::HeapSort(){

}

HeapSort::~HeapSort(){

}
void HeapSort::exchange(std::vector<int> & Vector, int index1, int index2){
	int lhs = Vector[index1];
	int rhs = Vector[index2];
	Vector[index1] = rhs;
	Vector[index2] = lhs;
}

void HeapSort::fix_down(std::vector<int>& Vector ,int  k, int size){
	int leftchild = (2 * k) + 1;
	int rightchild = (2 * k) + 2;

	while (leftchild < size){
		int j = leftchild;
		if (rightchild < size && (Vector[rightchild] > Vector[leftchild])){
			j = rightchild;
		}
		if (Vector[k] < Vector[j]){
			exchange(Vector, k, j);
		}
		k = j;
		leftchild = (2 * k) + 1;
		rightchild = (2 * k) + 2;
	}
}
void HeapSort::sort(std::vector<int>& vector){
	int size = vector.size();

	for (int i = size-1; i >= 0; i--){
		fix_down(vector, i, size);
	}

	for (int i = size-1; i > 0; i--){
		exchange(vector, 0, i);
		fix_down(vector, 0, i);
	}

}