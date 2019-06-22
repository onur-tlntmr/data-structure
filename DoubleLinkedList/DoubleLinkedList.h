#ifndef _DoubleLinkedList
#define _DoubleLinkedList

struct n{
    int x;
    struct n *prev;
    struct n *next;
};

typedef struct n DList;


void printDList(DList *root);
DList* addItem(DList *root,int item);
DList* orderedAddItem(DList *root,int item);
DList* removeItem(DList *root,int item);





#endif