/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
private:
    string getNext(string &s, int &p) {
        if (p < s.size() && s[p] == ',') p++;
        if (p < s.size() && (s[p] == '[' || s[p] == ']')) return s.substr(p++, 1);
        int start = p;
        if (p < s.size() && s[p] == '-') p++;
        while (p < s.size() && isdigit(s[p])) p++;
        return s.substr(start, p - start);
    }
public:
    NestedInteger deserialize(string s) {
        stack<NestedInteger> stk;
        int p = 0;
        while (p < s.size()) {
            string comp = getNext(s, p);
            if (comp == "[")
                stk.push(NestedInteger());
            else {
                NestedInteger ni;
                if (comp == "]") {
                    ni = stk.top();
                    stk.pop();
                }
                else
                    ni = NestedInteger(stoi(comp));
                if (stk.size())
                    stk.top().add(ni);
                else
                    stk.push(ni);
            }
        }
        return stk.top();
    }
};