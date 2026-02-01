#include <iostream>
#include <stack>
using namespace std;
// Introduction of Stack Data Structure & it's implementation(implementing it's
// function) Using C++ STL(standard Template Library)
int main() {
  stack<int> s;
  stack<int> st;

  s.push(30);
  s.push(20);
  s.push(10);
  s.push(0);

  st.push(40);
  st.push(50);
  st.push(60);
  st.push(70);

  cout << "Before Swapping\n" << endl;

  while (!(s.empty())) {
    cout << s.top() << " ";
    s.pop();
  }
  cout << endl;

  while (!(st.empty())) {
    cout << st.top() << " ";
    st.pop();
  }
  cout << endl;

  st.swap(s);

  cout << "After Swapping\n" << endl;

  while (!(s.empty())) {
    cout << s.top() << " ";
    s.pop();
  }
  cout << endl;

  while (!(st.empty())) {
    cout << st.top() << " ";
    st.pop();
  }
  cout << endl;

  return 0;
}
