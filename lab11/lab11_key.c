#include "lab11.h"

// Structure implementations
struct _BSTNode
{
    void * data;
    BSTNode * left;
    BSTNode * right;
};

struct _BST 
{
    BSTNode * root;
    int size;
    GETKEYFUNCTION GetKey;
    PRINTDATAFUNCTION PrintData;
};

// Helper prototypes
BSTNode* createNode(void * data);
BSTNode* insertNode(BST * tree, BSTNode* root, void * data);
void inOrderPrintBSTWorker(BST * tree, BSTNode * root);
void freeNodes(BSTNode* node);



BST* initBST(GETKEYFUNCTION getKeyDelegate, PRINTDATAFUNCTION printDataDelegate)
{
    BST* tree = (BST*)malloc(sizeof(BST));
    if (!tree) return NULL;
    tree->root = NULL;
    tree->size = 0;
    tree->GetKey = getKeyDelegate;
    tree->PrintData = printDataDelegate;
    return tree;
}

BSTNode* createNode(void * data) 
{
    BSTNode* node = (BSTNode*)malloc(sizeof(BSTNode));
    if (!node) return NULL;
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

BSTNode* insertNode(BST * tree, BSTNode* root, void * data) 
{
    if (!root) 
    {
        BSTNode* newNode = createNode(data);
        if (!newNode) 
        {
            return NULL;
        }
        return newNode;
    }


    if (tree->GetKey(data) < tree->GetKey(root->data))
    {
        root->left = insertNode(tree, root->left, data);
    }
    else if (tree->GetKey(data) >= tree->GetKey(root->data))
    {
        root->right = insertNode(tree, root->right, data);
    }

    return root;
}

void insertBST(BST* tree, void * data)
{
    if (!tree) return;
    tree->root = insertNode(tree, tree->root, data);
    if (NULL!=tree->root) 
    {
        tree->size++;
    }
}

void * getMinimum(BST* tree) 
{
    if (!tree || !tree->root) return NULL;
    BSTNode* current = tree->root;
    while (current->left)
        current = current->left;
    return current->data;
}

void * getMaximum(BST* tree) 
{
    if (!tree || !tree->root) return NULL;
    BSTNode* current = tree->root;
    while (current->right)
        current = current->right;
    return current->data;
}

int getSize(BST * tree)
{
    if (NULL==tree)
    {
        return -1;
    }

    return tree->size;
}

void inOrderPrintBSTWorker(BST * tree, BSTNode * root)
{
    if (NULL!=root)
    {
        inOrderPrintBSTWorker(tree, root->left);
        tree->PrintData(root->data);
        inOrderPrintBSTWorker(tree, root->right);
    }
}

void inOrderPrintBST(BST * tree)
{
    if (NULL==tree || tree->size==0 || tree->root==NULL)
    {
        return;
    }

    inOrderPrintBSTWorker(tree, tree->root);
}

void freeNodes(BSTNode* node) 
{
    if (!node) return;
    freeNodes(node->left);
    freeNodes(node->right);
    free(node);
}

void freeBST(BST* tree) 
{
    if (!tree) return;
    freeNodes(tree->root);
    free(tree);
}
