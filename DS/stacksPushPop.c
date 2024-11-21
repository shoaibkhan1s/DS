#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* top = NULL; // Top of the stack

// Push operation
void push(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = top;
    top = newNode;
    printf("%d pushed onto the stack.\n", value);
}

// Pop operation
void pop() {
    if (top == NULL) {
        printf("Stack is empty! Nothing to pop.\n");
        return;
    }
    struct Node* temp = top;
    printf("%d popped from the stack.\n", top->data);
    top = top->next;
    free(temp);
}

// Peek operation
void peek() {
    if (top == NULL) {
        printf("Stack is empty! No top element.\n");
        return;
    }
    printf("Top element is: %d\n", top->data);
}

// Traverse operation
void traverse() {
    if (top == NULL) {
        printf("Stack is empty! Nothing to display.\n");
        return;
    }
    struct Node* temp = top;
    printf("Stack elements: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    push(10);
    push(20);
    push(30);
    
    traverse();

    peek();

    pop();

    traverse();

    return 0;
}
