#include "HuffmanCode.h"

int main()
{
	HuffmanCode huf;

	std::string string{ "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaffffffffffffffffffaaa" };

	huf.buildHuffmanTree(string);
}