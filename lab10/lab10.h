
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
typedef struct BSTNode {
int data;
struct BSTNode* left;
struct BSTNode* right;
} BSTNode;
typedef struct BST {
BSTNode* root;
int size;
} BST;
// Function prototypes
BST* initBST();
int insertBST(BST* tree, int data);
int getHeightBST(BST* tree);
int getMinimum(BST* tree);
int getMaximum(BST* tree);
int isValidBST(BST* tree);
void freeBST(BST* tree);
// Optional: Helper prototypes that might be useful
BSTNode* createNode(int data);
BSTNode* insertNode(BSTNode* root, int data, int* success);
int getHeightHelper(BSTNode* node);
int isValidBSTHelper(BSTNode* node, int min, int max);
void freeNodes(BSTNode* node);
