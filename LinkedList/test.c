#include <stddef.h>
#include "LinkedList.h"
int main() {
	List* root=NULL;
	root = orderedAddItem(root, 70);
	root = orderedAddItem(root, 25);
	root = orderedAddItem(root, 20);
	root = orderedAddItem(root, 40);
	root = orderedAddItem(root, 7);
	root = orderedAddItem(root, 43);
	
/*
	root = addItem(root,0);
	root = addItem(root,10);
	root = addItem(root,20);
	root = addItem(root,30);
	root = addItem(root,-1);
*/
	printList(root);
	return 0;
}