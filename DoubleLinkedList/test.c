#include <stddef.h>
#include "DoubleLinkedList.h"
int main(){
    
    DList *list = NULL;

    list = orderedAddItem(list,0);
    list = orderedAddItem(list,10);
    list = orderedAddItem(list,20);
    list = orderedAddItem(list,15);
    list = orderedAddItem(list,30);
    printDList(list);

    list=removeItem(list,10);
    printDList(list);
    list=removeItem(list,8);
    printDList(list);
    list=removeItem(list,0);
    printDList(list);
    list=removeItem(list,30);
    printDList(list);

    return 0;
}