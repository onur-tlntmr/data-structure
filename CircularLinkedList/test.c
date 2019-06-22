#include <stddef.h>
#include "CircularLinkedList.h"


int main() {

	CList* list = NULL;

	list = orderedAddItem(list,3);
	list = orderedAddItem(list,2);
	
	
	list = orderedAddItem(list,40);
	list = orderedAddItem(list,4);
	list = orderedAddItem(list,50);
	list = orderedAddItem(list,60);
	list = orderedAddItem(list,55);
    
	printCList(list);
	list = removeItem(list,4);
	printCList(list);

	list = removeItem(list,2);
	printCList(list);

	list = removeItem(list,3);
	printCList(list);
	list = removeItem(list,60);
	printCList(list);

	

	return 0;
}