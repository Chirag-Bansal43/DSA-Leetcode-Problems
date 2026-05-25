#include <bits/stdc++.h>
using namespace std;

string sortVowels(string s) {
        vector<char> ans(s.size(),'\0');
        // char, count
        map<char,int> m;
        for(int i=0;i<s.size();i++){
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' ||
               s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U'
            ){
                m[s[i]]++;
            }
            else{
                ans[i] = s[i];
            }

        }

        map<char,int>::iterator it;
        int index = 0;
        for(it=m.begin();it!=m.end();it++){
            while(it->second != 0){
                while(ans[index] != '\0')   index++;
                ans[index++] = it->first;
                it->second--;
            }
        }

        string result(ans.begin(),ans.end());
        return result;

    }

int main(){
    cout<<sortVowels("chirag");

    return 0;
}