#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//The Node data structure for this API
typedef struct listNode {

    char* data;

    struct listNode* previous;
    struct listNode* next;

} Node;



//HEADERS



/* Name: insertBack
 * Description: This function inserts a node to the back of the list
 * 
 * Parameters: The list and the new node to add
 * Return: None
*/
void insertBack(Node** list, Node* newNode);



/* Name: insertFront
 * Description: This function inserts a node to the front of the list
 * 
 * Parameters: The list and the new node
 * Return: None
*/
void insertFront(Node** list, Node* newNode);



/* Name: printList
 * Description: This function prints the data held by every node in the list
 * 
 * Parameters: The list of nodes
 * Return: None
*/
void printList(Node* list);



/* Name: removeAll
 * Description: This function removes every node in the linked list
 * 
 * Parameters: The list of nodes
 * Return: None
*/
void removeAll(Node** list);



/* Name: removeBack
 * Description: This function removes the back node from the list
 * 
 * Parameters: The list of nodes
 * Return: None
*/ 
void removeBack(Node** list);



/* Name: removeFront
 * Description: This function removes the front node from the list
 * 
 * Parameters: The list of nodes
 * Return: None
*/ 
void removeFront(Node** list);



/* Name: removeSpecific
 * Description: This function removes a specific node from the list. Compares by string value
 * 
 * Parameters: The list of nodes and the data string of the node to remove
 * Return: None
*/ 
void removeSpecific(Node** list, char* data);



//IMPLEMENTATIONS



//Function insertBack
void insertBack(Node** list, Node* newNode) {

    //Temporary Node object for modifying the listxs
    Node* temp = *list;

    //If the passed Node object is NULL, return
    if (newNode == NULL) {
        printf("ERROR: Passed node to insert is NULL\n");
        return;
    }

    //If the list is empty, set it equal to the new node
    if (temp == NULL) {
        temp = newNode;
    }

    //Otherwise,
    else {

        //Create an iterator to get to the back of the list
        Node* it = temp;

        //Navigate to the back of the list
        while (it->next != NULL) {
            it = it->next;
        }
        
        //Set the new node to point to the previous back node
        newNode->previous = it;

        //Set the current back node to point to the new one
        it->next = newNode;
    }

    //Set the passed list to the temporary head to save the changes made
    *list = temp;
}



//Function insertFront
void insertFront(Node** list, Node* newNode) {

    //Temporary Node object for modifying the list
    Node* temp = *list;

    //If the passed Node object is NULL, return
    if (newNode == NULL) {
        printf("ERROR: Passed node to insert is NULL\n");
        return;
    }

    //If the list is empty, set it equal to the new node
    if (temp == NULL) {
        temp = newNode;
    }

    //Otherwise,
    else {

        //Set the current front node to point to the new node
        temp->previous = newNode;

        //Set the new node to point to the previous front node
        newNode->next = temp;

        //Set the head of the list to the new node
        temp = newNode;
    }

    //Set the passed list to the temporary head to save the changes made
    *list = temp;
}



//Function printList
void printList(Node* list) {

    //If the passed list pointer is NULL, (no nodes in the list)
    if (list == NULL) {
        printf("ERROR: List passed to print data for is empty.");
        return;
    }

    //Otherwise,
    else {

        //Print every node in the list's data (Add more print statements as needed)
        while (list != NULL) {
            printf("%s\n", list->data);
            list = list->next;
        }
    }
}



//Function removeAll
void removeAll(Node** list) {

    //Temporary Node object for modifying the list
    Node* temp = *list;

    //If the list is empty, return
    if (temp == NULL) {
        return;
    }

    //Otherwise,
    else {

        //Free the first n-1 nodes in the list  
        while (temp->next != NULL) {
            temp = temp->next;
            free(temp->previous);
        }

        //Free the last node in the list
        free(temp);
    }
}



//Function removeBack
void removeBack(Node** list) {

    //Temporary Node object for modifying the list
    Node* temp = *list;

    //If the list is empty, return
    if (temp == NULL) {
        return;
    }

    //If the list only has one node, free it directly
    else if (temp->next == NULL) {
        free(temp);
    }

    //Otherwise,
    else {

        //Create an iterator to navigate the list
        Node* it = temp;

        //Navigate to the back of the list
        while (it->next != NULL) {
            it = it->next;
        }
        
        //Set the second last node to point to NULL
        it->previous->next = NULL;

        //Remove the last node from the list
        free(it);
    }

    //Set the passed list to the temporary head to save the changes made
    *list = temp;
}



//Function removeFront
void removeFront(Node** list) {

    //Temporary Node object for modifying the list
    Node* temp = *list;

    //If the list is empty, return
    if (temp == NULL) {
        return;
    }

    //If the list only has one node, free it directly
    else if (temp->next == NULL) {
        free(temp);
    }

    //Otherwise,
    else {

        //Set the temporary head pointer to the second node
        temp = temp->next;

        //Free the first node
        free(temp->previous);

        //Set the second element to point back to NULL
        temp->previous = NULL;
    }

    //Set the passed list to the temporary head to save the changes made
    *list = temp;
}



//Function removeSpecific
void removeSpecific(Node** list, char* data) {

    //Temporary Node object for modifying the list
    Node* temp = *list;

    //If the passed data string to search for is NULL, return
    if (data == NULL) {
        printf("ERROR: Data specified to search for is NULL.\n");
        return;
    }

    //If the list is empty, return
    if (list == NULL) {
        return;
    }

    //Otherwise,
    else {

        //Create an iterator to iterate through the list
        Node* it = temp;

        //Keep searching until the end of the list
        while (it != NULL) {

            //Once we find the node we need, stop iterating
            if (strcmp(it->data, data) == 0) {
                break;
            }

            //Otherwise, keep searching
            else {
                it = it->next;
            }
        }

        //If we didn't find the node with a matching string, return
        if (it == NULL) {
            return;
        }

        //Otherwise, remove it
        else {

            //If this is the only node in the list
            if (it->previous == NULL && it->next == NULL) {
                free(temp);
            }

            //If this is the first node in the list
            if (it->previous == NULL && it->next != NULL) {

                //Set the second last node's previous pointer to NULL
                it->next->previous = NULL;

                //Move the head pointer to the second node
                temp = it->next;

                //Free the node
                free(it);            
            }

            //If this is the last node in the list
            else if (it->previous != NULL && it->next == NULL) {

                //Set the second last node's next pointer to NULL
                it->previous->next = NULL;

                //Free the node
                free(it);
            }

            //If this is a middle mode in the list
            else {

                //Set the next node to point to the one before the one to be removed
                it->previous->next = it->next;

                //Set the previous node to point to the one after the one to be removed
                it->next->previous = it->previous;

                //Free the node
                free(it);
            }

            //Set the passed list to the temporary head to save the changes made
            *list = temp;
        }
    }
}
