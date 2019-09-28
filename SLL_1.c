#include <stdio.h>
#include <stdlib.h>


typedef struct Node
{
    int data;
    struct Node* next;
}Node;
typedef struct Node node;
 node* Get_node();
 node* create_SLL(int);
 void display(node*);

 node* Get_node()
 {

     node* temp;
     temp=(node*)malloc(sizeof(node));
     printf("Enter data of node::\n");
     scanf("%d",&temp->data);
     temp->next=NULL;
     return ;
}

node* create_SLL(int no)
{
    int i;
   node *head,*q,*temp;
   head=q=NULL;


   for(i=0;i<no-1;i++)
   {
        temp=Get_node();
        if(head==NULL)
        {
            head=temp;
            q=head;
        }
        else
        {
           q->next=temp;
           q=q->next;
        }

   }
    return head;

}

void display(node *head)
{
if(head==NULL)
{
    printf("\nList is EMPTY!\n");
}
    while(head!=NULL)
    {
        printf("|%d|->",head->data);
        head=head->next;
    }
}

int main()
{
    int i,ch,no;
    node* head,temp;
    printf("Enter No of nodes::\n");
    scanf("%d",&no);

    head=create_SLL(no);
    display(head);


    return 0;
}
