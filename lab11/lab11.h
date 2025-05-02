
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
// You must pass a function of this type to some of the BST functions. The purpose
//of this
// sort of function is to get an integer that represents the "key" for whatever you
// passed in.
// Note the the function you implement will "know" what type the void * really is.
// We use
// void * so your BST can hold ANY data type.
typedef int (*GETKEYFUNCTION)(void *);
// Here is another delegate that allows you to print out whatever is actually
// pointed to
// by the void * in your BST
typedef void (*PRINTDATAFUNCTION)(void *);
// This is a "forward definition". You will want to properly
// define struct _BSTNode in your implementation file (lab11.c)
typedef struct _BSTNode BSTNode;
typedef struct _BST BST;
// Function prototypes
BST* initBST(GETKEYFUNCTION getKeyDelegate, PRINTDATAFUNCTION printDataDelegate);
void insertBST(BST* tree, void * data);
void * getMinimum(BST* tree);
void * getMaximum(BST* tree);
void freeBST(BST* tree);
int getSize(BST * tree);
void inOrderPrintBST(BST * tree);
