#ifndef _Stack
#define _Stack
typedef struct n
{
    int item;
    struct n *next;
}node;

typedef struct s{
    
    node* nodes;
    node* last_item;
    int size;
}Stack;


Stack* AllocateStack();
int IsEmpty(Stack* stack);
void PrintStack(Stack *stack);
void push(Stack *stack,int item);
int pop(Stack *stack);




#endif