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

int MaxSum(Node* root,int&sum){
        // null
        if(!root)   return 0;
        // leaf node
        if(!root->left && !root->right) return root->data;
        // left side
        int left = MaxSum(root->left,sum);
        // right side
        int right = MaxSum(root->right,sum);
        
        if(!root->left){ // only right exist
            return right+root->data;
        }
        else if(!root->right){ // only left exist
            return left+root->data;
        }
        else{ // root ka left and right both exist
            sum = max(sum,left+right+root->data);
            if(left>=right) return left+root->data;
            else    return right+root->data;
        }
    }

    int maxPathSum(Node* root) {
        int sum = INT_MIN;
        int maxSum = MaxSum(root,sum);
        // edge case :- When root node have only one child and became special node
        // if root become special node
        if(!root->left || !root->right) return max(sum,maxSum);
        return sum;
    }

int main(){
    
    return 0;
}