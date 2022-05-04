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
private:
	Node *m_root = nullptr;
	int m_size;

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
	int getHighTree(Node *tree, int high = 0);

	//��������� ���������� ����� ������
	int getNumber(Node *tree, int number = 0);

	//�������� ���� �� ������ �� �����(���������� true, ���� ���� ��� �����)
	bool deleteKnot(Node *tree, int key);

	//��������� �������(std::vector<int>), ����������� ��� ����� ������(����� ������ ����������� ����� ��������);
	std::vector<int> getVectorKeys(Node *tree, int level = 0);

	//����� � ������� ������ �� �������(����� ���������������� ������ ����������� ������);
	void printHorizontal();
	void printHorizontal(Node *subTreeRoot, const int level = 0);

	//����� � ������� ������ ������("������" ���� ��� �� �������, �.�., ����� ����� ����� ������ ������ ��������� : 2 ^ (������ ������));
	void printLevel(const int level);
	void printLevel(Node *subTreeRoot, const int level, const int currentLevel = 0);
};