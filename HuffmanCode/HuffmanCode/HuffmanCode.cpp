#include "HuffmanCode.h"
#include <algorithm>
#include <vector>
#include <queue>

HuffmanCode::HuffmanCode()
{
	m_root = new Node(3, 4);
}

HuffmanCode::~HuffmanCode()
{

}

Node *HuffmanCode::getRoot()
{
	return m_root;
}

std::map<char, int> HuffmanCode::createMap(std::string &string)
{
	std::map<char, int> numberTable;
	for (char symbol : string)
	{
		numberTable[symbol]++;
	}

	std::map<char, int> ::iterator it = numberTable.begin();
	for (; it != numberTable.end(); it++)
	{
		std::cout << it->first << " " << it->second << std::endl;
	}

	return numberTable;
}

void HuffmanCode::encodePriority(Node *root, std::string string,
	std::map<char, std::string> &codeTable)
{
	if(root)
	{
		if (!root->m_leftChild && !root->m_rightChild)
		{
			codeTable[root->m_key] = string;
		}

		encodePriority(root->m_leftChild, string + "0", codeTable);
		encodePriority(root->m_rightChild, string + "1", codeTable);
	}
}

int HuffmanCode::encode(Node *root, std::string string)
{
	if (root == nullptr)
	{
		return -1;
	}

	std::map<char, int> numberTable = createMap(string);

	std::vector<Node*> vectorNode;
	for (auto leaf : numberTable)
	{
		Node *tmp = new Node(leaf.first, leaf.second);
		vectorNode.push_back(tmp);
	} 

	std::sort(vectorNode.begin(), vectorNode.end(), [](Node *a, Node *b)->bool
	{
		return a->m_frequency < b->m_frequency;
	}
	);

	for (unsigned int i = 0; i < vectorNode.size(); i++)
	{
		std::cout << vectorNode[i]->m_frequency << " " << vectorNode[i]->m_key << std::endl;
	}



	//while (numberTable.size() != 1)
	//{


	//}
}