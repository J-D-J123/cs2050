// some code provided by GPT (print and adding code)

#include <stdio.h>
#include <stdlib.h>

typedef struct _heapNode {
    int data;
    struct _heapNode *left;
    struct _heapNode *right;
} heapNode;

typedef struct _Heap {
    heapNode *root;
    int totalSize;
} Heap;

// ============== Helper: Create descending array ==============
void fillDescendingArray(int *array, int size) {
    if (array == NULL || size == 0) return;
    for (int i = 0; i < size; i++) {
        array[i] = size - i;
    }
}

// ============== Helper: Create ascending array ==============
void fillAscendingArray(int *array, int size) {
    if (array == NULL || size == 0) return;
    for (int i = 0; i < size; i++) {
        array[i] = i + 1;
    }
}

int countNodes(heapNode *node) {
    if (node == NULL) return 0;
    return 1 + countNodes(node->left) + countNodes(node->right);
}

void addNodeHelper(heapNode *current, heapNode *newNode) {
    // Base case: insert if left or right is empty
    if (current->left == NULL) {
        current->left = newNode;
    } else if (current->right == NULL) {
        current->right = newNode;
    } else {
        // Count size of left and right subtrees
        int leftCount = countNodes(current->left);
        int rightCount = countNodes(current->right);

        // Recur into the smaller one
        if (leftCount <= rightCount) {
            addNodeHelper(current->left, newNode);
        } else {
            addNodeHelper(current->right, newNode);
        }
    }

    // Bubble up: if child is smaller than parent, swap
    if (current->left && current->left->data < current->data) {
        int temp = current->data;
        current->data = current->left->data;
        current->left->data = temp;
    }
    if (current->right && current->right->data < current->data) {
        int temp = current->data;
        current->data = current->right->data;
        current->right->data = temp;
    }
}

// ============== Min Heap Build ==============
Heap * build_min_heap(int array[], int size) {
    Heap *heap = (Heap *)malloc(sizeof(Heap));
    if (!heap) return NULL;

    heap->root = NULL;
    heap->totalSize = 0;

    for (int i = 0; i < size; i++) {
        heapNode *newNode = (heapNode *)malloc(sizeof(heapNode));
        if (!newNode) continue;

        newNode->data = array[i];
        newNode->left = newNode->right = NULL;

        if (heap->root == NULL) {
            heap->root = newNode;
        } else {
            addNodeHelper(heap->root, newNode);
        }

        heap->totalSize++;
    }

    return heap;
}

void printHeapTree(heapNode *node, int space, char branch) {
    if (node == NULL)
        return;

    const int SPACING = 5;
    printHeapTree(node->right, space + SPACING, '/');

    for (int i = 0; i < space; i++) printf(" ");
    if (branch != ' ') printf("%c", branch);
    printf("%d\n", node->data);

    printHeapTree(node->left, space + SPACING, '\\');
}

void freeHeap(heapNode *node) {
    if (node == NULL) return;

    freeHeap(node->left);
    freeHeap(node->right);
    free(node);
}


int main(void) {
    int size = 14;
    int *array = (int *)malloc(size * sizeof(int));
    if (array == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    fillDescendingArray(array, size);
    printf("Descending Array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    Heap *heap = build_min_heap(array, size);
    if (heap && heap->root) {
        printf("Heap created successfully. Root = %d\n", heap->root->data);
        printf("Heap structure (Root -> Left -> Right):\n");
        printHeapTree(heap->root, 0, ' ');
    } else {
        printf("Heap creation failed\n");
    }

    free(array);

    // free the heap 
    freeHeap(heap->root);
    free(heap); 
    return 0;
} // end of prelab12.c
