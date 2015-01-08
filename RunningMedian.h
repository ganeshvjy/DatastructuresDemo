#include "Interfaces03.h"

class RunningMedian :public IRunningMedian{
public:
	RunningMedian();
	~RunningMedian();
	std::vector<int> compute(std::vector<int> vec, int window_size);
	void sort(std::vector<int> & Vector);
	int Median(std::vector<int> Temp);
};