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
 node* Insert_start();
 void Insert_at_mid(node*);
 void Insert_at_end();
 void Delete(node*);
 void reverse(node*);
 node* revert(node*);

 node* Get_node()
 {
     node* temp;
     temp=(node*)malloc(sizeof(node));
     printf("Enter data of node::\n");
     scanf("%d",&temp->data);
     temp->next=NULL;
     return temp;
}

node* create_SLL(int no)
{
    int i;
   node *head,*q,*temp;
   head=q=NULL;


   for(i=0;i<no;i++)
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

 node* Insert_start(node *head)
 {
     node *temp=Get_node();
     temp->next=head;
     head=temp;
     return head;
 }

 void Insert_at_mid(node* head)
 {
     int data_insert;
     node *temp,*q;
     q=head;
     temp=Get_node();
     printf("Enter data after which you want to enter:\n");
     scanf("%d",data_insert);
     while(q->data!=data_insert)
     {
              q=q->next;
     }
     temp->next=q->next;
     q->next=temp;

 }


void Insert_at_end(node *head)
 {
     node *temp=Get_node();
     while(head->next!=NULL)
     {
         head=head->next;
     }
     head->next=temp;


 }

void display(node *head)
{
if(head==NULL)
{
    printf("list is EMPTY!\n");
}
    while(head!=NULL)
    {
        printf("|%d|->",head->data);
        head=head->next;
    }
}

void Delete(node* head)
{
   int Data_del;
   node *q;

   printf("Enter the data which you want to delete:\n");
   scanf("%d",&Data_del);

   while(head->data!=Data_del && head!=NULL)
   {
       q=head;
       head=head->next;

   }
   if(head==NULL)
   {
       printf("Data Not Found\n");
   }
    else
    {
     q->next=head->next;
    }
    free(head);

}

 void reverse(node* head)
 {
     if(head!=NULL)
     {
         reverse(head->next);
         printf("<-|%d|",head->data);

     }
 }

node*revert(node *head)
 {
   node *p,*q,*r;
   p=head->next;
   q=head;
   r=NULL;
   while(q!=NULL)
   {
       q->next=r;
       r=q;
       q=p;
       if(p!=NULL)
       {
         p=p->next;
       }
   }
return r;
 }
int main()
{
    int i,ch,no;
    int ch_insert;
    node* head,temp;
    printf("Enter No of nodes::\n");
    scanf("%d",&no);
    head=create_SLL(no);
        do{
                printf("\n-------------------------------------------------------------------------------------------------------\n");
                printf("\nEnter your choice::\n");
        printf("1.Display node \n Insert node:\n\t 2.Insert at start \n\t 3.Insert in between \n\t 4.Insert at end\n");
        printf("5.Delete node\n 6.Reverse \n 7. Revert \n 8. Exit\n");
        scanf("%d",&ch);
        switch(ch)
        {

        case 1:
            display(head);
            break;

        case 2:

                    head=Insert_start(head);
                    break;
        case 3:
                    Insert_at_mid(head);
                    break;

        case 4:
                    Insert_at_end(head);
                    break;
        case 5:
                   Delete(head);
                   break;
        case 6:
                   reverse(head);

                   break;
        case 7:
                 head=revert(head);
                  display(head);
                 break;
        default:
            printf("\nWrong option\n");
                    break;
            }
      }while(ch!=8);


    return 0;
}
