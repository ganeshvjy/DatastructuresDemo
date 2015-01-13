#include "Interfaces04.h"


class MyPoint:public IPoint{
public:
	MyPoint();
	~MyPoint();
	int getX();
	int getY();
	int getDistance();
	void setX(int value);
	void setY(int value);
	void setDistance(int value);
private:
	int Xval;
	int Yval;
	int distance;
};