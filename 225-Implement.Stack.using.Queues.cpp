class Stack {
private:
    int q_no, s_top;
    vector<queue<int>> q;
public:
    Stack() {
        q_no = 0;
        s_top = 0;
        q.push_back(queue<int>());
        q.push_back(queue<int>());
    }

    // Push element x onto stack.
    void push(int x) {
        q[q_no].push(x);
        s_top = x;
    }

    // Removes the element on top of the stack.
    void pop() {
        int k = (q_no) ? 0 : 1;
        int t;
        while (q[q_no].size() > 1) {
            t = q[q_no].front();
            q[q_no].pop();
            q[k].push(t);
            s_top = t;
        }
        while (!q[q_no].empty())
            q[q_no].pop();
        q_no = k;
    }

    // Get the top element.
    int top() {
        return s_top;
    }

    // Return whether the stack is empty.
    bool empty() {
        return q[q_no].empty();
    }
};