#include <iostream>
using namespace std;

typedef long long ll;
ll size = 1e7;
ll a[10000000];
int count;
void traverse ()
{
    for(int i=0;i<count;i++)
    cout<<a[i]<<" ";
    cout<<endl;
}

void Insert(int val,int idx)
{
      for(int i=count-1;i>=idx;i--)
        a[i+1]=a[i];
        a[idx]=val;
        count++;
}

int Search(int val)
{
    for(int i=0;i<count;i++)
    if(a[i]==val)
    return i;
    
    return -1;
}

void Delete(int val)
{
    int key = Search(val);
    if(key>=0)
    {
        for(int i=key;i<count-1;i++)
        a[i]=a[i+1];
        cout<<"The element was deleted successfully"<<endl;
        count--;
    }
    else
    cout<<"Element not found"<<endl;
}

void Update(int val, int index)
{
    a[index]=val;
    return;
}



int main() {
    cout<<"The program has started"<<endl;
    cout<<"Enter the number of elements in the original"<<endl;
    cin>>count;
    cout<<"Enter the "<<count<<" values of the array"<<endl;
    for(int i=0;i<count;i++)
    cin>>a[i];
    while(1)
    {
        cout<<"To Traverse the array press 1"<<endl;
        cout<<"To Insert an element into the array press 2"<<endl;
        cout<<"To Delete an element from the array press 3"<<endl;
        cout<<"TO Search for an element press 4"<<endl;
        cout<<"To Update any element of the array press 5"<<endl;
        cout<<"Press anything else to exit"<<endl;
        
        int key=0;
        cin>>key;
        
        if(key==1)
        {
            cout<<"The array elements are:";
            traverse();
        }
        else if(key==2)
        {
            cout<<"Enter the element to be inserted: ";
            int ele;
            cin>>ele;
            cout<<"Enter the index for its insertion: ";
            int index;
            cin>>index;
            if(index<=count)
                {
                    Insert(ele,index);
                    cout<<"Array after insertion: ";
                    traverse();
                }
            else 
            cout<<"Invalid insertion"<<endl;
        }
        else if(key==3)
        {
            cout<<"Enter the value of the element that is to be deleted: ";
            int val;
            cin>>val;
            Delete(val);
            cout<<"Array after deletion: ";
            traverse();
        }
        else if(key==4)
        {
            cout<<"Enter tha value that is to be searched: ";
            int val;
            cin>>val;
            int key=Search(val);
            if(key==-1)
            cout<<val<<" is not in the array"<<endl;
            else 
            cout<<"1st index for "<<val<<" is "<<key<<endl;
        }
        else if(key==5)
        {
            cout<<"Enter the index of element to be updated: ";
            int index;
            cin>>index;
            if(index<count)
            {
                cout<<"Enter the new value for the index: ";
                int val;
                cin>>val;
                Update(val,index);
                cout<<"Array after updation: ";
                    traverse();
            }
            else
            cout<<"You entered wrong index";
        }
        else
        {
            break;
        }   
    }
    
    cout<<"The program has ended"<<endl;
    return 0;
}