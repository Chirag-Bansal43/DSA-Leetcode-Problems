#include <bits/stdc++.h>
using namespace std;

string intToRoman(int num) {
    // value, symbol
    map<int,string,greater<int>> m = {
        {1000,"M"},{900,"CM"},{500,"D"},{400,"CD"},{100,"C"},{90,"XC"},{50,"L"},{40,"XL"},{10,"X"},
        {9,"IX"},{5,"V"},{4,"IV"},{1,"I"}
    };

    string ans;

    for(auto& [value,symbol]:m){
        int count = num/value;
        switch (count){
            case 1:
                ans += symbol;
                break;
            case 2:
                ans += symbol+symbol;
                break;
            case 3:
                ans += symbol+symbol+symbol;
                break;
            default:
                break;
        }
        num -= count*value;
        if(num == 0)    break;
    }

    return ans;

}

int main(){
    cout<<intToRoman(3949)<<endl;
    return 0;
}