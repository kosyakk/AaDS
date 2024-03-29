#pragma once
#include <vector>

struct Node
{
	Node(const int key = 13, Node *leftChild = nullptr, Node *rightChild = nullptr) :
		key(key),
		leftChild(leftChild),
		rightChild(rightChild)
	{}

	int key;
	Node *leftChild = nullptr;
	Node *rightChild = nullptr;
}; 

class BinaryTree
{
protected:
	Node *m_root = nullptr;
	int m_size;

	bool deleteKnotWithParent(Node *tree, const int key, Node *parent);

public:
	//������������(�� ��������� � � �����������)
	BinaryTree();
	BinaryTree(int key);

	//����������
	~BinaryTree();

	//��������� ����� ������
	Node *getRoot();

	//���������� ���� � ������
	Node *addNode(Node *subTreeRoot, const int key);

	//������� ������(�������� ���� �����)
	void deleteTree(Node *tree);

	//isEmpty(���������� true, ���� ������ �����)
	bool isEmpty(Node *tree);

	//��������� ������ ������;
	int getHighTree(Node *tree);

	//��������� ���������� ����� ������
	int getNumber(Node *tree);

	//�������� ���� �� ������ �� �����(���������� true, ���� ���� ��� �����)
	bool deleteKnot(Node *tree, const int key);
	Node *getParentByKey(Node *tree, const int key);
	Node *getTreeByKey(Node *tree, const int key);

	//��������� �������(std::vector<int>), ����������� ��� ����� ������(����� ������ ����������� ����� ��������);
	std::vector<int> getVectorKeys(Node *tree);
	void getKeys(Node *tree, std::vector<int> &vector);

	//����� � ������� ������ �� �������(����� ���������������� ������ ����������� ������);
	void printHorizontal();
	void printHorizontal(const int high);

	//����� � ������� ������ ������("������" ���� ��� �� �������, �.�., ����� ����� ����� ������ ������ ��������� : 2 ^ (������ ������));
	void printLevel(const int level);
	void printLevel(Node *subTreeRoot, const int level, const int currentLevel = 0);
};