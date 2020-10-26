
// Defining node structure

struct node{
  int data;
  struct node* left;
  struct node* right;
};


// Function for creating new node

node* newnode(int data)
{
  node* temp=new node;
  temp->data=data;
  temp->left=temp->right=NULL;
  return temp;
}


void levelOrderTraversal(node* root){

	if(root==NULL)
		return;

	queue<node *> q;

	q.push(root);

	while(!q.empty()){
		node *temp=q.front();
		q.pop();
		if(temp){
			cout<<temp->data<<" ";
		}

		if(temp->left)
			q.push(temp->left);
		if(temp->right)
			q.push(temp->right);
	}
}
