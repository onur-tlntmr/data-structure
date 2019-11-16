#include<stdio.h>
#include<stdlib.h>
#include"Queue.h"

Queue* AllocateQueue(){//En baştan bir Queue oluşturan fonksiyon
    Queue* q = (Queue* )malloc(sizeof(Queue));
    q->first_item = 0;
    q->size = 0;
    q->nodes = (node*)malloc(sizeof(node));
    return q;
}


int IsEmpty(Queue* q){ 
    if(q == NULL )
        return 1;
    else if(q->size == 0)
        return 1;
    else
        return 0;
}


void PrintQueue(Queue* q){
    if(IsEmpty(q))
        printf("Bastırılacak Eleman Bulunamadı...\n");
    else{
        node* iter = q->nodes;

        do{
            printf("%d ",iter->item);
            iter = iter->next;
        }while(iter != NULL);
        printf("\n");
    }
}


Queue* Push(Queue* q,int item){

    if(IsEmpty(q)){ //Queue Boş ise elemanlar teker teker oluşuruluyor
        q = AllocateQueue();
        q->first_item = item; // Sayı ekleniyor
        q->size++; // eleman sayısı artırılıyor
        q->nodes->item=item; // yeni elemanlar eklenirse diye node'lara  da ekleniyor
        q->nodes->next=NULL;
    }

    else {
        node* temp = q->nodes; // node'ların başına node ekleneği için eski elemanlar tutuluyor
        node* root = (node*)malloc(sizeof(node));  // ilk eleman oluşturuluyor
        q->first_item=item; //q'nun bilgileri güncelleniyor
        q->size++;
        root->item = item; //root'a değerler ekleniyor
        root->next = temp; // root'a eski node'lar ekleniyor
        q->nodes = root; // yeni hazırlanan node'lar q'ya ekleniyor

        
    }
    return q;

}

int Get(Queue *q){ //Q'dan ilk elemanı alan ve aldığı elemanı silen fonksiyon
    
    int numb = q->first_item; //ilk sayi döndürülen değer olduğu için alınıyr

    node* temp = q->nodes; //
    q->nodes = temp->next;
    free(temp);
    if(q->size == 1){
        q->first_item = 0;
    }
    else{
        q->first_item = q->nodes->item;
    }

    q->size--;


    return numb;

}

