class Logger {
private:
    unordered_map<string, int> msg;
public:
    /** Initialize your data structure here. */
    Logger() {

    }

    /** Returns true if the message should be printed in the given timestamp, otherwise returns false.
        If this method returns false, the message will not be printed.
        The timestamp is in seconds granularity. */
    bool shouldPrintMessage(int timestamp, string message) {
        auto it = msg.find(message);
        if (it == msg.end()) {
            msg[message] = timestamp;
            return true;
        }
        else {
            int k = it->second;
            if (timestamp - k >= 10) {
                msg[message] = timestamp;
                return true;
            }
            else
                return false;
        }
    }
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger obj = new Logger();
 * bool param_1 = obj.shouldPrintMessage(timestamp,message);
 */