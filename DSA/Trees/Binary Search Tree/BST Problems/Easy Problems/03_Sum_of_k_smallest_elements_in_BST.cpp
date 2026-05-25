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

void SumKEle(Node* root,int& k,int& sum){
    if(!root)   return;
    // left side
    SumKEle(root->left,k,sum);
    
    if(k){
        sum += root->data;
        k--;
    }
    else    return;
    // right side
    SumKEle(root->right,k,sum);
}

int sum(Node* root, int k) {
    int sum = 0;
    SumKEle(root,k,sum);
    return sum;
}

int main(){
    
    return 0;
}