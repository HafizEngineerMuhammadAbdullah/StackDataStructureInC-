#include <iostream>
#include <stack>
#include <vector>
using namespace std;

// Space Complexity: O(n)
// Time Complexity: O(n)
void previousSmallerElement(vector<int> &arr) {
  // create a stack
  stack<int> s;
  // create an ans vector
  vector<int> ans(arr.size());

  for (size_t i = 0; i < arr.size(); i++) {
    // removing those elements from the stack that are not the smaller than the
    // current element of the vector arr.
    while (s.size() > 0 && s.top() >= arr[i]) {
      s.pop();
    }

    // caseI:if our stack got empty after popping all of the greater elements as
    // compared to current element of arr.
    if (s.empty()) {
      ans[i] = -1;
    }

    // caseII:else our stack is not empty means next previous element exist at
    // the top of our stack.
    else {
      ans[i] = s.top();
    }

    s.push(arr[i]);// push the current element at the top of stack
  }

  // Print result
  cout << "Previous Smaller Elements: ";
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
  cout << "\n \t \t \t \t \t Program to find the Previous Smaller Element of all "
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
  // declare a dynamic array
  vector<int> arr(size);

  cout << "Please,Enter the elements in an Array of size " << size << endl;
  inputArray(arr, 0);
  cout << endl;

  cout << "The inputted elements of Array are:..." << endl;
  printArray(arr, 0);
  cout << endl;
  cout << "Previous Smaller Element Results:" << endl;
  previousSmallerElement(arr);

  return 0;
}