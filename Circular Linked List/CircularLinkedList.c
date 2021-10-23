#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int info;
    struct Node *link;
};
struct Node *tail=NULL;

void Create();
void insertBeg();
void insertMid();
void insertEnd();
void deleteBeg();
void deleteMid();
void deleteEnd();
void Count();
void Display();
void Reverse();
void Sort();
void DeleteAll();
void main()
{
    int ch;
    do
    {
        printf("\n1.Create Nodes\n");
        printf("2.Insert at Begining\n");
        printf("3.Insert in Between\n");
        printf("4.Insert at End\n");
        printf("5.Delete at Beginning\n");
        printf("6.Delete in Between\n");
        printf("7.Delete at End\n");
        printf("8.Count No.of Nodes\n");
        printf("9.Display Linked List\n");
        printf("10.Reverse a List\n");
        printf("11.Sort the Linked List\n");
        printf("12.Empty the Linked List\n");
        printf("13.Exit\n\n");
        printf("\tEnter Choice: ");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:Create();
            break;
        case 2:insertBeg();
            break;
        case 3:insertMid();
            break;
        case 4:insertEnd();
            break;
        case 5:deleteBeg();
            break;
        case 6:deleteMid();
            break;
        case 7:deleteEnd();
            break;
        case 8:Count();
            break;
        case 9:Display();
            break;
        case 10:Reverse();
            break;
        case 11:Sort();
            break;
        case 12:DeleteAll();
            break;
        case 13:printf("Exiting .....\n");
            break;    
        default:printf("Wrong Choice !!!");
            break;
        }
    }while(ch!=13);    
}
void Create()
{
    if(tail==NULL)
    {
        int n;
        printf("Enter No.of Nodes you want to Create\n");
        scanf("%d",&n);
        struct Node *ptr=NULL,*first=NULL;
        while(n>0)
        {
            ptr=(struct Node*)malloc(sizeof(struct Node));
            
            if(tail==NULL)
            {
                printf("Enter the Element: \n");
                scanf("%d",&ptr->info);
                first=ptr;
                tail=ptr;
                tail->link=first;
            }
            else
            {
                printf("Enter the Element: \n");
                scanf("%d",&ptr->info);
                tail->link=ptr;
                tail=ptr;
                tail->link=first;
            }                      
            n--;
        }
        first=NULL;
        free(first);
    }
    else
    printf("Create Func is applicable only in Empty Linked List\n");
}
void insertBeg()
{
    struct Node *ptr;
    int data;
    ptr=(struct Node *)malloc(sizeof(struct Node));
    if(ptr==NULL)
    {
        printf("Memory Not Available\n");
        exit(1);
    }
    printf("Enter the Element Value\n");
    scanf("%d",&data);
    ptr->info=data;
    if(tail==NULL)
    {
        tail=ptr;
        tail->link=ptr;
    }
    else
    {
        ptr->link=tail->link;
        tail->link=ptr;
    }      
}
void insertMid()
{
    if(tail==NULL)
    printf("Empty List !!!\n");
    else
    {
       struct Node *ptr,*temp;
       ptr=(struct Node*)malloc(sizeof(struct Node));
       if(ptr == NULL)  
       {   
            printf("\nMemory Not Available !!\n");  
            exit(1);     
       }
       int loc,data;
       printf("After how many nodes you want to enter new node: ");
       scanf("%d",&loc); 
       temp=tail->link;
       printf("Enter the Element: ");
       scanf("%d",&data);
       while(loc>1)
       {
           loc--;
           temp=temp->link;
       }
       ptr->link=temp->link;
       temp->link=ptr;
       ptr->info=data;
       if(temp==tail)
       tail=ptr;
    }
    
}
void insertEnd()
{
    if(tail==NULL)
    printf("Empty List !!!!\n");
    else
    {
        struct Node *ptr;
        ptr=(struct Node*)malloc(sizeof(struct Node));
        if(ptr == NULL)  
        {   
                printf("\nMemory Not Available !!\n");  
                exit(1);     
        }
        int data;
        printf("Enter the Element: ");
        scanf("%d",&data);
        ptr->info=data;                
        ptr->link=tail->link;
        tail->link=ptr;
        tail=ptr;
    }
}
void deleteBeg()
{
    struct Node *ptr;  
    if(tail == NULL)  
    {  
        printf("\nList is empty\n");  
    }  
    else   
    {  
        ptr=tail->link;
        if(tail->link==tail)
        {
            tail=NULL;
            printf("\nOnly node of the list deleted ...\n");
        }
        else 
        {
        tail->link=ptr->link;
        }
        ptr->link=NULL;
        free(ptr);          
    }
}
void deleteMid()
{
    if(tail==NULL)
    printf("Empty List !!!\n");    
    else
    {
        struct Node *ptr,*temp;
        int loc;
        printf("After How many Nodes you want to delete Node: ");
        scanf("%d",&loc);
        ptr=tail->link;
        while(loc>1)
        {
            loc--;
            ptr=ptr->link;
        }
        temp=ptr->link;
        if(temp==tail)
        {
            ptr->link=tail->link;
            tail=ptr;
        }
        else
        {
            ptr->link=temp->link;
        }        
        temp->link=NULL;
        free(temp);
    }
     
}
void deleteEnd()
{
    if(tail==NULL)
    printf("Empty List !!!\n");    
    else if(tail->link == tail)  
    {  
        tail = NULL;  
        struct Node *ptr;
        ptr=tail;
        ptr->link=NULL;
        free(ptr); 
        printf("\nOnly node of the list deleted ...\n");  
    }
    else
    {
        struct Node *ptr,*temp;
        ptr=tail->link;
        while(ptr->link!=tail)
        {
            ptr=ptr->link;
        }
        temp=ptr->link;
        tail=ptr;
        tail->link=temp->link;
        temp->link=NULL;
        free(temp);
    }
}
void Count()
{
    struct Node *p=tail->link;
    int counter=0;
    while(p!=tail)
    {
        counter++;
        p=p->link;
    }
    counter++;
    printf("\nNo.of Nodes are: %d",counter);
}
void Display()
{
    if(tail==NULL)
    printf("List is Empty !!!!\n");
    else
    {
        struct Node *ptr=tail->link;
        while(ptr!=tail)  
        {        
            printf("||%d|%u|| --> ",ptr->info,ptr->link);        
            ptr=ptr->link;
        }
        printf("||%d|%u|| --> ",ptr->info,ptr->link); 
    }  
}
void Reverse()
{
    
    struct Node *ptr=tail->link;
    struct Node *temp=tail->link;
    struct Node *r=NULL;
    if(ptr!=tail)
    {
        if(temp==tail->link)
        {
            temp=tail->link->link;
            ptr->link=tail;
            tail=ptr;        
        }    
        while(temp!=tail->link)
        {
            r=temp;
            temp=temp->link;
            r->link=ptr;
            ptr=r;
        }    
        temp->link=ptr; 
    }   
    ptr=r=temp=NULL;
    free(ptr);
    free(r);
    free(temp);   
}
void Sort()
{   
    if(tail==NULL)
    printf("Empty Linked List !!!\n");
    else if(tail->link==tail)
    return;
    else
    {
        struct Node *ptr=tail->link;
        struct Node *p=NULL;
        struct Node *min=NULL;
        while(ptr!=tail)
        {
            p=ptr->link;
            min=ptr;
            while(p!=tail->link)
            {
                if(p->info<min->info)
                min=p;
                p=p->link;
            }
            if(min!=ptr)
            {
                int d=min->info;
                min->info=ptr->info;
                ptr->info=d;
            }
            ptr=ptr->link;
            
        }
    }
}
void DeleteAll()
{
    tail=NULL;
    printf("List Emptied !!!!!!");
}