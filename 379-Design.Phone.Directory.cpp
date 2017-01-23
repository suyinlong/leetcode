class PhoneDirectory {
public:
    /** Initialize your data structure here
        @param maxNumbers - The maximum numbers that can be stored in the phone directory. */
    PhoneDirectory(int maxNumbers) : idx(0), cnt(maxNumbers), freeList(maxNumbers), isFree(maxNumbers, true) {
        for (int i = 0; i < cnt; i++)
            freeList[i] = i;
    }

    /** Provide a number which is not assigned to anyone.
        @return - Return an available number. Return -1 if none is available. */
    int get() {
        int n = -1;
        if (idx < cnt) {
            n = freeList[idx++];
            isFree[n] = false;
        }
        return n;
    }

    /** Check if a number is available or not. */
    bool check(int number) {
        if (number < 0 || number >= cnt)
            return false;
        return isFree[number];
    }

    /** Recycle or release a number. */
    void release(int number) {
        if (number < 0 || number >= cnt || isFree[number])
            return;
        freeList[--idx] = number;
        isFree[number] = true;
    }
private:
    vector<int> freeList;
    vector<bool> isFree;
    int idx, cnt;
};

/**
 * Your PhoneDirectory object will be instantiated and called as such:
 * PhoneDirectory obj = new PhoneDirectory(maxNumbers);
 * int param_1 = obj.get();
 * bool param_2 = obj.check(number);
 * obj.release(number);
 */