/**
* Name:     J-D-J123
* Date:     4/11/2025
* Class:    cs2050
* Desc:     Track packages and use binary search + 
*               Hide array size 
*/  

// #include "lab9.h" 

// ------------------------ HELLPER FUNCTION!!! -------------- // 
int binarySearch(Package * array, Package * query, int left, int right) {
    
    if(array == NULL || query == NULL) {
        return -1; 
    }

    if(left > right) {
        return -1; 
    }

    int mid = (left + right) / 2;

    // comapre packages together 
    // a < b : -1 
    // a == b: 0
    // a > b : 1
    int packMid = comparePackages(&array[mid], query); 

    if (packMid == 0) {
        return mid; 
    } else {
        if(packMid < 0) {

            return binarySearch(array, query, mid + 1, right); 
        } else {

            return binarySearch(array, query, left, mid - 1); 
        }
    }
}

/**
* Allocate memory for a dynamic array that holds metadata. 
*   Before the array, store the array size (number
*   of elements) as an int. A pointer to the first 
*   actual element of the array (not the metadata). 
*   Returns NULL if allocation fails
*/
void * createArray(int arraySize, int elementSize) {

    // printf("arraySize: %d elementSize: %d\n", arraySize, elementSize);

    if(arraySize <= 0 || elementSize <= 0) {
        return NULL; 
    }

    // make the array struct is called package 
    Package * packages = (Package*)malloc(arraySize * elementSize + sizeof(int));

    // printf("packages array made\n");
    if(packages != NULL) {

        // printf("storing size %d\n", arraySize); 
        // store the size in -1 
        *(int*)packages = arraySize; 

        // printf("size: %d\n", *((int*)packages));
        return (void *)(packages + 1); 
    } else {
        return NULL; 
    }
}

/**
* Returns the number of elements stored in the array, which is stored just before the start of the array
*   pointer. The input must be a pointer to an array allocated using createArray.
*   O(1)
*/
int arraySize(void * array) {
    if(array == NULL) {
        return 0; 
    } else {
        return *((int*)((Package*)array - 1)); 
    }
}

/**
* Search the sorted array recursively using binary search 
*   (based on deliveryDistance). The index of
*   the matching Package if found; -1 otherwise. 
*   The complexity must be O(log n)
*/
int findPackage(Package * array, Package * query) {

    if (array == NULL || query == NULL) {
        return -1; 
    }

    // called my own helper function for binary search      
    return binarySearch(array, query, 0, arraySize(array) - 1); 
}

/**
* Compares two packages by their deliveryDistance. Returns negative if a < b, returns zero if a ==
*   b, and returns positive if a > b. The complexity must be O(1).
*/
int comparePackages(Package *a, Package *b) {

    if (a == NULL || b == NULL) {
        return 0; 
    } 

    if(a->deliveryDistance < b->deliveryDistance) {
        return -1; 
    }

    if(a->deliveryDistance > b->deliveryDistance) {
        return 1; 
    }

    return 0; 
}

void destroyArray(void * array) {
    if(array == NULL) {
        return;
    }

    free((Package*)(array - 1)); 
}
