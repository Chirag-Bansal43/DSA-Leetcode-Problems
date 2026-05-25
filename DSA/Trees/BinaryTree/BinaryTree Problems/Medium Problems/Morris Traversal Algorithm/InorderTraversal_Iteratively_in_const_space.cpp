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

// Morris Traversal Algorithm
// TC = O(n) SC = O(1)
vector<int> inOrder(Node* root) {
        vector<int> ans;
        while(root){
            // Check left exist or not
            if(!root->left){ // left not exist
                ans.push_back(root->data);
                root=root->right;
            }
            else{ // left exist
                Node* curr = root->left;
                while(curr->right != nullptr && curr->right != root){
                    curr = curr->right;
                }
                
                if(curr->right == nullptr){
                    // make link
                    curr->right = root;
                    // move root to left subtree
                    root = root->left;
                }
                else{
                    // link already bana hua hai means left part already traversed
                    // link ko toodenge
                    curr->right = nullptr;
                    // print root node
                    ans.push_back(root->data);
                    // move root to right subtree
                    root = root->right;
                }
            }
        }
        return ans;
    }

int main(){
    
    return 0;
}