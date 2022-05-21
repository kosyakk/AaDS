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
	//конструкторы(по умолчанию и с параметрами)
	BinaryTree();
	BinaryTree(int key);

	//деструктор
	~BinaryTree();

	//получение корня дерева
	Node *getRoot();

	//добавление узла в дерево
	Node *addNode(Node *subTreeRoot, const int key);

	//очистка дерева(удаление всех узлов)
	void deleteTree(Node *tree);

	//isEmpty(возвращает true, если дерево пусто)
	bool isEmpty(Node *tree);

	//получение высоты дерева;
	int getHighTree(Node *tree, int high = 0);

	//получение количества узлов дерева
	int getNumber(Node *tree);

	//удаление узла из дерева по ключу(возвращает true, если узел был удалён)
	bool deleteKnot(Node *tree, const int key);
	Node *getKnotTree(Node *tree, const int key);

	//получение вектора(std::vector<int>), содержащего все ключи дерева(обход вершин производить любым способом);
	std::vector<int> getVectorKeys(Node *tree);
	void getKeys(Node *tree, std::vector<int> &vector);

	//вывод в консоль дерева по уровням(через последовательные вызовы предыдущего метода);
	void printHorizontal();

	//вывод в консоль уровня дерева("пустые" узлы так же вывести, т.о., общее число узлов уровня всегда постоянно : 2 ^ (индекс уровня));
	void printLevel(const int level);
	void printLevel(Node *subTreeRoot, const int level, const int currentLevel = 0);
};