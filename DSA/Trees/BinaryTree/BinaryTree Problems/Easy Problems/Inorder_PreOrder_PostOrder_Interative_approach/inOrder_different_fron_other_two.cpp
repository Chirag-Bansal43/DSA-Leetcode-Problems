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


vector<int> inOrder(Node* root) {
        vector<int> ans;
        stack<Node*> st;
        stack<int> visited;
        st.push(root);
        visited.push(0);
        while(!st.empty()){
            Node* currNode = st.top();
            int visit = visited.top();
            st.pop();   visited.pop();
            if(visit){
                ans.push_back(currNode->data);
            }
            else{
                // right child
                if(currNode->right){
                    st.push(currNode->right);
                    visited.push(0);
                }
                // node
                st.push(currNode);
                visited.push(1);
                // left child
                if(currNode->left){
                    st.push(currNode->left);
                    visited.push(0);
                }
            }
        }
        return ans;
    }

// Method 2 : Finding inorder traversal using only one stack better than previous solution
// TC = O(n) , SC = O(n)    
    vector<int> inOrder(Node* root) {
        vector<int> ans;
        stack<Node*> st;
        
        // Initialise the stack with all the nodes in the left most boundary of tree
        while(root){
            st.push(root);
            root = root->left;
        }
        
        // Now left most element is at the top of stack so put it in ans and push it's right child and all the left childs of it's right child into stack
        while(!st.empty()){
            Node* currNode = st.top();
            ans.push_back(currNode->data);
            st.pop();
            
            //push it's right child and all the left childs of it's right child into stack
            Node* temp = currNode->right;
            while(temp){
                st.push(temp);
                temp = temp->left;
            }
        }
        return ans;
    }

int main(){
    
    return 0;
}