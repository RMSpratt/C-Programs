#include <stdio.h>
#include <stdlib.h>

//The Node data structure for this API
typedef struct listNode {

    int id;

    char* data;

    struct listNode* previous;
    struct listNode* next;

} Node;



//HEADERS



/* Name: insertNode
 * Description: This function inserts a new Node into the list
 * 
 * Parameters: The list, and the new node to insert
 * Return: None
*/
void insertNode(Node** list, Node* newNode);



/* Name: printList
 * Description: This function prints the data held in every list node
 * 
 * Parameters: The list of nodes
 * Return: None
*/
void printList(Node* list);



/* Name: removeAllNodes
 * Description: This function removes all of the nodes from the list
 * 
 * Parameters: The list to remove nodes from
 * Return: None
*/
void removeAllNodes(Node** list);



/* Name: removeSpecificNode
 * Description: This function removes a specific node from the list
 * 
 * Parameters: The list and the id of the node to remove
 * Return: None
*/ 
void removeSpecificNode(Node** list, int id);



//IMPLEMENTATIONS



//Function insertNode
void insertNode(Node** list, Node* newNode) {

    //Temporary Node object for modifying the list
    Node* temp = *list;

    //If the passed Node is NULL, return
    if (newNode == NULL) {
        printf("ERROR: Passed Node to insert is NULL.\n");
        return;
    }

    //If the list is empty, set the head pointer to the new Node
    else if (temp == NULL) {
        temp = newNode;
    }

    //Otherwise,
    else {
    
        //Create an iterator to iterate through the list
        Node* it = temp;

        //Navigate until the right position is found or we hit the end of the list
        while (it->next != NULL) {

            //If the current node is greater than the node's being inserted, stop
            if (it->id > newNode->id) {
                break;
            }

            //Otherwise, keep iterating
            else {
                it = it->next;
            }
        }

        //If the list only had one element, compare the new one and insert in front or behind
        if (it->previous == NULL && it->next == NULL) {

            //The new node comes before the current one
            if (it->id > newNode->id) {
                
                //Set the current node to point back to the new inserted one
                it->previous = newNode;

                //Set the new node to point ahead to the next one
                newNode->next = it;

                //Set the head of the list to the new node inserted
                temp = newNode;
            }

            //The new node goes after the current one
            else {

                //Set the second last node to point to the new node
                it->next = newNode;

                //Set the new node to point to the second last node
                newNode->previous = it;
            }
        }

        //If we need to insert the node at the front of the list
        else if (it->previous == NULL && it->next != NULL) {

            //Set the current node to point back to the new inserted one
            it->previous = newNode;

            //Set the new node to point ahead to the next one
            newNode->next = it;

            //Set the head of the list to the new node inserted
            temp = newNode;
        }
            
        //If we need to insert the node at the back of the list
        else if (it->previous != NULL && it->next == NULL) {

            //The new node to insert is the second last node
            if (it->id > newNode->id) {
                
                //Set the new node to point ahead to the last one
                newNode->next = it;

                //Set the new node to point back to the third last one
                newNode->previous = it->previous;
            
                //Set the third last node to point to the new one
                it->previous->next = newNode;

                //Set the last node to point back to the new one
                it->previous = newNode;

            }

            //The new node to insert is the last node
            else {

                //Set the second last node to point to the new node
                it->next = newNode;

                //Set the new node to point to the second last node
                newNode->previous = it;
            }
        }

        //If we are inserting to the middle of the list
        else {

            //Set the new node to point ahead to the next one
            newNode->next = it;

            //Set the new node to point back to the previous
            newNode->previous = it->previous;
            
            //Set the previous node to point to the new one
            it->previous->next = newNode;

            //Set the next node to point back to the new one
            it->previous = newNode;
        }
    }

    *list = temp;
}



//Function printList
void printList(Node* list) {

    //If the passed list pointer is NULL, (no nodes in the list)
    if (list == NULL) {
        printf("ERROR: List passed to print data for is empty.\n");
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



//Function removeAllNodes
void removeAllNodes(Node** list) {

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
        temp = NULL;
    }

    //Set the passed list to the temporary head to save the changes made
    *list = temp;
}



//Function removeSpecificNode
void removeSpecificNode(Node** list, int id) {

   //Temporary Node object for modifying the list
    Node* temp = *list;

    //If the list is empty, return
    if (temp == NULL) {
        return;
    }

    //If the list has one node left
    else if (temp->next == NULL) {
        
        //If the id being searched for matches, free the node and set the list head to NULL
        if (temp->id == id) {
            free(temp);
            temp = NULL;
        }

        //Otherwise, simply return
        else {
            return;
        }
    }

    //Otherwise,
    else {

        //Create an iterator to iterate through the list
        Node* it = temp;

        //Keep searching until the end of the list
        while (it != NULL) {

            //Once we find the node we need, stop iterating
            if (it->id == id) {
                break;
            }

            //Otherwise, keep searching
            else {
                it = it->next;
            }
        }

        //If we didn't find the node with a matching ID, return
        if (it == NULL) {
            return;
        }

        //Otherwise, remove it
        else {

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
