class Solution {
public:
    bool isNumber(string s) {
        enum InputType
        {
            INVALID,    // 0
            SPACE,      // 1
            SIGN,       // 2
            DIGIT,      // 3
            DOT,        // 4
            EXPONENT,   // 5
            NUM_INPUTS  // 6
        };

        int transitionTable[][NUM_INPUTS] =
        {
            -1,  0,  3,  1,  2, -1,     // next states for state 0
            -1,  8, -1,  1,  4,  5,     // next states for state 1
            -1, -1, -1,  4, -1, -1,     // next states for state 2
            -1, -1, -1,  1,  2, -1,     // next states for state 3
            -1,  8, -1,  4, -1,  5,     // next states for state 4
            -1, -1,  6,  7, -1, -1,     // next states for state 5
            -1, -1, -1,  7, -1, -1,     // next states for state 6
            -1,  8, -1,  7, -1, -1,     // next states for state 7
            -1,  8, -1, -1, -1, -1,     // next states for state 8
        };

        int state = 0;
        auto is = s.begin();
        while (is != s.end())
        {
            InputType inputType = INVALID;
            if (isspace(*is))
                inputType = SPACE;
            else if (*is == '+' || *is == '-')
                inputType = SIGN;
            else if (isdigit(*is))
                inputType = DIGIT;
            else if (*is == '.')
                inputType = DOT;
            else if (*is == 'e' || *is == 'E')
                inputType = EXPONENT;

            state = transitionTable[state][inputType];

            if (state == -1)
                return false;
            else
                ++is;
        }

        return state == 1 || state == 4 || state == 7 || state == 8;
    }
};