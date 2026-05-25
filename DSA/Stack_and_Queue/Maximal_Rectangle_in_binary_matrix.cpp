#include<bits/stdc++.h>
using namespace std;
    vector<int> NextSmallestElementIndex(vector<int> arr){
        int n = arr.size();
        vector<int> ans(n);
        stack<int> st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()]>=arr[i]){
                st.pop();
            }
            if(!st.empty()) ans[i] = st.top();
            else    ans[i] = -1;
            st.push(i);
        }
        return ans;
    }

    vector<int> PreviousSmallestElementIndex(vector<int> arr){
        int n = arr.size();
        vector<int> ans(n);
        stack<int> st;
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()]>=arr[i]){
                st.pop();
            }
            if(!st.empty()) ans[i] = st.top();
            else    ans[i] = -1;
            st.push(i);
        }
        return ans;
    }

    int largestRectangleArea(vector<int>& heights) {
        int N = heights.size();
        vector<int> nextSmallestEleIndex(N);
        vector<int> previousSmallestEleIndex(N);
        nextSmallestEleIndex = NextSmallestElementIndex(heights);
        previousSmallestEleIndex = PreviousSmallestElementIndex(heights);

        int MaxArea = INT_MIN;
        for(int i=0;i<N;i++){
            int length = heights[i];
            int n = nextSmallestEleIndex[i];
            int p = previousSmallestEleIndex[i];
            if(n == -1) n=N;
            int width = n-p-1;
            int area = length*width;
            MaxArea = max(MaxArea,area);
        }
        return MaxArea;

    }


    int maximalRectangle(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> prefixSum(m , vector<int>(n,0));

        for(int col=0;col<n;col++){
            int sum=0;
            for(int row=0;row<m;row++){
                sum+=matrix[row][col];
                if(matrix[row][col] == 0)   sum = 0;
                prefixSum[row][col] = sum;
            }
        }

        int MaxArea = 0;
        for(int row=0;row<m;row++){
            int area = largestRectangleArea(prefixSum[row]);
            MaxArea = max(MaxArea,area);
        }

        return MaxArea;
    }

int main(){

    vector<vector<int>> matrix = {{1,0,1,0,0},{1,0,1,1,1},{1,1,1,1,1},{1,0,0,1,0}};
    cout<< maximalRectangle(matrix);

    return 0;
}