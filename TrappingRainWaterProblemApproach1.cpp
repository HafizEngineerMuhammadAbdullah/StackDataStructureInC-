#include <iostream>
#include <vector>
using namespace std;

// Function to calculate the total amount of trapped rain water
int trapWater(vector<int> &height) {
  int n = height.size();
  if (n == 0)
    return 0;

  // create two arrays to store the left max and right max for each index
  vector<int> lmax(n, 0);
  vector<int> rmax(n, 0);
  // initilaize the first value of lmax
  lmax[0] = height[0];
  // initialize the last value of rmax
  rmax[n - 1] = height[n - 1];

  // fill the lmax array with left max vaues
  for (size_t i = 1; i < n; i++) {
    lmax[i] = max(lmax[i - 1], height[i]);
  }
  // fill the right max array with the right max values
  for (int i = n - 2; i >= 0; i--) {
    rmax[i] = max(rmax[i + 1], height[i]);
  }

  // calculate the total trapped water
  int trappedWater = 0;
  for (int i = 0; i < n; i++) {
    trappedWater += min(lmax[i], rmax[i]) - height[i];
  }

  return trappedWater;
}
int main() {
  cout << "\n \t \t \t \t \t \t Trapping Rain Water Problem using Approach 1!"
       << endl;
  cout << "\n \t \t \t \t \t \t=============================================="
       << endl;
  vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
  int totalTrappedWater = trapWater(height);
  cout << "\n Total Trapped Rain Water is: " << totalTrappedWater << endl;

  return 0;
}