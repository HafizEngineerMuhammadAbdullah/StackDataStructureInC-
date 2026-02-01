#include <iostream>
#include <stack>
#include <vector>
using namespace std;

// Program to solve the Stock Span Problem:
vector<int> solveStockSpanProblem(vector<int> &price) {

  // create an ans vector
  vector<int> ans(price.size(), 0);

  // create a stack
  stack<int> s;

  for (int i = 0; i < price.size(); i++) { // TC:O(n), SC: O(n)
    // remove the lesser value as compared to  current stock day price
    // from stack and try to find the immediately greater value(prevHigh)
    while (s.size() > 0 && price[s.top()] <= price[i]) {
      s.pop();
    }

    // if our stack is got empty means there is no prevHigh value exists
    // edge case(corner case)
    if (s.empty()) {
      ans[i] = i + 1;
    }
    // else our prevHigh exists in our stack
    else {
      ans[i] = i - s.top(); // s.top()=>prevHigh
    }
    // simply push the current stock day price idx
    s.push(i);
  }
  return ans;
}
int main() {
  cout << "\n \t \t \t \t \t \t \t \t Program to solve the Stock Span "
          "Problem:..."
       << endl;
  cout << "\n \t \t \t \t \t \t \t"
          "\t============================================="
       << endl;
  // stock prices
  vector<int> prices = {100, 80, 60, 70, 60, 75, 85};

  vector<int> v = solveStockSpanProblem(prices);

  // print ans values
  for (int val : v) {
    cout << val << " ";
  }
  cout << endl;

  return 0;
}