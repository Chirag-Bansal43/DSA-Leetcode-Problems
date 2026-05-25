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
vector<int> postOrder(Node* root) {
        vector<int> ans;
        // check root->right exist or not
        while(root){
            if(!root->right){ // not exist
                // print node
                ans.push_back(root->data);
                // move root to left
                root=root->left;
            }
            else{ // right child exist
                Node* curr = root->right;
                while(curr->left != nullptr && curr->left != root){
                    curr = curr->left;
                }
                
                if(curr->left == nullptr){
                    // make link
                    curr->left = root;
                    // print node
                    ans.push_back(root->data);
                    //move to right subtree
                    root = root->right;
                }
                else{
                    // link already exist means we traversed root and it's right subtree
                    // so, first break link and move root to left subtree
                    curr->left = nullptr;
                    root = root->left;
                }
            }
        }
        
        reverse(ans.begin(),ans.end());
        return ans;
    }

int main(){
    
    return 0;
}