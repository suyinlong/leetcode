class MinStack {
private:
    stack<int> _stack, _minStack;
public:
    /** initialize your data structure here. */
    MinStack() {

    }

    void push(int x) {
        _stack.push(x);
        if (_minStack.empty() || _minStack.top() >= x)
            _minStack.push(x);
    }

    void pop() {
        int x = _stack.top();
        _stack.pop();
        if (_minStack.top() == x)
            _minStack.pop();
    }

    int top() {
        return _stack.top();
    }

    int getMin() {
        return _minStack.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */