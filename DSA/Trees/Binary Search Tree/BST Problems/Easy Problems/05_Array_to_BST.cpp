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

Node* CreateBST(Node* root,int st,int end,vector<int>& arr){
        // base case
        if(st>end)  return nullptr;
        
        // node
        int mid = (st+end)/2;
        root = new Node(arr[mid]);
        
        // create left subtree
        root->left = CreateBST(root->left,st,mid-1,arr);
        // create right subtree
        root->right = CreateBST(root->right,mid+1,end,arr);
        
        return root;
    }

    Node* sortedArrayToBST(vector<int>& arr) {
        int start = 0;
        int end = arr.size()-1;
        Node* root = nullptr;
        root = CreateBST(root,start,end,arr);
        return root;
    }

int main(){
    
    return 0;
}