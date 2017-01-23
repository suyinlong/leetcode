class Solution {
public:
    string n2w(int num) {
        vector<string> smap = {"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
        vector<string> tmap = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};

        string s = "";
        if (num == 0)
            return s;
        if (num / 100 > 0) {
            s += smap[num / 100] + " Hundred";
            num %= 100;
        }
        if (num / 10 >= 2) {
            if (s.size() > 0) s += " ";
            s += tmap[num / 10];
            if (num % 10 > 0)
                s += " " + smap[num % 10];
        }
        else if (num / 10 == 1) {
            if (s.size() > 0) s += " ";
            s += smap[num];
        }
        else if (num / 10 == 0 && num % 10 > 0) {
            if (s.size() > 0) s += " ";
            s += smap[num % 10];
        }
        return s;
    }
    string numberToWords(int num) {
        string s;
        if (num == 0) {
            s = "Zero";
            return s;
        }
        int k = num % 1000;
        if (k > 0) {
            string s1 = n2w(k);
            s = s1;
        }
        num /= 1000;
        k = num % 1000;
        if (k > 0) {
            string s2 = n2w(k);
            if (s.size() > 0)
                s = s2 + " Thousand " + s;
            else
                s = s2 + " Thousand";
        }
        num /= 1000;
        k = num % 1000;
        if (k > 0) {
            string s3 = n2w(k);
            if (s.size() > 0)
                s = s3 + " Million " + s;
            else
                s = s3 + " Million";
        }
        num /= 1000;
        k = num % 1000;
        if (k > 0) {
            string s4 = n2w(k);
            if (s.size() > 0)
                s = s4 + " Billion " + s;
            else
                s = s4 + " Billion";
        }
        return s;

    }
};