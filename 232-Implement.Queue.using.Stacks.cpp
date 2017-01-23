class Queue {
private:
    stack<int> s1, s2;
    void toS2() {
        if (s2.empty()) {
            while (!s1.empty()) {
                int x = s1.top();
                s1.pop();
                s2.push(x);
            }
        }
    }
public:
    // Push element x to the back of queue.
    void push(int x) {
        s1.push(x);
    }

    // Removes the element from in front of queue.
    void pop(void) {
        toS2();
        s2.pop();
    }

    // Get the front element.
    int peek(void) {
        toS2();
        return s2.top();
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return s1.empty() && s2.empty();
    }
};