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

// Optimal solution
// TC = O(n) SC = O(h) {recursive}
Node* CreateBST(Node* root,int strange,int endrange,vector<int>& arr,int& index){
        // base case
        if(index == arr.size()) return nullptr;

        // node
        if(arr[index]>strange && arr[index]<endrange){
            root = new Node(arr[index]);
            index++;
        }
        else    return nullptr;

        // left side 
        root->left = CreateBST(root->left,strange,root->data,arr,index);

        // right side
        root->right = CreateBST(root->right,root->data,endrange,arr,index);

        return root;
    }

    Node* bstFromPreorder(vector<int>& preorder) {
        Node* root = nullptr;   int index = 0;
        root = CreateBST(root,INT_MIN,INT_MAX,preorder,index);
        return root;
    }

//------------------------------------------------------------------------------------------------
// Method - 2
// TC = O(n*h) or O(n^2) in worst case
// SC = O(h) (recursive)
    Node* CreateBST(Node* root,int st,int end,vector<int>& arr){
        //base case
        if(st>end)  return nullptr;

        // node
        root = new Node(arr[st]);

        int i;
        for(i=st+1;i<=end;i++){
            if(arr[i]>arr[st]){
                // create left subtree
                root->left = CreateBST(root->left,st+1,i-1,arr);
                // create right subtree
                root->right = CreateBST(root->right,i,end,arr);
                break;
            }
        }

        // No greater element from node in array means only left subtree exist
        // create left subtree
        // edge case
        if(i == end+1)
            root->left = CreateBST(root->left,st+1,end,arr);

        return root;
    }

    Node* bstFromPreorder(vector<int>& preorder) {
        Node* root = nullptr;
        root = CreateBST(root,0,preorder.size()-1,preorder);
        return root;
    }

    //----------------------------------------------------------------------------------------------------
    // Method - 3
    // TC = O(n*h) or O(n^2) in worst case
    // SC = O(h) (recursive)
    Node* InsertNode(Node* root,int value){
        // base case
        if(!root){
            return new Node(value);
        }
        
        if(value<= root->data){
            // left side
            root->left = InsertNode(root->left,value);
        }
        else{
            // right side
            root->right = InsertNode(root->right,value);
        }

        return root;
    }

    Node* bstFromPreorder(vector<int>& preorder) {
        Node* root = nullptr;
        for(int i=0;i<preorder.size();i++){
            root = InsertNode(root,preorder[i]);
        }
        return root;
    }

int main(){
    
    return 0;
}