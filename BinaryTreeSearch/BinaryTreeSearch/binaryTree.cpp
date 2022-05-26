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
}

Node *BinaryTree::getRoot()
{
	return m_root;
}

int BinaryTree::getHighTree(Node *tree)
{
	int high = 0;
	if (tree)
	{
		int left, right;
		left = getHighTree(tree->leftChild);
		right = getHighTree(tree->rightChild);
		
		high = ((left > right) ? left : right) + 1;
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
	int high = this->getHighTree(this->getRoot());
	for (int i = 0; i < high; i++)
	{
		printLevel(i);
		std::cout << std::endl;
	}
}
void BinaryTree::printHorizontal(const int high)
{
	for (int i = 0; i < high; i++)
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
	if (subTreeRoot == nullptr)
	{
		if (subTreeRoot == m_root) 
		{
			std::cout << "Tree is empty" << std::endl;
			return;
		}
	}

	if (currentLevel == level && subTreeRoot) 
	{
			std::cout << subTreeRoot->key << "   ";
	}
	else if (subTreeRoot && currentLevel < level) 
	{
		printLevel(subTreeRoot->leftChild, level, currentLevel + 1);
		printLevel(subTreeRoot->rightChild, level, currentLevel + 1);
	}
}

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

			Node *parent = getParentByKey(tree->leftChild, key);

			if (parent == nullptr)
			{
				return getParentByKey(tree->rightChild, key);
			}
			else
			{
				return parent;
			}
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

	Node *parent = nullptr;
	if (tree->key != key)
	{
		parent = getParentByKey(tree, key);
		tree = getTreeByKey(parent, key);
	}

	if (tree && tree->leftChild == nullptr && tree->rightChild == nullptr)
	{
		if (parent->leftChild == tree)
		{
			parent->leftChild = nullptr;
		}

		if (parent->rightChild == tree)
		{
			parent->rightChild = nullptr;
		}

		m_size--;
		delete tree;
		return true;
	}

	if (tree && tree->leftChild == nullptr && tree->rightChild != nullptr)
	{
		if (parent->leftChild == tree)
		{
			parent->leftChild = tree->rightChild;
		}

		if (parent->rightChild == tree)
		{
			parent->rightChild = tree->rightChild;
		}

		m_size--;
		delete tree;
		return true;
	}

	if (tree && tree->leftChild != nullptr && tree->rightChild == nullptr)
	{
		if (parent->leftChild == tree)
		{
			parent->leftChild = tree->leftChild;
		}

		if (parent->rightChild == tree)
		{
			parent->rightChild = tree->leftChild;
		}

		m_size--;
		delete tree;
		return true;
	}

	if (tree && tree->leftChild && tree->rightChild)
	{
		if (parent)
		{
			if (parent->leftChild == tree)
			{
				Node* rightDescendant = tree->rightChild;
				Node* leftDescendant = tree->leftChild;
				m_size--;
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
				m_size--;
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
			m_size--;
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