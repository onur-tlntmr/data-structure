#include<stdio.h>
#include<stdlib.h>

struct n {
	int x;
	struct n *next;
};

typedef struct n node;

void printCList(node *root) {
	
	if (root == NULL) {
		printf("Boş liste...\n");
	}
	
	else {
		node *iter = root;
		
		do {
			printf(" %d ", iter->x);
			iter = iter->next;
		} while (iter != root);

	}
		printf("\n");
}



node* addItem(node *root,int item) {
	if (root == NULL) {
		root = (node*)malloc(sizeof(node));
		root->x = item;
		root->next = root;
		return root;

	}

	node *iter = root;
	while (iter->next != root) {
		iter = iter->next;
	}

	iter->next = (node*)malloc(sizeof(node));
	iter->next->x = item;
	iter->next->next = root;

	return root;

}


node* orderedAddItem(node* root,int item){
    if (root == NULL) {
		root = (node*)malloc(sizeof(node));
		root->x = item;
		root->next = root;
		return root;
	}
    
	node *iter = root;
	node *temp;

    if(root->x > item ){
		root = (node*)malloc(sizeof(node));
		root->x = item;
		root->next = iter;
		iter->next = root;
		return root;
	}

	while(iter->next != root && iter->next->x < item )
		iter = iter->next;

	temp = iter->next;
	iter->next  = (node*)malloc(sizeof(node));
	iter = iter->next ;
	iter->x = item;
	iter->next =temp;
	return root;

}


node* removeItem(node *root,int item){
	if(root == NULL){
		printf("Bos Liste...\n");
	}

	node *iter = root;
	node *temp;
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

int main() {

	node* list = NULL;

	list = orderedAddItem(list,3);
	list = orderedAddItem(list,2);
	
	
	list = orderedAddItem(list,40);
	list = orderedAddItem(list,4);
	list = orderedAddItem(list,50);
	list = orderedAddItem(list,60);
	list = orderedAddItem(list,55);
    
	printCList(list);
	list = removeItem(list,4);
	printCList(list);

	list = removeItem(list,2);
	printCList(list);

	list = removeItem(list,3);
	printCList(list);
	list = removeItem(list,60);
	printCList(list);

	

	return 0;
}