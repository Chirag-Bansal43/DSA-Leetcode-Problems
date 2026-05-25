#include <bits/stdc++.h>
using namespace std;

// Sliding window concept used to solve this in O(n) time and O(128) = O(1) space

int longest_substring_length(string str){
    int n = str.size(); // size of string
    int Maxlen = 0; // for storing maximum window length
    int len = 0; // for storing arbitary window length
    bool windowCharPresent[128] = {0};  // ye sabhi ascii character ke liye constant size ka array bana diya. ye array ye store karta hai ki kon kon se characters humare window(or substring) mein present hai matlab jo bhi characters window mein ha unko yaha maap karta jata hai and jo characters window se nikal diye unki mapping hattata jayega(in real time)

    // our sliding window(or our substring) is from first pointer to second pointer in the string str
    int first = 0;
    int second = 0;

    while(second<n){
        // second's char is present in window or not
        if(windowCharPresent[str[second]] == 0){ // second's char is not present in window
            windowCharPresent[str[second]] = true;
            len = second - first + 1;
            Maxlen = max(Maxlen,len);
        }
        else{  // second's char is present in window
            while(str[first] != str[second]){  // loop will run untill first char will not become equal to second char
                windowCharPresent[str[first]] = 0; // first character ko window se hata do
                first++;
            }
            first++;
        }
        second++;
    }

    return Maxlen;
}


int main(){
    
    string str1;
    cout<<"Input string : ";
    cin>>str1;

    cout<<"length of lonest substring without repeated characters : "<<longest_substring_length(str1);

    return 0;
}