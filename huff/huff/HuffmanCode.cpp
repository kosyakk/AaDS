#include "HuffmanCode.h"

void HuffmanCode::encode(Node* root, std::string str, std::unordered_map<char, std::string>& huffmanCode)
{
	if (root == nullptr)
		return;

	if (!root->leftChild && !root->rightChild) 
	{
		huffmanCode[root->key] = str;
	}

	encode(root->leftChild, str + "0", huffmanCode);
	encode(root->rightChild, str + "1", huffmanCode);
}

void HuffmanCode::decode(Node* root, int& index, std::string str)
{
	if (root == nullptr) 
	{
		return;
	}

	if (!root->leftChild && !root->rightChild)
	{
		std::cout << root->key;
		return;
	}

	index++;

	if (str[index] == '0')
	{
		decode(root->leftChild, index, str);
	}
	else
	{
		decode(root->rightChild, index, str);
	}
}


void HuffmanCode::buildHuffmanTree(std::string text)
{
	std::unordered_map<char, int> freq;

	for (char ch : text) 
	{ 
		freq[ch]++;
	}

	std::priority_queue<Node*, std::vector<Node*>, compareHuffmanNodes> pq;

	for (auto pair : freq) 
	{
		pq.push(getNode(pair.first, pair.second, nullptr, nullptr));
	}

	while (pq.size() != 1)
	{
		Node* left = pq.top(); pq.pop();
		Node* right = pq.top();	pq.pop();

		int sum = left->freq + right->freq;
		pq.push(getNode('\0', sum, left, right));
	}

	Node* root = pq.top();

	std::unordered_map<char, std::string> huffmanCode;
	if (!root->leftChild && !root->rightChild) 
	{
		encode(root, "0", huffmanCode);
	}
	else 
	{
		encode(root, "", huffmanCode);
	}

	std::cout << "Huffman Codes:\n";
	for (auto pair : huffmanCode) 
	{
		std::cout << pair.first << " " << pair.second << '\n';
	}

	std::cout << "Original string:\n" << text;

	std::string str = "";
	for (char ch : text) 
	{
		str += huffmanCode[ch];
	}

	std::cout << "Encoded string is :\n" << str << '\n';
	int index = -1;
	std::cout << "Decoded string is: \n";
	while (index < (int)str.size() - 1) 
	{
		decode(root, index, str);
		if (!root->leftChild && !root->rightChild)
		{
			index++;
		}
	}
}