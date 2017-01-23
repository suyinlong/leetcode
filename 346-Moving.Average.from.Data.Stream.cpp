class MovingAverage {
private:
    int n;
    queue<int> window;
    double sum;
public:
    /** Initialize your data structure here. */
    MovingAverage(int size) {
        n = size;
        sum = 0.0;
    }

    double next(int val) {
        if (window.size() == n) {
            sum -= window.front();
            window.pop();
        }
        window.push(val);
        sum += val;
        return sum / window.size();
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage obj = new MovingAverage(size);
 * double param_1 = obj.next(val);
 */