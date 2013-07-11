/*
 * BinarySearchTreeMain.cpp
 *
 *  Created on: Jul 12, 2013
 *      Author: RAGHUTEJA
 */

#include "BinarySearchTreeMain.h"

BinarySearchTreeMain::BinarySearchTreeMain() {
	BinarySearchTree* bst = new BinarySearchTree();

	bst->insert(3);
	bst->insert(2);
	bst->insert(1);
	bst->insert(4);
	bst->insert(5);
	bst->insert(6);
	bst->insert(7);
	bst->insert(16);
	bst->insert(15);
	bst->insert(14);
	bst->insert(13);
	bst->insert(12);
	bst->insert(11);
	bst->insert(10);
	bst->insert(8);
	bst->insert(9);
	bst->insert(3);

	bst->remove(3);
	bst->remove(16);
	bst->remove(8);
	bst->remove(9);
	bst->remove(0);

	bst->preOrder();
	bst->inOrder();
	bst->postOrder();
	bst->levelOrder();

}

BinarySearchTreeMain::~BinarySearchTreeMain() {

}
