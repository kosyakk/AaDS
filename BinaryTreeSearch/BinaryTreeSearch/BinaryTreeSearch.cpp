#include "BinaryTreeSearch.h"

BinaryTreeSearch::BinaryTreeSearch() : BinaryTree()
{
	
}

BinaryTreeSearch::~BinaryTreeSearch()
{

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

	return nullptr;
}


