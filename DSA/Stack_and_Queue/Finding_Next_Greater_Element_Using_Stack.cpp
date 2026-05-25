#include<bits/stdc++.h>
using namespace std;

void print_vector(vector<int>& v1){
    for(int i=0;i<v1.size();i++){
        cout<<v1[i]<<" ";
    }
    cout<<endl;
}




vector<int> nextGreaterElement_01(vector<int>& arr, int n)
{
	deque<int> ans;
	stack<int> st;
	for(int i=n-1;i>=0;i--){
		if(!st.empty() && st.top()>arr[i]){
			ans.push_front(st.top());
			st.push(arr[i]);
		}
		else{
			while(!st.empty() && st.top()<=arr[i]){
				st.pop();
			}

			if(!st.empty() && st.top()>arr[i]){
				ans.push_front(st.top());
				st.push(arr[i]);
			}
			else{
				ans.push_front(-1);
                st.push(arr[i]);
			}
		}
	}

	vector<int> result;
	for(auto i:ans){
		result.push_back(i);
	}

	return result;
}

vector<int> nextGreaterElement(vector<int> &arr, int n)
{   
    vector<int> ans(n);
    stack<int> st;
    for(int i=n-1;i>=0;i--){
        while(!st.empty() && st.top()<=arr[i]){
            st.pop();
        }
        if(!st.empty()) ans[i] = st.top();
        else    ans[i] = -1;
        st.push(arr[i]);
    }
    return ans;
}

int main(){
    vector<int> v = {2,1,12,4,6,5,7,11,3};
    vector<int> ans = nextGreaterElement(v,9);
    print_vector(ans);

}