#include<stdio.h>
#include<stdlib.h>
struct stack
{
    int val;
    struct stack *next;
};

int isfull(struct stack *head)
{
    struct stack *t=malloc(sizeof(struct stack));
    if(t!=NULL)
    {
        free(t);
        return 0;
    }
    else
    return(1);
}

int isempty(struct stack *head)
{
    if(head==NULL)
    return 1;
    else
    return 0;
}

struct stack* push(struct stack *head)
{
    if(isfull(head))
    { 
    printf("Stack full");
    return(head);
    }
    else
    {
        int t;
        printf("Enter the number want to pushed in stack=");
        scanf("%d",&t);
        struct stack *temp=(struct stack*)malloc(sizeof(struct stack));
        temp->val=t;
        temp->next=NULL;
        if(head==NULL)
        head=temp;
        else
        {
            temp->next=head;
            head=temp;
        }
        return(head);
    }
}
struct stack * pop(struct stack *head)
{
       if(head==NULL)
       {
           printf("The stack is empty");
           return(head);
       }
       else
       {
           int t=head->val;
           printf("The poped element=%d",t);
           struct stack *temp;
           temp=head;
           head=head->next;
           free(temp);

           return(head);
      }
}
int main()
{
    int ch=0,c,t;
    struct stack *head=NULL,*h;
    do
    {
         printf("\nMain Menu\n1.Push\n2.Pop\n3.isempty\n4.isfull\n5.To print whole stack");
         int ch;
         scanf("%d",&ch);
         switch(ch)
         {
             case 1:head=push(head);
                    break;
             case 2:head=pop(head);
                    break;
             case 3:t=isempty(head);
                     if(t==1)
                     printf("\nStack Empty");
                     else
                     printf("\nStack not empty");
                     break;
             case 4:t=isfull(head);
                     if(t==1)
                     printf("\nStack Full");
                     else
                     printf("\nStack not Full");
                     break;
            case 5: h=head;
                    while(h!=NULL)
                    {
                        printf("\n%d",h->val);
                        h=h->next;
                    }
                    break;
         }

         printf("\nDo you want to do more operations(1/0)=");
         scanf("%d",&c);
    }while(c==1);
    
   

}
