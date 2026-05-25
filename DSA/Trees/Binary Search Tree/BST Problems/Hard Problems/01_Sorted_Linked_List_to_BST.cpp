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

// Easy ha pata nahi hard mein kyu daal diya

struct LNode { //Linked List
    int data;
    struct LNode* next;
    LNode(int x){
        data = x;
        next = NULL; }
};
struct TNode {   //Tree
    int data;
    struct TNode* left;
    struct TNode* right;
    TNode(int x){
        data=x;
        left=right=NULL; }
}; 

// TC = O(2n) SC = O(n) {converting LL into array}
TNode* buildBST(vector<int>& arr,int st,int end){
        //base case
        if(st > end)    return nullptr;
        
        int mid = st + (end-st+1)/2;
        
        // node
        TNode* root = new TNode(arr[mid]);
        
        // left subtree
        root->left = buildBST(arr,st,mid-1);
        
        // right subtree
        root->right = buildBST(arr,mid+1,end);
        
        return root;
    }

     TNode *sortedListToBST(LNode *head) {
        // Copying LL to array
        vector<int> arr;
        while(head){
            arr.push_back(head->data);
            head=head->next;
        }
        
        return buildBST(arr,0,arr.size()-1);
    }


    // Solve this problem without converting LL into array in O(1) space How ?? 
    

int main(){
    
    return 0;
}