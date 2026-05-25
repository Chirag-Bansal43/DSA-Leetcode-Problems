#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    int height;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

int getHeight(Node* root){
    if(!root)   return 0;
    return root->height;
}

Node* leftRotation(Node* root){
    // Define Child
    Node* child = root->right;
    // ChildLeft ka address store karlo
    Node* ChildLeft = child->left;
    
    child->left = root;
    root->right = ChildLeft;

    // Update height of root and child
    root->height = 1 + max(getHeight(root->left),getHeight(root->right));
    child->height = 1 + max(getHeight(child->left),getHeight(child->right));

    return child;
}

Node* rightRotation(Node* root){
    // Define Child
    Node* child = root->left;
    // ChildRight ka address store karlo
    Node* ChildRight = child->right;
    
    child->right = root;
    root->left = ChildRight;

    // Update height of root and child
    root->height = 1 + max(getHeight(root->left),getHeight(root->right));
    child->height = 1 + max(getHeight(child->left),getHeight(child->right));

    return child;
}

Node* DeleteFromAVL(Node* root,int value){
    // base case
    if(!root)   return nullptr;

    // Find the node in the tree
    if(root->data < value){
        // right mein dhundo
        root->right = DeleteFromAVL(root->right,value);
    }
    else if(root->data > value){
        // left mein dhundo
        root->left = DeleteFromAVL(root->left,value);
    }
    else{
        // node found
        // Type of node :- Node can be Leaf node, Node with one child , Node having two child
        if(!root->left && !root->right){
            delete root;
            return nullptr;
        }
        else if(root->left && !root->right){
            Node* temp = root->left;
            delete root;
            return temp;
        }
        else if(!root->left && root->right){
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else{
            // Dono child ha
            Node* curr = root->right;
            while(curr->left){
                curr=curr->left;
            }
            // Replace root->data with curr->data
            root->data = curr->data;
            
            // Abb right side jakar root->data wali value wale node ko delete kardo
            root->right = DeleteFromAVL(root->right,root->data);
        }
    }

    // Now Return aate wakt
    // Update height of uppar wale nodes
    root->height = 1 + max(getHeight(root->left),getHeight(root->right));

    // Check the node is balanced or not
    int diff = getHeight(root->left) - getHeight(root->right);
    if(diff < -1){ // right unbalance (RR or RL)
        // Find height difference of root->right wala node ka
        int RightDiff = getHeight(root->right->left) - getHeight(root->right->right);
        if(RightDiff <= 0){ // right mein jyada ya equal nodes ha left se
            // So, here RR unbalance occurs || Equal ke case mein RR or RL dono mein se koi bhi unbalance laga sakte ha
            return leftRotation(root);
        }
        else{
            // RL unbalance
            root->right = rightRotation(root->right);
            return leftRotation(root);
        }
    }
    else if(diff > 1){ // left unbalance
        // Find height difference of root->left wala node ka
        int LeftDiff = getHeight(root->left->left) - getHeight(root->left->right);
        if(LeftDiff >= 0){ // left mein jyada ya equal nodes ha right se
            // So, here LL unbalance occurs || Equal ke case mein LL or LR dono mein se koi bhi unbalance laga sakte ha
            return rightRotation(root);
        }
        else{
            // LR unbalance
            root->left = leftRotation(root->left);
            return rightRotation(root);
        }
    }
    else{
        // No unbalance
        return root;
    }
}

int main(){
    
    return 0;
}