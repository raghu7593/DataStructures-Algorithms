/*
 * BinarySearchTree.cpp
 *
 *  Created on: Jul 11, 2013
 *      Author: RAGHUTEJA
 */

#include "BinarySearchTree.h"

BinarySearchTree::BinarySearchTree() {
	root = NULL;
	count = 0;
}

BinarySearchTree::~BinarySearchTree() {
	makeEmpty(root);
	root = NULL;
	count = 0;
}

BinarySearchTreenodePtr BinarySearchTree::getRoot() {
	return root;
}

void BinarySearchTree::setRoot(BinarySearchTreenodePtr root) {
	this->root = root;
}

int BinarySearchTree::getCount() {
	return count;
}

void BinarySearchTree::insert(int x) {
	root = insert(x, root);
}

BinarySearchTreenodePtr BinarySearchTree::insert(int x, BinarySearchTreenodePtr t) {
	if(t == NULL) {
		t = new BinarySearchTreeNode(x,NULL,NULL,NULL);
		count++;
	}
	else if(x < t->value)
		t->leftChild = insert(x, t->leftChild);
	else if(x > t->value)
		t->rightChild = insert(x, t->rightChild);
	return t;
}

void BinarySearchTree::remove(int x) {
	root = remove(x, root);
}

BinarySearchTreenodePtr BinarySearchTree::remove(int x, BinarySearchTreenodePtr t) {
	if(t == NULL)
		t = NULL;
	else if(x < t->value)
		t->leftChild = remove(x, t->leftChild);
	else if(x > t->value)
		t->rightChild = remove(x, t->rightChild);
	else if((t->leftChild != NULL) && (t->rightChild != NULL)) {
		t->value = findMin(t->rightChild);
		t->rightChild = remove(t->value, t->rightChild);
	}
	else if(t->leftChild != NULL) {
		BinarySearchTreenodePtr old = t;
		t = t->leftChild;
		delete(old);
		count--;
	}
	else if(t->rightChild != NULL) {
		BinarySearchTreenodePtr old = t;
		t = t->rightChild;
		delete(old);
		count--;
	}
	else {
		delete(t);
		t = NULL;
		count--;
	}
	return t;
}

bool BinarySearchTree::contains(int x) {
	return contains(x, root);
}

bool BinarySearchTree::contains(int x, BinarySearchTreenodePtr t) {
	if(t == NULL)
		return false;
	else if(x < t->value)
		return contains(x,t->leftChild);
	else if(x > t->value)
		return contains(x,t->rightChild);
	else
		return true;
}

BinarySearchTreenodePtr BinarySearchTree::search(int x) {
	return search(x, root);
}

BinarySearchTreenodePtr BinarySearchTree::search(int x, BinarySearchTreenodePtr t) {
	if(t == NULL)
		return NULL;
	else if(x < t->value)
		return search(x,t->leftChild);
	else if(x > t->value)
		return search(x,t->rightChild);
	else
		return t;
}

int BinarySearchTree::findMin(BinarySearchTreenodePtr t) {
	if(t == NULL)
		return NULL;
	else if(t->leftChild == NULL)
		return t->value;
	else
		return findMin(t->leftChild);
}

void BinarySearchTree::makeEmpty(BinarySearchTreenodePtr t) {
	if(t == NULL)
		return;
	else {
		makeEmpty(t->leftChild);
		makeEmpty(t->rightChild);
		delete(t);
	}
	t = NULL;
}

void BinarySearchTree::preOrder() {
	preOrder(root);
	cout<<endl;
}

void BinarySearchTree::preOrder(BinarySearchTreenodePtr t) {
	if(t == NULL)
		return;
	else {
		cout<<t->value<<" ";
		preOrder(t->leftChild);
		preOrder(t->rightChild);
	}
}

void BinarySearchTree::inOrder() {
	inOrder(root);
	cout<<endl;
}

void BinarySearchTree::inOrder(BinarySearchTreenodePtr t) {
	if(t == NULL)
		return;
	else {
		inOrder(t->leftChild);
		cout<<t->value<<" ";
		inOrder(t->rightChild);
	}
}

void BinarySearchTree::postOrder() {
	postOrder(root);
	cout<<endl;
}

void BinarySearchTree::postOrder(BinarySearchTreenodePtr t) {
	if(t == NULL)
		return;
	else {
		postOrder(t->leftChild);
		postOrder(t->rightChild);
		cout << t->value << " ";
	}
}

void BinarySearchTree::levelOrder() {
	queue<BinarySearchTreenodePtr> q;
	q.push(root);

	while(!q.empty()) {
		BinarySearchTreenodePtr t = q.front();
		if(t != NULL) {
			cout<< t->value << " ";
			q.push(t->leftChild);
			q.push(t->rightChild);
		}
		q.pop();
	}
}
