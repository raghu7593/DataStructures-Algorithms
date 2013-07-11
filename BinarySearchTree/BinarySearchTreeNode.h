/*
 * Node.h
 *
 *  Created on: Jul 11, 2013
 *      Author: RAGHUTEJA
 */

#ifndef NODE_H_
#define NODE_H_

struct BinarySearchTreeNode {
	int value;
	BinarySearchTreeNode* parent;
	BinarySearchTreeNode* leftChild;
	BinarySearchTreeNode* rightChild;

	BinarySearchTreeNode(int x = 0, BinarySearchTreeNode* par = NULL, BinarySearchTreeNode* left = NULL, BinarySearchTreeNode* right = NULL) : value(x), parent(par), leftChild(left), rightChild(right) {}
};

typedef BinarySearchTreeNode* BinarySearchTreenodePtr;

#endif /* NODE_H_ */
