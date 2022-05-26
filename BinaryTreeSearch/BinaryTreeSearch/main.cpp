#include <iostream>
#include "BinaryTreeSearch.h"

int main()
{
	BinaryTreeSearch tree;

	tree.addNode(tree.getRoot(), 3);
	tree.addNode(tree.getRoot(), 15);
	tree.addNode(tree.getRoot(), 6);
	tree.addNode(tree.getRoot(), 1);
	tree.addNode(tree.getRoot(), 5);
	tree.addNode(tree.getRoot(), 17);
	tree.addNode(tree.getRoot(), 14);
	tree.addNode(tree.getRoot(), 8);

	tree.printHorizontal();

	tree.deleteKnot(tree.getRoot(), 17);

	tree.printHorizontal(4);
}
