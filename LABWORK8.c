#include <stdio.h>
#include <stdlib.h>

/* NAME: Rishit Agarwal
   REG NO: AP25110070245
*/

struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};

// --- BOB'S DLL: INSERT FRONT ---
// Logic: Each node has two pointers. New nodes are added to the head.
void task1_bob_dll() {
    int N, val;
    struct Node *head = NULL;
    printf("\n--- Task 1: Bob's DLL (Insert Front) ---\n");
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &val);
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = val;
        newNode->prev = NULL;
        newNode->next = head;
        if (head != NULL) head->prev = newNode;
        head = newNode;

        printf("Node Inserted\n");
        struct Node* temp = head;
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

// --- SARAN'S DLL: REMOVE LAST ---
// Logic: Appends to the end and deletes the tail node specifically.
void task2_saran_dll() {
    int n, val;
    struct Node *head = NULL, *tail = NULL;
    printf("\n--- Task 2: Saran's DLL (Remove Last) ---\n");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = val;
        newNode->next = NULL;
        if (head == NULL) {
            newNode->prev = NULL;
            head = tail = newNode;
        } else {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
    }
    if (tail != NULL) {
        struct Node* toDelete = tail;
        if (tail->prev != NULL) {
            tail = tail->prev;
            tail->next = NULL;
        } else head = tail = NULL;
        free(toDelete);
    }
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// --- RAJ'S CLL: INSERT AT POSITION ---
// Logic: Circularly linked nodes. Insertion at any position M.
void task3_raj_cll() {
    int N, val, pos;
    struct Node *head = NULL, *tail = NULL;
    printf("\n--- Task 3: Raj's CLL (Insert at Position) ---\n");
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &val);
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = val;
        if (head == NULL) {
            head = tail = newNode;
            newNode->next = head;
        } else {
            tail->next = newNode;
            newNode->next = head;
            tail = newNode;
        }
    }
    scanf("%d %d", &val, &pos);
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    struct Node* temp = head;
    for (int i = 1; i < pos - 1; i++) temp = temp->next;
    newNode->next = temp->next;
    temp->next = newNode;
    
    temp = head;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

// --- SUPERMARKET CLL: REMOVE LAST ---
// Logic: Circularly linked queue where the tail is removed and head relinked.
void task4_supermarket_cll() {
    int N, val;
    struct Node *head = NULL, *tail = NULL;
    printf("\n--- Task 4: Supermarket Queue (Remove Last) ---\n");
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &val);
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = val;
        if (head == NULL) {
            head = tail = newNode;
            newNode->next = head;
        } else {
            tail->next = newNode;
            newNode->next = head;
            tail = newNode;
        }
    }
    if (N > 1) {
        struct Node* temp = head;
        while (temp->next != tail) temp = temp->next;
        free(tail);
        temp->next = head;
        tail = temp;
    } else if (N == 1) { free(head); head = NULL; }
    
    if (head != NULL) {
        struct Node* temp = head;
        do {
            printf("%d ", temp->data);
            temp = temp->next;
        } while (temp != head);
    }
    printf("\n");
}

int main() {
    task1_bob_dll();
    task2_saran_dll();
    task3_raj_cll();
    task4_supermarket_cll();
    return 0;
}