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

	//std::map<char, int> ::iterator it = numberTable.begin();
	//for (; it != numberTable.end(); it++)
	//{
	//	std::cout << it->first << " " << it->second << std::endl;
	//}

	return numberTable;
}

int HuffmanCode::encode(Node *root, std::string string,
	std::map<char, std::string> &codeTable)
{
	if (root == nullptr)
	{
		return -1;
	}

	if (!root->m_leftChild && !root->m_rightChild)
	{
		codeTable[root->m_key] = string;
	}

	encode(root->m_leftChild, string + "0", codeTable);
	encode(root->m_rightChild, string + "1", codeTable);
}

void HuffmanCode::build(Node *root, std::string &string)
{
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

	while (vectorNode.size() != 1)
	{

		Node *left = vectorNode.front();
		vectorNode.erase(vectorNode.begin());
		Node *right = vectorNode.front();
		vectorNode.erase(vectorNode.begin());

		int frequency = left->m_frequency + right->m_frequency;
		Node *tmp = new Node('\0', frequency, left, right);
		vectorNode.push_back(tmp);

		std::sort(vectorNode.begin(), vectorNode.end(), [](Node *a, Node *b)->bool
		{
			return a->m_frequency < b->m_frequency;
		}
		);
	}

	Node *rootTree = vectorNode.front();

	std::map<char, std::string> huff;
	encode(rootTree, "", huff);

	std::cout << "Huffman Codes:" << std::endl;
	for (auto tmp : huff) {
		std::cout << tmp.first << " " << tmp.second << '\n';
	}

	std::string stringEncode = "";
	for (char key : string) {
		stringEncode += huff[key];
	}

	std::cout << "Encoded string:" << stringEncode << std::endl;

	std::string stringDecode;
	
	decode(rootTree, stringEncode, stringDecode);

	std::cout << "Decoded string:" << std::endl;
	std::cout << stringDecode;
}

bool HuffmanCode::decode(Node *root, std::string &stringEncode, std::string &string)
{
	if (!root)
	{
		return false;
	}

	int index = -1;
	while (index < (int)stringEncode.size() - 2) 
	{
		string += decodeRek(root, index, stringEncode);
	}

	return true;
}

char HuffmanCode::decodeRek(Node* root, int &index, std::string &string)
{
	if (!root->m_leftChild && !root->m_rightChild)
	{
		return root->m_key;
	}

	index++;

	if (string[index] == '0')
	{
		decodeRek(root->m_leftChild, index, string);
	}
	else
	{
		decodeRek(root->m_rightChild, index, string);
	}
		
}