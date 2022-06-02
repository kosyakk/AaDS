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
	if (tree != nullptr)
	{
		deleteTree(tree->leftChild);
		deleteTree(tree->rightChild);
		m_size--;
		delete tree;
	}
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
	m_size = 0;
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
	for (int i = 0; i < this->getHighTree(this->getRoot()); i++)
	{
		printLevel(i);
		std::cout << std::endl;
	}
}

void BinaryTree::printLevel(const int level)
{
	printLevel(m_root, level);
}

void BinaryTree::printLevel(Node * subTreeRoot, const int level, const int currentLevel)
{
	if (subTreeRoot == nullptr) {
		if (subTreeRoot == m_root) {
			std::cout << "Tree is empty" << std::endl;
		}
		return;
	}

	if (currentLevel == level) {
		std::cout << subTreeRoot->key << "   ";
	}
	else if (currentLevel < level) {
		printLevel(subTreeRoot->leftChild, level, currentLevel + 1);
		printLevel(subTreeRoot->rightChild, level, currentLevel + 1);
	}
}

//Node *BinaryTree::getKnotTree(Node *tree, const int key)
//{
//	if (tree == nullptr)
//	{
//		return nullptr;
//	}
//
//	if (tree->leftChild != nullptr && tree->leftChild->key == key)
//	{
//		return tree->leftChild;
//	}
//	if (tree->rightChild != nullptr && tree->rightChild->key == key)
//	{
//		return tree->rightChild;
//	}
//
//	getKnotTree(tree->leftChild, key);
//	getKnotTree(tree->rightChild, key);
//}
//
//bool BinaryTree::deleteKnot(Node *tree, const int key)
//{
//	tree = getKnotTree(tree, key);
//
//	if (tree == nullptr)
//	{
//		return false;
//	}
//
//	if (tree->rightChild == nullptr)
//	{
//		if (tree->leftChild == nullptr)
//		{
//			delete tree;
//		}
//	}
//
//	return true;
//}

Node * BinaryTree::getTreeByKey(Node *tree, const int key)
{
	if (tree)
	{
		if (tree->leftChild && tree->leftChild->key == key)
		{
			return tree->leftChild;
		}
		if (tree->rightChild && tree->rightChild->key == key)
		{
			return tree->rightChild;
		}
	}

	return tree;
}

Node* BinaryTree::getParentByKey(Node *tree, int key)
{
	if (tree)
	{
		if (tree->leftChild || tree->rightChild)
		{
			if ((tree->leftChild && tree->leftChild->key == key) ||
				(tree->rightChild && tree->rightChild->key == key))
			{
				return tree;
			}

		getParentByKey(tree->leftChild, key);
		getParentByKey(tree->rightChild, key);
			
		}
	}

	return nullptr;
}

bool BinaryTree::deleteKnot(Node *tree, const int key)
{
	if (tree == nullptr)
	{
		return false;
	}


	Node* parent = getParentByKey(tree, key);
	//if (parent && parent->leftChild && parent->leftChild->key == key)
	//{
	//	tree = parent->leftChild;
	//}
	//if (parent && parent->rightChild && parent->rightChild->key == key)
	//{
	//	tree = parent->rightChild;
	//}

	if (tree->leftChild == nullptr && tree->rightChild == nullptr)
	{
		if (parent && parent->leftChild == tree)
		{
			parent->leftChild = nullptr;
		}

		if (parent && parent->rightChild == tree)
		{
			parent->rightChild = nullptr;
		}

		if (!parent)
		{
			m_root = nullptr;
		}

		delete tree;
		return true;
	}

	if (tree->leftChild == nullptr && tree->rightChild != nullptr)
	{
		if (parent && parent->leftChild == tree)
		{
			parent->leftChild = tree->rightChild;
		}

		if (parent && parent->rightChild == tree)
		{
			parent->rightChild = tree->rightChild;
		}

		if (!parent)
		{
			m_root = tree->leftChild;
		}

		delete tree;
		return true;
	}

	if (tree->leftChild != nullptr && tree->rightChild == nullptr)
	{
		if (parent && parent->leftChild == tree)
		{
			parent->leftChild = tree->leftChild;
		}

		if (parent && parent->rightChild == tree)
		{
			parent->rightChild = tree->leftChild;
		}

		if (!parent)
		{
			m_root = tree->leftChild;
		}

		delete tree;
		return true;
	}

	if (tree->leftChild && tree->rightChild)
	{
		if (parent)
		{
			if (parent->leftChild == tree)
			{
				Node* rightDescendant = tree->rightChild;
				Node* leftDescendant = tree->leftChild;
				delete tree;
				parent->leftChild = leftDescendant;
				Node* parentOfLeaf = leftDescendant;
				while (parentOfLeaf->leftChild != nullptr)
					parentOfLeaf = parentOfLeaf->leftChild;
				parentOfLeaf->leftChild = rightDescendant;
				return true;
			}
			else if (parent->rightChild == tree)
			{
				Node* rightDescendant = tree->rightChild;
				Node* leftDescendant = tree->leftChild;
				delete tree;
				parent->rightChild = leftDescendant;
				Node* parentOfLeaf = leftDescendant;
				while (parentOfLeaf->leftChild != nullptr)
					parentOfLeaf = parentOfLeaf->leftChild;
				parentOfLeaf->leftChild = rightDescendant;
				return true;
			}
		}
		else
		{
			Node* rightDescendant = tree->rightChild;
			Node* leftDescendant = tree->leftChild;
			delete tree;
			m_root = leftDescendant;
			Node* parentOfLeaf = m_root;
			while (parentOfLeaf->leftChild != nullptr)
				parentOfLeaf = parentOfLeaf->leftChild;
			parentOfLeaf->leftChild = rightDescendant;
			return true;
		}
	}
	return false;
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