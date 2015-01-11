#include "BTreeNode.h"
#include <iostream>
BTreeNode::BTreeNode(int size,bool leaf){
	keySize = 0;
	childSize = 0;
	Leaf = leaf;
	keyCapacity = size;
	childCapacity = size + 1;
	keys = new int[keyCapacity];
	Child = new IBTreeNode*[childCapacity];
	
}

BTreeNode::~BTreeNode(){

}

int BTreeNode::getKey(int index){
	if(index < keyCapacity){
		return keys[index];
	}
	else
		return 0;
}

void BTreeNode::setKey(int index, int key){
	keys[index] = key;
}

int BTreeNode::getKeySize(){
	return keySize;
}

void BTreeNode::setKeySize(int size){
	keySize=size;
}

int BTreeNode::getChildSize(){
	return childSize;
}

void BTreeNode::setChildSize(int size){
	childSize=size;
}

IBTreeNode * BTreeNode::getChild(int index){
	if(index < childCapacity){
		return Child[index];
	}
	else{
		return 0;
	}
}

void BTreeNode::setChild(int index, IBTreeNode * child){
	Child[index]=child;
}

 bool BTreeNode::isLeaf(){
	 return Leaf;
 }

 void BTreeNode::incKeyInd(){
	 keySize++;
 }

 void BTreeNode::incChildInd(){
	 childSize++;
 }