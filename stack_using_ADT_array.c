#include<stdio.h>
#define n 5
int arr[n];
int top=-1;
int push()
{
    if(top==n-1)
    { 
    printf("\nStack full");
    return -1;   //just a variable to see operation success or failure
    }
    else
    {
       int a;
       printf("\nEnter the element to be pushed=");
       scanf("%d",&a);
       arr[++top]=a;
       return 1;   //just a variable to see operation success or failure
    }
}

int pop()
{
    if(top==-1)
    {
        printf("\nStack empty");
        return -100000;
    }
    else
    {
        int temp=arr[top--];
        return(temp);
    }
}
int isempty()
{
    if(top==-1)
    return 1;
    else 
    return -1;
}
int isfull()
{
    if(top==n-1)
    return 1;
    else 
    return -1;
}
int main()
{
    int ch=0,c,t;
    do
    {
         printf("\nMain Menu\n1.Push\n2.Pop\n3.isempty\n4.isfull");
         int ch;
         scanf("%d",&ch);
         switch(ch)
         {
             case 1:t=push();
                    break;
             case 2: t=pop();
                    if(t!=-100000)
                    printf("\nThe poped element is=%d",t);
                    break;
             case 3:t=isempty();
                     if(t==1)
                     printf("\nStack Empty");
                     else
                     printf("\nStack not empty");
                     break;
             case 4:t=isfull();
                     if(t==1)
                     printf("\nStack Full");
                     else
                     printf("\nStack not Full");
                     break;
         }

         printf("\nDo you want to do more operations(1/0)=");
         scanf("%d",&c);
    }while(c==1);
    
   

}
