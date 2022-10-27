#include <stdio.h>
#include <stdlib.h>

// I ain't done yet

struct Node{
    int data;
    struct Node *next;
};

int len(struct Node *head){
    int i = 0;
    while(head != NULL){
        i++;
        head = head->next;
    }
    return i;
}

int main(){
    struct Node *head = malloc(sizeof(struct Node));
    struct Node *second = malloc(sizeof(struct Node));
    struct Node *third = malloc(sizeof(struct Node));

    head->data = 1;
    head->next = second;

    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next = NULL;

    if (head != NULL){
        for(int i = 1; i <= 3; i++){
            printf("Node %i value: %i\n", i, head->data);
            head = head->next;
        }
    }

}
