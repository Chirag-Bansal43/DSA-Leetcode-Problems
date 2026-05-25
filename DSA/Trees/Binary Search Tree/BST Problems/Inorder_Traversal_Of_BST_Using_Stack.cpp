// Very Important

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