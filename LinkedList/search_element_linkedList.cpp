// searching an element in the linked list
#include <iostream>
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

class Node{
  public:
  	int data;
  	Node *next;
};

// iterative function to check if the given value is present in the linked list
bool search(Node *head, int x)
{
	Node *ptr = head;
	while(ptr != NULL)
	{
		if(ptr->data == x)
			return true;
		ptr = ptr->next;
	}
	return false;
}

// recursive function to check if the entered value is present in the linked list
/*
	bool search(Node *ref, int x)
	{
		// if linked list is empty
		if(ref == NULL)
			return false;
		// if the key is present in the current node
		if(ref->data == x)
			return true;
		// else traverse the linked list and search for the element
		return search(ref->next, x);
	}
*/

// function to add a new node at the front of linked list
void push(Node **ref, int value)
{
	Node *new_node = new Node();
	new_node->data = value;
	new_node->next = *ref;
	*ref = new_node;
}

int main()
{
	Node *head = NULL;
	push(&head, 12);
	push(&head, 67);
	push(&head, 35);
	push(&head, 44);
	cout << "Enter a value to check if it is present in the linked list : ";
	int x = 0;
	cin >> x;
	if(search(head, x))
		cout << "The element is present in the Linked list." << endl;
	else
		cout << "The element is not present in the Linked list." << endl;
	return 0;
}
