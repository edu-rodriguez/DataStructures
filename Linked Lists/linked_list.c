#include <stdio.h>
#include <stdlib.h>
https://github.com/antoniosarosi/dotfiles/tree/83fb32e60921a879cfab717553f8f016e0145d2b
// I ain't done yet

typedef struct Node{
    int data;
    struct Node *next;
}Node;

Node *listNodes(Node *list){
    list = NULL;
    return list;
}

Node *addNode(Node *list, int data){
    Node *newNode, *aux;
    newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    if (list == NULL){
        list = newNode;
    } else {
        aux = list;
        while(aux->next != NULL){
            aux = aux->next;
        }
        aux->next = newNode;
    }
    return list;
}

int main(){
    Node *list = listNodes(list);
    list = addNode(list, 5);
    list = addNode(list, 2);
    while(list != NULL){
        printf("%i\n", list->data);
        list = list->next;
    }
    free(list);
}
