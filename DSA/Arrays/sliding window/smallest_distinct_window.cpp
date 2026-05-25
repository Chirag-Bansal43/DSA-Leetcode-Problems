#include <bits/stdc++.h>
using namespace std;

int findSubString(string& str) {
        int first = 0;
        int second = 0;
        int len = str.size();
        int windowCharCount[128] = {0};
        int difference = 0;
        /* kitne different characters ha jo hamare string mein present hai but humare 
        substring(or window) mein nahi present hai
        */
        for(auto ch:str){
            if(windowCharCount[ch] == 0){
                difference++;
                windowCharCount[ch]++;
            }
        }
        
        // making the count array zero
        for(int i=0;i<128;i++){
            windowCharCount[i] = 0;
        }
        
        
        while(second<str.size()){
            while(second<str.size() && difference != 0){
                if(windowCharCount[str[second]] == 0){
                    difference--;
                }
                windowCharCount[str[second]]++;
                second++;
            }
            len = min(len,second-first);
            
            while(difference != 1){ // matlab window se jab tak ek different character nahi hat jata tab tak loop chalana hai
                windowCharCount[str[first]]--;
                if(windowCharCount[str[first]] == 0){ // checking first wala element puri tarah se window se hata ha ya nahi
                    difference++;
                }
                first++;
                
                if(difference == 0)     len = min(len,second-first); // difference = 0  matab the particular substring is valid substring containing all distinct characters
            }
        }
        
        return len;
        
    }


int main(){
    string str;
    cin>>str;
    cout<<"smallest distinct substring length : "<<findSubString(str)<<endl;
    return 0;
}