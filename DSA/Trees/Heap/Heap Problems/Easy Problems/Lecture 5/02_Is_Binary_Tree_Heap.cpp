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


 int CountNodes(Node* root){ // TC = O(n) , SC = O(h)
        if(!root)   return 0;
        return 1 + CountNodes(root->left) + CountNodes(root->right);
    }
    
    bool IsBSTAHeap(Node* root,int index,int N){ // TC = O(n) , SC = O(h)
        if(!root)   return 1;
        
        // index < size hona chaihye
        if(index >= N)  return 0;
        
        // Check left child if it is greater than the parent node or not
        if(root->left && root->left->data > root->data) return 0;
        
        // Check right child if it is greater than the parent node or not
        if(root->right && root->right->data > root->data) return 0;
        
        // Go to left side
        bool left = IsBSTAHeap(root->left,2*index+1,N);
        if(!left)   return 0;
        
        bool right = IsBSTAHeap(root->right,2*index+2,N);
        if(!right)   return 0;
        
        return 1;

    }

    // Optimal :-
    // TC = O(n) , SC = O(h)
    bool isHeap(Node* tree) { 
        int N = CountNodes(tree);
        return IsBSTAHeap(tree,0,N);
    }

int main(){
    queue<int>q;
    
    return 0;
}