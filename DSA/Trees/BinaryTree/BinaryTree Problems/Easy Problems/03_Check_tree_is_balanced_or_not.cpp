#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
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

int isBalanced(Node* root,int& valid){
    if(!root)   return 0;

    int leftSide = isBalanced(root->left,valid);
    if(!valid)  return 0;
    int rightSide = isBalanced(root->right,valid);
    if(!valid)  return 0;

    int diff = leftSide-rightSide;
    if(diff> 1 || diff<-1){
        valid = 0;
        return 0;
    }

    return 1+max(leftSide,rightSide);
}

int main(){
    int valid = 1;
    Node* root = BinaryTree();
    isBalanced(root,valid);
    cout<<"valid or not : "<< valid<<endl;
    return 0;
}