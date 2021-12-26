#include<stdio.h>
#define n 5
int arr[n];
int rear=-1,front=-1;
void enque(int a)
{
    if(rear==n&&rear!=-1)
    {
        printf("\nQueue full");
    }
    else
    {
        if(rear==-1)
        {
            front=0,rear=0;
            arr[rear++]=a;
        }
        else
        arr[rear++]=a;
    }
}

int deque()
{
    if(rear==-1&&front==-1)
    {
        printf("\nQueue empty");
        return(-10000);
    }
    else
    {
        int t=arr[front++];
        if(rear==front)
        {
            rear=front=-1;
        }
        return(t);
     }
}
int isfull()
{
    if(rear==n)
    return 1;
    else
    return 0;
}
int main()
{
    int ch;
    int c=0,t;
    do{ 
    printf("Main Menu\n1.Enque\n2.Deque");
    scanf("%d",&ch);
    switch (ch)
    {
    case 1: if(!( isfull() ))
            { 
            printf("\nEnter the element to be inserted=");
            scanf("%d",&t);
            enque(t);
            }
            else
            {
                printf("\nQueue full");
            }
            break;
    case 2: t=deque();
             if(t!=-10000)
            printf("The deleted element is =%d",t);
            break;
    default: printf("Wrong Choice");
        break;
    }
    printf("\nDo you want to do more operations=");
    scanf("%d",&c);
    }while(c>=1);
}
