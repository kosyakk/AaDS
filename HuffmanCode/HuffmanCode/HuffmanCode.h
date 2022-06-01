#pragma once
#include <iostream>
#include <string>
#include <map>

class HuffmanCode;
class Node
{
private:
	char m_key;
	int m_frequency;
	Node *m_leftChild;
	Node *m_rightChild;

public:
	Node(const char key, const int frequency, Node *leftChild = nullptr,
	Node *rightChild = nullptr)
	{
		m_frequency = frequency;
		m_key = key;
		m_leftChild = leftChild;
		m_rightChild = rightChild;
	}

	Node(Node *node)
	{
		delete this;

		m_frequency = node->m_frequency;
		m_key = node->m_key;
		m_leftChild = node->m_leftChild;
		m_rightChild = node->m_rightChild;
	}

	friend HuffmanCode;
};

class HuffmanCode
{
private:
	Node *m_root;
	std::map<char, std::string> m_codeTable;

public:
	HuffmanCode();

	~HuffmanCode();

	Node *getRoot();

	void build(Node *root, std::string &string);
	int encode(Node *root, std::string string,
		std::map<char, std::string> &codeTable);
	std::map<char, int> createMap(std::string &string);

	bool decode(Node *root, std::string &stringEncode, std::string &string);
	char decodeRek(Node* root, int &index, std::string &string);
};
