#include <iostream>
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

class Node{
	public:
		int data;
		Node* next;
};

// the head node declared globally

Node *head = NULL; 

// inserting a node at front 
void push(Node **ref, int x)
{
	Node *new_node = new Node();
	new_node->data = x;
	new_node->next = *ref;
	*ref = new_node;	
}

// function to reverse the linked list
void reverse() 
{
	Node *cur = head;
	Node *prev = NULL;
	Node *next = NULL;
	while(cur != NULL)
	{
		next = cur->next;
		cur->next = prev;
		prev = cur;
		cur = next;
	}
	head = prev;
}

void printList()
{
	Node *ptr = head;
	while(ptr != NULL)
	{
		cout << ptr->data << " ";
		ptr = ptr->next;
	}
	cout << endl;
}

int main()
{
	push(&head, 89);
	push(&head, 07);
	push(&head, 27);
	push(&head, 52);
	push(&head, 36);
	push(&head, 49);
	cout << "The linked list is:" << endl;
	printList();
	reverse();
	cout << "Linked list after reversal:" << endl;
	printList();
	return 0;
}
