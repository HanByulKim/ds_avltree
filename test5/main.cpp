#include "Avl.h"

void main(){
	Avl<int> tree;

	tree.insert(2);
	tree.insert(1);
	tree.insert(0);
	tree.print();
	system("pause");
}