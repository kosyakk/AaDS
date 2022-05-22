#pragma once

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

};

