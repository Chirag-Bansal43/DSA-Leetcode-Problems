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


vector<int> largestValues(Node* root) {
        // code here
        vector<int> ans;
        if(!root)   return ans;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            int maxEle = INT_MIN;
            for(int i=0;i<size;i++){
                Node* currNode = q.front();
                q.pop();
                maxEle = max(maxEle,currNode->data);
                if(currNode->left)  q.push(currNode->left);
                if(currNode->right)  q.push(currNode->right);
            }
            ans.push_back(maxEle);
        }
    }

int main(){
    
    return 0;
}