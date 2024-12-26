/*
 * @lc app=leetcode id=155 lang=cpp
 *
 * [155] Min Stack
 */
#include<iostream>
#include<stack>
using namespace std;

// @lc code=start
class MinStack {
private:
    stack<int> stack1;
    stack<int> minStack;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        if(minStack.empty() || val<=minStack.top())
            minStack.push(val);

        stack1.push(val);
    }
    
    void pop() {
        if(!minStack.empty() && minStack.top() == stack1.top())
            minStack.pop();
        
        stack1.pop();
    }
    
    int top() {
        return stack1.top();
    }
    
    int getMin() {
        return minStack.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// @lc code=end

