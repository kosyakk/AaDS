#include "BinaryTreeSearch.h"

BinaryTreeSearch::BinaryTreeSearch() : BinaryTree()
{
	
}

BinaryTreeSearch::~BinaryTreeSearch()
{

}

Node * BinaryTreeSearch::getKnotByKey(Node * subTreeRoot, const int key)
{
	while (subTreeRoot && subTreeRoot->key != key)
	{
		if (key > subTreeRoot->key)
		{
			subTreeRoot = subTreeRoot->rightChild;
		}
		else if (key < subTreeRoot->key)
		{
			subTreeRoot = subTreeRoot->leftChild;
		}
		
		if (subTreeRoot->key == key)
		{
			return subTreeRoot;
		}
	}

	return nullptr;
}

int BinaryTreeSearch::getMaxKey(Node *subTreeRoot)
{
	int max;

	while (subTreeRoot->rightChild)
	{
		subTreeRoot = subTreeRoot->rightChild;
		max = subTreeRoot->key;
	}

	return max;
}

int BinaryTreeSearch::getMinKey(Node * subTreeRoot)
{
	int min;

	while (subTreeRoot->leftChild)
	{
		subTreeRoot = subTreeRoot->leftChild;
		min = subTreeRoot->key;
	}

	return min;
}

Node * BinaryTreeSearch::addNode(Node * subTreeRoot, const int key)
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

	if (subTreeRoot->rightChild == nullptr && key >= subTreeRoot->key)
	{
		subTreeRoot->rightChild = new Node(key);
		m_size++;
	}
	else if (subTreeRoot->leftChild == nullptr && key < subTreeRoot->key)
	{
		subTreeRoot->leftChild = new Node(key);
		m_size++;
	}
	else
	{
		if (key >= subTreeRoot->key)
		{
			addNode(subTreeRoot->rightChild, key);
		}
		else
		{
			addNode(subTreeRoot->leftChild, key);
		}
	}
}

bool BinaryTreeSearch::deleteKnot(Node *subTreeRoot, const int key)
{
	Node * parent = nullptr;

	while (subTreeRoot && subTreeRoot->key != key)
	{
		parent = subTreeRoot;

		if (key > subTreeRoot->key)
		{
			subTreeRoot = subTreeRoot->rightChild;
		}
		else if (key < subTreeRoot->key)
		{
			subTreeRoot = subTreeRoot->leftChild;
		}
	}

	if (subTreeRoot && subTreeRoot->leftChild == nullptr && subTreeRoot->rightChild == nullptr)
	{
		if (parent->leftChild == subTreeRoot)
		{
			parent->leftChild = nullptr;
		}
		else if (parent->rightChild == subTreeRoot)
		{
			parent->rightChild = nullptr;
		}

		delete subTreeRoot;
		m_size--;
		return true;
	}

	if (subTreeRoot && subTreeRoot->leftChild == nullptr && subTreeRoot->rightChild != nullptr)
	{
		if (parent->leftChild == subTreeRoot)
		{
			parent->leftChild = subTreeRoot->rightChild;
		}

		if (parent->rightChild == subTreeRoot)
		{
			parent->rightChild = subTreeRoot->rightChild;
		}

		delete subTreeRoot;
		m_size--;
		return true;
	}

	if (subTreeRoot && subTreeRoot->leftChild != nullptr && subTreeRoot->rightChild == nullptr)
	{
		if (parent->leftChild == subTreeRoot)
		{
			parent->leftChild = subTreeRoot->leftChild;
		}

		if (parent->rightChild == subTreeRoot)
		{
			parent->rightChild = subTreeRoot->leftChild;
		}

		delete subTreeRoot;
		m_size--;
		return true;
	}

	if (subTreeRoot && subTreeRoot->leftChild && subTreeRoot->rightChild)
	{
		if (parent)
		{
			if (parent->leftChild == subTreeRoot)
			{
				Node* rightDescendant = subTreeRoot->rightChild;
				Node* leftDescendant = subTreeRoot->leftChild;
				delete subTreeRoot;
				m_size--;

				parent->leftChild = leftDescendant;
				Node* parentOfLeaf = leftDescendant;
				while (parentOfLeaf->leftChild != nullptr)
					parentOfLeaf = parentOfLeaf->rightChild;
				parentOfLeaf->rightChild = rightDescendant;

				return true;
			}
			else if (parent->rightChild == subTreeRoot)
			{
				Node* rightDescendant = subTreeRoot->rightChild;
				Node* leftDescendant = subTreeRoot->leftChild;
				delete subTreeRoot;
				m_size--;

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
			Node* rightDescendant = subTreeRoot->rightChild;
			Node* leftDescendant = subTreeRoot->leftChild;
			delete subTreeRoot;
			m_size--;

			m_root = leftDescendant;
			Node* parentOfLeaf = m_root;
			while (parentOfLeaf->leftChild != nullptr)
				parentOfLeaf = parentOfLeaf->rightChild;
			parentOfLeaf->rightChild = rightDescendant;

			return true;
		}
	}

	return false;
}


