#include <iostream>
#include <vector>
using namespace std;
// Introduction of Stack Data Structure & it's implementation(implementing it's
// function) Using Vector Data Structure
class Stack {
  vector<int> v;

public:
  // method to push(add/insert)  the new element at the top of stack
  void push(int val) { // TC:O(1)
    v.push_back(val);
    return;
  }

  // method to pop(delete/remove) the last inserted element from the top of
  // stack
  void pop() { // TC:O(1)
    v.pop_back();
    return;
  }

  // method that returns the top element(last inserted element) of the stack
  int top() { return v[v.size() - 1]; }

  // method that returns true if our stack is empty otherwise return false.
  bool isEmpty() { return v.size() == 0; }
};
int main() {
  Stack s;

  s.push(30);
  s.push(20);
  s.push(10);
  s.push(0);

  while (!(s.isEmpty())) {
    cout << s.top() << " ";
    s.pop();
  }

  return 0;
}
