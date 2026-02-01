#include <iostream>
#include <stack>
#include <vector>
using namespace std;

// Function to find the celebrity in a group
// A celebrity is known by everyone but knows no one
// Input: 2D matrix arr where arr[i][j] = 1 means i knows j
// Output: index of celebrity or -1 if no celebrity exists
// Time Complexity: O(n)
// Space Complexity: O(n)
// where n is the number of people in the group
// using stack data structure
// to solve the Celebrity Problem
int celebrity(vector<vector<int>> &arr) {
  int n = arr.size();
  if (n == 0)
    return -1;
  // create a stack
  stack<int> s;
  // push all the candidates into the stack
  for (int i = 0; i < n; ++i) {
    s.push(i);
  }

  // eliminate candidates until only one candidate is left in the stack
  while (s.size() > 1) {
    int i = s.top();
    s.pop();
    int j = s.top();
    s.pop();

    // if i knows j then i can't be candidate for celebrity
    // else j can't be celebrity candidate
    if (arr[i][j] == 0) {
      s.push(i); // j can't be celebrity
    } else {
      s.push(j); // i can't be celebrity
    }
  }

  int celebrityCandidate = s.top();
  // verify the celebrity candidate
  for (int i = 0; i < n; ++i) {

    // celebrityCandidate should not know anyone
    // and everyone should know celebrityCandidate
    if ((i != celebrityCandidate) &&
        (arr[i][celebrityCandidate] == 0 || arr[celebrityCandidate][i] == 1)) {
      return -1;
    }
  }
  return celebrityCandidate; // return the index of celebrity
}
int main() {
  cout << "\n \t \t \t \t \t \t Celebrity Problem using Stack Data Structure "
          "in C++"
       << endl;
  cout << "\n \t \t \t \t \t "
          "\t------------------------------------------------------"
       << endl;
  vector<vector<int>> arr = {
      {0, 0, 1, 0}, {0, 0, 1, 0}, {0, 0, 0, 0}, {0, 0, 1, 0}};
  int celebIndex = celebrity(arr);
  if (celebIndex == -1) {
    cout << "No celebrity found in the group." << endl;
  } else {
    cout << "Celebrity found at index: " << celebIndex << endl;
  }
}