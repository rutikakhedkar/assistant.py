#include<stdio.h>
#include <stdlib.h>

struct Node
{
   int data;
   struct Node* next;
   //struct Node* prev;
};

struct Node* head= NULL;

struct Node* create(int value)
{
    struct Node* temp= NULL;
    temp= (struct Node*)malloc(sizeof(struct Node));
    temp->data=value;
    temp->next=NULL;
    return temp;
}

void append()
{
    int value;
    struct Node* temp= NULL;
    struct Node* p= NULL;
    printf("Enter the value");
    scanf("%d",&value);
    temp=create(value);
    if(head==NULL)
    {
       head=temp;
    }
    else
    {
        p=head;
        while(p->next!=NULL)
        {
            p=p->next;
        }
        p->next=temp;
    }
}

void display()
{
    struct Node* temp= head;
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}

void length()
{
    struct Node* temp= head;
    int count=0;
    while(temp!=NULL)
    {
        count++;
        temp=temp->next;
    }
    printf("The length is %d \n",count);
}

void search()
{
    struct Node* temp= head;
    int value;
    printf("Enter the value");
    scanf("%d",&value);
    while(temp!=NULL)
    {
        if(value==temp->data)
        {
            printf("The value is found\n");
            break;
        }
        temp=temp->next;
    }
    if(temp==NULL)
        printf("The value is not found\n");
}

void del()
{
    struct Node* temp;
    struct Node* prev;
    int val;
    temp=head;
    printf("Insert element  to be deleted");
    scanf("%d",&val);
    while(temp!=NULL)
    {
        if(temp->data==val) //check whether the current node is to be deleted or not
        {
            if(head==temp)  //case 1
            {
                head=temp->next;
            }
            else
            {
                prev->next=temp->next;
            }
            free(temp);
            printf("Deletion Successful\n");
            break;
        }
        prev=temp;
        temp=temp->next;
    }
    if(temp==NULL)
        printf("Element not found\n");
}




void insert()
{
    struct Node* temp;
    struct Node* newnode;
    int val, after;
    printf("Enter the value to be inserted");
    scanf("%d",&val);
    printf("Enter the element after which new value to be added");
    scanf("%d",&after);
    newnode=create(val);
    temp=head;
    while(temp!=NULL)
    {
        if(temp->data==after)
        {
            newnode->next=temp->next;
            temp->next=newnode;
            printf("Insertion Successful \n");
            break;
        }
        else
            temp=temp->next;
    }
    if(temp==NULL)
        printf("Insertion Not Successful \n");
}

void reverse()
{
    struct Node* current=head;
    struct Node* prev=NULL;
    struct Node* next=NULL;
    //current=head;
    while(current!=NULL)
    {
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
    }
    head=prev;
    display();
}


void main()
{
    int ch;
    do
    {
        printf("1. Append \n");
        printf("2. Display\n");
        printf("3. Find Length\n");
        printf("4. Search\n");
        printf("5. Delete\n");
        printf("6. Insert\n");
        printf("7. Reverse\n");
        printf("8. Exit\n");
        printf("Enter Your Choice");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                append();
                break;
            case 2:
                display();
                break;
            case 3:
                length();
                break;
            case 4:
                search();
                break;
            case 5:
                del();
                break;
            case 6:
                insert();
                break;
            case 7:
                reverse();
                break;
            case 8:
                break;
            default:
                printf("Enter the valid choice\n");
        }
    }while(ch!=8);
}
