#include<stdio.h>
#include<stdlib.h>

struct n {
	int x;
	struct n *next;
};

typedef struct n CList;


void printCList(CList *root) {
	
	if (root == NULL) {
		printf("Boş liste...\n");
	}
	
	else {
		CList *iter = root;
		
		do {
			printf(" %d ", iter->x);
			iter = iter->next;
		} while (iter != root);

	}
		printf("\n");
}



CList* addItem(CList *root,int item) {
	if (root == NULL) {
		root = (CList*)malloc(sizeof(CList));
		root->x = item;
		root->next = root;
		return root;

	}

	CList *iter = root;
	while (iter->next != root) {
		iter = iter->next;
	}

	iter->next = (CList*)malloc(sizeof(CList));
	iter->next->x = item;
	iter->next->next = root;

	return root;

}


CList* orderedAddItem(CList* root,int item){
    if (root == NULL) {
		root = (CList*)malloc(sizeof(CList));
		root->x = item;
		root->next = root;
		return root;
	}
    
	CList *iter = root;
	CList *temp;

    if(root->x > item ){
		root = (CList*)malloc(sizeof(CList));
		root->x = item;
		root->next = iter;
		iter->next = root;
		return root;
	}

	while(iter->next != root && iter->next->x < item )
		iter = iter->next;

	temp = iter->next;
	iter->next  = (CList*)malloc(sizeof(CList));
	iter = iter->next ;
	iter->x = item;
	iter->next =temp;
	return root;

}


CList* removeItem(CList *root,int item){
	if(root == NULL){
		printf("Bos Liste...\n");
	}

	CList *iter = root;
	CList *temp;
	if(root->x == item){//Silinecek eleman listenin başında ise
	
		while(iter->next != root)//iteri sona al
			iter = iter->next;
		temp = root;//ilk elemanı temp'e ata
		root = root->next;//root'u bir eleman kaydır...
		free(temp);//temp'i sil
		iter->next = root;//son eleman yeni root'u göstersin
		return root;
	}

	while(iter->next != NULL && iter->next->x != item)
		iter = iter->next;

	temp = iter->next;
	iter->next = temp->next;
	free(temp);
	return root;

}

