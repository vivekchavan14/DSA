#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 100
struct stack
{
    int data[SIZE];
    int top;
};
int main()
{
    struct stack * sptr;
    struct stack s[SIZE];
    sptr=&s;
    sptr->top=-1;
    int num,ch;
    while(1)
    {
        printf("1.push 2.pop 3.display 4.peek 5.Exit\n \n");
        printf("Enter choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:printf("Enter the data:");
            scanf("%d",&num);
            push(sptr,num);
            break;
            case 2:num=pop(sptr);
            printf("POPED %d\n",num);
            break;
            case 3:display(sptr);
            break;
            case 4:peek(sptr);
            break;
            case 5:exit(0);
            break;
            default:printf("Enter valid choice\n");
            break;
        }
    }

}

void push(struct stack *sptr, int num)
{
    if(sptr->top==SIZE-1)
    {
        printf("Stack Overflow\n");
    }
    else
    {
        sptr->top++;
        sptr->data[sptr->top]=num;
    }
}

int pop(struct stack *sptr)
{
    int num;
    if(sptr->top==-1)
    {
        printf("Stack underflow\n");
    }
    else
    {
        num=sptr->data[sptr->top];
        sptr->top--;
    }
    return num;
}

void display(struct stack *sptr)
{
    int i;
    if(sptr->top==-1)
    {
        printf("Stack empty\n");
    }
    else
    {
        for(i=sptr->top;i>=0;i--)
        {
            printf("%d ",sptr->data[i]);
        }
        printf("\n");
    }
}

void peek(struct stack *sptr)
{
    int i;
    if(sptr->top==-1)
    {
        printf("Stack empty\n");
    }
    else
    {
        printf("%d",sptr->data[sptr->top]);
    }
}
