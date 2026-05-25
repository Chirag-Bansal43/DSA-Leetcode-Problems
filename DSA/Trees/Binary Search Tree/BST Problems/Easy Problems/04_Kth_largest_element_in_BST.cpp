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

int KthLargest(Node* root,int& count,int k){
        if(!root)   return 0;
        // right side
        int ans = KthLargest(root->right,count,k);
        if(ans) return ans;
        // node
        count++;
        if(count == k){
            return root->data;
        }
        // left side
        ans = KthLargest(root->left,count,k);
        if(ans) return ans;
        return 0;
    }

    int kthLargest(Node *root, int k) {
        // Your code here
        int count = 0;
        return KthLargest(root,count,k);
    }

int main(){
    
    return 0;
}