#include <stdio.h>
#include <stdlib.h>

typedef struct sortedListNode {

    int id;

    char* data;

    struct listNode* previous;
    struct listNode* next;

} SortedNode;


//Main Driver
int main() {

    Node* driver = NULL;

    Node* newTOne = malloc(sizeof(Node));
    newTOne->data = "First";
    newTOne->previous = NULL;
    newTOne->next = NULL;

    Node* newTTwo = malloc(sizeof(Node));
    newTTwo->data = "Second";
    newTTwo->previous = NULL;
    newTTwo->next = NULL;

    Node* newTThree = malloc(sizeof(Node));
    newTThree->data = "Third";
    newTThree->previous = NULL;
    newTThree->next = NULL;

    insertBack(&driver, newTOne);
    insertBack(&driver, newTTwo);
    insertBack(&driver, newTThree);

    removeSpecific(&driver, "Second");

    printList(driver);
    printf("\n");

    newTTwo = malloc(sizeof(Node));
    newTTwo->data = "Second";
    newTTwo->previous = NULL;
    newTTwo->next = NULL;

    insertBack(&driver, newTTwo);
    printList(driver);

    removeAll(&driver);
    
    return 0;
}

void insertSorted(Node** list, SortedNode* newNode) {

}

void printSorted(SortedNode* list) {

}

void removeAllSorted(Node** list) {

}

void removeSpecificSorted(SortedNode** list, int id) {

}
