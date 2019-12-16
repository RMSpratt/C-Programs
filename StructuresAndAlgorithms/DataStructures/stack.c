/*
 * Author: Reed Spratt
 *
 * Description: This program includes numerous functions for working with the stack data structure. 
 *              This includes functions for pushing nodes to and popping nodes from the stack, as well as auxillary functions
 *              for getting the stack's size and printing its data. 
 *
 * Date: December 15th 2019
*/



#include <stdio.h>
#include <stdlib.h>
#include <string.h>



//The node data structure for the stack
typedef struct stackNode {

    //Pointer to a string of data
    char* data;

    //The number of nodes below this one in the stack
    int nodesBelow;

    //Pointer to the previous node in the stack
    struct stackNode* previous;

} node;



/* Name: getStackSize
 * Description: This function returns the number of nodes in the stack. 
 * 
 * Parameter: stack             The stack to return the size of
 * Return: int                  The number of nodes in the stack
*/ 
int getStackSize(node* stack);



/* Name: peekStack
 * Description: This function prints the data of the top node in the stack.
 * 
 * Parameter: stack             The stack to print the top node's data of
 * Return: void
*/
void peekStack(node* stack);



/* Name: popAllFromStack
 * Description: This function pops all of the nodes from the stack.
 * 
 * Parameter: stack             The stack to pop all the nodes from
 * Return: stack                The modified stack
*/ 
node* popAllFromStack(node* stack);



/* Name: popFromStack
 * Description: This function pops the topmost node from the stack.
 * 
 * Parameter: stack             The stack to pop a node from
 * Return: stack                The modified stack
*/ 
node* popFromStack(node* stack);



/* Name: printStack
 * Description: This function prints the data of each node in the stack.
 * 
 * Parameter: stack             The stack to print the data of
 * Return: void
*/ 
void printStack(node* stack);



/* Name: pushToStack
 * Description: This function pushes the new passed node into the stack.
 * 
 * Parameter: stack             The stack to push the new node into
 * Parameter: new               The new node to push into the stack
 * Return: stack                The modified stack
*/
node* pushToStack(node* stack, node* new);



//FUNCTION getStackSize
int getStackSize(node* stack) {

    //If the passed stack is null, return
    if (stack == NULL) {
        return 0;
    }

    //Else, return the number of nodes in the stack
    else {
        return stack->nodesBelow + 1; 
    }
}



//FUNCTION peekStack
void peekStack(node* stack) {

    //Print the top node's data if it isn't NULL
    if (stack != NULL && stack->data != NULL) {
        printf("Top Node data: %s\n", stack->data);
    }
}



//FUNCTION popAllFromStack
node* popAllFromStack(node* stack) {

    //Variable to hold the node popNode from the stack
    node* popNode;

    //Free all of the nodes from the stack
    while (stack != NULL) {

        //Get the topmost node to be popNode from the stack
        popNode = stack;
        printf("Popping the node %s from the stack.\n", popNode->data);

        //Set the stack head to the next node in the stack
        stack = stack->previous;

        //If the node to pop has data, free it
        if (popNode->data != NULL) {
            free(popNode->data);
        }

        //Free the node
        free(popNode);
    }

    printf("The stack is now empty.\n");

    //Return the modified stack
    return stack;
}



//FUNCTION popFromStack
node* popFromStack(node* stack) {

    //Variable to hold the node popNode from the stack
    node* popNode;

    //If the stack is empty, return
    if (stack == NULL) {
        return stack;
    }

    //Else, the stack isn't empty
    else {

        //Get the topmost node to be popNode from the stack
        popNode = stack;
        printf("Popping the node %s from the stack.\n", popNode->data);

        //Set the stack head to the next node in the stack
        stack = stack->previous;

        //If the node to pop has data, free it
        if (popNode->data != NULL) {
            free(popNode->data);
        }

        //Free the node
        free(popNode);
    }

    //Return the modified stack
    return stack;
}



//FUNCTION printStack
void printStack(node* stack) {

    while (stack != NULL && stack->data != NULL) {
        printf("Node data: %s\n", stack->data);
    }
}



//FUNCTION pushToStack
node* pushToStack(node* stack, node* new) {

    //If the new node to push into the stack is NULL, return
    if (new == NULL) {
        printf("The new node to add passed was NULL.\n");
        return stack;
    }

    //If the stack is empty, set its pointer to the new node
    if (stack == NULL) {
        printf("Pushing the node %s into the stack.\n", new->data);
        stack = new;
        stack->nodesBelow = 0;
    }

    //Else, set the new node to point back to the previous top node and set the stack to point to the new node
    else {
        printf("Pushing the node %s into the stack.\n", new->data);
        new->previous = stack;
        new->nodesBelow = (stack->nodesBelow + 1);
        stack = new;
    }

    //Return the modified stack
    return stack;
}
