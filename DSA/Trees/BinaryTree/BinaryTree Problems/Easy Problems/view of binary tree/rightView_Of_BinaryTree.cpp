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
vector<int> rightview(Node *root) {
        vector<int> ans;
        // inserting first element of each level into ans vector by doing level order traversal
        queue<Node*> q;
        if(!root) return ans;
        q.push(root);
        
        while(!q.empty()){
            int size = q.size();
            ans.push_back(q.back()->data); // q.front() ki jagah q.back() likh do baas
            for(int i=0;i<size;i++){
                Node* currNode = q.front();
                q.pop();
                if(currNode->left)  q.push(currNode->left);
                if(currNode->right)  q.push(currNode->right);
            }
        }
        return ans;
    }

    // aur agar q.front() hi likhna hai to phele right child daal do then left child daalo queue mein taki back element queue ke front mein aa jaye
    vector<int> rightview(Node *root) {
        vector<int> ans;
        // inserting first element of each level into ans vector by doing level order traversal
        queue<Node*> q;
        if(!root) return ans;
        q.push(root);
        
        while(!q.empty()){
            int size = q.size();
            ans.push_back(q.front()->data); // q.front() ki jagah q.back() likh do baas
            for(int i=0;i<size;i++){
                Node* currNode = q.front();
                q.pop();
                if(currNode->right)  q.push(currNode->right);
                if(currNode->left)  q.push(currNode->left);
            }
        }
        return ans;
    }

// Method 2 using recursion
void Rview(Node* root,int level,vector<int>& ans){
        if(!root)   return;
        
        // right mein jaao nodes ko dhekho agar right side element ke level pe pheli baar aaye ho to usko ans mein insert kardo nahi to skip karo
        if(level == ans.size()){ // means visiting this level first time
            ans.push_back(root->data);
        }
        
        // Right side ko phele visit karo (right side se preOrder traversal suru karo)
        Rview(root->right,level+1,ans);
        Rview(root->left,level+1,ans);
    }

vector<int> rightView(Node *root) {
        vector<int> ans;
        // tree ko right side se traverse karna start karo
        Rview(root,0,ans);
        return ans;
    }

int main(){
    
    return 0;
}