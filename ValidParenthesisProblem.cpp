#include <iostream>
#include <stack>
using namespace std;

// Program to solve Valid Parenthesis Problem
bool isValid(string str) { // TC:O(n),SC:O(n)
  stack<char> st;

  for (int i = 0; i < str.length(); ++i) {
    // if the char is opening bracket
    if (str[i] == '(' || str[i] == '{' || str[i] == '[') {
      st.push(str[i]); // simply,push into the stack
    }

    // else if the char is closing bracket
    else {
      // if opening brackets is less in quantity than the closing
      // brackets(opening bracket < closing bracket)
      if (st.size() == 0) {
        return false; // if the size of stack got empty means there is less
                      // number of opening bracket in the given string(opening
                      // bracket < closing bracket)
      }
      // for closing bracket
      if ((st.top() == '(' && str[i] == ')') ||
          (st.top() == '{' && str[i] == '}') ||
          (st.top() == '[' && str[i] == ']')) {
        st.pop(); // simply pop(delete/remove/eliminate) that char from the
                  // stack if it's pair is found
      } else { // the pair of brackets(characters) doesn't match
        return false;
      }
    }
  }

  // if opening brackets is more in quantity than the closing
  // brackets(opening bracket > closing bracket)
  return st.size() ==
         0; // there is less number of closing bracket provided in the string
}
int main() {
  cout << "\n \t \t \t \t Program to solve Valid Parenthesis Problem in "
          "respective Time Complexity and Space Complexity of O(n):..."
       << endl;
  cout << "\n \t \t \t \t"
          "===================================================================="
          "========================================"
       << endl;

  cout << isValid("({}[])");
  return 0;
}