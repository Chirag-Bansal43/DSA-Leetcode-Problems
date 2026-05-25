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

Node* InsertionBST(Node* root,int value){
    // base case
    if(!root){
        Node* temp = new Node(value);
        return temp;
    }
    if(value<=root->data){
        root->left = InsertionBST(root->left,value);
    }
    else{
        root->right = InsertionBST(root->right,value);
    }
    return root;
}

int main(){
    
    return 0;
}