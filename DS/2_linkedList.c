#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node
{
    char name[50];
    int roll_no;
    struct node *next;
};
struct node *head = NULL;

void insertNode(int roll_no, char name[])
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->roll_no = roll_no;
    strcpy(newNode->name, name);
    newNode->next = head;
    head = newNode;
}

void deleteNode(int roll_no)
{
    if (head == NULL)
    {
        printf("list is empty");
        return;
    }
    if (head->roll_no == roll_no)
    {
        struct node *temp = head;
        head = temp->next;
        free(temp);
        return;
    }

    struct node *temp = head;
    while (temp->next != NULL && temp->next->roll_no != roll_no)
    {
        temp = temp->next;
    }
    if (temp->next == NULL)
    {
        printf("roll no. not found\n");
        return;
    }
    else
    {
        struct node *del = temp->next;
        temp->next = del->next;
        free(del);
    }
}

void reverse()
{
    struct node *prev = NULL, *current = head, *next = NULL;
    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
}

void display()
{
    struct node *temp = head;
    while (temp != NULL)
    {
        printf("NAME : %s, ROLL NO. : %d\n", temp->name, temp->roll_no);
        temp = temp->next;
    }
}
int main()
{
    insertNode(12, "Shoaib");
    insertNode(85, "Khan");
    insertNode(45, "Saab");
    display();

    reverse();
    printf("inverse list : \n");
    display();

    deleteNode(45);
    printf("delete node : \n");
    display();
    return 0;
}