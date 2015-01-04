#include "Interfaces03.h"
#include "DoubleNode03.h"

class KthMin :public IKthMin{
public:
	KthMin();
	~KthMin(); 

	int findKthMin(IDoubleList03 * data, int k);
	
	void exchange(IDoubleNode03 * First, IDoubleNode03 * Second);

private:
	IDoubleList03 * head;
};