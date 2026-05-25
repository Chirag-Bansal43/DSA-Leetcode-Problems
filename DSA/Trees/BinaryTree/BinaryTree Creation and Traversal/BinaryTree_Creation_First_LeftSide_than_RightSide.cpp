#include <bits/stdc++.h>
using namespace std;

// Creating Binary Tree in which I first create current node then it's complete left side and then it's complete right side
// It can be called as preOrder Binary tree Creation in which I first create the node then it's left side nodes and then it's right side nodes

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

int main(){
    cout<<"\nEnter root Element : ";
    Node* root = BinaryTree();
    cout<<"\nRoot Element : "<<root->data<<endl;

    


    return 0;
}