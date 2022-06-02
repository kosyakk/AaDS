#include "HuffmanCode.h"

int main()
{
	HuffmanCode huf;

	std::string string{ "Aaafjdskljfofawj;oibnfda;o kdljfoijewo." };

	huf.build(huf.getRoot(), string);
}