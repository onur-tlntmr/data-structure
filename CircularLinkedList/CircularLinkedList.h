#ifndef _CircularLinkedList
#define _CircularLinkedList
struct n {
	int x;
	struct n *next;
};

typedef struct n CList;

void printCList(CList *);
CList* addItem(CList *,int);
CList* orderedAddItem(CList* ,int);
CList* removeItem(CList *,int);


#endif