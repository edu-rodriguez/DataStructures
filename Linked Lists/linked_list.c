#include <stdio.h>
#include <stdlib.h>

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
    Node *newNode;
    newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    if (list == NULL){
        list = newNode;
    } else {

    }
    return list;
}

int main(){
    Node *list = listNodes(list);
    list = addNode(list, 5);
    printf("The nodes list is: %d\n", list->data);
}
