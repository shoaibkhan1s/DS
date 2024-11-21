#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct college
{
    int id;
    char name[100];
    struct college *next;
};

struct college *head = NULL;
void insert(int id,char name[100]){
       struct college *newNode = (struct college *)malloc(sizeof(struct college));
       newNode->id =id;
       strcpy(newNode->name, name);

       if (head==NULL)
       {
        newNode->next = newNode;
        head= newNode;
       }
       else{
        struct college *temp=head;
        while (temp->next!=head)
        {
            temp =temp->next;
        }
        temp->next = newNode;
        newNode->next=head;
        head=newNode;  
       }
}
       void delete(){
        if (head==NULL)
        {
            printf("list is empty\n");
            return;
        }
        struct college *temp = head;
        while (temp->next->next!=head)
        {
            temp=temp->next;
        }
        struct college *last = temp->next;
        temp->next=head;
        free(last);
        printf("last node deleted successfully\n");
       }

        void display(){
            struct college *temp=head;
           do
            {
                printf("id : %d, College : %s\n", temp->id,temp->name);
                temp=temp->next;
            }while (temp!=head);
            
        }

        int main(){
            insert(101,"MAIT");
            insert(102,"AMU");
            insert(103,"GGSIPU");

            printf("list is : \n");
            display();

            delete();
            display();


        }
    
 