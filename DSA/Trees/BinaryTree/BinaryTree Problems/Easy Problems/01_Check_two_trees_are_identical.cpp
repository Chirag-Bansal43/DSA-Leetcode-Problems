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


bool isIdentical(Node* r1, Node* r2) {
        // code here
        if(!r1 && !r2)  return 1;
        if((!r1 && r2) || (r1 && !r2))  return 0;
        
        int nodeTree1 = r1->data;
        int nodeTree2 = r2->data;
        if(nodeTree1 != nodeTree2)  return 0;
        
        /*
        // left side 
        bool leftSide = isIdentical(r1->left,r2->left);
        if(!leftSide)   return 0;
        
        // right side
        bool rightSide = isIdentical(r1->right,r2->right);
        if(!rightSide)  return 0;
        
        return 1; */ 

        //or
        // && operation mein agar 1st condition false aa gayi then dusri condition ko check hi nahi karta means dusra function call hoga hi nahi agar left part hi same nahi hua to
        return isIdentical(r1->left,r2->left) && isIdentical(r1->right,r2->right);
    }

int main(){
    
    return 0;
}