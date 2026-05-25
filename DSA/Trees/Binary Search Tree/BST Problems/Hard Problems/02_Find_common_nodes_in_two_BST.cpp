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

// Function to find the nodes that are common in both BST.
    // Method 1 : Optimal
    vector<int> findCommon(Node *r1, Node *r2) {
        vector<int> ans;
        stack<Node*> st1; // for BST 1 to traverse it in inorder form
        stack<Node*> st2; // for BST 2 to traverse it in inorder form
        
        // Initialise both the stack with all the nodes in the left most boundary of tree
        while(r1){
            st1.push(r1);
            r1=r1->left;
        }
        
        while(r2){
            st2.push(r2);
            r2=r2->left;
        }
        
        while(!st1.empty() && !st2.empty()){
            Node* curr1 = st1.top();
            Node* curr2 = st2.top();
            
            if(curr1->data == curr2->data){
                ans.push_back(curr1->data);
                st1.pop(); st2.pop();
                //push it's right child and all the left childs of it's right child into stack for both BST's
                Node* temp1 = curr1->right;
                Node* temp2 = curr2->right;
                while(temp1){
                    st1.push(temp1);
                    temp1 = temp1->left;
                }
                while(temp2){
                    st2.push(temp2);
                    temp2 = temp2->left;
                }
            }
            else if(curr1->data < curr2->data){
                st1.pop();
                Node* temp1 = curr1->right;
                while(temp1){
                    st1.push(temp1);
                    temp1 = temp1->left;
                }
            }
            else{
                st2.pop();
                Node* temp2 = curr2->right;
                while(temp2){
                    st2.push(temp2);
                    temp2 = temp2->left;
                }
            }
        }
        
        return ans;
        
    }

    // Short version of above solution => procedure is same as above only code writing is nice
    vector<int> findCommon(Node *root1, Node *root2) {
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
            
            if(st1.top()->data == st2.top()->data){
                
                ans.push_back(st1.top()->data);
                
                root1 = st1.top()->right;
                root2 = st2.top()->right;
                
                st1.pop(); st2.pop();
            }
            else if(st1.top()->data < st2.top()->data){
                root1 = st1.top()->right;
                st1.pop();
            }
            else{
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
        
        return ans;
        
    }
    

    // Method 2 : Better
    void Inorder(Node* root,vector<int>& inorder){
        if(!root)   return;
        
        Inorder(root->left,inorder);
        inorder.push_back(root->data);
        Inorder(root->right,inorder);
    }
    vector<int> findCommon(Node *r1, Node *r2) {
        vector<int> ans;
        vector<int> inorder1,inorder2;
        Inorder(r1,inorder1);
        Inorder(r2,inorder2);
        
        int first=0,second=0;
        while(first<inorder1.size() && second<inorder2.size()){
            if(inorder1[first] == inorder2[second]){
                ans.push_back(inorder1[first]);
                first++; second++;
            }
            else if(inorder1[first] < inorder2[second]){
                first++;
            }
            else{
                second++;
            }
        }
        return ans;
    }

int main(){
    
    return 0;
}