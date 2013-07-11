/*
 * BinarySearchTree.h
 *
 *  Created on: Jul 11, 2013
 *      Author: RAGHUTEJA
 */

#ifndef BINARYSEARCHTREE_H_
#define BINARYSEARCHTREE_H_

#include <iostream>
#include <cstdlib>
#include <queue>
#include "BinarySearchTreeNode.h"
using namespace std;

class BinarySearchTree {
	private:
		BinarySearchTreenodePtr root;
		int count;

		BinarySearchTreenodePtr insert(int, BinarySearchTreenodePtr);
		BinarySearchTreenodePtr remove(int, BinarySearchTreenodePtr);
		bool contains(int, BinarySearchTreenodePtr);
		BinarySearchTreenodePtr search(int, BinarySearchTreenodePtr);
		void makeEmpty(BinarySearchTreenodePtr);
		int findMin(BinarySearchTreenodePtr);
		void preOrder(BinarySearchTreenodePtr);
		void inOrder(BinarySearchTreenodePtr);
		void postOrder(BinarySearchTreenodePtr);

	public:
		BinarySearchTree();
		virtual ~BinarySearchTree();
		BinarySearchTreenodePtr getRoot();
		void setRoot(BinarySearchTreenodePtr);
		int getCount();

		// Basic operations
		void insert(int);
		void remove(int);
		bool contains(int);
		BinarySearchTreenodePtr search(int);

		// Traversals
		void preOrder();
		void inOrder();
		void postOrder();
		void levelOrder();
};

#endif /* BINARYSEARCHTREE_H_ */
