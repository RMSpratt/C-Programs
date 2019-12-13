#include <stdio.h>
#include <stdlib.h>


//Struct representing a leaf in the tree
typedef struct leafNode {

    //ID for searching, inserting, and deletion purposes
    int ID;

    //Pointers to the node's left and right children in the tree
    struct leafNode* leftChild;
    struct leafNode* rightChild;

} leaf;



/* Name: createNode
 * Description: This function creates a new leaf structure and returns it.
 * 
 * Parameter: newID         The ID of the new leaf to be created
 * Return: newLeaf          The allocated new leaf
*/ 
//Create and allocate a new leaf node and return it
leaf* createNode(int newID);



/* Name: iterativeDeleteTree
 * Description: This function iteratively deletes all of the leaf nodes in a tree.
 * 
 * Parameter: root          The root of the tree to clear all of the nodes of
 * Return: void
*/ 
void iterativeDeleteTree(leaf** root);



/* Name: iterativeFindBiggest
 * Description: This function iteratively searches for the biggest node in the passed tree.
 * 
 * Parameter: root          The root of the passed tree to search through
 * Return: biggest          The biggest node in the tree or NULL
*/
leaf* iterativeFindBiggest(leaf* root);



/* Name: iterativeFindSmallest
 * Description: This function iteratively searches for the smallest node in the passed tree.
 * 
 * Parameter: root          The root of the passed tree to search through
 * Return: smallest         The smallest node in the tree or NULL
*/
leaf* iterativeFindSmallest(leaf* root);



/* Name: iterativeInsertLeaf
 * Description: This function iteratively searches through a tree to insert a node based on its ID.
 * 
 * Parameter: root          The root of the passed tree to insert the node into
 * Parameter: newLeaf       The new leaf node to insert into the tree
 * Return: void
*/ 
void iterativeInsertLeaf(leaf** root, leaf* newLeaf);



/* Name: iterativeRemoveLeaf
 * Description: This function iteratively searches through a tree to delete a node with the given ID.
 * 
 * Parameter: root
 * Parameter: searchID
 * Return: void
*/ 
void iterativeRemoveLeaf(leaf** root, int searchID);



/* Name: iterativeSearch
 * Description: This function iteratively searches through the passed tree for the node with the given ID
 * 
 * Parameter: root              The root of the tree to search through
 * Parameter: searchID          The ID of the leaf being searched for
 * Return: void
*/ 
void iterativeSearch(leaf* root, int searchID);



/* Name: recursiveDeleteTree
 * Description: This function recursively deletes all of the leaf nodes in a tree.
 * 
 * Parameter: root              The root of the tree to clear all of the nodes of
 * Return: void
*/
void recursiveDeleteTree(leaf* root);



/* Name: recursiveInsertLeaf
 * Description: This function recursively searches through a tree to insert a node based on its ID.
 * 
 * Parameter: root          The root of the passed tree to insert the node into
 * Parameter: newLeaf       The new leaf node to insert into the tree
 * Return: void
*/ 
leaf* recursiveInsertLeaf(leaf* root, leaf* newLeaf);



/* Name: recursiveRemoveLeaf
 * Description: This function recursively searches through a tree to delete a node with the given ID.
 * 
 * Parameter: root
 * Parameter: searchID
 * Return: void
*/ 
leaf* recursiveRemoveLeaf(leaf* root, int searchID);



/* Name: recursiveSearch
 * Description: This function recursively searches through the passed tree for the node with the given ID
 * 
 * Parameter: root              The root of the tree to search through
 * Parameter: searchID          The ID of the leaf being searched for
 * Return: void
*/ 
void recursiveSearch(leaf* root, int searchID);



//FUNCTION createNode
leaf* createNode(int newID) {

    //Allocate the passed leaf
    leaf* newLeaf = malloc(sizeof(leaf));

    //Set the new leaf's ID to the passed one
    newLeaf->ID = newID;

    //Set the new leaf's child pointers to NULL
    newLeaf->leftChild = NULL;
    newLeaf->rightChild = NULL;

    return newLeaf;
}



//FUNCTION iterativeDeleteTree
void iterativeDeleteTree(leaf** root) {

    //Temporary pointer to the root
    leaf* tempRoot = *root;

    //Temporary iterator to iterate through the tree
    leaf* it = tempRoot;

    //Iterate and delete nodes until the entire tree is deleted
    while (tempRoot != NULL) {

        //If the current node has a left child
        if (it->leftChild != NULL) {

            //If the current node's left child has children, traverse to the left
            if (it->leftChild->leftChild != NULL || it->leftChild->rightChild != NULL) {
                it = it->leftChild;
            }
            
            //Else, free the current node's left child
            else {
                printf("Freeing the node: %d.\n", it->leftChild->ID);
                free(it->leftChild);
                it->leftChild = NULL;

                //Reset the iterator
                it = tempRoot;
            }
        }

        //Else if the current node has a right child
        else if (it->rightChild != NULL) {

            //If the current node's right child has children, traverse to the right
            if (it->rightChild->leftChild != NULL || it->rightChild->rightChild != NULL) {
                it = it->rightChild;
            }
            
            //Else, free the current node's right child
            else {
                printf("Freeing the node: %d.\n", it->rightChild->ID);
                free(it->rightChild);
                it->rightChild = NULL;

                //Point the iterator back at the root
                it = tempRoot;
            }
        }

        //Else, this is the root node, free it
        else {
            printf("Freeing the root node: %d.\n", it->ID);
            free(it);
            break;
        }
    }

    //Set the root pointer to NULL
    *root = tempRoot;
} 



//FUNCTION iterativeFindBiggest
leaf* iterativeFindBiggest(leaf* root) {

    //Pointer to hold the biggest value in the tree
    leaf* biggest = root;

    //If the passed tree is NULL, return
    if (biggest == NULL) {
        printf("The passed tree is NULL and has no biggest leaf value.\n");
        return NULL;
    }

    //Keep searching for the biggest value
    while (biggest->rightChild != NULL) {
        biggest = biggest->rightChild;
    }

    //Return the leaf with the biggest value
    return biggest;
}



//FUNCTION iterativeFindSmallest
leaf* iterativeFindSmallest(leaf* root) {

    //Pointer to hold the smallest value in the tree
    leaf* smallest = root;

    //If the passed tree is NULL, return
    if (smallest == NULL) {
        printf("The passed tree is NULL and has no smallest leaf value.\n");
        return NULL;
    }

    //Keep searching for the smallest value in the tree
    while (smallest->leftChild != NULL) {
        smallest = smallest->leftChild;
    }

    //Return the leaf with the smallest value
    return smallest;
}



//FUNCTION iterativeInsert
void iterativeInsertLeaf(leaf** root, leaf* newLeaf) {

    //Temporary pointer to the root
    leaf* tempRoot = *root;

    //If the passed new leaf node is NULL, return
    if (newLeaf == NULL) {
        printf("ERROR: New leaf passed is NULL.\n");
        return;
    }

    //If the root node is NULL, simply set it to the passed leaf
    if (tempRoot == NULL) {
        tempRoot = newLeaf;
    }

    //Else the root pointer is not NULL
    else {

        //Temporary iterator to iterate through the tree
        leaf* it = tempRoot;

        //Iterate through the tree until finding its proper insertion location
        while (it != NULL) {

            //If the newLeaf's ID is less than the current node
            if (newLeaf->ID < it->ID) {

                //If the current leaf's leftChild pointer is NULL, set it to the new leaf being added
                if (it->leftChild == NULL) {
                    it->leftChild = newLeaf;
                    break;
                }

                //Else, set the iterator to the current leaf's left child, and keep searching
                else {
                    it = it->leftChild;
                }
            }

            //Else if the newLeaf's ID is greater than the current node
            else if (newLeaf->ID > it->ID) {

                //If the current leaf's rightChild pointer is NULL, set it to the new leaf being added
                if (it->rightChild == NULL) {
                    it->rightChild = newLeaf;
                    break;
                }

                //Else, set the iterator to the current leaf's right child, and keep searching
                else {
                    it = it->rightChild;
                }
            }

            //Else, the new leaf's ID is equal to an existing leaf in the tree, and can't be added
            else {
                printf("ERROR: The new leaf's ID already exists within the tree.\n");
                break;
            }
        }
    }

    //Set the passed tree root to the temporary root to save the changes made
    *root = tempRoot;
}



//FUNCTION iterativeSearch
void iterativeSearch(leaf* root, int searchID) {

    //Iterate through the tree until reaching an end
    while (root != NULL) {

        //If the search ID is less than the current node's, go to the left
        if (searchID < root->ID) {
            root = root->leftChild;
        }

        //Else if the search ID is greater than the current node's, go to the right
        else if (searchID > root->ID) {
            root = root->rightChild;
        }

        //Else, the search ID matches the current node's, we found the desired leaf
        else {
            printf("The leaf with ID %d was found in the tree.\n", searchID);
            return;
        }
    }

    //If the end of the tree was reached without finding the desired ID, inform the user
    printf("The leaf with ID %d could not be found in the tree.\n", searchID);
}



//FUNCTION iterativeRemoveLeaf
void iterativeRemoveLeaf(leaf** root, int searchID) {

    //Temporary pointer to the root node
    leaf* tempRoot = *root;

    //Pointer holding the parent of the leaf node to delete
    leaf* parentLeaf = tempRoot;

    //Pointer to the leaf node to delete
    leaf* deleteLeaf = NULL;

    //If the passed tree is NULL, return
    if (tempRoot == NULL) {
        printf("The leaf to delete with ID %d could not be found in the tree.\n", searchID);
        return;
    }

    //Look for the leaf to delete until it's found or we reach a dead-end
    while (parentLeaf != NULL) {

        //If the node to delete's ID is less than the current node
        if (searchID < parentLeaf->ID) {

            //If the current node's left child is NULL, we've reached a dead-end
            if (parentLeaf->leftChild == NULL) {
                break;
            }

            //Else if the current node's left child matches the ID being searched for, we found the node to delete
            else if (parentLeaf->leftChild->ID == searchID) {
                deleteLeaf = parentLeaf->leftChild;
                break;
            }

            //Else, keep searching
            else {
                parentLeaf = parentLeaf->leftChild;
            }
        }

        //Else if the node to delete's ID is greater than the current node
        else if (searchID > parentLeaf->ID) {

            //If the current node's right child is NULL, we've reached a dead-end
            if (parentLeaf->rightChild == NULL) {
                break;
            }

            //Else if the current node's right child matches the ID being searched for, we found the node to delete
            else if (parentLeaf->rightChild->ID == searchID) {
                deleteLeaf = parentLeaf->rightChild;
                break;
            }

            //Else, keep searching
            else {
                parentLeaf = parentLeaf->rightChild;
            }
        }

        //Else, we found the ID being searched for
        else {
            deleteLeaf = parentLeaf;
            break;
        }
    }
   
    //CASE ONE: If the node to delete wasn't found, return from the function
    if (deleteLeaf == NULL) {
        printf("The leaf to delete with ID %d could not be found in the tree.\n", searchID);
        return;
    }

    //CASE TWO: If the desired leaf is the parent leaf, then we're deleting the root node
    if (deleteLeaf == parentLeaf) {
        printf("Freeing the root with ID %d.\n", deleteLeaf->ID);

        //If the root has no children, simply free it and set it to NULL
        if (deleteLeaf->leftChild == NULL && deleteLeaf->rightChild == NULL) {
            tempRoot = NULL;
            free(deleteLeaf);
        }

        //Else if the root only has a left child, free the old root, and set its pointer to the left child
        else if (deleteLeaf->leftChild != NULL && deleteLeaf->rightChild == NULL) {
            tempRoot = deleteLeaf->leftChild;
            free(deleteLeaf);
        }

        //Else if the root only has a right child, free the old root, and set the pointer to the child
        else if (deleteLeaf->leftChild == NULL && deleteLeaf->rightChild != NULL) {
            tempRoot = deleteLeaf->rightChild;
            free(deleteLeaf);
        }

        //Else, the root has a left and right child
        else {

            //Make a temporary pointer to the node to delete's right child
            leaf* tempRight = deleteLeaf->rightChild;

            //Find the leaf node to replace the one to delete, as the next node in sequence
            leaf* successor = iterativeFindSmallest(deleteLeaf->rightChild);

            //Find the successor leaf's biggest right child
            leaf* succRight = iterativeFindBiggest(successor->rightChild);

            //Set the node to delete's ID to the successor's ID
            deleteLeaf->ID = successor->ID;

            //If the successor leaf had a right child
            if (succRight != NULL) {

                //Set the node to delete's new right child to its successor's biggest right child
                deleteLeaf->rightChild = succRight;

                //Set the successor's biggest right child's rightChild pointer to deleteLeaf's rightChild
                succRight->rightChild = tempRight;

                //Set the node to delete's old right child's left pointer to NULL
                tempRight->leftChild = NULL;    
            }

            //Else if the node to delete's successor was its right child (Implies the node it was at the second lowest level of the tree)
            else if (tempRight == successor) {

                //Set the node to delete's right child pointer to NULL
                deleteLeaf->rightChild = NULL;
            }

            //Otherwise, the successor node didn't have any right children and isn't the node to delete's right child
            else {
                //Simply leave the leaf to delete's right child unaltered
            }

            //Free the successor node (At the bottom of the tree)
            free(successor);
            successor = NULL;
        }
        
        //Save the changes made to the passed root
        *root = tempRoot;
        return;
    }

    //CASE THREE: If the node to delete is not the root and has no children, simply free it and set it to NULL
    if (deleteLeaf->leftChild == NULL && deleteLeaf->rightChild == NULL) {
        printf("Freeing the node with ID %d.\n", deleteLeaf->ID);

        //If the node to delete's ID is less than its parent's, set its parent's leftChild pointer to NULL
        if (deleteLeaf->ID < parentLeaf->ID) {
            parentLeaf->leftChild = NULL;
        }

        //Else the node to delete's ID is greater than its parent's, set its parent's rightChild pointer to NULL
        else {
            parentLeaf->rightChild = NULL;
        }

        //Free the node to delete
        free(deleteLeaf);
    }

    //CASE FOUR: Else if the node to delete is not the root and only has a left child, give it to its parent
    else if (deleteLeaf->leftChild != NULL && deleteLeaf->rightChild == NULL) {

        //Make a temporary pointer to the left child
        leaf* tempLeft = deleteLeaf->leftChild;

        //Free the leaf and set it to NULL
        free(deleteLeaf);
        deleteLeaf = NULL;

        //If the temporary pointer ID is less than the parent leaf's ID, make it the parent's left child
        //(This implies that the deleted leaf was its parent's left child)
        if (tempLeft->ID < parentLeaf->ID) {
            parentLeaf->leftChild = tempLeft;
        }

        //Else the temporary pointer ID is greater than the parent leaf's ID, make it the parent's right child
        //(This implies that the deleted leaf was its parent's right child)
        else {
            parentLeaf->rightChild = tempLeft;
        }
    }

    //CASE FIVE: Else if the node to delete is not the ROOT and only has a right child, give it to its parent
    else if (deleteLeaf->leftChild == NULL && deleteLeaf->rightChild != NULL) {

        //Make a temporary pointer to the right child
        leaf* tempRight = deleteLeaf->rightChild;

        //Free the leaf and set it to NULL
        free(deleteLeaf);
        deleteLeaf = NULL;

        //If the temporary pointer ID is less than the parent leaf's ID, make it the parent's left child
        //(This implies that the deleted leaf was its parent's left child)
        if (tempRight->ID < parentLeaf->ID) {
            parentLeaf->leftChild = tempRight;
        }

        //Else the temporary pointer ID is greater than the parent leaf's ID, make it the parent's right child
        //(This implies that the deleted leaf was its parent's right child)
        else if (tempRight->ID > parentLeaf->ID) {
            parentLeaf->rightChild = tempRight;
        }
    }

    //CASE SIX: Else the node to delete is not the root and has two children
    else {
        printf("Freeing a node with two children: %d\n", deleteLeaf->ID);

        //Make a temporary pointer to the node to delete's right child
        leaf* tempRight = deleteLeaf->rightChild;

        //Find the leaf to replace this one, as the next node in sequence
        leaf* successor = iterativeFindSmallest(deleteLeaf->rightChild);

        //Find the successor leaf's biggest right child
        leaf* succRight = iterativeFindBiggest(successor->rightChild);

        //Set the node to delete's ID to its successor's
        deleteLeaf->ID = successor->ID;

        //If the successor leaf had a right child
        if (succRight != NULL) {

            //Set the node to delete's new right child to its successor's biggest right child
            deleteLeaf->rightChild = succRight;

            //Set the successor's biggest right child's rightChild pointer to the old rightChild of deleteLeaf
            succRight->rightChild = tempRight;

            //Set the node to delete's old right child's left pointer to NULL (It previously pointed to successor)
            tempRight->leftChild = NULL;
        }

        //Else if the node to delete's successor was its right child (Implies it was at the second lowest level)
        else if (tempRight == successor) {

            //Set the node to delete's right child pointer to NULL
            deleteLeaf->rightChild = NULL;
        }

        //Otherwise, the successor node didn't have any right children and isn't the leaf to delete's right child
        else {
            //Simply leave the node to delete's right child unaltered
        }

        //Free the successor node (At the bottom of the tree)
        free(successor);
        successor = NULL;
    }

    //Save the changes made to the original root
    *root = tempRoot;
}



//FUNCTION recursiveDeleteTree
void recursiveDeleteTree(leaf* root) {

    //Return from the function when all of the nodes are freed
    if (root == NULL) {
       return;
    }

    //Recurse through the left and right subtrees
    recursiveDeleteTree(root->leftChild);
    recursiveDeleteTree(root->rightChild);

    //Free each leaf node
    printf("Freeing the leaf: %d.\n", root->ID);
    free(root);
}



//FUNCTION recursiveInsertLeaf
leaf* recursiveInsertLeaf(leaf* root, leaf* newLeaf) {

    //If the passed tree is NULL, set the new leaf as the root
    if (root == NULL) {
        return newLeaf;
    }

    //If the new leaf's ID matches a pre-existing leaf, return
    if (newLeaf->ID == root->ID) {
        printf("ERROR: Leaves with duplicate IDs are not accepted.\n");
        return root;
    }

    //Else if the new leaf's ID is less than the current leaf, recurse the left subtree
    else if (newLeaf->ID < root->ID) {
        root->leftChild = recursiveInsert(root->leftChild, newLeaf);
    }

    //Else if the new leaf's ID is greater than the current leaf, recurse the right subtree
    else if (newLeaf->ID > root->ID) {
        root->rightChild = recursiveInsert(root->rightChild, newLeaf);
    }

    //Return the modified root when finished
    return root;
}



//FUNCTION recursiveRemoveLeaf
leaf* recursiveRemoveLeaf(leaf* root, int searchID) {

    //If the passed root is NULL or we couldn't find the desired value, exit the function
    if (root == NULL) {
        printf("The desired leaf to delete with ID %d could not be found in the tree.\n", searchID);
        return root;
    }

    //If the ID being searched for is less than the current leaf, search the left subtree
    if (searchID < root->ID) {
        root->leftChild = recursiveRemoveLeaf(root->leftChild, searchID);
    }

    //Else if the ID being searched for is greater than the current leaf, search the right subtree
    else if (searchID > root->ID) {
        root->rightChild = recursiveRemoveLeaf(root->rightChild, searchID);
    }

    //Else, we found the desired node
    else {

        //The root node has no children, free it
        if (root->leftChild == NULL && root->rightChild == NULL) {
            free(root);
            root = NULL;
        }

        //The root node only has a left child
        else if (root->leftChild != NULL && root->rightChild == NULL) {
            
            //Make a temporary pointer to the left child
            leaf* tempLeft = root->leftChild;

            //Free the root
            free(root);
            root = NULL;

            return tempLeft;
        }

        //The root node only has a right child
        else if (root->leftChild == NULL && root->rightChild != NULL) {
            
            //Make a temporary pointer to the right child
            leaf* tempRight = root->rightChild;

            //Free the root
            free(root);
            root = NULL;

            return tempRight;
        }

        //The root node has two children
        else {

            //Find the in-order successor of the node to be deleted
            leaf* successor = iterativeFindSmallest(root->rightChild);

            //Set the node to be deleted to the successor node
            root->ID = successor->ID;

            //Delete the successor node instead
            root->rightChild = recursiveRemoveLeaf(root->rightChild, successor->ID);
        }
    }

    return root;
}



//FUNCTION recursiveSearch
void recursiveSearch(leaf* root, int searchID) {

    //If the end of the tree was reached without finding the desired ID, inform the user
    if (root == NULL) {
        printf("The leaf with ID %d could not be found in the tree.\n", searchID);
        return;
    }

    //If the search ID is less than the current node's, go to the left
    if (searchID < root->ID) {
        recursiveSearch(root->leftChild, searchID);
    }

    //Else if the search ID is greater than the current node's, go to the right
    else if (searchID > root->ID) {
        recursiveSearch(root->rightChild, searchID);
    }

    //Else, the search ID matches the current node's and we found the desired leaf
    else {
        printf("The leaf with ID %d was found in the tree.\n", searchID);
        return;
    }
}
