#include<stdio.h>
#include<stdlib.h>

struct n{
    int x;
    struct n *prev;
    struct n *next;
};

typedef struct n DList;


void printDList(DList *root){
    
    if(root == NULL ){
        printf("Bos Liste\n");
    }

    else{
        DList *iter = root;
        do{
            printf(" %d",iter->x);
            iter = iter->next;
        }while(iter != NULL);
        printf("\n");
    }
}


DList* addItem(DList *root,int item){
    if(root == NULL){
        root = (DList*)malloc(sizeof(DList));
        root->x = item;
        root->next = NULL;
        root->prev = NULL;
        return root;
    }
    DList *iter = root;

    DList* temp;
    while(iter->next != NULL)
        iter = iter->next;
    temp = (DList*)malloc(sizeof(DList));
    temp->x = item;
    temp->prev = iter;
    temp->next = NULL;
    iter->next=temp;

    return root;

}


DList* orderedAddItem(DList *root,int item){
    if(root == NULL){
        root = (DList*)malloc(sizeof(DList));
        root->x = item;
        root->next = NULL;
        root->prev = NULL;
        return root;
    }

    DList *temp;
    if(root->x > item){
        temp = (DList*)malloc(sizeof(DList));
        temp-> x = item;
        temp->next = root;
        root->prev = temp;
        temp->prev = NULL;
        return temp;
    }

    DList *iter = root;
    

    while(iter->next != NULL && iter->next->x < item)
        iter = iter->next;

    temp = iter->next;
    iter->next = (DList*)malloc(sizeof(DList));
    iter->next->x = item;
    iter->next->next = temp;

    if(temp != NULL)
        temp->prev = iter->next;

    return root;

}


DList* removeItem(DList *root,int item){
    if(root == NULL){
        printf("Bos Liste\n");
        return root;
    }
    DList *temp;
    if(root->x == item){
        temp = root;
        root = root->next;
        root->prev = NULL;
        free(temp);
        return root;

    }
    DList *iter = root;
    while(iter->next != NULL && iter->next->x != item)
        iter = iter->next;
    
    if(iter->next == NULL){
        printf("Silinece Eleman Bulunamadı...\n");
        return root;
    }

    temp = iter->next;
    iter->next = temp->next;
    if(temp->next != NULL)
        temp->next->prev = iter;
    free(temp);
    
    return root;
    
}


