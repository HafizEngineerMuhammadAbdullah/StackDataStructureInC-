#include <iostream>
#include <stack>
using namespace std;

// Program to implement all the functions of Queue(push,pop,top,empty) with the
// help of  Two Stacks.
// Note: Here we are making push operation costly.
// So that pop and front operations can be done in O(1) time complexity.
// TC of push operation: O(n)
// TC of pop operation: O(1)
// TC of front operation: O(1)
// TC of empty operation: O(1)
// SC: O(n)
// where n is the number of elements in the queue
// Create a class called MyQueue
// Make push expensive so that pop/top is O(1)
// This preserves:
// ✔ FIFO in Queue
class MyQueue {
public:
  // create two Stacks
  stack<int> s1;
  stack<int> s2;
  // create a constructor for MyQueue class
  MyQueue() {}

  // method that push(add/insert) the new element at the front of queue
  void push(int val) {
    // copy the entire elements of stack1(primary stack) into the stack2(helper
    // stack)
    while (!s1.empty()) {
      s2.push(s1.top());
      s1.pop();
    }
    // insert(add/push) the new element at the top of stack1(primary stack)
    s1.push(val);
    // copy the entire elements of stack2(helper stack) back to the
    // stack1(primary stack)
    while (!s2.empty()) {
      s1.push(s2.top());
      s2.pop();
    }
  }

  // method that delete(remove/pop/eliminate) the element from the front of
  // queue and return that element
  int pop() {
    if (s1.empty()) {
      return -1; // Queue is empty
    }
    int ans = s1.top();
    s1.pop();
    return ans;
  }

  // method that return the top element of the stack
  int front() { return s1.top(); }

  // method that check whether the stack is empty or not
  bool empty() { return s1.empty(); }
};
int main() {
  cout << "\n \t \t \t \t \t \t \t Implement Queue using Stacks" << endl;
  cout << "\n \t \t \t \t \t \t \t-------------------------------" << endl;
  MyQueue q1;
  q1.push(10);
  q1.push(20);
  cout << "Front element is: " << q1.front() << endl;
  cout << "Popped element is: " << q1.pop() << endl;
  cout << "Is queue empty? " << (q1.empty() ? "Yes" : "No") << endl;
  while (!q1.empty()) {
    cout << "Popped element is: " << q1.pop() << endl;
  }
  cout << "Is queue empty? " << (q1.empty() ? "Yes" : "No") << endl;
  q1.push(30);
  q1.push(40);
  q1.push(50);
  cout << "Elements in the queue are: ";
  stack<int> q1Copy = q1.s1; // Create a copy to preserve original
  while (!q1.empty()) {
    cout << q1.front() << " ";
    q1.pop();
  }
  cout << endl;

  return 0;
}
