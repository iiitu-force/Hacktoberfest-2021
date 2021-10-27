#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
class Node{
    public:
    int data;
    Node*next;
    Node(int data){
       this->data=data;
       next= NULL; 
    }
};
Node* takeInput(){
    int data;
    cin>>data;
    Node *head= NULL;
    Node *tail= NULL;  
    while(data != -1){
        Node *newNode=new Node(data);
        if(head==NULL){
            head=newNode;
            tail=newNode;
        }else{
            tail->next=newNode;
            tail=tail->next;  
        }
        
        cin>>data;
    }
    return head;
}
Node* takeInput2(Node* head,int data, int i){
    Node* newNode=new Node(data);
    if(head==NULL){
        
        return head;
    }
    if(i==0){
        newNode->next=head;
        head=newNode;
        return head;
    }
    else{
       Node* temp= takeInput2(head->next,data,i-1);
       head->next=temp;
       return head;
    }
}
void print(Node *head){
    while (head!=NULL)
    {
        cout<<head->data<<" ";
        head=head -> next;
    }
    
}
Node* insertNode(Node *head,int i,int data){
    Node *newNode=new Node(data);
    int count=0;
    Node *temp=head;
    if(i==0){
        newNode->next=head;
        head=newNode;
        return head; 
    }
    while (temp!=NULL && count<i-1)
    {
        temp=temp->next;
        count++;
    }
    if(temp!=NULL){
        newNode->next=temp->next;
        temp->next=newNode;
    }
    return head;
    
    
}
Node* deleteNode(Node *head,int i){
    if(i==0){
        head=head->next;
        return head;
    }
    Node *temp=head;
    int count=0;
    while (temp!=NULL && count<i-1)
    {
        temp=temp->next;
        count++;
    }
    if(temp!=NULL){
    Node*a=temp->next;
    temp->next=a->next;
    }
    return head;
}
Node* deleteNode2(Node* head,int i){
    if(head==NULL){
        return head;
    }
    if(i==0){
        head=head->next;
        return head;
    }
    else{
        Node* temp=deleteNode2(head->next,i-1);
        head->next=temp;
        return head;
    }
}
int lenghtofLinkedlist(Node *head){
    Node*temp=head;
    int count=0;
     while (temp!=NULL)
    {
        temp=temp->next;
        count++;
    }
    return count;

}
int getCount(Node *head){
    if(head==NULL){
        return 0;
    }
    
        return 1+ getCount(head->next);
    
}
void midleNode(Node* head){
    if(head==NULL){
        cout<<"Linked List is empty"<<endl;
        return ;
    }
    Node* fast=head->next;
    Node* slow=head;

    
    while (fast!=NULL )
    {
        
        if(fast->next!=NULL){
             fast=fast->next->next;
             slow=slow->next;
        }else{
            break;
        }
       
        
        
    }
    
    cout<<slow->data<<endl;
   
}

int main()
{
      Node* head;
      head=takeInput();
     // int i;
     // cin>>i;
     midleNode(head);
     // head=deleteNode2(head,i);
    //  head=takeInput2(head,data,i);
    //   print(head);
    //   int i,data;
    //   cin>>i;
    //    head=insertNode(head,i,data);
    //   head=deleteNode(head,i);
    // cout<<lenghtofLinkedlist(head)<<endl;
    //   print(head);
    
return 0;
}