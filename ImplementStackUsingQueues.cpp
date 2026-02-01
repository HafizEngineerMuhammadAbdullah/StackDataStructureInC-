#include <iostream>
#include <queue>
using namespace std;

// Program to implement all the functions of Stack(push,pop,top,empty) using Two
// Queues.
// Note: Here we are making push operation costly./
// So that pop and top operations can be done in O(1) time complexity.
// TC of push operation: O(n)
// TC of pop operation: O(1)
// TC of top operation: O(1)
// TC of empty operation: O(1)
// SC: O(n)
// where n is the number of elements in the stack
// Create a class called MyStack
// Make push expensive so that pop/top is O(1)
// This preserves:
// ✔ LIFO in Stack
class MyStack {
public:
  // create two Queues
  queue<int> q1;
  queue<int> q2;
  // create a constructor for MyStack class
  MyStack() {}

  // method that push(add/insert) the new element at the top of stack
  void push(int val) {
    // copy the entire elements of queue1(primary queue) into the queue2(helper
    // queue)
    while (!q1.empty()) {
      q2.push(q1.front());
      q1.pop();
    }
    // insert(add/push) the new element at the front of Queue1(primary queue)
    q1.push(val);
    // copy the entire elements of queue2(helper queue) back to the
    // queue1(primary queue)
    // keep copying the entire elements of q2(helper queue) back to the
    // q1(primary queue) until and unless queue q2 becomes empty
    while (!q2.empty()) {
      q1.push(q2.front());
      q2.pop();
    }
  }

  // method that delete(remove/pop/eliminate) the element from the top of stack
  // and return that element
  int pop() {
    if (q1.empty()) {
      return -1; // Stack is empty
    }
    int ans = q1.front();
    q1.pop();
    return ans;
  }

  // method that return the top element of the stack
  int top() { return q1.front(); }

  // method that check whether the stack is empty or not
  bool empty() { return q1.empty(); }
};
int main() {
  cout << "\n \t \t \t \t \t \t \t Implement Stack using Queues" << endl;
  cout << "\n \t \t \t \t \t \t \t-------------------------------" << endl;
  MyStack s1;
  s1.push(10);
  s1.push(20);
  cout << "Top element is: " << s1.top() << endl;
  cout << "Popped element is: " << s1.pop() << endl;
  cout << "Is stack empty? " << (s1.empty() ? "Yes" : "No") << endl;
  while (!s1.empty()) {
    cout << "Popped element is: " << s1.pop() << endl;
  }
  cout << "Is stack empty? " << (s1.empty() ? "Yes" : "No") << endl;
  s1.push(30);
  s1.push(40);
  s1.push(50);
  cout << "Elements in the stack are: ";
  queue<int> s1Copy = s1.q1; // Create a copy to preserve original
  while (!s1.empty()) {
    cout << s1.top() << " ";
    s1.pop();
  }
  return 0;
}
