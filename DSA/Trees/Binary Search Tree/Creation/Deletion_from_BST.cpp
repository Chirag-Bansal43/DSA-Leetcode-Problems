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



Node* deleteNodeBST(Node* root,int target){
    if(!root)   return nullptr;
    if(root->data == target){
        // Deletion Node is leaf node(no chold)
        if(!root->left && !root->right){
            delete root;
            return nullptr;
        }
        // Deletion Node have only one child
        else if(!root->left && root->right){
            Node* child = root->right;
            delete root;
            return child;
        }
        else if(root->left && !root->right){
            Node* child = root->left;
            delete root;
            return child;
        }
        // Deletion node have two childs : replacing it with highest element of left subtree(or you can also replace it with lowest element of right subtree)
        else{
            // edge case 
            if(!root->left->right){ // child = root->left and parent = root
                Node* child = root->left;
                child->right = root->right;
                delete root;
                return child;
            }
            else{ // parent != root
                Node* parent = root->left;
                Node* child = root->left->right;
                while(child->right){
                    parent = child;
                    child = child->right;
                }
                parent->right = child->left;
                child->left = root->left;
                child->right = root->right;
                delete root;
                return child;
            }
        }
    }

    else if(root->data>target){
        // target is lie in left side
        root->left = deleteNodeBST(root->left,target);
    }
    else{
        // target is lie in right side
        root->right = deleteNodeBST(root->right,target);
    }
    return root;
}

int main(){
    
    return 0;
}