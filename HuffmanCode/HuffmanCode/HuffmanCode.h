#pragma once
#include <string>

class Node
{
	char m_key;
	int m_frequency;
	Node *m_leftChild;
	Node *m_rightChild;

	Node()
	{
		
	}

	Node(const char key, const int frequency)
	{
		m_frequency = frequency;
		m_key = key;
		m_leftChild = nullptr;
		m_rightChild = nullptr;
	}
};

class HuffmanCode
{
private:
	Node *m_root;
	std::string encode;
	std::string decode;

public:
	HuffmanCode();

	HuffmanCode();

	void build(std::string &string);

	int encode(std::string &string, std::string &stringCoded);

	bool decode(std::string &string, std::string &stringDecoded);
};

