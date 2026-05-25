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


void mirror(Node* root) {
        // null
        if(!root) return;
        // leaf nodes
        if(!root->left && !root->right) return;
        
        Node* temp = root->left;
        root->left = root->right;
        root->right = temp;
        
        // Left side ke nodes ke liye mirror fxn chala do
        mirror(root->left);
        
        // right side ke nodes ke liye mirror fxn chala do
        mirror(root->right);
    }

int main(){
    
    return 0;
}