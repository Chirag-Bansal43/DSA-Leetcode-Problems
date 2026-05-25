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

// Brilliant Solution Mind Blowing
// Iterative Solution TC = O(n) SC = O(n) {here heap space is used by stl stacks}
int canRepresentBST(int arr[], int N) {
        stack<int> lower;   lower.push(INT_MIN);
        stack<int> upper;   upper.push(INT_MAX);
        int index = 0;
        while(index<N){
            // can't form BST with that node in preorder
            if(arr[index] < lower.top())    return 0;
            
            while(arr[index] > upper.top()){
                lower.pop();    upper.pop();
            }
            
            // Now element is in the range present in stack
            int low = lower.top();  lower.pop();
            int high = upper.top(); upper.pop();
            // pushing right range of newly inserted node
            lower.push(arr[index]);     upper.push(high);
            // pushing left range of newly inserted node
            lower.push(low);    upper.push(arr[index]);
            index++;
        }
        return 1;
    }

//------------------------------------------------------------------------------------
// Recursive Solution
//TC = O(n) SC = O(n) {stack space is used for recurrsive calls}
// Method - 1: using recursion TC = O(n) , SC = O(n) but here space used in stack, recurrsion calls are present in stack memory so stack memory can overflow because of our recussion calls (because of gfg server issue)
    // So in this question we have to solve it iterativelly using stack from stl library because DS from stl (stacks or vectors) stores there value in heap not in stack so in this case memory stack won't overflow
    Node* CreateBST(Node* root,int strange,int endrange,int *arr,int N,int& index){
        // base case
        if(index == N) return nullptr;

        // node
        if(arr[index]>strange && arr[index]<endrange){
            root = new Node(arr[index]);
            index++;
        }
        else    return nullptr;

        // left side 
        root->left = CreateBST(root->left,strange,root->data,arr,N,index);

        // right side
        root->right = CreateBST(root->right,root->data,endrange,arr,N,index);

        return root;
    }

    int canRepresentBST(int arr[], int N) {
        Node* root = nullptr;
        int index = 0;
        root = CreateBST(root,INT_MIN,INT_MAX,arr,N,index);
        if(index < N){
            return 0;
        }
        else return 1;
    }

int main(){
    
    return 0;
}