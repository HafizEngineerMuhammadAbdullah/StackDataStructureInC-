#include <iostream>
#include <vector>
using namespace std;

// Function to calculate the total amount of trapped rain water using two
// pointers approach
int trapRainWater(vector<int> &height) {//TC:O(n) SC:O(1)
  int n = height.size();
  int l = 0;
  int r = n - 1;
  int lmax = 0;
  int rmax = 0;
  // variable to store the total trapped water
  int ans = 0;
  // loop until the two pointers meet
  while (l < r) {
    // calculate the left max and right max
    lmax = max(lmax, height[l]);
    rmax = max(rmax, height[r]);
    if (lmax < rmax) {
      ans += lmax - height[l]; // water trapped at index l
      l++;                     // update left pointer
    } else {
      ans += rmax - height[r]; // water trapped at index r
      r--;                     // update right pointer
    }
  }
  return ans;
}
int main() {
  cout << "\n \t \t \t \t \t \t Trapping Rain Water Problem using Approach 2 "
          "(Two Pointers Approach)!"
       << endl;
  cout << "\n \t \t \t \t \t "
          "\t=================================================================="
          "===="
       << endl;
  vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
  int totalTrappedWater = trapRainWater(height);
  cout << "\n Total Trapped Rain Water is: " << totalTrappedWater << endl;
  cout << endl;

  return 0;
}