#include <bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int data;
    Node* left,*right;

    Node(int val){
        data = val;
        left = right = nullptr;
    }
};

// Binary Tree Construction : TC = O(n) , SC = O(h) where n = no. of nodes , h = height of tree
Node* BinaryTree(){
    int nextEle;
    cin>>nextEle;
    if(nextEle == -1)   return nullptr;
    Node* newNode = new Node(nextEle);
    // Left Side 
    cout<<"Enter the left Child of "<<nextEle<<" : ";
    newNode->left = BinaryTree();
    cout<<"Enter the right Child of "<<nextEle<<" : ";
    newNode->right = BinaryTree();
    return newNode;
}

// Binary Tree Traversals : TC = O(n) , SC = O(h) where n = no. of nodes , h = height of tree
// PreOrder Traversal : N L R
void PreOrder(Node* root){
    if(root == nullptr) return;
    cout<<root->data<<" ";
    PreOrder(root->left);
    PreOrder(root->right);
}

// InOrder Traversal : L N R
void InOrder(Node* root){
    if(root == nullptr) return;
    InOrder(root->left);
    cout<<root->data<<" ";
    InOrder(root->right);
}

// PostOrder Traversal : L R N
void PostOrder(Node* root){
    if(root == nullptr) return;
    PostOrder(root->left);
    PostOrder(root->right);
    cout<<root->data<<" ";
}

// Level Order Traversal : Level wise nodes printing
void LevelOrder(Node* root){
    queue<Node*> q;
    if(!root)   return;
    q.push(root);

    while(!q.empty()){
        Node* currNode = q.front();
        q.pop();
        cout<<currNode->data<<" ";
        if(currNode->left != nullptr){
            q.push(currNode->left);
        }

        if(currNode->right != nullptr){
            q.push(currNode->right);
        }
    }
}

int main(){
    
    cout<<"\nEnter root Element : ";
    Node* root = BinaryTree();

    cout<<"\nPreOrder : ";
    PreOrder(root);

    cout<<"\nInOrder : ";
    InOrder(root);

    cout<<"\nPostOrder : ";
    PostOrder(root);
    cout<<endl;

    cout<<"LevelOrder : ";
    LevelOrder(root);
    cout<<endl;

    return 0;
}