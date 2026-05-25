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

// Method 1 : using recursion
// same as top view baas higher level wala node lena hai
void Find(Node* root,int pos,int& l,int& r){ // pos = x position
    if(!root)   return;
    l = min(l,pos);
    r = max(r,pos);
    
    //left side
    Find(root->left,pos-1,l,r);
    
    // right side
    Find(root->right,pos+1,l,r);
}

void Bview(Node* root, int index,int l,vector<int>& ans,vector<int>& level){ // l = currnodeLevel
    if(!root)   return;
    
    // if currnode have less level than written in level array update level array and ans array
    if(l >= level[index]){
        level[index] = l;
        ans[index] = root->data;
    }
    
    // Left Side
    Bview(root->left,index-1,l+1,ans,level);
    
    // right side
    Bview(root->right,index+1,l+1,ans,level);
}

vector<int> bottomView(Node *root) {
    // Step 1 : Find Xlevel of left most node and right most node
    int l=0,r=0; // l = left most X position , r = right most X position
    Find(root,0,l,r);
    
    // step 2 : Make ans and visited array of size r-l+1
    vector<int> ans(r-l+1);
    vector<int> level(r-l+1,INT_MIN);
    
    // Solved using pre order traversal using recursion without queue
    Bview(root,-1*l,0,ans,level);
    
    return ans;
}