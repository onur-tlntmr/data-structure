#ifndef _Queue
#define _Queue
typedef struct n
{
    int item;
    struct n* next;
    /* data */
}node;

typedef struct q{
    node* nodes;
    int first_item;
    int size;
}Queue;

//Queue* AllocateQueue();
int IsEmpty(Queue* );
void PrintQueue(Queue* );
Queue* Push(Queue* q, int item);
int Get(Queue*);
#endif
