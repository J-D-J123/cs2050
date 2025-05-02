/**
* Name:         J-D-J123
* Date:         4/25/2025
* File:         lab10.c
* Desc:         uses function pointers for different types of data
*/

#include "lab11.h"

// BST* initBST(GETKEYFUNCTION getKeyDelegate, PRINTDATAFUNCTION printDataDelegate);
// void insertBST(BST* tree, void * data);
// void * getMinimum(BST* tree);
// void * getMaximum(BST* tree);
// void freeBST(BST* tree);
// int getSize(BST * tree);
// void inOrderPrintBST(BST * tree);

// HELPER FUNCTIONs
void inOrderPrintNOW(BSTNode * node);
void freeNodes(BSTNode * node); 

struct _BSTNode {
    void * value; 
    struct _BSTNode * rightNode; 
    struct _BSTNode * leftNode;
};

struct _BST {
    BSTNode * root; 
    int size; 
};

//---------------HELPERS--------------------------------// 
void freeNodes(BSTNode * node) {
    freeNodes(node->leftNode);
    freeNodes(node->rightNode); 
    free(node); 
}

// helper for inOrderPrint
void inOrderPrintNOW(BSTNode * node) {

    if(node != NULL) {
        inOrderPrintNOW(node->leftNode); 
        // printDataDelegate(node->value); 

        // call the function pointer to print the data using the printDataDelegate
        printf("%d ", *(int*)node->value); 

        inOrderPrintNOW(node->rightNode);
    }
}

// ------------- Main Code ----------------------------- // 

BST * initBST(GETKEYFUNCTION getKeyDelegate, PRINTDATAFUNCTION printDataDelegate) {

    if(getKeyDelegate != NULL && printDataDelegate != NULL) {
        BST * tree = (void*)malloc(sizeof(BST)); 

        tree->root = NULL; 
        tree->size = 0; 
        return tree; 
    }
    return NULL; 
}

// void insertBST(BST* tree, void * data) {

//     if(tree == NULL || data == NULL) {
//         return;
//     }

//     BSTNode * newNode = malloc(sizeof(BSTNode));

//     newNode->value = data;
//     newNode->leftNode = NULL;
//     newNode->rightNode = NULL;

//     if (tree->root == NULL) {
//         tree->root = newNode;
//     } else {
//         BSTNode * current = tree->root;
//         BSTNode * parent = NULL;

//         while (current != NULL) {
//             parent = current;
//             if (newNode->value < current->value) {
//                 current = current->leftNode;
//             } else {
//                 current = current->rightNode;
//             }
//         }

//         if (newNode->value < parent->value) {
//             parent->leftNode = newNode;
//         } else {
//             parent->rightNode = newNode;
//         }
//     }
//     tree->size++;
// }

void insertBST(BST* tree, void * data) {

    if(tree == NULL || data == NULL) {
        return;
    }

    BSTNode * newNode = malloc(sizeof(BSTNode));

    newNode->value = data;
    newNode->leftNode = NULL;
    newNode->rightNode = NULL;

    if (tree->root == NULL) {
        tree->root = newNode;
        tree->size = (tree->size) + 1;
        return; 
    } else {
        BSTNode * current = tree->root;
        BSTNode * parent = NULL;

        while (current != NULL) {
            parent = current;
            if (*(int*)newNode->value < *(int*)current->value) {
                current = current->leftNode;
            } else {
                current = current->rightNode;
            }
        }

        if (*(int*)newNode->value < *(int*)parent->value) {
            parent->leftNode = newNode;
        } else {
            parent->rightNode = newNode;
        }
    }
    tree->size = (tree->size) + 1;
}

void * getMinimum(BST * tree) {

    if(tree != NULL && tree->root != NULL) {

        BSTNode * current = tree->root; 
        
        while(current->leftNode != NULL) {
            current = current->leftNode;
        } 

        return current->value; 
    }
    return NULL; 
}

void * getMaximum(BST * tree) {

    if(tree != NULL && tree->root != NULL) {

        BSTNode * current = tree->root; 
        
        while(current->rightNode != NULL) {
            current = current->rightNode;
        } 

        // return the node 
        return current->value;
    }
    return NULL; 
}

int getSize(BST * tree) {

    if(tree != NULL) {
        return tree->size; 
    }
    return 0; 
}

void inOrderPrintBST(BST * tree) {

    if(tree != NULL && tree->root != NULL) {

        inOrderPrintNOW(tree->root); 
    }
}

void freeBST(BST * tree) {

    if(tree != NULL && tree->root != NULL) {

        // freeNodes(tree->root); 
        //free(tree); 

        // first free the nodes
        // without using recursion 
        BSTNode * current = tree->root;
        BSTNode * previous = NULL;

        while (current != NULL) {
            if (current->leftNode != NULL) {
                current = current->leftNode;
            } else if (current->rightNode != NULL) {
                previous = current;
                current = current->rightNode;
            } else {
                free(current);
                if (previous != NULL) {
                    previous->rightNode = NULL;
                }
                current = previous;
            }
            if (current != NULL && current->leftNode == NULL && current->rightNode == NULL) {
                free(current);
                current = NULL;
            }
        }
    }
}
