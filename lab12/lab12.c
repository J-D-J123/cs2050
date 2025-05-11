/**
* Name:     J-D-J123
* File:     lab12.c
* Class:    cs2050 
* Desc:     Expand your understanding of Heaps 
*
*/

#include "lab12.h"

// make these functions: :(
// Animal * create_animal(int legs, const char * name); 
// Heap * create_node(Animal * data); 
// void insert(HeapInstance * heap, Animal * data); 
// Heap * insert_key(Heap * root, Animal * data, AnimalCompareFunc cmp);
// void update_size(Heap * node); 
// void swap_data(Heap * a, Heap * b); 
// void print_level_order(Heap * root); 
// int compare_by_legs_min(Animal * a, Animal * b); 
// int compare_by_legs_max(Animal * a, Animal * b); 
// int compare_by_name_asc(Animal * a, Animal * b); 
// int compare_by_name_desc(Animal * a, Animal * b);  
// void free_heap(HeapInstance * heap); 

int countNodes(Heap * node); 
void freeHeap(Heap * node); 

// --------------------------------------------------- HELPER FUNCTIONs // 
int countNodes(Heap * node) {

    if(node == NULL) {
        return 0; 
    }

    return 1 + countNodes(node->left) + countNodes(node->right); 
}

void freeHeap(Heap * node) {

    if(node == NULL) {
        return; 
    }

    freeHeap(node->left); 
    freeHeap(node->right); 
    free(node->data); 
    free(node); 
}

Animal * create_animal(int legs, const char * name) {

    if (name == NULL) {
        return NULL; 
    }

    Animal * animal = (Animal*)malloc(sizeof(Animal)); 
    if(animal) {

        animal->num_of_legs = legs; 
        strcpy(animal->name, name); 
        
        return animal;
    } else {
        return NULL; 
    }

}

// Creates a Heap node with the given Animal data that was created and returns a pointer to a Heap
// struct, or NULL on failure.
Heap * create_node(Animal * data) {

    if(data == NULL) {
        return NULL; 
    }

    Heap * heap = (Heap *)malloc(sizeof(Heap)); 
    if(heap) {

        heap->data = data;
        heap->left = NULL; 
        heap->right = NULL; 
        heap->size++;

        return heap; 
    }

    return NULL; 
}

// inserts the Animal data into the heap using the insert_key helper function 
void insert(HeapInstance * heap, Animal * data) {

    if(heap == NULL || data == NULL) {
        return; 
    }

    // printf("creating newNode\n"); 
    Heap * newNode = create_node(data); 
    if(newNode) {
        newNode->data = data; 
        newNode->right = NULL;
        newNode->left = NULL; 

        // printf("newNode created aka Heap\n");
    } else {
        return; 
    }

    // printf("going to the heap looking to insert...\n");
    
    if(heap->root == NULL) {

        // printf("    adding to root\n");
        heap->root = newNode; 

        update_size(heap->root); 
    } else if(heap->root->left == NULL) {
        // printf("    adding to left\n");

        heap->root->left = newNode; 

        update_size(heap->root); 
    } else if(heap->root->right == NULL) {
        // printf("    adding to right\n");

        heap->root->right = newNode; 

        update_size(heap->root); 
    } else {

        // insert somewhere else in the heap 
        // printf("    adding to SOMWHERE\n");
        insert_key(heap->root, newNode->data, compare_by_legs_min); 
        update_size(heap->root); 
    }
}


// recusive function that inserts the data into the heap 
// based on Animal CompareFunc which determins max-heap or min heap 
// returns the root node of the heap and NULL on failure 
Heap * insert_key(Heap * root, Animal * data, AnimalCompareFunc cmp) {

    // should use that algorithm to insert the data into the heap
    if(root == NULL || cmp == NULL || data == NULL) {
        return NULL; 
    }


    // already checks for NULL checks so no point in checking again 
    int leftCount = countNodes(root->left); 
    int rightCount= countNodes(root->right); 

    // left and right are NULL 
    if(leftCount == 0) {
        root->left = create_node(data); 
        return root; 
    } else if(rightCount == 0) {
        root->right = create_node(data); 
        return root; 
    }

    // make the Heap balanced 
    if(leftCount <= rightCount) {
        root->left = insert_key(root->left, data, cmp); 
    } else {
        root->right = insert_key(root->right, data, cmp); 
    }
    if(cmp(data, root->data)) {
        swap_data(root, root->left); 
    } else if(cmp(data, root->data)) {
        swap_data(root, root->right); 
    }
    update_size(root);
    return root;
}

// updates the size (number of nodes of the subtree) of the Heap node
// invoked during the insert_key (helper func)
void update_size(Heap * node) {

    if(node == NULL) {
        return; 
    } else {

        int size = countNodes(node); 
        node->size = size; 
    }
}

// This function swaps the Heap node pointers 
void swap_data(Heap * a, Heap * b) {

    // swap the data of the two nodes
    Animal * temp = a->data;
    a->data = b->data;
    b->data = temp;

    // swap the left and right pointers
    Heap * tempLeft = a->left;
    a->left = b->left;
    b->left = tempLeft;

    Heap * tempRight = a->right;
    a->right = b->right; 
    b->right = tempRight; 

    // swap the size of the two nodes
    int tempSize = a->size;
    a->size = b->size;
    b->size = tempSize;
}

// prints level order
void print_level_order(Heap * root) {

    if(root == NULL) {
        return; 
    }

    // print the root node 
    printf("(%d, %s)", root->data->num_of_legs, root->data->name); 

    // print the left and right nodes 
    print_level_order(root->left); 
    print_level_order(root->right); 
    printf("\n");
}


// use for min-heap based on legs
// function returns 1 if the number of legs for 'a' less than 'b' 
// and 0 otherwise 
// Must be passed to the function pointer AnimalCompareFunc cmp
int compare_by_legs_min(Animal * a, Animal * b) {

    if(a == NULL || b == NULL) {
        return 0; 
    }

    if(a->num_of_legs < b->num_of_legs) {
        return 1; 
    }

    return 0;
}

// use for min-heap based on legs
// function returns 1 if the number of legs for 'a' greater than 'b' 
// and 0 otherwise 
// Must be passed to the function pointer AnimalCompareFunc cmp
int compare_by_legs_max(Animal * a, Animal * b) {

    if(a == NULL || b == NULL) {
        return 0; 
    }

    if(a->num_of_legs > b->num_of_legs) {
        return 1; 
    }

    return 0;
}

// use for min-heap based on legs
// function returns 1 if the name for 'a' is less than 'b' 
// and 0 otherwise 
// Must be passed to the function pointer AnimalCompareFunc cmp
int compare_by_name_asc(Animal * a, Animal * b) {

    if(a == NULL || b == NULL) {
        return 0; 
    } else {

        if(strcmp(a->name, b->name) < 0) {
            return 1; 
        }
    }

    return 0;
}

// use for min-heap based on legs
// function returns 1 if the name for 'a' is greater than 'b' 
// and 0 otherwise 
// Must be passed to the function pointer AnimalCompareFunc cmp
int compare_by_name_desc(Animal * a, Animal * b) {

    if(a == NULL || b == NULL) {
        return 0; 
    } else {

        if(strcmp(a->name, b->name) > 0) {
            return 1; 
        }
    }

    return 0;
}

// Frees all memory used by the HeapInstance and Heap nodes 
void free_heap(HeapInstance * heap) {

    freeHeap(heap->root); 
    free(heap); 
    heap = NULL; 
} // end of lab12.c
