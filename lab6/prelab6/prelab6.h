typedef struct linkedListStruct
{
int object;
struct linkedListStruct* next;
} LinkedList;
LinkedList* initializeLinkedList(int*);
LinkedList* insertAtHead(int, LinkedList*, int*);
int getAtIndex(int, LinkedList*);
int getLinkedListLength(LinkedList*);
LinkedList * freeLinkedList(LinkedList*);
void printArrayList(LinkedList*);
