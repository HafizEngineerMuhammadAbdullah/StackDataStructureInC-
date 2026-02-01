#include <iostream>
#include <stack>
#include <vector>
using namespace std;

// Forward declaration of the helper function
void solveNextGreaterElementProblem(int i, int j, stack<int> &s,
                                    vector<int> &ans, vector<int> &num1,
                                    vector<int> &num2);
// TC:O(n * m) SC: O(n)
void nextGreaterElementProblemI(vector<int> &num1, vector<int> &num2) {
  // create a stack
  stack<int> s;
  // create an ans vector
  vector<int> ans(num1.size(), -1);

  // using BruteForce Approach
  for (int i = num1.size() - 1; i >= 0; i--) {
    for (int j = 0; j < num2.size(); j++) {
      if (num1[i] == num2[j]) {
        solveNextGreaterElementProblem(i, j, s, ans, num1, num2);
      }
    }
  }

  cout << "Next Greater Elements!:" << endl;
  // print ans array
  for (int val : ans) {
    cout << val << " ";
  }
  cout << endl;
}

// function that takes the elements of array as input from the user
void inputArray(vector<int> &arr, int i) {
  if (i == arr.size()) {
    return;
  }
  cin >> arr[i];
  inputArray(arr, ++i);
}

void printArray(vector<int> &arr, int i) {
  if (i == arr.size()) {
    return;
  }
  cout << arr[i++] << " ";
  printArray(arr, i);
}
int main() {
  cout << "\n \t \t \t \t \t Program to find the Next Greater Element of all "
          "of the Elements present in an Array:..."
       << endl;
  cout << "\n \t \t \t \t "
          "\t=================================================================="
          "========================"
       << endl;

  // declare the size variable
  int size;
  cout << "\n \t \t \t \t \t \t \t Please,Enter the size of array:..." << endl;
  cin >> size;
  //   // declare a dynamic array
  //   vector<int> num1(size);
  //   // declare a dynamic array
  //   vector<int> num2(size);

  //   cout << "Please,Enter the elements in an Array of size " << size << endl;
  //   inputArray(num1, 0);
  //   cout << endl;

  //     cout << "Please,Enter the elements in an Array of size " << size <<
  //     endl;
  //   inputArray(num2, 0);
  //   cout << endl;

  //   cout << "The inputted elements of Array are:..." << endl;
  //   printArray(num1, 0);
  //   cout << endl;

  //   cout << "The inputted elements of Array are:..." << endl;
  //   printArray(num2, 0);
  //   cout << endl;

  cout << "Next Greater Element I Results:" << endl;
  vector<int> num1 = {4, 1, 2};
  vector<int> num2 = {1, 3, 4, 2};
  nextGreaterElementProblemI(num1, num2);

  return 0;
}

void solveNextGreaterElementProblem(int i, int j, stack<int> &s,
                                    vector<int> &ans, vector<int> &num1,
                                    vector<int> &num2) {

  // push all the elements into the stack which is greater then (j + 1) to
  // num2.length.
  for (int k = num2.size() - 1; k > j; k--) {
    s.push(num2[k]);
  }
  // removing those elements from the stack that are not the greater the
  // current element of the vector arr.
  while (s.size() > 0 && s.top() <= num2[j]) {
    s.pop();
  }

  // caseI:if our stack got empty after popping all of the lesser elements as
  // compared to current element of arr.
  if (s.empty()) {
    ans[i] = -1;
  }

  // caseII:else our stack is not empty means next greater element exist at
  // the top of our stack.
  else {
    ans[i] = s.top();
  }

  // eliminate all the remaining elements of stack(empty the stack) for next
  // iterations
  while (!s.empty()) { //// Clear stack for next call
    s.pop();
  }
  return;
}