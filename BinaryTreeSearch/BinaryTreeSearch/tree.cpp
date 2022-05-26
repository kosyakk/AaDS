#include <iostream>
#include "BinaryTree.h"

int main()
{
	BinaryTree bt;

	for (int i = 0; i < 10; i++)
		bt.addNode(bt.getRoot(), i);
	bt.printHorizontal();
	std::cout << std::endl << std::endl << std::endl;

	bt.deleteKnot(bt.getRoot(), 6);
	bt.printHorizontal();
	std::cout << bt.getNumber(bt.getRoot());
	

	return 0;
}