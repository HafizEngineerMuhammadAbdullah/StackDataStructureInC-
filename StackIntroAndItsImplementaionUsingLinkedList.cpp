#include <iostream>
#include <list>
#include <stack>
using namespace std;
// Introduction of Stack Data Structure & it's implementation(implementing it's
// function) Using LinkedList Data Structure
class Stack {
  list<int> ll;

public:
  // method to push(add/insert)  the new element at the top of stack
  void push(int val) { // TC:O(1)
    ll.push_front(
        val); // insert(add/push) the element at the front of LinkedList

    return;
  }

  // method to pop(delete/remove) the last inserted element from the top of
  // stack
  void pop() {      // TC:O(1)
    ll.pop_front(); // delete the head element(front element) of LinkedList
    return;
  }

  // method that returns the top element(last inserted element) of the stack
  int top() {
    return ll.front(); // returns the head(front) element of LinkedList.
  }

  // method that returns true if our stack is empty otherwise return false.
  bool isEmpty() { return ll.size() == 0; }
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
  cout << endl;

  return 0;
}
