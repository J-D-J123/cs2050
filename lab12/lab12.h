#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Animal {
    int num_of_legs;
    char name[20];
} Animal;
typedef int (*AnimalCompareFunc)(Animal *a, Animal *b);
typedef struct Heap {
    Animal* data;
    struct Heap *left;
    struct Heap *right;
    int size;
} Heap;
typedef struct HeapInstance {
    Heap* root;
    AnimalCompareFunc cmp;
} HeapInstance;

Animal * create_animal(int legs, const char * name); 
Heap * create_node(Animal * data); 
void insert(HeapInstance * heap, Animal * data); 
Heap * insert_key(Heap * root, Animal * data, AnimalCompareFunc cmp);
void update_size(Heap * node); 
void swap_data(Heap * a, Heap * b); 
void print_level_order(Heap * root); 
int compare_by_legs_min(Animal * a, Animal * b); 
int compare_by_legs_max(Animal * a, Animal * b); 
int compare_by_name_asc(Animal * a, Animal * b); 
int compare_by_name_desc(Animal * a, Animal * b);  
void free_heap(HeapInstance * heap); 
