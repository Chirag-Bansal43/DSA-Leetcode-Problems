
struct Node
{
    int data;
    Node* left;
    Node* right;
};

int countLeaves(Node* root) {
        // Method-2
        // empty
        if(!root) return 0;
        // leaf node
        if(!root->left && !root->right) return 1;
        
        return countLeaves(root->left) + countLeaves(root->right);
    }

     void CountLeav(Node* node,int& count){
        if(node == nullptr) return;
        CountLeav(node->left,count);
        CountLeav(node->right,count);
        if(!node->left && !node->right) count++;
        
    }