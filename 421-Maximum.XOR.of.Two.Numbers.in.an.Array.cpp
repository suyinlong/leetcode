class Solution {
struct TrieNode {
    TrieNode *child[2]{};
};
public:
    int findMaximumXOR(vector<int>& nums) {
        if (nums.size() == 0 || nums.size() == 1)
            return 0;
        int m = 0;
        TrieNode r;
        TrieNode *root = &r;

        for (int i = 0; i < nums.size(); i++) {
            // insert nums[i] into Trie
            int mask = 0x40000000, t = 0;
            TrieNode *p = root, *q = root;
            for (int shift = 30; shift >= 0; shift--) {
                int c = (nums[i] & mask) >> shift;
                if (!p->child[c])
                    p->child[c] = new TrieNode;
                p = p->child[c];

                int d = (c == 0) ? 1 : 0;
                if (q->child[d]) {
                    q = q->child[d];
                    t += mask;
                }
                else {
                    q = q->child[c];
                }
                mask >>= 1;
            }
            if (t > m)
                m = t;
        }
        return m;
    }
};