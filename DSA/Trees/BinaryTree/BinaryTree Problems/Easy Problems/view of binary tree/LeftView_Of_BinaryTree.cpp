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

// Method 1 : using queue DS
vector<int> leftView(Node *root) {
        vector<int> ans;
        // inserting first element of each level into ans vector by doing level order traversal
        queue<Node*> q;
        if(!root) return ans;
        q.push(root);
        
        while(!q.empty()){
            int size = q.size();
            ans.push_back(q.front()->data);
            for(int i=0;i<size;i++){
                Node* currNode = q.front();
                q.pop();
                if(currNode->left)  q.push(currNode->left);
                if(currNode->right)  q.push(currNode->right);
            }
        }
        return ans;
    }

// Method 2 : using recurrsion (finding level of node using recussion)

// Optimal solution TC = O(n) => doing one time traversal of tree , SC = O(n) {for recursion}
// Concept :- agar ans array ka size current node ke level ke baarabar hota hai matlab that particular node pheli baar visit ho rha ha
// node ka level batata hai uske uppar kitne levels aa chuke ha to utne hi elements ans array mein hone chaihye agar usse jyada hote hai matlab vo particular level ek se jyada baar visit hua ha

void Lview(Node* root,int level,vector<int>& ans){
    if(!root)   return;
    // first time level visit => insert the node's data in ans
    if(level == ans.size()){
        ans.push_back(root->data);
    }
    // left side
    Lview(root->left,level+1,ans);
    // right side
    Lview(root->right,level+1,ans);
}

vector<int> leftView(Node *root) {
    vector<int> ans;
    // preorder traversal and fill ans with left view elements
    Lview(root,0,ans); // O(n) TC , SC = O(n) {in recursion} in worst case
    return ans;
}

// Better Solution TC = O(2n) => doing two time traversal of tree , SC = O(2n) {for visited array and recursion}
int height(Node* root){
    if(!root)   return 0;
    return 1 + max(height(root->left),height(root->right));
}
void preOrder01(Node* root,int level,vector<int>& visited,vector<int>& ans){
    
    if(!root)   return;
    
    if(!visited[level]){
        ans[level] = root->data;
        visited[level]++;
    }
    
    // left side
    preOrder01(root->left,level+1,visited,ans);
    
    // right side
    preOrder01(root->right,level+1,visited,ans);
    
}

vector<int> leftView(Node *root) {
    int heig = height(root); //O(n) TC , SC = O(n) {in recursion} in worst case when height of tree = no.of nodes
    vector<int> visited(heig,0); // O(n) SC
    vector<int> ans(heig,0);
    
    // preorder traversal and fill ans with left view elements
    preOrder01(root,0,visited,ans); // O(n) TC , SC = O(n) {in recursion} in worst case
    
    return ans;
    
}


int main(){
    
    return 0;
}