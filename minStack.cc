#include <iostream>
#include <utility>
#include <stack>

using namespace std;

class MinStack
{
    stack<pair<int, int> > stk;

public:
    MinStack()
    {
    }

    void push(int val)
    {
        if (stk.empty())
        {
            stk.push({ val, val });
        }
        else
        {
            stk.push({ val, min(getMin(), val) });
        }
    }

    void pop()
    {
        stk.pop();
    }

    int top()
    {
        return stk.top().first;
    }

    int getMin()
    {
        return stk.top().second;
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


int main() {
    MinStack minStack;
    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);
    cout << minStack.getMin() << endl;
    minStack.pop();
    cout << minStack.top() << endl;
    cout << minStack.getMin() << endl;
}