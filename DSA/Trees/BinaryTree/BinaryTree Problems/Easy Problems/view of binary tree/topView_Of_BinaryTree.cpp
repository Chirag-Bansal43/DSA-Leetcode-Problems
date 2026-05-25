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

void Find(Node* root,int pos,int& l,int& r){ // pos = x position
        if(!root)   return;
        l = min(l,pos);
        r = max(r,pos);
        
        //left side
        Find(root->left,pos-1,l,r);
        
        // right side
        Find(root->right,pos+1,l,r);
    }
    
// Method 1 : Solved using level order traversal using queue
// TC = O(n) , SC = O(n)
void Tview(Node* root, int RootIndex,vector<int>& ans,vector<bool>& visited){
    // Solved using level order traversal using queue
    queue<Node*> q;
    queue<int> index;
    q.push(root);
    index.push(RootIndex);
    
    while(!q.empty()){
        int size = q.size();
        for(int i=0;i<size;i++){
            Node* currNode = q.front();
            int pos = index.front(); // here pos = current node Index
            q.pop();
            index.pop();
            if(!visited[pos]){
                ans[pos] = currNode->data;
                visited[pos] = 1;
            }
            if(currNode->left){
                q.push(currNode->left);
                index.push(pos-1);
            }
            if(currNode->right){
                q.push(currNode->right);
                index.push(pos+1);
            }
        }
    }
}

vector<int> topView(Node *root) {
    // Step 1 : Find Xlevel of left most node and right most node
    int l=0,r=0; // l = left most X position , r = right most X position
    Find(root,0,l,r);
    
    // step 2 : Make ans and visited array of size r-l+1
    vector<int> ans(r-l+1);
    vector<bool> visited(r-l+1,0);
    
    int RootIndex = abs(l);
    
    // Solved using level order traversal using queue
    Tview(root,RootIndex,ans,visited);
    
    return ans;
}

// Method 2 : Solve using Preorder traversal using recursion without queue

   void Tview(Node* root, int index,int l,vector<int>& ans,vector<int>& level){ // l = currnodeLevel
        if(!root)   return;
        
        // if currnode have less level than written in level array update level array and ans array
        if(l < level[index]){
            level[index] = l;
            ans[index] = root->data;
        }
        
        // Left Side
        Tview(root->left,index-1,l+1,ans,level);
        
        // right side
        Tview(root->right,index+1,l+1,ans,level);
    }

vector<int> topView(Node *root) {
        // Step 1 : Find Xlevel of left most node and right most node
        int l=0,r=0; // l = left most X position , r = right most X position
        Find(root,0,l,r);
        
        // step 2 : Make ans and visited array of size r-l+1
        vector<int> ans(r-l+1);
        vector<int> level(r-l+1,INT_MAX);
        
        // Solved using pre order traversal using recursion without queue
        Tview(root,-1*l,0,ans,level);
        
        return ans;
    }





int main(){
    
    return 0;
}