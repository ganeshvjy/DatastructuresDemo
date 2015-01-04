#include "KthMin.h"

KthMin::KthMin(){

}

KthMin::~KthMin(){

}

void KthMin::exchange(IDoubleNode03 * First, IDoubleNode03 * Second){

	IDoubleNode03 * temp;

	if (First != Second){
		temp = First;
		First->setNext(Second->getNext());
		First->setPrev(Second->getPrev());

		Second->setNext(temp->getNext());
		Second->setPrev(temp->getPrev());
	}

}

int KthMin::findKthMin(IDoubleList03 * Head,int k){
	int minPos = 0;
	int minVal = 0;

	IDoubleNode03 * First ;
	IDoubleNode03 * Second;
	IDoubleNode03 * temp = new DoubleNode03();

	for (First = Head->getHead(); minPos <= k; First = First->getNext()){
		temp = First;
		minVal = First->getValue();
		for (Second = First->getNext(); Second != NULL&& Second->getNext() != NULL; Second = Second->getNext()){
			int curVal = Second->getValue();
			if (curVal < minVal){
				temp = Second;
				minVal = curVal;
			}
		}
		exchange(First, temp);
		minPos++;
	}


	return temp->getValue();
}