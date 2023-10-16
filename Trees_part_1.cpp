#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Node
{
   public: 
   int data;
   Node* left;
   Node* right;
   
   Node(int data)
   {
       this->data = data;
       left = NULL;
       right = NULL;
   }
   
};

Node* BuiltTree()
{
    int data;
    cout<<"Enter the data"<<endl;
    cin>>data;
    
    if(data == -1)
    return NULL;
    
    Node* root = new Node(data);
    root->data = data;
    
    cout<<"Enter the data left child of "<<data<<" node"<<endl;
    root->left = BuiltTree();
    cout<<"Enter the data right child of "<<data<<" node"<<endl;
    root->right = BuiltTree();
    
    return root;
}

Node* BuiltByLevelOrderTraversal()
{
    int data;
    cout<<"Enter the data"<<endl;
    cin>>data;
    
    if(data == -1)
    return NULL;
    
    Node* root = new Node(data);
    queue<Node*> q1;
    q1.push(root);
    
    while(!q1.empty())
    {
        Node* temp = q1.front();
        q1.pop();
        
        int left,right;
        cout<<"Enter the data left child of "<<temp->data<<" node"<<endl;
        cin>>left;
        cout<<"Enter the data right child of "<<temp->data<<" node"<<endl;
        cin>>right;
        
        if(left != -1)
        {
            Node* LeftChild = new Node(left);
            temp->left = LeftChild;
            q1.push(LeftChild);
        }
        if(right != -1)
        {
            Node* RightChild = new Node(right);
            temp->right = RightChild;
            q1.push(RightChild);
        }
    }
    
    return root;
}

void PreOrderTraversal(Node* root)
{
    if(!root) return;
    
    cout<<root->data<<" ";
    PreOrderTraversal(root->left);
    PreOrderTraversal(root->right);
}

void InOrderTraversal(Node* root)
{
    if(!root) return;
    
    InOrderTraversal(root->left);
    cout<<root->data<<" ";
    InOrderTraversal(root->right);
}

void PostOrderTraversal(Node* root)
{
    if(!root) return;
    
    PostOrderTraversal(root->left);
    PostOrderTraversal(root->right);
    cout<<root->data<<" ";
}

void LevelOrderTraversal(Node* root)
{
    if(!root) return;
    
    queue<Node*> q1;
    q1.push(root);
    q1.push(NULL);
    int i=2;
    cout<<"\n"<<"1:- ";
    while(!q1.empty())
    {
       if(q1.front()==NULL)
       {
          q1.pop(); 
          if(!q1.empty())
          {
            cout<<"\n"<<i<<":- ";
            q1.push(NULL);
            i++;
          }else{return;}
       }

       Node* temp = q1.front();
       q1.pop();
       
       cout<<temp->data<<" ";
       
       if(temp->left) q1.push(temp->left);
       if(temp->right) q1.push(temp->right);
    }
}

int HeightOfTree(Node* root)
{
    int ans=0;
    if(!root) return ans;
    
    int left = HeightOfTree(root->left);
    int right = HeightOfTree(root->right);
    ans = max(left,right)+1;
    
    return ans;
}

int DiameterOfTree(Node* root)
{
    int ans = 0;
    
    if(!root) return ans;
    
    int left = DiameterOfTree(root->left);
    int right = DiameterOfTree(root->right);
    int center = HeightOfTree(root->left)+HeightOfTree(root->right);
    ans = max(left,max(right,center));
    
    return ans;
}

int main()
{
    //Node* root = BuiltTree();
    Node* root = BuiltByLevelOrderTraversal();
    cout<<endl;
    PreOrderTraversal(root);
    cout<<endl;
    InOrderTraversal(root);
    cout<<endl;
    PostOrderTraversal(root);
    cout<<endl;
    LevelOrderTraversal(root);
    cout<<endl;
    cout<<HeightOfTree(root);
    cout<<endl;
    cout<<DiameterOfTree(root);
    
    return 0;
}