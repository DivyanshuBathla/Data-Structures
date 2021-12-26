#include<stdlib.h>
#include<stdio.h>
#define n 50
char sta[n];
float istac[n];
int top=-1;
int itop=-1;

void ipush(float a)
{
    if(itop==n-1)
    {
        printf("Error!!!");
        exit(1);
    }
    else
    {
        istac[++itop]=a;
    }
}

void push(char a)
{
    if(top==n-1)
    {
        printf("Error!!!");
        exit(1);
    }
    else
    {
        sta[++top]=a;
    }
}
float ipop()
{
    if(itop==-1)
    return('$');
    else
    return(istac[itop--]);
}
char pop()
{
    if(top==-1)
    return('$');
    else
    return(sta[top--]);
}
char see()
{
    if(top==-1)
    return('$');
    else
    return(sta[top]);
}

int main()
{
    char arr[50];
    char con[50];
    int i=0,j=0;
    printf("Enter the expression=");
    scanf("%s",&arr);
    while(arr[i]!='\0')
    {
          char y=see();
          char a=arr[i];
          if((arr[i]>=97&&arr[i]<=122)||(arr[i]>=48&&arr[i]<=57))
          {
               con[j++]=arr[i];
               i++;
          }
          else if(a=='(')
          {
              push('$');
              i++;
          }
          else if(a==')')
          {
              while(y!='$')
              {
                 con[j++]=pop();
                  y=see();
              }
              y=pop();
              i++;
          }
          else if(y=='$')
          {
              push(a);
              i++;
          }
          else if(y=='/'||y=='*'||y=='%')
          {
              con[j++]=pop();
          }
          else if((y=='+'||y=='-')&&(a=='*'||a=='/'||a=='%'))
          {
              push(a);
              i++;
          }
         else if((y=='+'||y=='-')&&(a=='+'||a=='-'))
          {
              con[j++]=pop();
          }
    }
    char y=see();
    while(y!='$')
    {
        con[j++]=pop();
        y=see();
    }
    con[j++]='\0';
    
    printf("%s",con);


  float c,d;
  i=0;
  char x;
   while(con[i]!='\0')
   {
      char a=con[i];
      if(a>=48&&a<=57)
      {
          float x=a-48;
          ipush(x);
          i++;
      }
       else if(a=='+')
      {
          d=ipop();
          c=ipop();
          float t=c+d;
          printf("\n%d",t);
          ipush(t);
          i++;
      }
      else if(a=='-')
      {
          d=ipop();
          c=ipop();
          float t=c-d;
          ipush(t);
          i++;
      }
      else if(a=='*')
      {
          d=ipop();
          c=ipop();
          float t=c*d;
          ipush(t);
          i++;
      }
      else if(a=='/')
      {
          d=ipop();
          c=ipop();
          float t=c/d;
          ipush(t);
          i++;
      }
      else if(a=='%')
      {
          d=ipop();
          c=ipop();
          int e=c;
          int f=d;
          int t=e%f;
          ipush(t);
          i++;
      }

   }

   printf("\nThe result=%.2f",ipop());




}
