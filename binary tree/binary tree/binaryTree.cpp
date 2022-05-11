#include <random>
#include <iostream>
#include <vector>

#include "BinaryTree.h"

BinaryTree::BinaryTree()
{
	m_root = new Node();
	m_size = 1;
}

BinaryTree::BinaryTree(int key)
{
	m_root = new Node(key);
	m_size = 1;
}

void BinaryTree::deleteTree(Node *tree)
{
	if (tree)
	{
		deleteTree(tree->leftChild);
		deleteTree(tree->rightChild);
		delete tree;
	}
	m_size = 0;
}

bool BinaryTree::isEmpty(Node *tree)
{
	if (tree == nullptr)
	{
		return true;
	}
	return false;
}

BinaryTree::~BinaryTree()
{
	deleteTree(m_root);
}

Node *BinaryTree::getRoot()
{
	return m_root;
}

int BinaryTree::getHighTree(Node *tree, int high)
{
	if (tree)
	{
		high = getHighTree(tree->leftChild, high + 1);
	}

	return high;
}

int BinaryTree::getNumber(Node *tree)
{
	return m_size;
}

Node *BinaryTree::addNode(Node *subTreeRoot, const int key)
{
	if (subTreeRoot == nullptr) {
		if (m_root == nullptr) {
			m_root = new Node(key);
			m_size = 1;
			return m_root;
		}
		else {
			return nullptr;
		}
	}

	if (subTreeRoot->leftChild == nullptr) {
		subTreeRoot->leftChild = new Node(key);
		m_size++;
		return subTreeRoot->leftChild;
	}
	else if (subTreeRoot->rightChild == nullptr) {
		subTreeRoot->rightChild = new Node(key);
		m_size++;
		return subTreeRoot->rightChild;
	}
	else {
		if (rand() % 2) {
			return addNode(subTreeRoot->leftChild, key);
		}
		else {
			return addNode(subTreeRoot->rightChild, key);
		}
	}
}

void BinaryTree::printHorizontal()
{
	printHorizontal(m_root);
}

void BinaryTree::printHorizontal(Node *subTreeRoot, const int level)
{
	using std::cout;
	using std::endl;

	if (subTreeRoot == nullptr) {
		if (subTreeRoot == m_root) {
			cout << "Tree is empty" << endl;
		}
		return;
	}

	printHorizontal(subTreeRoot->rightChild, level + 1);

	for (int i = 0; i < level; i++)
		cout << "   ";
	cout << subTreeRoot->key << endl;

	printHorizontal(subTreeRoot->leftChild, level + 1);
}

void BinaryTree::printLevel(const int level)
{
	printLevel(m_root, level, 0);
}

void BinaryTree::printLevel(Node * subTreeRoot, const int level, const int currentLevel)
{
	using std::cout;
	using std::endl;

	if (subTreeRoot == nullptr) {
		if (subTreeRoot == m_root) {
			cout << "Tree is empty" << endl;
		}
		return;
	}

	if (currentLevel == level) {
		cout << subTreeRoot->key << "   ";
	}
	else if (currentLevel < level) {
		printLevel(subTreeRoot->leftChild, level, currentLevel + 1);
		printLevel(subTreeRoot->rightChild, level, currentLevel + 1);
	}
}

bool BinaryTree::deleteKnot(Node *tree, const int key)
{
	if (tree->rightChild == nullptr)
	{
		if (tree->leftChild == nullptr)
		{
			delete tree;
		}
		deleteTree(tree);
	}

	return true;
}

void BinaryTree::getKeys(Node *tree, std::vector<int> &vector)
{
	if (tree == nullptr)
	{
		return;
	}

	getKeys(tree->leftChild, vector);
	getKeys(tree->rightChild, vector);

	vector.push_back(tree->key);
}

std::vector<int> BinaryTree::getVectorKeys(Node *tree)
{
	std::vector<int> vector;

	getKeys(tree, vector);

	return vector;
}