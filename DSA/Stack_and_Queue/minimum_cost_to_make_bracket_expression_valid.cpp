#include <bits/stdc++.h> 
using namespace std;

void BracNos(stack<int>& st,int& a,int &b){
    cout<<a<<' '<<b<<endl;
    while(!st.empty()){
        if(st.top() == '{') a++;
        else b++;
        st.pop();
    }
}



int findMinimumCost(string str) {
    if (str.length() % 2 !=0)   return -1;

    stack<int> st;
    for(int i=0;i<str.length();i++){
        if(str[i] == '}'){
            if(!st.empty() && st.top() == '{'){
                st.pop();
                continue;
            }
        }
        st.push(str[i]);
    }

    if(st.empty())  return 0;

    
    int a=0,b=0;
    cout<<a<<' '<<b<<endl;
    BracNos(st,a,b);

    
    

    int ans = (a+1)/2 + (b+1)/2;

    return ans;

}


int main(){
    
    string str = "{{{}";
    cout<<findMinimumCost(str);


    return 0;
}