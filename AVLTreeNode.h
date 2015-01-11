#include "Interfaces04.h"


class AVLTreeNode:public IAVLTreeNode{
public:
	AVLTreeNode();
	~AVLTreeNode();
	void setLeft(IAVLTreeNode * left);
	void setRight(IAVLTreeNode * right);
	void setKey(int key);
	IAVLTreeNode * getLeft();
	IAVLTreeNode * getRight();
	int getKey();
	
private:
	int Key;
	IAVLTreeNode * LeftNode;
	IAVLTreeNode * RightNode;
};
