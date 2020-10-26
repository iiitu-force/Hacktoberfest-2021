//Inorder

//Recursive


void inorder(node* root)
{
	if(root){
		inorder(root->left);
		cout<<root->data<<" ";
		inorder(root->right);
	}
}


//Iterative


void iterativeInorder(node* root){
	if(root == NULL)
		return;

	stack<node *> nodeStack;
	node* curr = root;

	while(curr != NULL || nodeStack.empty() != true){

		while(curr != NULL){
			nodeStack.push(curr);
			curr = curr->left;
		}

		curr = nodeStack.top();
		cout<<curr->data<<" ";
		nodeStack.pop();
		curr = curr->right;
	}
}
