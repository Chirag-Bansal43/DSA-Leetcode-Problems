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

// Iteratively
Node* CreateBST01(vector<int>& arr){
    Node* root = new Node(arr[0]);

    for(int i=1;i<arr.size();i++){
        Node* newNode = new Node(arr[i]);
        Node* temp = root;
        while(true){
            if(arr[i]<=temp->data){
                if(!temp->left) break;
                else    temp=temp->left;
            }
            else{
                if(!temp->right) break;
                else    temp=temp->right;
            }
        }
        arr[i]<=temp->data ? temp->left = newNode : temp->right = newNode; 
    }
    return root;
}

void PreOrder(Node* root){
    if(root == nullptr) return;
    cout<<root->data<<" ";
    PreOrder(root->left);
    PreOrder(root->right);
}

int main(){
    vector<int> arr = {8,4,3,6,11,13,12,5,8};
    Node* root = CreateBST01(arr);
    PreOrder(root);
    return 0;
}