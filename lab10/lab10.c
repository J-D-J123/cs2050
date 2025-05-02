/**
* Name:         J-D-J123 
* Date:         4/18/2025
* File:         lab10.c
* Desc:         creates a tree BST 
*/

#include "lab10.h"

// ---------------------------- HELPER FUNCS ----------------------- // 
// frees the tree node by node O(N)
void freeNodes(BSTNode* node) {
    if (node != NULL) {
        freeNodes(node->left); 
        freeNodes(node->right); 

        // free the node
        free(node); 
    }
    return; 
}

BSTNode* createNode(int data) {

    BSTNode * treeNode = malloc(sizeof(BSTNode*)); 

    if(treeNode) {

        treeNode->data = data; 
        treeNode->left = NULL; 
        treeNode->right = NULL; 

        return treeNode; 
    }

    return (BSTNode*) NULL; 
}
 
// flatten the tree into a single array 
int flatten(BSTNode * node, int * array, int index) {

    if(node == NULL) {
        return index; 
    }

    index = flatten(node->left, array, index); 
    array[index] = node->data; 
    index = flatten(node->right, array, index+1); 
    return index; 
} // pretty sure this has a seg fault :(

// helper function for the height of the tree 
int getHeightHelper(BSTNode* node) {
    if(node == NULL) {
        return -1; 
    }

    int leftHeight = getHeightHelper(node->left); 
    int rightHeight= getHeightHelper(node->right); 

    if(leftHeight > rightHeight) {
        return leftHeight + 1; 
    } else {
        return rightHeight + 1; 
    }
}

// ------------------------- END OF HELPERS ----------------------------------- //

// initalizes the tree BST. O(1)
BST * initBST() {

    BST * bst = malloc(sizeof(BST*)); 

    if(bst) {
        bst->root = NULL; // pointer to root of tree
        bst->size = 0; // int 

        return bst; 
    } else {

        // malloc fails so return 
        return NULL; 
    }
}

// insertBST inserts a new int into the BST. 
// returns 0 on success, 1 on failure. O(Log N)
int insertBST(BST* tree, int data) {

    if(tree == NULL) {
        return 1; 
    }

    BSTNode * bstN = createNode(data); 

    if(bstN) {
        bstN->data  = data; 
        bstN->right = NULL; 
        bstN->left  = NULL; 

        // if root == NULL = first BSTNode
        if(tree->root == NULL) {
            tree->root = bstN; 
            tree->size++;
            return 0; 
        }

        // if root not NULL 
        BSTNode *current = tree->root; 
        BSTNode *parent  = NULL; 

        while(current != NULL) {

            parent = current; 
            if(bstN->data < current->data) {
                current = current->left; 
            } else if (bstN->data > current->data) {
                current = current->right; 
            } else {
                // Duplicate key return error 
                return 1; 
            }
        }

        // Insert the new node 
        if(data < parent->data) {
            parent->left = bstN; 
        } else {
            parent->right = bstN; 
        }

        tree->size++; 
        return 0; 
    } else {

        // malloc fails 
        return 1; 
    }
}

// returns the height of the BST
// Height is defined as the number of edges in the longest path 
// from the root to a leaf
int getHeightBST(BST * tree) {

    if(tree == NULL) {
        return 0; 
    }

    return getHeightHelper(tree->root); 
}

// getMinimum O(Log N)
// goes to the leftmost path form the rootNode 
// returns -1 if the tree is NULL or empty
int getMinimum(BST * tree) {

    if(tree == NULL || tree->root == NULL) {
        return -1; 
    }

    BSTNode * current = tree->root; 

    // loop through the left side while not NULL 
    while(current->left != NULL) {
        current = current->left; 
    }

    return current->data; 
}

// this function returns the max value stored in the rightmost path.
// returns -1 if the tree is NULL or empty 
int getMaximum(BST * tree) {

    if(tree == NULL || tree->root == NULL) {
        return -1; 
    }

    BSTNode * current = tree->root; 

    // just like the get min but on the right side loop 
    while(current->right != NULL) {
        current = current->right; 
    }

    return current->data; 
}

// checks the tree to see if its a valid binary search tree (BST)
// - Every node in the left subtree only contains values less than 
// - Every node in the right subtree only contains values greater than
// O(N)
int isValidBST(BST * tree) {

    if(tree == NULL || tree->root == NULL) {
        return 0;
    }

    // BSTNode * node = tree->root; 

    // return isValidBSTHelper(node, getMinimum(tree), getMaximum(tree)); 

    // flatten the tree then see if the array is increasing or decreasing 
    int size = tree->size; 
    int * array = malloc(sizeof(int) * size); 

    if(array == NULL) {
        return 0; 
    }
    
    int index = flatten(tree->root, array, 0); 
    if(index != size) {
        free(array); 
        return 0; 
    }

    // loop through the array to see if its in order 
    for(int i = 0; i < size; i++) {
        if(array[i] > array[i+1]) {
            free(array); 
            return 0; 
        }
    }
    return 1; 
}

// frees the tree O(N)
void freeBST(BST * tree) {

    if(tree == NULL || tree->root == NULL) {
        return; 
    }

    freeNodes(tree->root); 
} // end of lab10.c        
