
#include <bits/stdc++.h>
using namespace std;

// function to find the next greater elements in a circular array
// Time Complexity: O(N)
// Space Complexity: O(N)
vector<int> nextGreaterElements(vector<int> &nums) {
  int n = nums.size(); // initialize n with nums size

  // create a vector of ans
  vector<int> ans(n, -1);
  // create a stack
  stack<int> s;

  // traverse the array from the end to the beginning twice
  for (int i = 2 * n - 1; i >= 0; i--) {
    // keep deleting(removing/popping/eliminating) those elements that
    // are lesser than the current element of nums
    while (s.size() > 0 && nums[s.top()] <= nums[i % n]) {
      s.pop();
    }

    //stores the next greater element into ans
    ans[i % n] = s.empty() ? -1 : nums[s.top()];
    s.push(i % n); // push the index number of the current element of nums
  }

  return ans;
}
int main() {
  cout << "\n \t \t \t \t \t \t Next Greater Element II Problem!" << endl;
  cout << "\n \t \t \t \t \t \t======================================" << endl;
  vector<int> nums = {1, 2, 1};
  vector<int> result = nextGreaterElements(nums);
  cout << "The Next Greater Elements for the given array are: ";
  for (int val : result) {
    cout << val << " ";
  }
  cout << endl;
  return 0;
}