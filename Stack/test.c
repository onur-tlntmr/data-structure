#include "Stack.h"
#include <stdio.h>


int main(){

    Stack *stack = AllocateStack();

    printf("First Address: %p\n",stack);

    push(stack,10);
    push(stack,20);
    push(stack,30);
    push(stack,40);
    
    PrintStack(stack);

    printf("%d\n",pop(stack));
    PrintStack(stack);

    printf("%d\n",pop(stack));
    PrintStack(stack);

    printf("%d\n",pop(stack));
    PrintStack(stack);

    printf("%d\n",pop(stack));
    PrintStack(stack);

    // printf("%d\n",stack->nodes->item);
    

    return 0;

}