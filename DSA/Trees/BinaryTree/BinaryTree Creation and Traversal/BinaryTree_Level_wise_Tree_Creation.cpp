#include <bits/stdc++.h>
using namespace std;

// Level wise Construction Of Binary Tree

class Node
{
    public:
    int data;
    Node* left,*right;

    Node(int val){
        data = val;
        left = right = nullptr;
    }
};


int main(){
    
    int rootEle;
    cout<<"Enter Root Element : ";
    cin>>rootEle;

    Node* root = new Node(rootEle);
    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
        Node* currNode = q.front();
        q.pop();
        int leftChildEle,rightChildEle;
        cout<<"Enter left Child of "<<currNode->data<<" : ";
        cin>> leftChildEle;

        cout<<"Enter right Child of "<<currNode->data<<" : ";
        cin>>rightChildEle;
        
        if(leftChildEle != -1){
            currNode->left = new Node(leftChildEle);
            q.push(currNode->left);
        }
        
        if(rightChildEle != -1){
            currNode->right = new Node(rightChildEle);
            q.push(currNode->right);
        }
    }
    
    return 0;
}