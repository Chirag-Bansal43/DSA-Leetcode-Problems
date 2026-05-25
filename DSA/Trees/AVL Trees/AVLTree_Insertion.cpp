#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* left, *right;
    int height;

    Node(int val) {
        data = val;
        left = right = nullptr;
        height = 1;
    }
};

int getheight(Node* root){
    if(!root)   return 0;
    return root->height;
}

Node* leftRotation(Node* root){
    // 1. Define child
    Node* child = root->right;
    // 2. Define child->left
    Node* childLeft = child->left;
    // 3. Put root in child ka left mein
    child->left = root;
    // 4. Put childLeft node in root ka right mein
    root->right = childLeft;
    // 5. Update height of root and child
    root->height = 1+ max(getheight(root->left) , getheight(root->right));
    child->height = 1+ max(getheight(child->left) , getheight(child->right));
    // 6. return address of child node
    return child;
}

Node* rightRotation(Node* root){
    // 1. Define child
    Node* child = root->left;
    // 2. Define child->right
    Node* childRight = child->right;
    // 3. Put root in child ka right mein
    child->right = root;
    // 4. Put childRight node in root ka left mein
    root->left = childRight;
    // 5. Update height of root and child
    root->height = 1+ max(getheight(root->left) , getheight(root->right));
    child->height = 1+ max(getheight(child->left) , getheight(child->right));
    // 6. return address of child node
    return child;
}


Node* InsertInAVL(Node* root,int value){
    // if root is null => make new node and return it's address (perform insertion here)
    if(!root)   
        return new Node(value);
    
    // root is not null
    if(value < root->data){
        // go to left side
        root->left = InsertInAVL(root->left,value);
    }
    else if(value > root->data){
        // go to right side
        root->right = InsertInAVL(root->right,value);
    }
    else{ // value == root->data {duplicates are not allowed to insert}
        return root;
    }

    // Now function is returning back
    //1. Update the node's height
    root->height = 1 + max(getheight(root->left) , getheight(root->right));

    //2. Check the node is balanced or not
    int diff = getheight(root->left) - getheight(root->right);
    
    if(diff < -1){  // right side unbalance
        if(root->right->data < value)   // RR unbalance
            return leftRotation(root);
        else{   // RL unbalance
            root->right = rightRotation(root->right);
            return leftRotation(root);
        }
    }
    else if(diff > 1){ // left side unbalance
        if(root->left->data > value)    // LL unbalance
            return rightRotation(root);
        else{   // LR unbalance
            root->left = leftRotation(root->left);
            return rightRotation(root);
        }
    }
    else
        return root;

}

void PreOrder(Node* root){
    if(!root)   return;

    cout<<root->data<<" ";
    PreOrder(root->left);
    PreOrder(root->right);
}

void InOrder(Node* root){
    if(!root)   return;

    InOrder(root->left);
    cout<<root->data<<" ";
    InOrder(root->right);
}

int main(){
    
    Node* root = nullptr;
    
    root = InsertInAVL(root,11);
    root = InsertInAVL(root,7);
    root = InsertInAVL(root,15);
    root = InsertInAVL(root,5);
    root = InsertInAVL(root,9);
    root = InsertInAVL(root,10);

    cout<<"PreOrder : ";
    PreOrder(root);
    cout<<"\nInOrder : ";
    InOrder(root);
    cout<<endl;


    return 0;
}