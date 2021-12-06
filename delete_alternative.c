/*Program to delete alternative nodes in a given single linked list*/
#include <stdio.h>
#include<stdlib.h>
struct node{
    int val;
    struct node* next;
};
struct node* insert(struct node* head)
{
    struct node* temp=(struct node *)malloc(sizeof(struct node));
    if(temp==NULL)
    {
        printf("\nCant insert");
        return(head);
    }
    int t;
    printf("\nEnter the value=");
    scanf("%d",&t);
    temp->next=NULL;
    temp->val=t;
    if(head==NULL)
    {
        return(temp);
    }
    else
    {
        temp->next=head;
        return(temp);
    }
}


struct node* delete_alt(struct node* head)
{
    if(head==NULL)
    return(head);
      struct node * tem=head;
      struct node *prev=head;
    int count=0;
    while(head!=NULL)
    {
        if(count%2!=0)
        {
        
            prev->next=head->next;
            struct node * temp=head;
            head=head->next;
            free(temp);
              count++;        
        }
        else
        {
            prev=head;
            head=head->next;
            count++;
        }
    }
    return(tem);
}


void display(struct node* temp)
{
    while(temp!=NULL)
    {
        int t=temp->val;
        printf("%d ",t);
        temp=temp->next;
    }
}
int main()
{
    int ch,c;
    struct node *head=NULL;
    do{
    printf("MAin menu\n1.insert\n2.delete alterntive nodes\n3.display");
    scanf("%d",&ch);
    switch(ch)
    {
      case 1:head=insert(head);
             break;
      case 2:head=delete_alt(head);
              break;
      case 3: display(head);
             break;
      default:printf("\nWrong choice|||");
    }
    printf("\nWanna to do more operations(1/0)");
    scanf("%d",&c);
    }while(c==1);
    
}

