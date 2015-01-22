#include "RTree.h"
#include "MyPoint.h"

RTree::RTree(){

}
RTree::~RTree(){

}

void quickSort(std::vector<IPoint *>& Vector, int front, int back){
	int start = front;
	int end = back;
	int pivot = Vector[(front + back) / 2]->getDistance();
	while (start <= end){
		while (Vector[start]->getDistance() < pivot){ start++; }
		while (Vector[end]->getDistance() > pivot){ end--; }
		if (start <= end){
			IPoint * temp = Vector[start];
			Vector[start] = Vector[end];
			Vector[end] = temp; start++; end--;
		}
	}
	if (front < end)
		quickSort(Vector, front, end);

	if (start < back)
		quickSort(Vector, start, back);

}

void RTree::hilbertSort(std::vector<IPoint *>& points){

	int maxX = 0;
	int maxY = 0;
	int maxXY = 0;
	for (int i = 0; i < points.size(); i++){
		int X = points[i]->getX();
		int Y = points[i]->getY();
		if (X > maxX){
			maxX = X;
		}
		if (Y > maxY){
			maxY = Y;
		}
	}

	maxXY = (maxX > maxY) ? maxX : maxY;

	int power = 2;
	for (;;){
		if (power >= maxXY){ break; }
		else{ power *= 2; }
	}

	maxXY = power;

	for (int j = 0; j < points.size(); j++){
		int xNew = points[j]->getX();
		int yNew = points[j]->getY();

		int w = maxXY / 2;
		int distance = 0;

		while (w != 0){

			int Quadrant = -1;
			if ((xNew >= 0 && xNew < w) && (yNew >= 0 && yNew < w)){ Quadrant = 0; }
			if ((xNew >= 0 && xNew < w) && (yNew >= w && yNew <= maxXY)){ Quadrant = 1; }
			if ((xNew >= w && xNew <= maxXY) && (yNew >= w && yNew <= maxXY)){ Quadrant = 2; }
			if ((xNew >= w && xNew <= maxXY) && (yNew >= 0 && yNew < w)){ Quadrant = 3; }

			int temp = 0;
			distance += (Quadrant * w * w);
			switch (Quadrant){
			case 0:
				temp = xNew; xNew = yNew; yNew = temp;
				break;
			case 1:
				yNew = yNew - w;
				break;
			case 2:
				xNew = xNew - w;
				yNew = yNew - w;
				break;
			case 3:
				temp = xNew;
				xNew = w - yNew - 1;
				yNew = w * 2 - temp - 1;
				break;
			}
			w = w / 2;
		}
		points[j]->setDistance(distance);
	}

	quickSort(points, 0, points.size() - 1);


}

void RTree::bulkInsert(std::vector<IPoint *>& points){
	for (int i = 0; i < points.size(); i++){
		Points.push_back(points[i]);
	}
}

std::vector<IPoint *> RTree::findWithin(IPoint * top_left, IPoint * bottom_right){
	std::vector<IPoint *> foundPoints;
	std::vector<IPoint *> input;

	for (int i = 0; i < Points.size(); i++){
		if ((bottom_right->getX() >= Points[i]->getX() && top_left->getX() <= Points[i]->getX())
			&& (bottom_right->getY() >= Points[i]->getY() && top_left->getY() <= Points[i]->getY()))
			foundPoints.push_back(Points[i]);
	}
	return foundPoints;
}