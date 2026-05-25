#include <bits/stdc++.h>
using namespace std;

// TC = O(n^2), S.C = O(n) : Brute Force 
char FirstNoRepCharInQ_01(queue<char> q){
    vector<int> CharCount(26);
    string subStr = "";
    while(!q.empty()){
        char ch = q.front();
        CharCount[ch-'a']++;
        subStr += ch;
        q.pop();
    }

    for(int i=0;i<subStr.size();i++){
        if(CharCount[subStr[i]-'a'] == 1){
            return subStr[i];
        }
    }
    return '#';
}

string FirstNoRepCharsInCharsStream01(string A){
    string B = "";
    queue<char> q;
    for(int i=0;i<A.size();i++){
        q.push(A[i]);
        B += FirstNoRepCharInQ_01(q);
    }
    return B;
}
//------------------------------------------------------------------------------------------------

char FirstNoRepCharInQ(queue<char>& q,vector<int>& CharCount){
    while(!q.empty()){
        if(CharCount[q.front()-'a'] == 1){
            return q.front();
        }
        else{
            q.pop();
        }
    }
    return '#';
}

string FirstNoRepCharsInCharsStream(string A){
    string B = "";
    queue<char> q;
    vector<int> CharCount(26);
    for(int i=0;i<A.size();i++){
        q.push(A[i]);
        CharCount[A[i]-'a']++;
        B += FirstNoRepCharInQ(q,CharCount);
    }
    return B;
}


int main(){
    cout<<FirstNoRepCharsInCharsStream("ababdc")<<endl;
    return 0;
}