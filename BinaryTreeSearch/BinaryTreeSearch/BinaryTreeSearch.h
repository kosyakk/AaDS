#pragma once
#include "binaryTree.h"

class BinaryTreeSearch : public BinaryTree
{
public:
	//������������(�� ���������, -�����������);
	BinaryTreeSearch();
	
	//����������;
	~BinaryTreeSearch();
	
	//����� ���� ������ �� �����;
	Node *getKnotByKey(Node *subTreeRoot, const int key);
	
	//��������� ������������ / ������������� ����� ������(����� ������ ��������);
	int getMaxKey(Node *subTreeRoot);
	int getMinKey(Node *subTreeRoot);

	//���������� ���� � ������(����� ������ ��������);
	Node *addNode(Node *subTreeRoot, const int key);
	
	//�������� ���� �� ������ �� �����(���������� true, ���� ���� ��� �����) (����� ������ ��������);
	bool deleteKnot(Node *subTreeRoot, const int key);
	
	//-�������� ���� �� ������ �� �������(���������� true, ���� ���� ��� �����) (����� ������ ��������);
	//-��������� ������ ������� �� �����(���������� ������ ������ ��� - 1, ���� ������� �� �������) (����� ������ ��������);
	//-�������� ������������
	//-����������� ��������� ����(���������� ����� ������ ������);
};

