#include <bits/stdc++.h>
using namespace std;

// Normal Brute Force Approach
bool RowCheck(vector<vector<int>>& mat,int row){
    int col = 0;
    while(col != row){
        if(mat[row][col] != 0){
            return false;
        }
        col++;
    }

    col++;
    while(col < mat.size()){
        if(mat[row][col] != 0){
            return false;
        }
        col++;
    }
    return true;
}



int celebrity_01(vector<vector<int>>& mat) {
    int n = mat.size();
    for(int col=0;col<n;col++){
        for(int row=0;row<n;row++){
            if(mat[row][col] == 0){
                goto end;
            }
        }
        if(RowCheck(mat,col)){
            return col;
        }
        end:;
    }
    return -1;
}

// Optimal Approach Using Stack

bool Verify(vector<vector<int>>& mat,stack<int>& st){
    int person = st.top();
    for(int row = 0;row<mat.size();row++){
        if(mat[row][person] != 1){
            return false;
        }
    }

    int col = 0;
    int zeroCount=0;
    while(col < mat.size()){
        if(mat[person][col] == 0){
            zeroCount++;
        }
        col++;
    }

    if(zeroCount != mat.size()-1){
        return false;
    }

    return true;
}

// T.C=O(n) , SC=O(n)
int celebrity(vector<vector<int>>& mat) {
    stack<int> st;
    for(int i=0;i<mat.size();i++){
        st.push(i);
    }
    while(st.size() != 1){
        int A = st.top();
        st.pop();
        int B = st.top();
        st.pop();
        if(mat[A][B]){ // A knows B => A is not a celebrity
            st.push(B);
        }
        else{
            // A not knows B => B is not a celebrity
            st.push(A);
        }
    }

    if(Verify(mat,st))  return st.top();
    return -1;

}


int main(){
    
    // Correct: a 2D vector (matrix) initialized with 3 rows
    vector<vector<int>> mat = {{1, 1},{1,1}};
    cout << celebrity(mat);

    return 0;
}