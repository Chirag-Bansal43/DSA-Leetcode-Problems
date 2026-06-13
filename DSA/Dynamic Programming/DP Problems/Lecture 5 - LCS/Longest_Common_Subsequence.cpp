#include <bits/stdc++.h>
using namespace std;

// Recursive logic
int Find(int index1 , int index2 , string &s1, string &s2){
        //base case
        if(index1==0 || index2==0)
        return 0;
        
        // Main LCS logic
        // agar dono ka last character same hai then 1 + function call kar deni hai baki baachi string ke liye , dono same character ko hata denge 
        if(s1[index1-1] == s2[index2-1]){
            return 1 + Find(index1-1,index2-1,s1,s2);
        }
        else{
            // 1st Function call: string1 ka last character chood do and baki characters le lo and string2 puri hi le lo
            // 2nd Function Call: string2 ka last character chood do and baki characters le lo and string1 puri hi le lo
            // Dono ka LCS nikalo aur dono mein se jo maximum aaya usko upar return kar do
            return max( Find(index1-1,index2,s1,s2) , Find(index1,index2-1,s1,s2));
        }
    }

    int lcs(string &s1, string &s2) {
        return Find(s1.size(), s2.size() , s1,s2);  // last character ka index dono string mein note it is a 1 based indexing
    }


    // Top Down
    int Find(int index1 , int index2 , string &s1, string &s2, vector<vector<int>>& dp){
        //base case
        if(index1==0 || index2==0)
        return 0;
        
        if(dp[index1][index2] != -1)
        return dp[index1][index2];
        
        // Main LCS logic
        // agar dono ka last character same hai then 1 + function call kar deni hai baki baachi string ke liye , dono same character ko hata denge 
        if(s1[index1-1] == s2[index2-1]){
            return dp[index1][index2] = 1 + Find(index1-1,index2-1,s1,s2,dp);
        }
        else{
            // 1st Function call: string1 ka last character chood do and baki characters le lo and string2 puri hi le lo
            // 2nd Function Call: string2 ka last character chood do and baki characters le lo and string1 puri hi le lo
            // Dono ka LCS nikalo aur dono mein se jo maximum aaya usko upar return kar do
            return dp[index1][index2] = max( Find(index1-1,index2,s1,s2,dp) , Find(index1,index2-1,s1,s2,dp));
        }
    }

    int lcs(string &s1, string &s2) {
        
        // Top Down Approach
        vector<vector<int>> dp(s1.size()+1, vector<int>(s2.size()+1,-1));
        
        return Find(s1.size(), s2.size() , s1,s2,dp);  // last character ka index dono string mein note it is a 1 based indexing
    }

    //Bottom Up
    // TC = O(n*m) SC = O(n*m), n=size of s1 string, m=size of s2 string
    int lcs(string &s1, string &s2) {
        // Bottom Up Approach
        vector<vector<int>> dp(s1.size()+1, vector<int>(s2.size()+1,0));
        
        for(int i=1;i<=s1.size();i++){
            for(int j=1;j<=s2.size();j++){
                // Main LCS logic
                // agar dono ka last character same hai then 1 + function call kar deni hai baki baachi string ke liye , dono same character ko hata denge 
                if(s1[i-1] == s2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else{
                    // 1st Function call: string1 ka last character chood do and baki characters le lo and string2 puri hi le lo
                    // 2nd Function Call: string2 ka last character chood do and baki characters le lo and string1 puri hi le lo
                    // Dono ka LCS nikalo aur dono mein se jo maximum aaya usko upar return kar do
                    dp[i][j] = max( dp[i-1][j] , dp[i][j-1] );
                }
            }
        }
        
        return dp[s1.size()][s2.size()];  // last character ka index dono string mein note it is a 1 based indexing
    }

    // Bottom Up Approach with space optimization
    // TC = O(n*m) SC = O(m) , m=size of s2 string
    int lcs(string &s1, string &s2) {
        // Bottom Up Approach with space optimization
        
        vector<int> dp(s2.size()+1,0);
        
        for(int i=1;i<=s1.size();i++){
            int third = 0; // third variable dp[i][j-1] ki old value store karke rakhega taaki vo value next iteration mein dp[i][j] nikalne mein use ho paaye
            for(int j=1;j<=s2.size();j++){
                int old_value = dp[j]; // dp[i][j] ki value phele hi old_value mein store kardo phir iski value update ho jayegi
                
                if(s1[i-1] == s2[j-1]){
                    dp[j] = 1 + third;
                }
                else{
                    dp[j] = max( dp[j] , dp[j-1] );
                }
                // dp[i][j] ki value update ho gayi ha
                third = old_value; // dp[i][j] ki old_value third mein store kardo taki next iteration mein dp[i][j] nikalne ke kaam aaye
            }
        }
        
        return dp[s2.size()];  // last character ka index dono string mein note it is a 1 based indexing
    }

int main(){
    
    return 0;
}