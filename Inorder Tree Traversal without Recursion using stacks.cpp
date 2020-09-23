// C++ program to print inorder traversal 
// using stack. 
#include<bits/stdc++.h> 
using namespace std; 
  
/* A binary tree Node has data, pointer to left child 
   and a pointer to right child */
struct Node 
{ 
    int data; 
    struct Node* left; 
    struct Node* right; 
    Node (int data) 
    { 
        this->data = data; 
        left = right = NULL; 
    } 
}; 
  
/* Iterative function for inorder tree 
   traversal */
void inOrder(struct Node *root) 
{ 
    stack<Node *> s; 
    Node *curr = root,*pre,*R; 
    if(curr==NULL) 
      return;
    s.push(curr); 
    while ( s.empty() == false) 
    { 
        /* Reach the left most Node of the 
           curr Node */
      curr = s.top(); 
        s.pop(); 
      if(curr->right==NULL && curr->left==NULL){
        cout<<curr->data<<" ";continue;}  
      
  
      if(curr->right)
      s.push  (curr->right);

      pre=new Node(curr->data);
      s.push(pre);
      if(curr->left)
        s.push(curr->left);


        /* Current must be NULL at this point */
        
        
  
        /* we have visited the node and its 
           left subtree.  Now, it's right 
           subtree's turn */
        //curr = curr->right; 
  
    } /* end of while */
} 
  
/* Driver program to test above functions*/
int main() 
{ 
  
    /* Constructed binary tree is 
              1 
            /   \ 
          2      3 
        /  \ 
      4     5 
    */
    struct Node *root = new Node(1); 
    root->left        = new Node(2); 
    root->right       = new Node(3); 
    root->left->left  = new Node(4); 
    root->left->right = new Node(5); 
  
    inOrder(root); 
    return 0; 
} 
