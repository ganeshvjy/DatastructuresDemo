#include "MyPoint.h"

MyPoint::MyPoint(){
	Xval = 0;
	Yval = 0;
	distance = 0;
}

MyPoint::~MyPoint(){

}

int MyPoint::getX(){
	return Xval;
}

int MyPoint::getY(){
	return Yval;
}

int MyPoint::getDistance(){
	return distance;
}
void MyPoint::setDistance(int value){
	distance = value;
}
void MyPoint::setX(int value){
	Xval = value;
}

void MyPoint::setY(int value){
	Yval = value;
}