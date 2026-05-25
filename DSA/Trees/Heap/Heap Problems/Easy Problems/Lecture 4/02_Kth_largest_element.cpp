#include <bits/stdc++.h>
using namespace std;

// In case of finding largest element we use MinHeap
// M-1 : Optimal Same as kth smallest element :- TC = n*log(k) , SC = O(k)
int findKthLargest(vector<int>& arr, int k) {
        // Using MinHeap
        priority_queue<int,vector<int>,greater<int>> q;
        for(int i=0;i<k;i++){ // insert first k elements into priority queue :- O(k*logk)
            q.push(arr[i]);
        }
        
        for(int i=k;i<arr.size();i++){  // O((n-k)*logk)
            if(arr[i] > q.top()){
                q.pop();
                q.push(arr[i]);
            }
        }
        
        return q.top();
    }

// M-2 : Optimal using QuickSelect similar to quick sort better for average cases , it's worst case complexity is O(n^2)

int partition(vector<int>& nums, int left, int right) {
    int pivotIndex = left + rand() % (right - left + 1);
    int pivot = nums[pivotIndex];

    // Move pivot to end
    swap(nums[pivotIndex], nums[right]);

    int storeIndex = left;
    for (int i = left; i < right; i++) {
        if (nums[i] < pivot) {
            swap(nums[i], nums[storeIndex]);
            storeIndex++;
        }
    }

    // Move pivot to final place
    swap(nums[storeIndex], nums[right]);
    return storeIndex;
}

int quickSelect(vector<int>& nums, int left, int right, int target) {
    if (left == right)
        return nums[left];

    int pivotIndex = partition(nums, left, right);

    if (pivotIndex == target)
        return nums[pivotIndex];
    else if (pivotIndex < target)
        return quickSelect(nums, pivotIndex + 1, right, target);
    else
        return quickSelect(nums, left, pivotIndex - 1, target);
}

int findKthLargest(vector<int>& nums, int k) {
    int n = nums.size();
    int target = n - k; // convert to kth smallest index
    return quickSelect(nums, 0, n - 1, target);
}

int main() {
    vector<int> nums = {3, 2, 1, 5, 6, 4};
    int k = 2;

    cout << findKthLargest(nums, k) << endl; // Output: 5
    return 0;
}
