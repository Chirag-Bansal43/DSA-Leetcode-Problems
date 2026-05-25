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


vector<int> preOrder(Node* root) {
        vector<int> ans;
        stack<Node*> st;
        st.push(root);
        while(!st.empty()){
            Node* currNode = st.top();
            ans.push_back(currNode->data);
            st.pop();
            // right child
            if(currNode->right) st.push(currNode->right);
            // left child
            if(currNode->left) st.push(currNode->left);
        }
        return ans;
    }

int main(){
    
    return 0;
}