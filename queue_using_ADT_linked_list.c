#include<stdlib.h>
#include<stdio.h>
struct queue{
    int val;
    struct queue *next;
};

struct queue *last;
int isfull()
{
    struct queue *t=malloc(sizeof(struct queue));
    if(t==NULL)
    {
        return 1;
    }
    else
    {
        free(t);
        return 0;
    }
}
struct queue* enque(struct queue *head,int a)
{
    if(isfull())
    { 
    printf("queue full");
    return(head);
    }
    else
    {
        struct queue *temp=(struct queue *)malloc(sizeof(struct queue));
        temp->val=a;
        temp->next=NULL;
        if(head==NULL)
        {
            head=temp;
            last=temp;
        }
        else
        {
            last->next=temp;
            last=temp;
        }
        
      return(head);
    }
}
struct queue* deque(struct queue * head)
{
    if(head==NULL)
    {
        printf("Queue empty");
        return(head);
    }
    else
    {   int temp=head->val;
        printf("The deleted element is=%d",temp);
        struct queue *t=head;
        head=head->next;
       // free(t);
        return(head);
    }
}
int main()
{
     int ch;
    int c=0,t;
    struct queue *head=NULL;
    do{ 
    printf("Main Menu\n1.Enque\n2.Deque");
    scanf("%d",&ch);
    switch (ch)
    {
    case 1: if(!( isfull() ))
            { 
            printf("\nEnter the element to be inserted=");
            scanf("%d",&t);
            head=enque(head,t);
            }
            else
            {
                printf("\nQueue full");
            }
            break;
    case 2: head=deque(head);
            break;
    default: printf("Wrong Choice");
        break;
    }
    printf("\nDo you want to do more operations=");
    scanf("%d",&c);
    }while(c>=1);
}
