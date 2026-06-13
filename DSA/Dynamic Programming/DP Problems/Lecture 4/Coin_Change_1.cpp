#include <bits/stdc++.h>
using namespace std;

// Pure Recursive Solution ( it later converted into dp)
// very high TC
int Find(int index,int amount,vector<int>& coins){
        // base case
        if(index == 0)
        return -1;

        if(amount == 0)
        return 0;

        // recursion logic
        if(coins[index-1] <= amount){
            int take = Find(index,amount - coins[index-1], coins);
            int dontake = Find(index-1,amount, coins);

            if(take == -1)  return dontake;
            if(dontake == -1)   return 1+take;

            if(take < dontake)  return 1+take;
            else    return dontake;
        }
        else{
            return Find(index-1,amount,coins);
        }
    }

    int coinChange(vector<int>& coins, int amount) {
        if(amount == 0) return 0;
        
        int n = coins.size();

        return Find(n,amount,coins);
    }

    // Top Down Approach
    // Bahut hi khatarnak chij pata chali hai
// It is Top Down Approach of DP but still giving TLE beacuse I initialized my DP with -1 and also In base case when index==0 then the function returns -1; that means jo find(index,amount) ki value calculate karke -1 aayi aur 
//dp[index][amount] mein store hui usko ye program soch lega ki ye to uncalculated function ha aur iski value vapas se calculate karne lag jayega...
//To isse apna DP lagane ka kuch faayeda hi nahi hua...
//This phenomena is also called Poisoned Memoization.

//So, yaha humko apne dp ko -1 se initialize nahi karna hai kisi aur value se initialise kar sakte hai... 
    int Find(int index,int amount,vector<int>& coins,vector<vector<int>>& dp){
        // base case
        if(index == 0)
        return -1;

        if(amount == 0)
        return 0;

        // Top Down Approach
        if(dp[index][amount] != -2)
        return dp[index][amount];

        // recursion logic
        if(coins[index-1] <= amount){
            int take = Find(index,amount - coins[index-1], coins,dp);
            int dontake = Find(index-1,amount, coins,dp);

            if(take == -1)  return dp[index][amount] = dontake;
            if(dontake == -1)   return dp[index][amount] = 1+take;

            if(take < dontake)  return dp[index][amount] = 1+take;
            else    return dp[index][amount] = dontake;
        }
        else{
            return dp[index][amount] = Find(index-1,amount,coins,dp);
        }
    }

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        // Top Down Approach
        //yaha humko apne dp ko -1 se initialize nahi karna hai kisi aur value se initialise kar sakte hai beacause apna base case index==0 bhi -1 return kar raha hai
        vector<vector<int>> dp(n+1, vector<int>(amount+1,-2));
        return Find(n,amount,coins,dp);
    }

    // Bottom Up Approach
    //Here is one pitfall I fall into while copy pasting the code of top-down approach and making it bottom up is that in if() conditions of top down logic , If there is return statement present then this return statement is doing two things 
//1. It returns the current function and the code below that if statement won't execute
//2. It returns the entire function
//So, while copy pasting the code of top down into bottom up you carefully see that koi bhi return statement if ke aandar na rhe jaaye and 
//** (IMP) second most important thing you have to chain your if statements of top down approach into else if chain... Because function ke case mein to if() statement mein agar return likha ha to function return ho jayega and if statement ke niche ka code nahi chalega but in iterative method , it doesn't have any return statement in if() block . So, code below if() block will run and it may lead to some unexpected results.
//So, you must do else if chaining in your Bottom Up Approach ,if your top down logic uses multiple if statements simultaneously... 

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        // Bottom Up Approach
        vector<vector<int>> dp(n+1, vector<int>(amount+1,-2));

        // Initializing 2D DP
        for(int i=0;i<=n;i++){
            dp[i][0] = 0;
        }

        for(int i=1;i<=amount;i++){
            dp[0][i] = -1;
        }
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=amount;j++){
                if(coins[i-1] <= j){
                    int take = dp[i][j-coins[i-1]];
                    int dontake = dp[i-1][j];

                    // Do else if chaining of simulataneous if() statements of your top down code, agar tumare if statements ke aandar return ha in top down code , to top down mein if() ke niche ka code nahi chalega but bottom up mein if() ke niche ka code chalta hai so else if() ki jarurat hai bottom up mein, taki agar ek if() statement chal jati hai to baki ki na chale 
                    if(take == -1)   dp[i][j] = dontake;
                    else if(dontake == -1)  dp[i][j] = 1+take;

                    else if(take < dontake)  dp[i][j] = 1+take;
                    else    dp[i][j] = dontake;
                }   
                else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[n][amount];
    }

    // Bottom Up Approach with space optimization
    // Always in space optimization first find out the required space for finding dp[i][j] in 2D array
    // required space matlab 2D array ka vo space jo humko dp[i][j] ki value nikalne ke liye required hai
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        // Bottom Up Approach with space optimization
        vector<int> dp(amount+1,-2);

        // Initializing 1D DP
        dp[0] = 0;
        for(int i=1;i<=amount;i++){
            dp[i] = -1;
        }
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=amount;j++){
                if(coins[i-1] <= j){
                    int take = dp[j-coins[i-1]];
                    int dontake = dp[j];
                    if(take == -1)   dp[j] = dontake;
                    else if(dontake == -1)  dp[j] = 1+take;

                    else if(take < dontake)  dp[j] = 1+take;
                    else    dp[j] = dontake;
                }   
            }
        }
        return dp[amount];
    }

int main(){
    
    return 0;
}