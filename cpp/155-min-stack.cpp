#include <iostream>
#include <vector>

using namespace std;

class MinStack {
  vector<int> minStack;
    int track =0; 
  vector<int>minVals; 

 public:
  MinStack() {  // constructor
  }

  void push(int val) {
    if (val < minVals[track]) {
      minVals[track++] = val; 
    }

    minStack.push_back(val);
  }

  void pop() {
   minStack.pop_back();

  }

  int top() { return minStack[0]; }

  int getMin() { return minVals[track]; }   
};

int main() {
  MinStack minStack;

  minStack.push(-2);
  minStack.push(0);
  minStack.push(-3);
 cout<<"Min val: "<< minStack.getMin()<<endl;;
  minStack.pop();
  cout<<"Top: "<<minStack.top()<<endl;  // return 0
cout<<"Min val: "<< minStack.getMin()<<endl;;
}