#include<stdio.h>
#include<stdlib.h>
struct node {
	int x;
	int index;
	struct node *next;
};

typedef struct node List;

void printList(List *root) {//liste elemanlarını ekrana basan fonksiyon...
	if (root == NULL) {
		printf("listenin elemanı Yok !!!\n");
		
	}

	else {
		List *iter = root;

		do {
			printf(" %d", iter->x);
			printf("\n%d",iter->index);
			iter = iter->next;
		} while (iter != NULL);

	}

}

List* addItem(List* root, int item) {//listenin sonuna sırasız eleman ekleyen fonksiyon

	if (root == NULL) {//Boş rooteye eleman eklenmesi durumu
		printf("Dizi bos oldugu icin yeni alan tahsis edildi...\n");
		root = (List*)(malloc(sizeof(List)));
		root->x = item;
		root->index = 0;
		root->next = NULL;

		return root;
	}

	List * iterator = root;
	int iter_index = 1;
	while (iterator->next != NULL) {//listenin son elemanına gidildi
		iterator = iterator->next;
		iter_index++;
	}

	iterator->next = (List *)(malloc(sizeof(List)));
	iterator = iterator->next;
	iterator->x = item;
	iterator->index = iter_index;
	iterator->next = NULL;
	return root;
}

List* removeItem(List* root, int item) {
	if (root == NULL) {
		printf("Bos listeden Eleman silinemez....\n");
		return NULL;
	}

	else if (root->x == item) {
		List* temp = root;
		root = root->next;		
		free(temp);
		return root;
	}

	List *iter = root;
	List* temp;
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

List* updateItem(List *root,int oldItem,int newItem) {
	if (root == NULL) {
		printf("Boş listeden eleman guncellenemez...\n");
		return NULL;
	}

	List* iter = root;
	while (iter->x != oldItem) {
		iter = iter->next;
	}
	iter->x = newItem;

	return root;

}

List* orderedAddItem(List* root, int item) {
	List* iter = root;
	int iter_index = 0;
	List *temp;

	if (root == NULL) {
		root = (List*)malloc(sizeof(List));
		root->x = item;
		root->index = 0;
		root->next = NULL;
		printf("item:%d index:%d\n",item,iter_index);

		return root;
	}

	
	if (item < root->x) {
		temp = root;
		root = (List*)malloc(sizeof(List));
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
	iter->next = (List*)malloc(sizeof(List));
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




