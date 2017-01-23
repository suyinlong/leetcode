class Solution {
public:
    bool isValidSerialization(string preorder) {
        int diff = 1;
        for (int i = 0; i < preorder.length();) {
            if (--diff < 0)
                return false;
            if (preorder[i++] != '#') diff += 2;
            while (i < preorder.length() && preorder[i++] != ',');
        }
        return diff == 0;
    }
};