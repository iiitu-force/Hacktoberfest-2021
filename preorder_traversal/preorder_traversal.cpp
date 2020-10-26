//Preorder

//Recursive


  void preorder (node* root)
{
	if(root){
		cout<<root->data<<" ";
		preorder(root->left);
		preorder(root->right);
	}
}


//Iterative
void iterativePreorder(node * root)
{

	if(root==NULL)
		return;

	stack<node *> s;
	s.push(root);

	while(!s.empty()){
		node* temp=s.top();
		s.pop();

		cout<<temp->data<<" ";

		if(temp->right)
			s.push(temp->right);
		if(temp->left)
			s.push(temp->left);
	}

}
