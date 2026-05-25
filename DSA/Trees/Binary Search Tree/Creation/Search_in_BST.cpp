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

bool searchBST(Node* root,int target){
    // base case
    if(root == nullptr)    return 0;

    if(target == root->data){
        return 1;
    }
    else if(target<=root->data){
        return searchBST(root->left,target);
    }
    else{
        return searchBST(root->right,target);
    }
}

int main(){
    
    return 0;
}