#include "VectorDoubleSort.h"
#include "vector.h" 

VectorDoubleSort::VectorDoubleSort(){

}

VectorDoubleSort::~VectorDoubleSort(){

}
void VectorDoubleSort::exchange(std::vector<double> &Vector, int index1, int index2){
	double lhs = Vector[index1];
	double rhs = Vector[index2];
	Vector[index1] = rhs;
	Vector[index2] = lhs;
}


void VectorDoubleSort::sort(std::vector<double>& vec){
	quickSort(vec, 0, vec.size() - 1);
}


void VectorDoubleSort::quickSort(std::vector<double>& vec, int left, int right){
	int front = left;
	int back = right;
	double temp;
	int mid = (left + right) / 2;
	double pivot = vec[mid];
	while (front <= back){
		while (vec[front] < pivot){ front++; }
		while (vec[back] > pivot){ back--; }
		if (front <= back){
			exchange(vec,front,back);
			front++;back--;
		}
	}
	if (left < back)
		quickSort(vec, left, back);
	if (front < right)
		quickSort(vec, front, right);
}


