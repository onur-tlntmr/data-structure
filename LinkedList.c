#include<stdio.h>
#include<stdlib.h>
struct n {
	int x;
	int index;
	struct n *next;
};

struct z{
	struct n*t;
}

typedef struct n node;
typedef struct z test;



void printList(node *root) {//liste elemanlarını ekrana basan fonksiyon...
	if (root == NULL) {
		printf("listenin elemanı Yok !!!\n");
		
	}

	else {
		node *iter = root;

		do {
			printf(" %d", iter->x);
			printf("\n%d",iter->index);
			iter = iter->next;
		} while (iter != NULL);

	}

}

node* addItem(node* root, int item) {//listenin sonuna sırasız eleman ekleyen fonksiyon

	if (root == NULL) {//Boş rooteye eleman eklenmesi durumu
		printf("Dizi bos oldugu icin yeni alan tahsis edildi...\n");
		root = (node*)(malloc(sizeof(node)));
		root->x = item;
		root->index = 0;
		root->next = NULL;

		return root;
	}

	node * iterator = root;
	int iter_index = 1;
	while (iterator->next != NULL) {//listenin son elemanına gidildi
		iterator = iterator->next;
		iter_index++;
	}

	iterator->next = (node *)(malloc(sizeof(node)));
	iterator = iterator->next;
	iterator->x = item;
	iterator->index = iter_index;
	iterator->next = NULL;
	return root;
}

node* removeItem(node* root, int item) {
	if (root == NULL) {
		printf("Bos listeden Eleman silinemez....\n");
		return NULL;
	}

	else if (root->x == item) {
		node* temp = root;
		root = root->next;		
		free(temp);
		return root;
	}

	node *iter = root;
	node* temp;
	while ( iter->next != NULL && iter->next->x != item ) { //Aranan değerden bir önceki bulundu....
		iter = iter->next;
	}

	if (iter->next == NULL) {
		printf("Aranan Eleman Bulanamadi !!!\n");
		return root;
	}
		temp = iter->next->next; // sonraki eleman için temp işlemi yapıldı....
		free(iter->next);
		iter->next = temp;
		
		return root;
}

node* updateItem(node *root,int oldItem,int newItem) {
	if (root == NULL) {
		printf("Boş listeden eleman guncellenemez...\n");
		return NULL;
	}

	node* iter = root;
	while (iter->x != oldItem) {
		iter = iter->next;
	}
	iter->x = newItem;

	return root;

}

node* orderedAddItem(node* root, int item) {
	node* iter = root;
	int iter_index = 0;
	node *temp;

	if (root == NULL) {
		root = (node*)malloc(sizeof(node));
		root->x = item;
		root->index = 0;
		root->next = NULL;
		printf("item:%d index:%d\n",item,iter_index);

		return root;
	}

	
	if (item < root->x) {
		temp = root;
		root = (node*)malloc(sizeof(node));
		root->x= item;
		root->next = temp;
		
		do{
			iter->index = iter_index++;
			printf("item:%d index:%d\n",item,iter_index);
			iter = iter->next;

		}while(iter->next != NULL);

		return root;
	}
	printf("while\n");	
	while (iter->next != NULL && iter->next->x < item  ) {
		iter = iter->next;
		iter_index++;
	}

	temp = iter->next;
	iter->next = (node*)malloc(sizeof(node));
	iter->next->x = item;
	iter->next->index = iter_index;
	iter->next -> next = temp;
	printf("item:%d index:%d\n",item,iter_index);
	do{
		temp->index++;
		temp = temp->next;
	}while(temp!= NULL);

	return root;



}

//int getIndexOf()


int main() {
	node* root=NULL;
	root = orderedAddItem(root, 70);
	root = orderedAddItem(root, 25);
	root = orderedAddItem(root, 20);
	root = orderedAddItem(root, 40);
	root = orderedAddItem(root, 7);
	root = orderedAddItem(root, 43);
	
/*
	root = addItem(root,0);
	root = addItem(root,10);
	root = addItem(root,20);
	root = addItem(root,30);
	root = addItem(root,-1);
*/
	printList(root);
	printf("/n%d",sizeof(node));
	return 0;
}