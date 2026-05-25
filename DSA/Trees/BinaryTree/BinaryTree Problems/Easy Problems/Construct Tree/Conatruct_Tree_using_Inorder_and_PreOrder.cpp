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

// TC = O(n^2) , SC = O(n) {recursive call}

int Find(int ele,vector<int>& in,int inStart,int inEnd){
        for(int i=inStart;i<=inEnd;i++){
            if(in[i] == ele){
                return i;
            }
        }
        return -1;
    }
    
    Node* Tree(int inStart,int inEnd,int index,vector<int>& in,vector<int>& pre){
        // base condition
        if(inStart>inEnd)   return nullptr;
        
        // create node
        Node* root = new Node(pre[index]);
        
        // Find it in inorder array
        int pos = Find(pre[index],in,inStart,inEnd);
        
        // left side tree construct
        root->left = Tree(inStart,pos-1,index+1,in,pre);
        // right tree construct
        root->right = Tree(pos+1,inEnd,index+pos-inStart+1,in,pre);
        
        return root;
    }

     Node *buildTree(vector<int> &inorder, vector<int> &preorder) {
        int inStart=0,inEnd=inorder.size()-1,index=0;
        Node* root = Tree(inStart,inEnd,index,inorder,preorder);
        return root;
    }

int main(){
    
    return 0;
}