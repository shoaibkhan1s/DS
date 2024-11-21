#include <stdio.h>
#define MAX 10

int arr[MAX];
int top1 = -1; // Top pointer for Stack 1
int top2 = MAX; // Top pointer for Stack 2

// Push into Stack 1
void push1(int data) {
    if (top1 < top2 - 1) {
        top1++;
        arr[top1] = data;
    } else {
        printf("Stack Overflow for Stack 1!\n");
    }
}

// Push into Stack 2
void push2(int data) {
    if (top1 < top2 - 1) {
        top2--;
        arr[top2] = data;
    } else {
        printf("Stack Overflow for Stack 2!\n");
    }
}

// Pop from Stack 1
int pop1() {
    if (top1 >= 0) {
        return arr[top1--];
    } else {
        printf("Stack 1 is empty!\n");
        return -1;
    }
}

// Pop from Stack 2
int pop2() {
    if (top2 < MAX) {
        return arr[top2++];
    } else {
        printf("Stack 2 is empty!\n");
        return -1;
    }
}

// Display Stack 1
void display1() {
    if (top1 == -1) {
        printf("Stack 1 is empty!\n");
        return;
    }
    printf("Stack 1: ");
    for (int i = 0; i <= top1; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Display Stack 2
void display2() {
    if (top2 == MAX) {
        printf("Stack 2 is empty!\n");
        return;
    }
    printf("Stack 2: ");
    for (int i = top2; i < MAX; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    // Push elements into both stacks
    push1(10);
    push1(20);
    push1(30);

    push2(40);
    push2(50);
    push2(60);

    printf("After pushing elements:\n");
    display1();
    display2();

    // Pop elements from both stacks
    printf("Popped from Stack 1: %d\n", pop1());
    printf("Popped from Stack 2: %d\n", pop2());

    printf("After popping elements:\n");
    display1();
    display2();

    return 0;
}
