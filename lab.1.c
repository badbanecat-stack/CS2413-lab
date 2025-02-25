#include <stdio.h>
#include <stdlib.h>

struct ListNode;
struct ListNode* createList(int arr[], int size);
struct ListNode* removeElements(struct ListNode* head, int val);
void printList(struct ListNode* head);

int main() {
    int arr[] = {1, 2, 6, 3, 4, 5, 6};
    int size = sizeof(arr) / sizeof(arr[0]);
    struct ListNode* head = createList(arr, size);
    printf("Original list:\n");
    printList(head);
    head = removeElements(head, 6);
    printf("After removing 6:\n");
    printList(head);
    return 0;
}

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* createList(int arr[], int size) {
    if (size == 0) return NULL;
    struct ListNode* head = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->val = arr[0];
    head->next = NULL;
    struct ListNode* current = head;
    for (int i = 1; i < size; i++) {
        struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
        node->val = arr[i];
        node->next = NULL;
        current->next = node;
        current = node;
    }
    return head;
}

struct ListNode* removeElements(struct ListNode* head, int val) {
    struct ListNode dummy = {0, head};
    struct ListNode *cur = &dummy;
    while (cur->next) {
        if (cur->next->val == val)
            cur->next = cur->next->next;
        else
            cur = cur->next;
    }
    return dummy.next;
}

void printList(struct ListNode* head) {
    while (head) {
        printf("%d", head->val);
        if (head->next) printf(" -> ");
        head = head->next;
    }
    printf("\n");
}
