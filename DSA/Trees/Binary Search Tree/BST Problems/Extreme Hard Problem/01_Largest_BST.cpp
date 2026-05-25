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

// solution written by me : Brute force TC = O(n^2) , SC = O(h)
    int CheckBST(Node* root,int& count,Node*& prev){
        if(!root)   return 0;
        
        if(root->left){
            int cntLeft = CheckBST(root->left,count,prev);
            if(!cntLeft)    return 0;
        }
        
        // node
        if(prev && root->data <= prev->data){
            count = 0;
            return count;
        }
        else{
            count++;
            prev = root;
        }
        
        if(root->right){
            int cntRight = CheckBST(root->right,count,prev);
            if(!cntRight)   return 0;
        }
        
        return count;
    }
    
    void largBST01(Node* root,int& MaxCount){
        if(!root)   return;
        
        // check for complete tree containing root node
        int count = 0;  Node* prev = nullptr;
        int size = CheckBST(root,count,prev);
        MaxCount = max(MaxCount,size);
        
        if(size == 0){
            // left side 
            largBST01(root->left,MaxCount);
        
            // right side
            largBST01(root->right,MaxCount);
        }
    }

    int largestBst(Node *root) {
        int MaxCount = 0;
        
        largBST01(root,MaxCount);
        
        return MaxCount;
    }


    // Optimal solution : Very Unique Concept that is make class and you can return multiple information at a time
    // TC = O(n)    SC = O(h)
    class box {
        public:
        bool BST;
        int size,min,max;
        box(int value){
            BST = 1;
            size = 1;
            min = value;
            max = value;
        }
    };

    box* largeBST(Node* root,int& MaxCount){
        // root is leaf node
        if(!root->left && !root->right){
            box* head = new box(root->data);
            MaxCount = max(MaxCount,head->size);
            return head;
        }
        // root has only left child
        else if(root->left && !root->right){
            box* head = largeBST(root->left,MaxCount);
            if(head->BST && head->max < root->data){
                head->max = root->data;
                head->size++;
                MaxCount = max(MaxCount,head->size);
                return head;
            }
            else{
                head->BST = 0;
                return head;
            }
        }
        // root has only right child
        else if(root->right && !root->left){
            box* head = largeBST(root->right,MaxCount);
            if(head->BST && head->min > root->data){
                head->min = root->data;
                head->size++;
                MaxCount = max(MaxCount,head->size);
                return head;
            }
            else{
                head->BST = 0;
                return head;
            }
        }
        // root hase both left and right child
        else{
            box* Lhead = largeBST(root->left,MaxCount);
            box* Rhead = largeBST(root->right,MaxCount);
            if(Lhead->BST && Rhead->BST && Lhead->max < root->data && Rhead->min > root->data){
                box* head = new box(Lhead->min);
                head->max = Rhead->max;
                head->size = 1 + Lhead->size + Rhead->size;
                MaxCount = max(MaxCount,head->size);
                return head;
            }
            else{
                Lhead->BST = 0;
                return Lhead;
            }
        }
    }

    int largestBst(Node *root) {
        int MaxCount = 0;
        
        largeBST(root,MaxCount);
        
        return MaxCount;
    }

// or same concept written in short code

class Box {
    public:
    bool BST;
    int size,min,max;
    Box(){
        BST = 1;
        size = 0;
        min = INT_MAX;
        max = INT_MIN;
    }
};

Box* largBST(Node* root,int& MaxCount){
        // root is null
        if(!root)
            return new Box();
        
        // root is a non null node
        Box* Lhead = largBST(root->left,MaxCount);
        Box* Rhead = largBST(root->right,MaxCount);
        if(Lhead->BST && Rhead->BST && Lhead->max < root->data && Rhead->min > root->data){
            Box* head = new Box();
            head->size = 1 + Lhead->size + Rhead->size;
            head->min = min(Lhead->min,root->data);
            head->max = max(Rhead->max,root->data);
            MaxCount = max(MaxCount,head->size);
            return head;
        }
        else{
            Lhead->BST = 0;
            return Lhead;
        }
    }

    int largestBst(Node *root) {
        int MaxCount = 0;
        
        largBST(root,MaxCount);
        
        return MaxCount;
    }

int main(){
    
    return 0;
}