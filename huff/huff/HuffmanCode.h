#pragma once
#include <iostream>
#include <string>
#include <queue>
#include <unordered_map>

class HuffmanCode
{
public:
	struct Node
	{
		char key;
		int freq;
		Node* leftChild, * rightChild;
	};

	struct compareHuffmanNodes
	{
		bool operator()(Node* l, Node* r)
		{
			return l->freq > r->freq;
		}
	};

	static Node* getNode(char key, int freq, Node* left, Node* right)
	{
		Node* Hnode = new Node();

		Hnode->key = key;
		Hnode->freq = freq;
		Hnode->leftChild = left;
		Hnode->rightChild = right;

		return Hnode;
	};

	static void encode(Node* root, std::string str, std::unordered_map<char, std::string>& huffmanCode);
	static void decode(Node* root, int& index, std::string str);
	static void buildHuffmanTree(std::string text);
};
