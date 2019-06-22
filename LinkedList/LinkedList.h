#ifndef _LinkedList
#define _LinkedList

struct node {
	int x;
	int index;
	struct node *next;
};

typedef struct node List;


void printList(List *root);

List* addItem(List* root, int item);

List* removeItem(List* root, int item);

List* updateItem(List *root,int oldItem,int newItem);

List* orderedAddItem(List* root, int item);



#endif