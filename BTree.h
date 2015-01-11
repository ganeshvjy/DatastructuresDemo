#pragma once
#include "Interfaces04.h"
#include "vector.h"

class BTree:public IBTree{
public:BTree();
       ~BTree();
       void insert(int key, int num_keys);
       void remove(int key, int num_keys);
       int kthMin(int k);
       IBTreeNode * getRoot();

	   void insertKey(IBTreeNode* node,int key,int num_keys);
	   void splitNode(IBTreeNode* Parent,IBTreeNode* LeftNode,int pos);

	   void removeUtil(IBTreeNode* node, int key);
	   IBTreeNode* findKey(IBTreeNode* root, int key);
	   IBTreeNode * getPred(IBTreeNode* node,int pos);
	   

private:
	   IBTreeNode* Root;
};