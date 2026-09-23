#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;=
}

struct Node* getMiddle(struct Node* start, struct Node* end) {
    if(start == NULL)
        return NULL;

    struct Node *slow = start, *fast = start;

    while(fast != end && fast->next != end) {
        fast = fast->next->next;
        slow = slow->next;
    }

    return slow;
}

struct Node* binarySearch(struct Node* start, struct Node* end, int key) {
    if(start == end)
        return NULL;

    struct Node* mid = getMiddle(start, end);

    if(mid == NULL)
        return NULL;

    if(mid->data == key)
        return mid;

    else if(mid->data > key)
        return binarySearch(start, mid, key);
    else    
        return binarySearch(mid->next, end, key);
}

int main() {
    int n, i, value, key;
    struct Node *head = NULL, *tail = NULL, *newNode, *result;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter sorted elements:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &value);
        newNode = createNode(value);

        if(head == NULL) {
            head = newNode;
            tail = head;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    printf("Enter element to search: ");
    scanf("%d", &key);

    result = binarySearch(head, NULL, key);

    if(result != NULL)
        printf("Element found: %d", result->data);
    else
        printf("Element not found");

    return 0;
}