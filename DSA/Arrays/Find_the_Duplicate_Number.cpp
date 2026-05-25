#include <bits/stdc++.h>
using namespace std;

// find the duplicate using Floyd's Tortoise and Hare cycle detection
int findDuplicate(vector<int>& nums) {
  // initialize pointers at the start
  int slow = nums[0];
  int fast = nums[0];

  // move slow by 1 step and fast by 2 steps until they meet
  do {
    slow = nums[slow];
    fast = nums[nums[fast]];
  } while (slow != fast);

  // reset fast to start to find the entrance to the cycle
  fast = nums[0];

  // move both by 1 step until they meet at the duplicate
  while (slow != fast) {
    slow = nums[slow];
    fast = nums[fast];
  }

  // return the duplicate value
  return slow;
}

// program entry
int main() {
  // initialize input
  vector<int> arr = {1, 3, 4, 2, 2};

  // print result
  cout << "The duplicate element is " << findDuplicate(arr) << endl;

  // exit
  return 0;
}