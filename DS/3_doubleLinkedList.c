#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct employee
{
    int id;
    char name[100];
    struct employee *prev, *next;
};

struct employee *head = NULL;
void insert(int id, char name[100])
{

    struct employee *newNode = (struct employee *)malloc(sizeof(struct employee));
    newNode->id = id;
    strcpy(newNode->name, name);
    newNode->prev = NULL;
    newNode->next = head;

    if (head != NULL)
    {
        head->prev = newNode;
    }
    head = newNode;
}

void delete()
{
    if (head == NULL)
    {
        printf("list is empty\n");
        return;
    }

    struct employee *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    if (temp->prev == NULL)
    {
        head = NULL;
        return;
    }
    else
    {
        temp->prev->next = NULL;
    }
    printf("last node is deleted\n");
}
void display()
{
    struct employee *temp = head;

    while (temp != NULL)
    {
        printf("id : %d,Name : %s\n", temp->id, temp->name);
        temp = temp->next;
    }
}

int main()
{
    printf("list : \n");
    insert(101, "shoaib");
    insert(102, "khan");
    insert(104, "saab");
    display();

    printf("list after deletion : \n");
    delete ();
    display();
}