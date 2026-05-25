#include <bits/stdc++.h>
using namespace std;

class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor
    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};


vector<vector<int>> levelOrder(Node *root) { // T.C = O(n) , n = no. of nodes
        vector<vector<int>> ans;
        if(!root)   return ans;
        queue<Node*> q; // SC = O(n/2 + 1) in worst case => equivalent to O(n) , n = no. of nodes
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            vector<int> level;
            for(int i=0;i<size;i++){
                Node* currNode = q.front();
                q.pop();
                level.push_back(currNode->data);
                if(currNode->left){
                    q.push(currNode->left);
                }
                if(currNode->right){
                    q.push(currNode->right);
                }
            }
            ans.push_back(level);
        }
        return ans;
    }

int main(){
    
    return 0;
}