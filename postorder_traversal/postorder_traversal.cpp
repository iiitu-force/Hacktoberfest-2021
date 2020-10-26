//Postorder

//Recursive

void postorder(node* root){
	if(root){
		postorder(root->left);
		postorder(root->right);
		cout<<root->data<<" ";
	}
}


//Iterative

void iterativePostorder(node* root){

	if(root==NULL)
		return;

	stack<node*> nodeStack;
	do{
		while(root){
			if(root->right)
				nodeStack.push(root->right);

			nodeStack.push(root);
			root=root->left;
		}

		root=nodeStack.top();
		nodeStack.pop();
		node* temp;
		if(!nodeStack.empty())
			 temp=nodeStack.top();
		else
			 temp==NULL;

		if(root->right && temp==root->right){
			nodeStack.pop();
			nodeStack.push(root);
			root=root->right;
		}

		else{
			cout<<root->data<<" ";
			root=NULL;
		}
	} while(!nodeStack.empty());
}
