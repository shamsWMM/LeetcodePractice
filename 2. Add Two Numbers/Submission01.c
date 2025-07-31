#include <stdio.h>
#include <stdlib.h>

// Definition for singly-linked list.
struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode *createNode(int val)
{
    struct ListNode *node = (struct ListNode *)malloc(sizeof(struct ListNode));
    if (!node)
    {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    node->val = val;
    node->next = NULL;
    return node;
}

// Helper function to create a linked list from an array
struct ListNode* createList(int* arr, int size) {
    if (size == 0) return NULL;
    
    struct ListNode* head = createNode(arr[0]);
    struct ListNode* current = head;
    
    for (int i = 1; i < size; i++) {
        current->next = createNode(arr[i]);
        current = current->next;
    }
    
    return head;
}

// Helper function to print the linked list
void printList(struct ListNode* head) {
    struct ListNode* current = head;
    while (current != NULL) {
        printf("%d -> ", current->val);
        current = current->next;
    }
    printf("NULL\n");
}

// Free the entire list to prevent memory leaks
void freeList(struct ListNode *head)
{
    while (head)
    {
        struct ListNode *tmp = head;
        head = head->next;
        free(tmp);
    }
}

struct ListNode *addTwoNumbers(struct ListNode *l1o, struct ListNode *l2o)
{
    struct ListNode h = {0, NULL};
    struct ListNode *t = &h;
    struct ListNode *l1 = l1o;
    struct ListNode *l2 = l2o;
    int c = 0;
    while (l2 || l1 || c)
    {
        int v1 = (l1) ? (*l1).val : 0;
        int v2 = (l2) ? (*l2).val : 0;
        int s = v1 + v2 + c;
        c = s > 9 ? 1 : 0;
        t->next = createNode(s % 10);
        t = t->next;

        if (l1)
            l1 = l1->next;
        if (l2)
            l2 = l2->next;
    }
    return h.next;
}

int main() {
    // Test case 1: 342 + 465 = 807
    int arr1[] = {2, 4, 3};  // represents 342
    int arr2[] = {5, 6, 4};  // represents 465
    
    struct ListNode* l1 = createList(arr1, 3);
    struct ListNode* l2 = createList(arr2, 3);
    
    printf("List 1: ");
    printList(l1);
    printf("List 2: ");
    printList(l2);
    
    struct ListNode* result = addTwoNumbers(l1, l2);
    printf("Result: ");
    printList(result);
    
    freeList(result);
    freeList(l1);
    freeList(l2);
    
    return 0;
}