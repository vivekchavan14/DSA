//DOUBLYLINKEDLIST (All operations)

#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *rlink;
    struct node *llink;
};

typedef struct node *NODE;

NODE getnode()
{
    NODE newnode;
    newnode=(NODE)malloc(sizeof(struct node));
    if(newnode==NULL)
    {
        printf("Memory not allocated\n");
        exit(0);
    }
    printf("Enter data\n");
    scanf("%d",&newnode->data);
    newnode->rlink=NULL;
    newnode->llink=NULL;\
    return newnode;
}

//Insert at end
NODE insert_end(NODE head)
{
    NODE newnode,current;
    newnode=getnode();
    if(head==NULL)
    {
        head=newnode;
    }
    else
    {
        current=head;
        while(current->rlink!=NULL)
        {
            current=current->rlink;
        }
        current->rlink=newnode;
        newnode->llink=current;
    }
    return head;
}

//Insert at begining
NODE insert_front(NODE head)
{

    NODE newnode=getnode();
    if(head==NULL)
    {
        head=newnode;
    }
    else
    {
        newnode->rlink=head;
        head->llink=newnode;
        head=newnode;
    }
    return head;
}

NODE delete_end(NODE head)
{
    NODE prev,current;
    if(head==NULL)
    {
        printf("List is empty\n");
    }
    else if(head->rlink==NULL)
    {
        printf("DELETED=%d",&head->data);
        free(head);
        head=NULL;
    }
    else
    {
        current=head;
        while(current->rlink!=NULL)
        {
            current=current->rlink;
        }
        prev=current->llink;
        prev->rlink=NULL;
        current->llink=NULL;
        printf("DELETED=%d",&current->data);
        free(current);
    }
    return head;
}

NODE delete_front(NODE head)
{
    NODE current;
    if(head==NULL)
    {
        printf("List is empty\n");
    }
    else if(head->rlink==NULL)
    {
        printf("DELETED=%d",&head->data);
        free(head);
        head=NULL;
    }
    else
    {
        current=head;
        head=head->llink;
        head->llink=NULL;
        current->rlink=NULL;
        free(current);
    }
    return head;
}

void display(NODE head)
{
    NODE current;
    if(head==NULL)
    {
        printf("LIST IS EMPTY\n");
    }
    else
    {
        current=head;
        while(current!=NULL)
        {
            printf("%d",&current->data);
            current=current->rlink;
        }
        printf("\n");
    }
}

//Display reverse
void display_rev(NODE head)
{
    NODE current;
    if(head==NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        current=head;
        while(current->rlink!=NULL)
        {
            current=current->rlink;
        }
        while(current!=NULL)
        {
            printf("%d",&current->data);
            current=current->llink;
        }
        printf("\n");
    }
}

int count(NODE head)
{
    int count=0;
    NODE current;
    if(head==NULL)
    {
        return count;
    }
    else
    {
        current=head;
        while(current!=NULL)
        {
            count++;
            current=current->rlink;
        }
    }
    return count;
}

void search(NODE head)
{
    int key,status;
    NODE current;
    printf("Enter key to be searched\n");
    scanf("%d",&key);
    if(head==NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        current=head;
        while(current!=NULL)
        {
            if(current->data==key)
            {
                status=1;
                break;
            }
            else
            {
                status=0;
                break;
            }

        }
        if(status==1)
        {
            printf("Key found %d\n",key);
        }
        else
        {
            printf("Key not found\n");
        }
    }
}

NODE search_and_delete(NODE head)
{
    NODE current,prev,temp;
    int key;
    if(head==NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        current=head;
        while(current->rlink!=NULL)
        {
            if(current->data==key)
            {
                prev->rlink=current->llink;
                temp=current;
                current=current->rlink;
                current->llink=prev;
                printf("DELETED=%d",&temp);
                free(temp);
                prev=prev->llink;
                current=current->llink;
            }
            else
            {
                printf("Key not found\n");
            }
            current=current->rlink;

        }
    }
}

int main(){
    int k,ch;
    NODE head=NULL;
    while(1){
        printf("Enter your choice\n");
        scanf("%d",&ch);
        switch(ch){
            case 1: head = insert_end(head);
                    break;
            case 2: head = insert_front(head);
                    break;
            case 3: display(head);
                    break;
            case 4: display_rev(head);
                    break;
            case 5: head = delete_end(head);
                    break;
            case 6: head = delete_front(head);
                    break;
            case 7: search(head);
                    break;
            case 8: head = search_and_delete(head);
                    break;
            case 9: k=count(head);
                    printf("Nodes : %d",k);
                    break;
            case 10: exit(0);
                    break;
            default: printf("Invalid choice\n");
                    break;
        }
    }
    return 0;
}
