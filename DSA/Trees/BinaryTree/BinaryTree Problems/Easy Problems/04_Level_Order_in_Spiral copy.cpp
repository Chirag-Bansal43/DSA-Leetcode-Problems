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

// Method 1 using queue and using stack to reverse queue in each level which increases time complexity
// TC = O(2n) SC = O(n) {for queue and stack}
vector<int> findSpiral(Node* root) {
    vector<int> ans;
    int direction = 1; // 1 for right to left and 0 for left to right
    queue<Node*> q;
    if(!root)   return ans;
    q.push(root);
    
    while(!q.empty()){
        // reversing the queue
        stack<Node*> st;
        while(!q.empty()){
            st.push(q.front());
            q.pop();
        }
        while(!st.empty()){
            q.push(st.top());
            st.pop();
        }
        
        // putting it's children into the queue according to direction
        int size = q.size();
        for(int i=0;i<size;i++){
            Node* currNode = q.front();
            q.pop();
            ans.push_back(currNode->data);
            if(direction){
                if(currNode->right) q.push(currNode->right);
                if(currNode->left) q.push(currNode->left);
            }
            else{
                if(currNode->left) q.push(currNode->left);
                if(currNode->right) q.push(currNode->right);
            }
        }
        direction = direction ? 0 : 1;
    }
        return ans;
}

// Method -2 : Optimal version
// Here no reversing of DS queue is required because here we are using 2 stacks and stack mein elements reverse order mein hi nikalte hai so reverse karne mein jo time lag rha tha vo nahi lagega idhar
// T.C = O(n) n= no of nodes , SC = O(n) {for both stack}   # ek stack ka maximum size utna hoga jitna bottom mein leaf nodes honge jo ki maximum hote ha = (n/2 + 1).. ek stack mein elements honge to dusra stack khali hoga last level pe
vector<int> findSpiral(Node* root) {
    vector<int> ans;
    stack<Node*> LtoRStack;
    stack<Node*> RtoLStack;
    if(!root)   return ans;
    RtoLStack.push(root);
        
    while(!RtoLStack.empty() || !LtoRStack.empty()){
        while(!RtoLStack.empty()){
            Node* currNode = RtoLStack.top();
            RtoLStack.pop();
            ans.push_back(currNode->data);
            if(currNode->right) LtoRStack.push(currNode->right);
            if(currNode->left) LtoRStack.push(currNode->left);
        }
        
        while(!LtoRStack.empty()){
            Node* currNode = LtoRStack.top();
            LtoRStack.pop();
            ans.push_back(currNode->data);
            if(currNode->left) RtoLStack.push(currNode->left);
            if(currNode->right) RtoLStack.push(currNode->right);
        }
    }
    return ans;
}

int main(){
    
    return 0;
}