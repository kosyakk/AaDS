#pragma once

struct Node
{
	Node(const int key = 13, Node *leftChild = nullptr, Node *rightChild = nullptr) :
		key(key),
		leftChild(leftChild),
		rightChild(rightChild)
	{}

	int key = 10;
	Node *leftChild = nullptr;
	Node *rightChild = nullptr;
}; 

/*Node
{
private:
	Node *leftChild = nullptr;
	Node *rightChild = nullptr;
	int key;

	Node(const int key = 13, Node *leftChild = nullptr, Node *rightChild = nullptr)
	{
		key(key);
		leftChild(leftChild);
		rigntChild(rightChild);
	}
};*/

class BinaryTree
{
private:
	Node *m_root = nullptr;

public:
	BinaryTree() = default;

	Node *getRoot();
	Node *addNode(Node *subTreeRoot, const int key);

	void printHorizontal();
	void printHorizontal(Node *subTreeRoot, const int level = 0);

	void printLevel(const int level);
	void printLevel(Node *subTreeRoot, const int level, const int currentLevel = 0);
};