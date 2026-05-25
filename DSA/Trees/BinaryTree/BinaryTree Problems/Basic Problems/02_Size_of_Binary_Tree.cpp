#include <bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};

// M - 2
int size02(Node* node){
    if(node == nullptr) return 0;
    return 1 + size02(node->left) + size02(node->right);
}

// M - 1
void size(Node* node,int& count){
    if(node == nullptr) return;
    count++;
    // left side
    size(node->left,count);
    // right side
    size(node->right,count);
    
    }

int main(){
    int count = 0;
    Node* root;
    size(root,count);
    cout<< count;
    return 0;
}