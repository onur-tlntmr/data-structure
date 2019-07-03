#include<stdio.h>
#include<stdlib.h>
#include "Stack.h"


Stack* AllocateStack(){
    Stack* stack = (Stack*)malloc(sizeof(stack));
    stack->nodes = NULL;
    stack->last_item = NULL;
    stack->size = 0;

    return stack;
} 

int IsEmpty(Stack* stack){
    if(stack == NULL||stack->nodes == NULL)
        return 1;
    return 0;
}


void PrintStack(Stack *stack){
    if(IsEmpty(stack)){
        printf("Bastirilacak eleman bulunamadı...\n");
    }

    else{

        node *iter = stack->nodes;

        for(int i = 0;i<stack->size;i++){
            printf("%d ",iter->item);
            iter++;
        }
        printf("\n");
    }

} 

void push(Stack *stack,int item){
    
    printf("Second Address: %p\n",stack);

    if(IsEmpty(stack)){ // Stack boş ise tekrar oluşturuluyor
        printf("Null stack hatası...\n")
    }

    if(stack->nodes == NULL){ // Stack var fakat içi boş ise ilk eleman olarak ekleniyor
        stack->nodes = (node*)malloc(sizeof(node));
        stack->nodes->item = item;
        stack->nodes->next = NULL;
        stack->last_item = stack->nodes;
        stack->size = 1;
        return ;
    }

    stack->last_item->next = (node*)malloc(sizeof(node));
    stack->last_item++;
    stack->last_item->item = item;
    stack->last_item->next = NULL;
    stack->size++;
}

int pop(Stack *stack){
    if(IsEmpty(stack)){
        printf("Eleman bulunamadı...\n");
        return -1;
    }

    if(stack->size == 1){
        int temp = stack->last_item->item;
        free(stack->last_item);
        stack->nodes = NULL;
        stack->size = 0;
        return temp;
    }

    node* temp_node = stack->last_item;
    int temp_item = temp_node->item;

    stack->last_item--;
    free(temp_node);
    stack->size--;

    return temp_item;
    

}