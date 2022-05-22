#include "HuffmanCode.h"

int main()
{
	HuffmanCode huf;

	std::string string{ "Mama myla ramu" };

	huf.encode(huf.getRoot(), string);
}