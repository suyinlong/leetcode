// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
private:
    char buffer[4];
    int pos, size;
public:
    Solution() {
        pos = 4;
        size = 0;
    }

    /**
     * @param buf Destination buffer
     * @param n   Maximum number of characters to read
     * @return    The number of characters read
     */
    int read(char *buf, int n) {
        int p = 0;
        while (n > 0) {
            if (pos >= size) {
                size = read4(buffer);
                pos = 0;
                if (size == 0)
                    break;
            }
            buf[p++] = buffer[pos++];
            n--;
        }
        return p;
    }
};