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

bool CheckBST(Node* root,int& prev){
        //base case 
        if(!root)   return 1;
        
        // go to left side
        bool left = CheckBST(root->left,prev);
        if(!left) return 0;
        // Checking curr node
        if(root->data<=prev)    return 0;
        else prev = root->data;
        
        // go to the right of node
        bool right = CheckBST(root->right,prev);
        if(!right) return 0;
        
        return 1;
    }

    bool isBST(Node* root) {
        int prev = INT_MIN;
        return CheckBST(root,prev);
        
    }

int main(){
    
    return 0;
}