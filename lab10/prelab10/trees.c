/**
  * Author:    J-D-J123
  * Date:      4/16/2025
  * File:      trees.c 
  * Desc:      Tree data structure with Records and a RecordDB
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Record {

    int key; 
    struct Record *left; 
    struct Record *right;
} Record; 

typedef struct RecordDB {

    Record *root; 
    int numRecords; 
    int errorCode; 
} RecordDB;

RecordDB initializeRecordDB(); // allocate memory for the RecordDB structure
RecordDB addRecord(Record *, RecordDB); // add a record to the RecordDB
int countRecordsInRange(int min, int max, RecordDB); // count records within a range
void freeRecordDB(RecordDB); // free the RecordDB structure
int getDatabaseErrorCode(RecordDB); // get the error code from the RecordDB


// helper METHOD
void freeTree(Record *treeNode); // free the binary tree recursively

RecordDB initializeRecordDB() {

    // no NULL test cases because no @param 

    RecordDB db; 

    db.root = NULL; 
    db.numRecords = 0; 
    db.errorCode = 0; 
    return db; 
}

RecordDB addRecord(Record *newRecord, RecordDB db) {
    if (newRecord == NULL) {
        db.errorCode = 1; // null input
        return db;
    }

    newRecord->left = NULL;
    newRecord->right = NULL;

    if (db.root == NULL) {
        // First record becomes the root
        db.root = newRecord;
        db.numRecords++;
        return db;
    }

    Record *current = db.root;
    Record *parent = NULL;

    while (current != NULL) {
        parent = current;
        if (newRecord->key < current->key) {
            current = current->left;
        } else if (newRecord->key > current->key) {
            current = current->right;
        } else {
            // Duplicate key
            db.errorCode = 2;
            return db;
        }
    }

    // Insert the new node at the correct spot
    if (newRecord->key < parent->key) {
        parent->left = newRecord;
    } else {
        parent->right = newRecord;
    }

    db.numRecords++;
    return db;
}


void freeRecordDB(RecordDB db) {

    printf("Attempting to free RecordDB...\n");
    if(db.root == NULL) {
        printf("RecordDB is already empty.\n");
        return; 
    }

    // Free the RecordDB
    freeTree(db.root);

    // set it to NULL so user is not able to change it 
    db.root = NULL;
    db.numRecords = 0; 
    db.errorCode = 0; 

    printf("RecordDB freed successfully.\n");
    

}

void freeTree(Record *treeNode) {
    if(treeNode != NULL) {
        freeTree(treeNode->left); 
        freeTree(treeNode->right);

        // free the current node 
        free(treeNode);
    }
}

int main(void) {
    // Tester
    RecordDB db = initializeRecordDB();

    // Dynamically allocate memory for records
    Record *record1 = (Record *)malloc(sizeof(Record));
    record1->key = 10;
    record1->left = NULL;
    record1->right = NULL;

    Record *record2 = (Record *)malloc(sizeof(Record));
    record2->key = 20;
    record2->left = NULL;
    record2->right = NULL;

    Record *record3 = (Record *)malloc(sizeof(Record));
    record3->key = 30;
    record3->left = NULL;
    record3->right = NULL;

    // Add records to the tree
    db = addRecord(record1, db);
    db = addRecord(record2, db);
    db = addRecord(record3, db);

    // Free the RecordDB (which also frees the tree nodes)
    freeRecordDB(db);
    
    return 0; 
} // end of prelab10
