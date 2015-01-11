#include "Interfaces04.h"

class AVLTree :public IAVLTree{
public:
	AVLTree();
	~AVLTree();
	void insert(int key);
	void remove(int key);
	int kthMin(int k);
	IAVLTreeNode * getRoot();

	int height(IAVLTreeNode * RootHeight);
	//int max(int val1, int val2);
	IAVLTreeNode * AddNode(IAVLTreeNode * TopNode, int Key);

	IAVLTreeNode* LeftRotate(IAVLTreeNode * LRotate);
	IAVLTreeNode* RightRotate(IAVLTreeNode * RRotate);
	IAVLTreeNode* LeftRotateTwice(IAVLTreeNode * LLRotate);
	IAVLTreeNode* RightRotateTwice(IAVLTreeNode * RRRotate);

	int KthMinimum(IAVLTreeNode * Node, int k);
	int NodeCount(IAVLTreeNode * Curr);

	IAVLTreeNode*  DeleteNode(IAVLTreeNode * Curr, int key);
	IAVLTreeNode * lowNode(IAVLTreeNode* Curr);


private:

	IAVLTreeNode * Root;
};