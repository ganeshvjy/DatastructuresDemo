#include "Interfaces03.h"

class VectorDoubleSort : public IVectorDoubleSort{
public:
	VectorDoubleSort();
	~VectorDoubleSort();
	void sort(std::vector<double>& vec);
	void quickSort(std::vector<double> &Vector, int left, int right);
	void exchange(std::vector<double> &Vector, int index1, int index2);
};