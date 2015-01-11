#pragma once
#include "Interfaces04.h"

class BTreeNode:public IBTreeNode{
public: BTreeNode(int num_keys,bool leaf);
       ~BTreeNode();
        int getKey(int index);  
        void setKey(int index, int key);
        int getKeySize();
        void setKeySize(int size);
        int getChildSize();
        void setChildSize(int size);
        IBTreeNode * getChild(int index);
        void setChild(int index, IBTreeNode * child);
        bool isLeaf();
		void incKeyInd();
		void incChildInd();
public:
		int *keys;
		int keySize;
		int keyCapacity;
	   
		IBTreeNode **Child;
		int childSize;
		int childCapacity;

		bool Leaf;   
};