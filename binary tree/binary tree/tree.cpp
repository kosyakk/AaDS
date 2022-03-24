#include <iostream>
#include "BinaryTree.h"

int main()
{
	BinaryTree bt;

	for (int i = 0; i < 10; i++)
		bt.addNode(bt.getRoot(), i);
	bt.printHorizontal();
	std::cout << std::endl << std::endl << std::endl;

	/*for (int i = 0; i < 10; i++) {
		bt.printLevel(i);
		std::cout << std::endl;
	}*/

	return 0;
}