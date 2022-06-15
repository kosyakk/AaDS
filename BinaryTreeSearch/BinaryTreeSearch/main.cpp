#include <iostream>
#include "BinaryTreeSearch.h"


bool test(const int treeSize = 50)
{
	BinaryTree bt;


	for (int i = 0; i < treeSize; i++) {
		bt.addNode(bt.getRoot(), i);
		std::cout << bt.getNumber(bt.getRoot()) << " " << bt.getHighTree(bt.getRoot()) << std::endl;
	}


	std::cout << "------------------------------------------" << std::endl;
	bt.printHorizontal();


	for (int i = 0; i < treeSize; i++) {
		bt.deleteKnot(bt.getRoot(), i);
		std::cout << bt.getNumber(bt.getRoot()) << " " << bt.getHighTree(bt.getRoot()) << std::endl;
	}


	std::cout << "------------------------------------------" << std::endl;

	bt.deleteKnot(bt.getRoot(), 13);

	bt.printHorizontal();


	std::cout << bt.deleteKnot(bt.getRoot(), 7) << std::endl;


	return true;
}




//int testSearchTree(BinaryTreeSearch &tree, const int size)
//{
//	if (tree.getNumber(tree.getRoot()) != size) {
//		return -1;
//	}
//
//
//	std::vector<int> nodesKeys = tree.getVectorKeys(tree.getRoot());
//
//
//	for (int i = size - 1; i >= 0; --i) {
//		BinaryTree subTree = tree.copySubTree(i);
//		int subTreeSize = subTree.numberOfNodes();
//		if (subTreeSize > 1) {
//			int rootKey = subTree.getKeyByIndex(0);
//			int rootLevel = subTree.getLevelByKey(rootKey);
//
//
//			int firstChildKey = subTree.getKeyByIndex(1);
//			int childsLevel = subTree.getLevelByKey(firstChildKey);
//
//
//			int secondChildKey = -1;
//			if (subTreeSize > 2) {
//				secondChildKey = subTree.getKeyByIndex(2);
//				if (subTree.getLevelByKey(secondChildKey) != childsLevel) {
//					secondChildKey = -1;
//				}
//			}
//
//
//			if (secondChildKey >= 0 && !(firstChildKey < rootKey && rootKey <= secondChildKey)) {
//				return -2;
//			}
//		}
//	}
//
//
//	return 0;
//}


bool testSearchTree(int size)
{
	int failedCase = 0;
	BinaryTreeSearch searchTree;
	std::vector<int> nodesKeys;


	for (int i = 0; i < size; ++i) {
		searchTree.addNode(searchTree.getRoot(), i);
		nodesKeys.push_back(i);
	}


	int index, key;

	searchTree.deleteKnot(searchTree.getRoot(), 13);

	while (nodesKeys.size()) {
	//	index = rand() % nodesKeys.size();
	//	nodesKeys.erase(nodesKeys.begin() + index);
	//	if (!searchTree.deleteKnot(searchTree.getRoot(), index)) {
	//		failedCase = 1;
	//		break;
	//	}


		/*if (testSearchTree(searchTree, nodesKeys.size())) {
			failedCase = 2;
			break;
		}*/


		if (nodesKeys.size()) {
			index = rand() % nodesKeys.size();
			key = nodesKeys[index];
			nodesKeys.erase(nodesKeys.begin() + index);
			if (!searchTree.deleteKnot(searchTree.getRoot(), key)) {
				failedCase = 3;
				break;
			}


			/*if (testSearchTree(searchTree, nodesKeys.size())) {
				failedCase = 4;
				break;
			}*/
		}
	}

	if (failedCase || !searchTree.isEmpty(searchTree.getRoot())) {
		if (!failedCase) {
			failedCase = -1;
		}


		std::cout << size << " " << searchTree.getNumber(searchTree.getRoot()) << std::endl;
		searchTree.printHorizontal();
		std::cout << std::endl;
		std::cout << std::endl;




	}
	return (failedCase == 0);
}

//
//int testSearchTreeAsBinaryTree(BinaryTree &tree, const int size)
//{
//	if (tree.getNumber(tree.getRoot()) != size) {
//		return -1;
//	}
//
//
//	std::vector<int> nodesKeys = tree.getVectorKeys(tree.getRoot());
//
//
//	for (int i = size - 1; i >= 0; --i) {
//		BinaryTree subTree = tree.copySubTree(i);
//		int subTreeSize = subTree.numberOfNodes();
//		if (subTreeSize > 1) {
//			int rootKey = subTree.getKeyByIndex(0);
//			int rootLevel = subTree.getLevelByKey(rootKey);
//
//
//			int firstChildKey = subTree.getKeyByIndex(1);
//			int childsLevel = subTree.getLevelByKey(firstChildKey);
//
//
//			int secondChildKey = -1;
//			if (subTreeSize > 2) {
//				secondChildKey = subTree.getKeyByIndex(2);
//				if (subTree.getLevelByKey(secondChildKey) != childsLevel) {
//					secondChildKey = -1;
//				}
//			}
//
//
//			if (secondChildKey >= 0 && !(firstChildKey < rootKey && rootKey <= secondChildKey)) {
//				return -2;
//			}
//		}
//	}
//
//
//	return 0;
//}


bool testSearchTreeAsBinaryTree(int size)
{
	int failedCase = 0;
	BinaryTreeSearch searchTree;
	BinaryTree &searchTreeRef = searchTree;
	std::vector<int> nodesKeys;


	for (int i = 0; i < size; ++i) {
		searchTreeRef.addNode(searchTreeRef.getRoot(), i);
		nodesKeys.push_back(i);
	}


	int index, key;

	searchTreeRef.deleteKnot(searchTreeRef.getRoot(), 13);

	while (nodesKeys.size()) {
		/*index = rand() % nodesKeys.size();
		nodesKeys.erase(nodesKeys.begin() + index);
		if (!searchTreeRef.deleteKnot(searchTreeRef.getRoot(), index)) {
			failedCase = 1;
			break;
		}*/


		/*if (testSearchTreeAsBinaryTree(searchTreeRef, nodesKeys.size())) {
			failedCase = 2;
			break;
		}*/


		if (nodesKeys.size()) {
			index = rand() % nodesKeys.size();
			key = nodesKeys[index];
			nodesKeys.erase(nodesKeys.begin() + index);
			if (!searchTreeRef.deleteKnot(searchTreeRef.getRoot(), key)) {
				failedCase = 3;
				break;
			}


			/*if (testSearchTreeAsBinaryTree(searchTreeRef, nodesKeys.size())) {
				failedCase = 4;
				break;
			}*/
		}
	}


	if (failedCase || !searchTreeRef.isEmpty(searchTreeRef.getRoot())) {
		if (!failedCase) {
			failedCase = -1;
		}


		std::cout << size << " " << searchTreeRef.getNumber(searchTreeRef.getRoot()) << std::endl;
		searchTreeRef.printHorizontal();
		std::cout << std::endl;
		std::cout << std::endl;




	}
	return (failedCase == 0);
}

int main()
{
	test();

	if (testSearchTree(150))
	{
		std::cout << "true1" << std::endl;
	}

	if (testSearchTreeAsBinaryTree(150))
	{
		std::cout << "true2" << std::endl;
	}
}
