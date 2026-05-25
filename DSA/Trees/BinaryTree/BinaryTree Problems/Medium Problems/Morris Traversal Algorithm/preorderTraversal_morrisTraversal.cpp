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
vector<int> preOrder(Node* root) {
        vector<int> ans;
        while(root){
            // Check if left of root exist or not
            if(!root->left){ // not exist
                ans.push_back(root->data);
                root=root->right;
            }
            else{ // left exist
                Node* curr = root->left;
                while(curr->right != nullptr && curr->right != root){
                    curr=curr->right;
                }
                
                if(curr->right == nullptr){
                    // make link
                    curr->right = root;
                    // print root node
                    ans.push_back(root->data);
                    // move root to left
                    root=root->left;
                }
                else{
                    // link exists
                    // break link
                    curr->right = nullptr;
                    // move root to right
                    root=root->right;
                }
            }
        }
        return ans;
    }

int main(){
    
    return 0;
}