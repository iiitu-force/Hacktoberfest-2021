#include<stdio.h>

void push(int);
void pop();
void display();
int peek();

int arrsize=5;
int stackarr[5], top = -1;

void main() {
	int value, option,exitst=1;
	while (exitst) {
		printf("\n1. Push\n2. Pop\n3. Display\n4. Peek\n5. Exit");
		printf("\nEnter your option: ");
		scanf("%d", &option);
		switch (option) {
		case 1:
			printf("Enter the value to be insert: ");
			scanf("%d", &value);
			push(value);
			break;
		case 2:
			pop();
			break;
		case 3:
			display();
			break;
		case 4:
			peek();
			break;
		case 5:
			printf("Exiting..");
			exitst = 0;
			break;
		default:
			printf("\nPlease enter correct option. Retry");
		}
	}
	
}
void push(int value) {
	if (top == arrsize-1)
		printf("\nStack is Currently Full. Please pop elements before pushing them.");
	else {
		top++;
		stackarr[top] = value;
		printf("\nInsertion was success. Stack got updated");
	}
}
void pop() {
	if (top == -1)
		printf("\nNo more elements to delete. Please push elements before trying to delete.");
	else {
		printf("\nDeleted : %d", stackarr[top]);
		top--;
		printf("\nStack is updated. Topmost Element is deleted.");
	}
}
void display() {
	if (top == -1)
		printf("\nStack is Empty!!!");
	else {
		int i;
		printf("\nStack elements are:\n\n");
		for (i = top; i >= 0; i--){
			printf("| %d |\n", stackarr[i]);
			printf("-----\n");

		}
	}
}

int peek(){
	if (top == -1)
		printf("\nStack is Empty");
	else
		printf("\nTop Value: %d\n",stackarr[top]);
}
