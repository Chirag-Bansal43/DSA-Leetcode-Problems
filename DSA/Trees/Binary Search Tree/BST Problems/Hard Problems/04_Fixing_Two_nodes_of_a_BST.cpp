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

// Method 1 : TC = O(n) SC = O(n) {Better solution}
    void Inorder(Node* root,vector<int>& ans){
        if(!root)   return;
        
        Inorder(root->left,ans);
        ans.push_back(root->data);
        Inorder(root->right,ans);
    }

    void Update(Node* root,int first,int second){
            if(!root)   return;
            
            if(root->data == first) root->data = second;
            else if(root->data == second)   root->data = first;
            
            // left side
            Update(root->left,first,second);
                
            // right side
            Update(root->right,first,second);
    }


    void correctBST(Node* root) {
        // first find inorder of tree
        vector<int> In;
        Inorder(root,In);
        
        // Traverse Inorder and find what are the nodes which are at incorrect position
        int first = -1,second=-1;
        for(int i=1;i<In.size();i++){
            if(In[i-1] > In[i]){
                if(first == -1){
                    first = In[i-1];
                    second = In[i];
                }
                else{
                    second = In[i];
                }
            }
        }
        
        // Traverse the BST and update the node values
        Update(root,first,second);
        
    }

    // Method 2 : without making inorder vector directly do inorder traverse in BST using prev and curr pointer
    //{using recursion} TC = O(n) SC = O(h) {of recursion}

    void BSTinorder(Node* root,Node* & prev,Node* & first,Node* & second){
        if(!root)   return;
        
        // Left side
        BSTinorder(root->left,prev,first,second);
        
        // node
        if(prev && root->data < prev->data){
            if(first == nullptr){
                first = prev;
                second = root;
            }
            else{
                second = root;
            }
        }
        
        prev = root;
        
        // right side
        BSTinorder(root->right,prev,first,second);
    }

    void correctBST(Node* root) {
        Node* prev = nullptr;
        Node* first = nullptr,*second = nullptr;
        
        BSTinorder(root,prev,first,second);
        
        int temp = first->data;
        first->data = second->data;
        second->data = temp;
        
    }

    // Method -3 : Solving this in constant space O(1) not using array space or recurrsion space
    // So for solving it in O(1) space we directly do inorder traversal of tree but not using recurrsion
    // We use Morris Inorder Traversal that takes O(1) space
    // TC = O(n), SC=O(1)
    void BSTinorder(Node* root,Node*& prev,Node*& first,Node*& second){
        // Morris Inorder Traversal
        while(root){
            // root->left exist or not
            // not exist
            if(!root->left){
                // node
                
                if(prev!=nullptr && root->data < prev->data){
                    if(first == nullptr){
                        first = prev;
                        second = root;
                    }
                    else{
                        second = root;
                    }
                }
                
                prev = root;
                
                // root ko right side le jayo
                root=root->right;
            }
            // exist
            else{
                Node* curr = root->left;
                while(curr->right != nullptr && curr->right != root){
                    curr=curr->right;
                }
                
                if(curr->right){
                    curr->right = nullptr;
                    
                    // node
                    if(root->data < prev->data){
                        if(first == nullptr){
                            first = prev;
                            second = root;
                        }
                        else{
                            second = root;
                        }
                    }
                
                    prev = root;
                    
                    // right mein chale jayo
                    root=root->right;
                }
                else{
                    curr->right = root;
                    root=root->left;
                }
            }
        }
        
    }

    void correctBST(Node* root) {
        Node* prev = nullptr;
        Node* first = nullptr,* second = nullptr;
        
        BSTinorder(root,prev,first,second);
        
        int temp = first->data;
        first->data = second->data;
        second->data = temp;
        
    }


int main(){
    
    return 0;
}