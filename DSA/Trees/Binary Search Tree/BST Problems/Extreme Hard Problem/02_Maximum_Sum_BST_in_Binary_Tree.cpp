#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node(int val) {
        this->val = val;
        left = right = nullptr;
    }
};


// Deeto same ha previous question se copy paste maaro code baas

class Box {
    public:
    bool BST;
    int sum,min,max;
    Box(){
        BST = 1;
        sum = 0;
        min = INT_MAX;
        max = INT_MIN;
    }
};


Box* largBST(Node* root,int& MaxSum){
        // root is null
        if(!root)
            return new Box();
        
        // root is a non null node
        Box* Lhead = largBST(root->left,MaxSum);
        Box* Rhead = largBST(root->right,MaxSum);
        if(Lhead->BST && Rhead->BST && Lhead->max < root->val && Rhead->min > root->val){
            Box* head = new Box();
            head->sum = root->val + Lhead->sum + Rhead->sum;
            head->min = min(Lhead->min,root->val);
            head->max = max(Rhead->max,root->val);
            MaxSum = max(MaxSum,head->sum);
            return head;
        }
        else{
            Lhead->BST = 0;
            return Lhead;
        }
    }

    int maxSumBST(Node* root) {
        int MaxSum = 0;
        
        largBST(root,MaxSum);
        
        return MaxSum;
    }

int main(){
    
    return 0;
}