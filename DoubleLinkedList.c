#include<stdio.h>
#include<stdlib.h>

struct n{
    int x;
    struct n *prev;
    struct n *next;
};

typedef struct n node;


void printList(node *root){
    
    if(root == NULL ){
        printf("Bos Liste\n");
    }

    else{
        node *iter = root;
        do{
            printf(" %d",iter->x);
            iter = iter->next;
        }while(iter != NULL);
        printf("\n");
    }
}


node* addItem(node *root,int item){
    if(root == NULL){
        root = (node*)malloc(sizeof(node));
        root->x = item;
        root->next = NULL;
        root->prev = NULL;
        return root;
    }
    node *iter = root;

    node* temp;
    while(iter->next != NULL)
        iter = iter->next;
    temp = (node*)malloc(sizeof(node));
    temp->x = item;
    temp->prev = iter;
    temp->next = NULL;
    iter->next=temp;

    return root;

}


node* orderedAddItem(node *root,int item){
    if(root == NULL){
        root = (node*)malloc(sizeof(node));
        root->x = item;
        root->next = NULL;
        root->prev = NULL;
        return root;
    }

    node *temp;
    if(root->x > item){
        temp = (node*)malloc(sizeof(node));
        temp-> x = item;
        temp->next = root;
        root->prev = temp;
        temp->prev = NULL;
        return temp;
    }

    node *iter = root;
    

    while(iter->next != NULL && iter->next->x < item)
        iter = iter->next;

    temp = iter->next;
    iter->next = (node*)malloc(sizeof(node));
    iter->next->x = item;
    iter->next->next = temp;

    if(temp != NULL)
        temp->prev = iter->next;

    return root;

}


node* removeItem(node *root,int item){
    if(root == NULL){
        printf("Bos Liste\n");
        return root;
    }
    node *temp;
    if(root->x == item){
        temp = root;
        root = root->next;
        root->prev = NULL;
        free(temp);
        return root;

    }
    node *iter = root;
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


int main(){
    
    node *list = NULL;

    list = orderedAddItem(list,0);
    list = orderedAddItem(list,10);
    list = orderedAddItem(list,20);
    list = orderedAddItem(list,15);
    list = orderedAddItem(list,30);
    printList(list);

    list=removeItem(list,10);
    printList(list);
    list=removeItem(list,8);
    printList(list);
    list=removeItem(list,0);
    printList(list);
    list=removeItem(list,30);
    printList(list);

    return 0;
}