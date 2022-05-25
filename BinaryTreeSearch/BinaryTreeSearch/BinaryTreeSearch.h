#pragma once
#include "binaryTree.h"

class BinaryTreeSearch : public BinaryTree
{
public:
	//конструкторы(по умолчанию, -копирования);
	BinaryTreeSearch();
	
	//деструктор;
	~BinaryTreeSearch();
	
	//поиск узла дерева по ключу;
	Node *getKnotByKey(Node *subTreeRoot, const int key);
	
	//получение минимального / максимального ключа дерева(имеет другой алгоритм);
	int getMaxKey(Node *subTreeRoot);
	int getMinKey(Node *subTreeRoot);

	//добавление узла в дерево(имеет другой алгоритм);
	Node *addNode(Node *subTreeRoot, const int key);
	
	//удаление узла из дерева по ключу(возвращает true, если узел был удалён) (имеет другой алгоритм);
	bool deleteKnot(Node *subTreeRoot, const int key);
	
	//-удаление узла из дерева по индексу(возвращает true, если узел был удалён) (имеет другой алгоритм);
	//-получение уровня вершины по ключу(возвращает индекс уровня или - 1, если вершина не найдена) (имеет другой алгоритм);
	//-оператор присваивания
	//-копирование поддерева узла(возвращает новый объект класса);
};

