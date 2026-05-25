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

// Method 1: Done by me

Node* Leaf(Node* root){
        // find right most leaf node
        if(!root->left && !root->right){
            return root;
        }
        
        Node* ans;
        if(root->right){
            ans = Leaf(root->right);
        }
        else{
            ans = Leaf(root->left);
        }
        return ans;
    }

    void flatten(Node *root) {
        while(root){
            // Check root->left exist or not
            if(!root->left) root=root->right;
            else{
                // find right most leaf node of left subtree
                Node* ansNode = Leaf(root->left);
                
                ansNode->right = root->right;
                root->right = root->left;
                root->left = nullptr;
                root=root->right;
            }
        }
    }

// Method 2 : by coder army bhaiya
void flatten(Node *root) {
        while(root){
            // Check root->left exist or not
            if(!root->left) root=root->right;
            else{
                // find right most leaf node of left subtree
                Node* curr = root->left;
                while(curr->right){
                    curr = curr->right;
                }
                curr->right = root->right;
                root->right = root->left;
                root->left = nullptr;
                root=root->right;
            }
        }
    }

int main(){
    
    return 0;
}