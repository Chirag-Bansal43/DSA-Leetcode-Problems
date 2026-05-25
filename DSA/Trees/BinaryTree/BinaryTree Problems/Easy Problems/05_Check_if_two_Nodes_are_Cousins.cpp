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


bool parentFound(Node* root, int x,int y){
        // null
        if(!root) return 0;
        
        // preorder traversal of tree to find the required parent node
        // check curr node have x&y child or not
        if(root->left && root->left->data == x && root->right && root->right->data == y){
            return 1;
        }
        else if(root->left && root->left->data == y && root->right && root->right->data == x){
            return 1;
        }
        
        // find this type of node in left side
        int leftFound = parentFound(root->left,x,y);
        if(leftFound)   return 1;
        
        // find this type of node in right side
        int rightFound = parentFound(root->right,x,y);
        if(rightFound)   return 1;
        
        return 0;
    }

// Method1 : Optimal TC = O(2n) , SC = O(n) {for queue}
bool isCousins(Node* root, int x, int y) {
        int xlevel = -1;
        int ylevel = -1;
        
        queue<Node*> q;
        q.push(root);
        int level = 0;
        // level order traversal
        while(!q.empty()){
            int size = q.size();
            for(int i=0;i<size;i++){
                Node* currNode = q.front();
                q.pop();
                if(currNode->data == x){
                    xlevel = level;
                }
                else if(currNode->data == y){
                    ylevel = level;
                }
                
                if(currNode->left)  q.push(currNode->left);
                if(currNode->right) q.push(currNode->right);
            }
            
            level++;
            // agar iss level pe x ka index mil gya and y nahi mila matlab y alag level pe ha then simply return 0
            if(xlevel != ylevel)    return 0;
            // agar dono ka index same ha matlab ya to dono -1 ha ya dono same level pe ha too agar xlabel != -1 hota ha means dono x&y label != -1 ha and dono x&y ka level same ha means we can break the loop 
            // aur agar dono -1 ha matlab agle level pe jana padega
            if(xlevel != -1)    break;
        }
        
        // if any node not present in tree
        if(xlevel == -1 || ylevel == -1)    return 0;
        
        
        // levels are same now check both have same parents or not
        // find is there any parent exist in tree whose childrens are x and y
        return !parentFound(root,x,y);
    }

// Method2 : using recursion


int main(){
    
    return 0;
}