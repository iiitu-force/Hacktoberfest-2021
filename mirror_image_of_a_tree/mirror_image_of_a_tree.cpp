// Check if two trees are Mirror

struct Node 
{ 
    int data; 
    Node* left, *right; 
}; 
  
  
    
/* Helper function that allocates a new node */
Node* newNode(int data) 
{ 
    Node* node = new Node; 
    node->data  = data; 
    node->left  =  node->right  = NULL; 
    return(node); 
} 


/* Given two trees, return true if they are 
   mirror of each other */
   
int areMirror(Node* a, Node* b) 
{ 
    /* Base case : Both empty */
    if (a==NULL && b==NULL) 
        return true; 
  
    // If only one is empty 
    if (a==NULL || b == NULL) 
        return false; 
  
    /* Both non-empty, compare them recursively 
     Note that in recursive calls, we pass left 
     of one tree and right of other tree */
     
    return  a->data == b->data && 
            areMirror(a->left, b->right) && 
            areMirror(a->right, b->left); 
} 
