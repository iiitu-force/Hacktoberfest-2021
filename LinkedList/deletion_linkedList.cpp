#include <iostream>
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

class Node{
   public:
   		int data;
   		Node* next;
};

// function for deleting the entire linked list
void deleteList(Node** ref)
{
	Node* current = *ref;
	Node* next;
	while(current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
	*ref = NULL;
}

// pushing a new node to the front of the linked list
void push(Node** ref, int value)
{
	Node* new_node = new Node();
	new_node->data = value;
	new_node->next = *ref;
	*ref = new_node;
}

int main()
{
	Node* head = NULL;
	push(&head, 41);
	push(&head, 12);
	push(&head, 23);
	push(&head, 40);
	push(&head, 57);
	deleteList(&head);
	cout << "Linked List Deleted" << endl;
	return 0;
}
