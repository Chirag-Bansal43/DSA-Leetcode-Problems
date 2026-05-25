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

// Optimal solution : TC = O(n) , SC = O(1)
int Burn(Node* root,int target,int& Timer,Node*& targetAdd){
        // null
        if(!root)   return 0;
        // target
        if(root->data == target){
            targetAdd = root;
            return -1;
        }
        
        int left = Burn(root->left,target,Timer,targetAdd);
        int right = Burn(root->right,target,Timer,targetAdd);
        if(left<0){
            Timer = max(Timer,right+abs(left));
            return left-1;
        }
        else if(right<0){
            Timer = max(Timer,left+abs(right));
            return right-1;
        }
        else{
            return 1+max(left,right);
        }
    }
    int Height(Node* root){
        //null
        if(!root)   return 0;
        // left side
        int left = Height(root->left);
        // right side
        int right = Height(root->right);
        
        return 1+max(left,right);
    }

    int minTime(Node* root, int target) {
        int Timer = 0;
        Node* targetAdd;
        Burn(root,target,Timer,targetAdd);
        int heig = Height(targetAdd);
        
        return max(Timer,heig-1);
    }

// Method 2: Better Solution

void BurnPath(Node* root,int target,vector<Node*>& path){
        // null
        if(!root)   return;
        // target
        if(root->data == target){
            path.push_back(root);
            return;
        }
        
        // left side
        BurnPath(root->left,target,path);
        if(path.size()){
            path.push_back(root);
            return;
        }
        
        // right side
        BurnPath(root->right,target,path);
        if(path.size()){
            path.push_back(root);
            return;
        }
    }
    int Height(Node* root){
        if(!root)   return 0;
        return 1+max(Height(root->left),Height(root->right));
    }

int minTime(Node* root, int target) {
        vector<Node*> path;
        vector<int> leftHeig;
        vector<int> rightHeig;
        
        // find path from root node to burn node
        BurnPath(root,target,path);
        
        // find left and right heights of nodes present in path array
        for(int i=0;i<path.size();i++){
            leftHeig.push_back(Height(path[i]->left));
            rightHeig.push_back(Height(path[i]->right));
        }
        
        // Finding maximum time
        int Timer = 0;
        for(int i=1;i<path.size();i++){
            if(path[i]->left == path[i-1]){
                Timer = max(Timer,i+rightHeig[i]);
            }
            else{
                Timer = max(Timer,i+leftHeig[i]);
            }
        }
        
        // height below target
        int heiBelTar = max(leftHeig[0],rightHeig[0]);
        return max(Timer,heiBelTar);
    }

int main(){
    
    return 0;
}