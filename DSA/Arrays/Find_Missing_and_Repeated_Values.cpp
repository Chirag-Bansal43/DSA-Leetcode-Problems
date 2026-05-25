#include <bits/stdc++.h>
using namespace std;

/*
vector<int> findTwoElement(vector<int>& arr) {
        
        int n = arr.size();
        vector<int> result(2,0);
        
        for(int i=0;i<arr.size();i++){
            arr[i]--;
        }
        
        // Now range of elements of array become = [0 to n-1]. So, we can take our
        // number = n , n = size of array
        
        for(int i=0;i<arr.size();i++){
            int oriEle = arr[i] % n; // ith index pe originally kya store tha vo nikal rahe ha (means ith index ka original element)
            arr[oriEle] += n; // aur humko original Element ka count store karna hai at index = original_element par
        }
        
        // Now check for count
        
        for(int i=0;i<arr.size();i++){
            // ith index ka count or element = i ka count
            int count = arr[i] / n; // ye element = i ka count ha
            if(count == 2){
                result[0] = i+1;
            }
            else if(count == 0){
                result[1] = i+1;
            }
            
            if(result[0] != 0 && result[1] != 0){
                break;
            }
            
        }
        
        for(int i=0;i<result.size();i++){
            cout<<result[i]<<" ";
        }
        cout<<endl;

        return result;
        
    }
*/

// SOLVED USING XOR OPERATOR (BIT MANIPULATION)
// Common mistake == have high precedance than & so in expression => 
// xr & (1 << bitno) == 0  this , this will treat like xr & ((1 << bitno) == 0) this which is wrong  

// IMP FORMULA OF BIT MANIPULATION:-
// There is a formula also to find this number which have 1 present only at first one encountered one in xr from the right
// that is => xr & ~(xr-1); 

vector<int> findTwoElement(vector<int>& arr) {
        
        int n = arr.size();
        
        int xr = 0;
        for(int i=0;i<n;i++){
            xr = xr ^ arr[i];
            xr = xr ^ i+1;
        }
        

        // finding first differentiable bit no in xr from right 
        int bitno = 0;
        while((xr & (1 << bitno)) == 0){
            bitno++;
        }
        
        // number with 1 present only at 1st differentiable bit no (i.e 1 only at bitno) is (1<< bitno)
        int number = 1<<bitno;  // or  int number = xr & ~(xr-1); (no bitno calculation is required)

        // check first differentiable bit no of every element in array and numbers from [1 to n] 
        //and club them in 0th club or 1st club
        
        int zeros = 0; // zeros club wale elements ka XOR isme store karenge
        int ones = 0; // ones club wale elements ka XOR isme store karenge
        
        for(int i=0;i<n;i++){
            (arr[i] & number) == 0 ? zeros = zeros ^ arr[i] : ones = ones ^ arr[i];
            (i+1 & number) == 0 ? zeros = zeros ^ i+1 : ones = ones ^ i+1;
        }
        
        // checking zeros number is missing or repeated
        int cnt = 0;
        for(int i=0;i<n;i++){
            if(arr[i] == zeros){
                cnt++;
            }
        }
        
        if(cnt == 2)    return {zeros,ones};
        return {ones,zeros};
    }


int main(){
    
    vector<int> arr = {2,2};
    
    vector<int> result = findTwoElement(arr);
    cout<<"Repeating No :- "<< result[0] <<endl;
    cout<<"Missing No :- "<< result[1] <<endl;

    return 0;
}

