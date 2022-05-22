#include <iostream>
#include "BinaryTreeSearch.h"

int main()
{
	BinaryTreeSearch tree;

	tree.addNode(tree.getRoot(), 3);
	tree.addNode(tree.getRoot(), 5);

	tree.printHorizontal();
}
