#include "RunningMedian.h"


RunningMedian::RunningMedian(){

}

RunningMedian::~RunningMedian(){

}
int RunningMedian::Median(std::vector<int> Temp){
	int average;
	int Size = Temp.size() - 1;
	int middle = (0 + Size) / 2;
	if (Size % 2){
		average = (Temp[middle] + Temp[middle + 1]) / 2;
	}
	else{
		average = Temp[middle];
	}
	return average;
}
void RunningMedian::sort(std::vector<int> & Vector){
	for (int i = 1; i < Vector.size(); i++){
		int key = Vector[i];
		int j = i-1;
		while ((j >= 0) && Vector[j] > key){
			Vector[j + 1] = Vector[j];
			--j;
		}
		Vector[j + 1] = key;
	}
}

std::vector<int> RunningMedian::compute(std::vector<int> vec, int window_size){
	std::vector<int> MedianVector;
	std::vector<int> Temp;
	int average = 0;
	int pointer = 0;
	for (int i = 0; i < vec.size(); i++){
		if (i == 0){
			Temp.push_back(vec[i]);
			MedianVector.push_back(vec[i]);
		}
		else if (i == 1){
			Temp.push_back(vec[i]);
			if (Temp[0]> Temp[1]){
				int temp = Temp[1]; Temp[1] = Temp[0]; Temp[0] = temp;
			}
			average = Median(Temp);
			MedianVector.push_back(average);
		}
		else{
			if (Temp.size() < window_size){
				Temp.push_back(vec[i]);
			}
			else{
				int deleteVal = vec[pointer++];
				std::vector<int>::iterator iter = Temp.begin();
				size_t index;
				for (int h = 0; h < Temp.size(); h++){
					if (Temp[h] ==deleteVal ) { index = h; break; }
				}
				std::distance(Temp.begin(), iter);
				Temp.erase(iter + index);
				Temp.push_back(vec[i]);
			}
			sort(Temp);
			average = Median(Temp);
			MedianVector.push_back(average);
		}
	}
	return MedianVector;
}
