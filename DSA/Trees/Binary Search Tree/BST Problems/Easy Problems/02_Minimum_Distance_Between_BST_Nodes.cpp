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

void MinDiff(Node* root,int& prev,int& Diff){
        //null
        if(!root)   return;
        // left side
        MinDiff(root->left,prev,Diff);
        // node
        if(prev != INT_MIN)
            Diff = min(Diff,abs(root->data-prev));
        prev = root->data;
        //right side
        MinDiff(root->right,prev,Diff);
    }

    int minDiffInBST(Node* root) {
        int prev = INT_MIN;
        int Diff = INT_MAX;
        MinDiff(root,prev,Diff);
        return Diff;
    }

int main(){
    
    return 0;
}