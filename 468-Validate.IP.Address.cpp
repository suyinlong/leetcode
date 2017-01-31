class Solution {
public:
    string validIPAddress(string IP) {
        if (IP.find('.') != std::string::npos)
            return validIPv4(IP);
        else if (IP.find(':') != std::string::npos)
            return validIPv6(IP);
        else
            return "Neither";
    }
    string validIPv4(string IP) {
        vector<int> dots;
        for (int i = 0; i < IP.size(); i++)
            if (IP[i] == '.')
                dots.push_back(i);
        if (dots.size() != 3)
            return "Neither";
        vector<string> nums(4);
        nums[0] = IP.substr(0, dots[0]);
        nums[1] = IP.substr(dots[0] + 1, dots[1] - dots[0] - 1);
        nums[2] = IP.substr(dots[1] + 1, dots[2] - dots[1] - 1);
        nums[3] = IP.substr(dots[2] + 1);
        for (int i = 0; i < 4; i++) {
            if (nums[i].size() < 1 || nums[i].size() > 3)
                return "Neither";
            for (int j = 0; j < nums[i].size(); j++)
                if (!isdigit(nums[i][j]))
                    return "Neither";
            if (stoi(nums[i]) < 0 || stoi(nums[i]) > 255 || (nums[i][0] == '0' && nums[i].size() > 1))
                return "Neither";
        }

        return "IPv4";
    }
    string validIPv6(string IP) {
        vector<int> dots;
        for (int i = 0; i < IP.size(); i++)
            if (IP[i] == ':')
                dots.push_back(i);
        if (dots.size() != 7)
            return "Neither";
        vector<string> nums(8);
        nums[0] = IP.substr(0, dots[0]);
        nums[1] = IP.substr(dots[0] + 1, dots[1] - dots[0] - 1);
        nums[2] = IP.substr(dots[1] + 1, dots[2] - dots[1] - 1);
        nums[3] = IP.substr(dots[2] + 1, dots[3] - dots[2] - 1);
        nums[4] = IP.substr(dots[3] + 1, dots[4] - dots[3] - 1);
        nums[5] = IP.substr(dots[4] + 1, dots[5] - dots[4] - 1);
        nums[6] = IP.substr(dots[5] + 1, dots[6] - dots[5] - 1);
        nums[7] = IP.substr(dots[6] + 1);
        for (int i = 0; i < 8; i++) {
            if (nums[i].size() > 4 || nums[i].size() < 1)
                return "Neither";
            for (int j = 0; j < nums[i].size(); j++)
                if (!(isdigit(nums[i][j]) || (nums[i][j] >= 'A' && nums[i][j] <= 'F') || (nums[i][j] >= 'a' && nums[i][j] <= 'f')))
                    return "Neither";
        }
        return "IPv6";
    }
};