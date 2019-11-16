#include<stdio.h>
#include"Queue.h"

int main(){
    Queue* q;
    q=Push(q,15);
    q=Push(q,3);
    q=Push(q,279);
    PrintQueue(q);
    printf("Onceki boyut: %d\n",q->size);
    int numb = Get(q);
    
    printf("Getirilen  Sayi: %d\n",numb);
    printf("Sonraki boyut: %d\n",q->size);

    PrintQueue(q);

}