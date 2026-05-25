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

void inorder(Node* root,vector<int>& in){
        if(!root)   return;
        
        inorder(root->left,in);
        in.push_back(root->data);
        inorder(root->right,in);
    }
    
    void postorderTraversal(Node* root,vector<int>& post,int& index){
        if(!root)   return;
        
        // left mein jaao
        postorderTraversal(root->left,post,index);
        
        // right mein jaoo
        postorderTraversal(root->right,post,index);
        
        // node ka value update karo
        root->data = post[index++];
    }

    // TC = O(n) , SC = O(n)
    void convertToMaxHeapUtil(Node* root) {
        vector<int> in; // inorder of BST
        inorder(root,in);
        
        // humko kya karna hai ki iske inorder traversal ko iska hi postorder traversal bana dena hai to humko apna special MaxHeap mil jayega
        /*jisme 1. parent node is greatest among it's child
                2. All nodes left child is less than all nodes of right child
                
                Dono property statisfy hongi
        */
        
        int index = 0;
        postorderTraversal(root,in,index);
    }

int main(){
    
    return 0;
}