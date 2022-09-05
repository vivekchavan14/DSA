//SINGLY LINKED LIST (all operations)

#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *link;
};

typedef struct node *NODE;

NODE getnode()
{
    NODE newnode;
    newnode=(NODE)malloc(sizeof(struct node));
    if(newnode==NULL)
    {
        printf("Memory not allocated\n");
    }
    else
    {
        printf("Enter data\n");
        scanf("%d",&newnode->data);
        newnode->link=NULL;
    }
      return newnode;
}

//Insert at end
NODE insert_end(NODE head)
{
    NODE current,newnode;
    newnode=getnode();
    if(head==NULL)
    {
        head=newnode;
    }
    else
    {
        head=current;
        while(current->link!=NULL)
        {
            current=current->link;
        }

    current->link=newnode;
    }
return head;
}

//Insert at begining
NODE insert_front(NODE head)
{
    NODE newnode = getnode();
    if(head==NULL)
    {
        head = newnode;
    }
    else
    {
        newnode->link=head;
        head=newnode;
    }
    return head;
}

//To insert at any position
//count number of nodes
int count_nodes(NODE head)
{int count=0;
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
            current=current->link;
        }
    }
    return count;
}

NODE insert_pos(NODE head)
{
    int pos;
    NODE current,prev,newnode;
    newnode=getnode();
    int count=count_nodes(head);
    printf("Enter position\n");
    scanf("%d",&pos);
    if(pos==1 && head==NULL)
    {
        head=newnode;
    }
    else if(pos==1)
    {
        newnode->link=head;
        head=newnode;
    }
    else if(pos=count+1)
    {
        current=head;
        while(current->link!=NULL)
        {
            current=current->link;
        }
        current->link=newnode;
    }
    else if(pos>1 && pos<=count)
    {
        for(int i=1;i<pos-1;i++)
        {
            prev=current;
            current=current->link;
        }
        prev->link=newnode;
        newnode->link=current;
    }
    else
    {
        printf("Invalid position");
    }
    return head;
}

//Delete node at begining
NODE delete_front(NODE head)
{
        NODE current;
        if(head==NULL)
        {
            printf("List is empty");
        }
        else
        {
            current=head;
            head=head->link;
            current->link=NULL;
            printf("deleted=%d",&head->data);
            free(current);
        }
}

//Delete node at end
NODE delete_end(NODE head)
{
    NODE prev,current;
    if(head==NULL)
    {
        printf("List is empty");
    }
    else
    {
        current=head;
        prev=NULL;
        while(current->link!=NULL)
        {
            prev=current;
            current=current->link;
        }
        prev->link=NULL;
        printf("deleted=%d",&current->data);
        free(current);
    }
}

//Delete at any position
NODE delete_pos(NODE head)
{
    int pos;
    NODE current,prev;
    int count=count_nodes(head);
    if(head==NULL)
    {
        printf("List empty");
    }
    else if(pos==1 && head->link==NULL)
    {
        free(head);
        head=NULL;
    }
    else if(pos==1)
    {
        current=head;
        head=head->link;
        current->link=NULL;
        free(current);
    }
    else if(pos=count)
    {
        current=head;
        prev=NULL;
        while(current->link!=NULL)
        {
            prev=current;
            current=current->link;
        }
        prev->link=NULL;
        free(current);
    }
    else if(pos>1 && pos<count)
    {
        prev=NULL;
        current = head;
        for(int i=1;i<pos-1;i++)
        {
            prev=current;
            current=current->link;
        }
        prev->link=NULL;
        free(current);
    }
    else
    {
        printf("Invalid position");
    }
}

//Search & delete
NODE search_and_delete(NODE head)
{
    NODE prev,current;
    int status=0,key;
    printf("key to be fount and deleted is");
    scanf("%d",&key);
    if(head==NULL)
    {
        printf("Empty list");
    }
    else if(head->data=key)
    {
        free(head);
        head=NULL;
    }
    else
    {
        prev=NULL;
        current=head;
        while(current->link=NULL)
        {
            if(current->data=key)
            {
                status=1;
                break;
            }
            prev=current;
            current=current->link;
        }
        prev->link=current->link;
        free(current);
    }
}

//To search node
void search(NODE head)
{
    NODE current;
    int status=0,key;
    printf("Enter key to be found\n");
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
            if(current->data=key)
            {
                status=1;
                break;
            }
            current=current->link;
        }
    }
        if(status==1)
        {
            printf("Key found\n");
        }
        else
        {
            printf("Key not found\n");
        }
}

void display(NODE head)
{
    NODE current;
    if(head==NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        current=head;
        while(current!=NULL)
        {
            printf("%d",&current->data);
            current=current->link;
        }
    }
}


int main()
{
    NODE head;
    head=NULL;
    int ch,count;
    while(1){
        printf("\n");
        printf("1.Insert End 2.Insert front 3.Insert position 4.Delete front 5.Delete end 6.Display 7.Countnodes 8.Delete position 9.Search nodes 10.Search and delete 11.Exit\n\n");
        printf("Enter your choice \n\n");
        scanf("%d",&ch);
        switch(ch){
            case 1: head=insert_end(head);
                    break;
            case 2: head = insert_front(head);
                    break;
            case 3: head = insert_pos(head);
                    break;
            case 4: head= delete_front(head);
                    break;
            case 5: head = delete_end(head);
                    break;
            case 6: display(head);
                    break;
            case 7: count = count_nodes(head);
                    printf("Total Nodes : %d",count);
                    break;
            case 8: head = delete_pos(head);
                    break;
            case 9: search(head);
                    break;
            case 10: search_and_delete(head);
                    break;
            case 11:
                exit(0);
                break;
            default: printf("Invalid choice\n");
                break;

        }
    }
return 0;
}


