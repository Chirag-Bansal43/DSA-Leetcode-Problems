// Totally Based on Previous Problem Find common nodes in two BSTs

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

// Kuch nahi kiya baas dono BST's ka inorder traversal kiya ha
// Method -1 : Here i am doing inorder traversal using stack 
// Optimal TC = O(m+n) where m = no.of nodes in Tree1 and n= no.of nodes in Tree2
// SC = O(h1 + h2) where h1 = height of Tree1 and h2 = height of Tree2 or in worst case O(m+n)
 vector<int> merge(Node *root1, Node *root2) {
        vector<int> ans;
        stack<Node*> st1; // for BST 1 to traverse it in inorder form
        stack<Node*> st2; // for BST 2 to traverse it in inorder form
        
        // Initialise both the stack with all the nodes in the left most boundary of tree
        while(root1){
            st1.push(root1);
            root1=root1->left;
        }
        
        while(root2){
            st2.push(root2);
            root2=root2->left;
        }
        
        while(!st1.empty() && !st2.empty()){
            // top equal
            if(st1.top()->data == st2.top()->data){
                ans.push_back(st1.top()->data);
                ans.push_back(st1.top()->data);
                
                root1 = st1.top()->right;
                root2 = st2.top()->right;
                
                st1.pop(); st2.pop();
                
            }
            // s1< s2
            else if(st1.top()->data < st2.top()->data){
                ans.push_back(st1.top()->data);
                root1 = st1.top()->right;
                st1.pop();
            }
            // s2< s1
            else{
                ans.push_back(st2.top()->data);
                root2 = st2.top()->right;
                st2.pop();
            }
            
            //push it's right child and all the left childs of it's right child into stack for both BST's
            while(root1){
                st1.push(root1);
                root1 = root1->left;
            }
            while(root2){
                st2.push(root2);
                root2 = root2->left;
            }
            
        }
        
        while(!st1.empty()){
            ans.push_back(st1.top()->data);
            
            root1 = st1.top()->right;
            st1.pop();
            
            while(root1){
                st1.push(root1);
                root1 = root1->left;
            }
        }
        
        while(!st2.empty()){
            ans.push_back(st2.top()->data);
            
            root2 = st2.top()->right;
            st2.pop();
            
            while(root2){
                st2.push(root2);
                root2 = root2->left;
            }
        }
        
        return ans;
        
    }

// or Better Solution
 void Inorder(Node* root,vector<int>& ans){
        if(!root)   return;
        
        Inorder(root->left,ans);
        ans.push_back(root->data);
        Inorder(root->right,ans);
    }

    vector<int> merge(Node *root1, Node *root2) {
        vector<int> ans;
        vector<int> ans1,ans2;
        Inorder(root1,ans1);
        Inorder(root2,ans2);
        
        int first = 0,second = 0;
        while(first < ans1.size() && second < ans2.size()){
            if(ans1[first] <= ans2[second]){
                ans.push_back(ans1[first++]);
            }
            else
                ans.push_back(ans2[second++]);
        }
        
        while(first < ans1.size()){
            ans.push_back(ans1[first++]);
        }
        
        while(second < ans2.size())
            ans.push_back(ans2[second++]);
        
        
        return ans;
    }

int main(){
    
    return 0;
}