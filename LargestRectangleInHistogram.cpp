#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int largestRectangleArea(vector<int>); // function prototype
int main() {
  cout << "\n \t \t \t \t \t Program to find the largest Area of the Rectangle"
       << endl;
  cout
      << "\n \t \t \t \t \t===================================================="
      << endl;

  cout << "\n \t \t \t \t \t The Largest Area of Rectangle of a Histogram is : " << endl;
  int ans = largestRectangleArea({2,1,5,6,2,3});
  cout << ans << endl;

  return 0;
}


// method that find the largest Area of the Rectangle
int largestRectangleArea(vector<int> heights) {
  //initialize n with heights size
  int n = heights.size();
  // create a stack
  stack<int> s;

  // create two vectors
  vector<int> left(n, 0);
  vector<int> right(n, 0);

  // find the right(next) nearest smaller element
  // loop through the heights array in a reverse fashion
  for (int i = n - 1; i >= 0; --i) {
    // if the top element of stack is greater than the current element
    // so keep removing the larger elements from the stack
        while(s.size() > 0 && heights[s.top()] >= heights[i]){
          s.pop();
        }

        right[i] = s.empty() ? n : s.top();
        s.push(i); // push the current element into the stack
  }

  // keep deleting(popping/removing/eliminating) all the remaining elements until the stack becomes empty
  while (!s.empty()) {
    s.pop();
  }

  // find the left(previous) nearest smaller element
  // loop through the heights array in a forward fashion
  for (int i = 0; i < n; ++i) {
    // if the top elements of stack is greater than the current element
    // so keep removing the larger elements from the stack
        while(s.size() > 0 && heights[s.top()] >= heights[i]){
          s.pop();
        }

        left[i] = s.empty() ? -1 : s.top();
        s.push(i); // push the current element into the stack
  }

  int ans = 0;
  for (int i = 0; i < n; ++i) {
    // calculate width
    int width = right[i] - left[i] - 1;
    int currArea =
        heights[i] * width;       // calculate the  Area of rectangle using formula
    ans = max(currArea, ans); // update the ans to max area of rectangle
  }
  return ans;//return ans value
}
