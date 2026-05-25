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

Node* CreateBST(Node* root,int strange,int endrange,int* arr,int n,int& index){
    // base case
    if(index<0) return nullptr; 
    
    // node
    if(arr[index] > strange && arr[index]<endrange){
        root = new Node(arr[index]);
        index--;
    }
    else return nullptr;
    
    // right side
    root->right = CreateBST(root->right,root->data,endrange,arr,n,index);
    
    // left side 
    root->left = CreateBST(root->left,strange,root->data,arr,n,index);
    
    return root;
}

Node *constructTree(int post[], int size) {
    Node* root = nullptr;
    int index = size-1;
    root = CreateBST(root,INT_MIN,INT_MAX,post,size,index);
    return root;
}

int main(){
    
    return 0;
}