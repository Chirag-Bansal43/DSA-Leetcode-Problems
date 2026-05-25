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


vector<int> postOrder(Node* node) {
        vector<int> ans;
        stack<Node*> st;
        st.push(node);
        while(!st.empty()){
            Node* currNode = st.top();
            ans.push_back(currNode->data);
            st.pop();
            // left child
            if(currNode->left)  st.push(currNode->left);
            // right child
            if(currNode->right)  st.push(currNode->right);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }

int main(){
    
    return 0;
}