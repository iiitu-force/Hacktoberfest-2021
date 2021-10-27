#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node*next;
    Node(int data){
        this->data=data;
        next=NULL;
    }
};
Node* enterElement(Node* head){
    
    int data;
    cin>>data;
    Node* newNode=new Node(data);
    if(head==NULL){
        head=newNode;
        return head;
    }
    Node* temp=head;
    while (temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=newNode;
    return head;
    

}
Node* insertNode(Node* head){
    cout<<"Enter the lenght of sorted linked list"<<endl;
    int lenght;
    cin>>lenght;
    cout<<"Enter data"<<endl;
    for (int i = 0; i < lenght; i++)
    {
        head=enterElement(head);
    }
    return head;
    
}
void print(Node *head){
    while (head!=NULL)
    {
        cout<<head->data<<" ";
        head=head -> next;
    }
    cout<<endl;
}
Node* mergeSorted(Node* head1,Node* head2, Node* head3){
    Node* fhead1=head1;
    Node* fhead2=head2;
    Node* ftail=NULL;
    Node* fhead=head3;
    if(fhead1->data<=fhead2->data){
        ftail=fhead1;
        fhead=fhead1;
        fhead1=fhead1->next;
        
    }
    else{
        ftail=fhead2;
        fhead=fhead2;
        fhead2=fhead2->next;
       
    }
    while (fhead1!=NULL && fhead2!=NULL)
    {
       if(fhead1->data<=fhead2->data){
        
        ftail->next=fhead1;
        ftail=fhead1;
        fhead1=fhead1->next;
        
    }
    else{
         ftail->next=fhead2;
         ftail=fhead2;
         fhead2=fhead2->next;
    }
   
    }

    while (fhead1!=NULL)
    {
        ftail->next=fhead1;
        
        break;
    }
     while (fhead2!=NULL)
    {
        ftail->next=fhead2;
        
        break;
    }
    head3=fhead;
    return head3;
    

    
}
int main()
{
    Node* head1=NULL;
    Node* head2=NULL;
    Node* head3=NULL;
    head1=insertNode(head1);
    cout<<"The first sorted linked list is"<<endl;
    print(head1);
    head2=insertNode(head2);
    cout<<"The second sorted linked list is"<<endl;
    print(head2);
    head3=mergeSorted(head1,head2,head3);
    cout<<"The merged sorted linked list is"<<endl;
    print(head3);
    return 0;
}