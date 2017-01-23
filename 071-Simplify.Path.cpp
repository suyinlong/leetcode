class Solution {
public:
    string simplifyPath(string path) {
        stack<string> pathStack;
        string folder = "";
        for (int i = 0; i <= path.size(); i++) {
            if (i == path.size() || path[i] == '/') {
                if (folder.size() > 0) {
                    if (folder == ".." && pathStack.size() > 0)
                        pathStack.pop();
                    else if (folder != "." && folder != "..")
                        pathStack.push(folder);
                }
                folder = "";
            }
            else {
                folder += path[i];
            }
        }
        string result = "";
        while (!pathStack.empty()) {
            string f = pathStack.top();
            pathStack.pop();
            result = "/" + f + result;
        }
        return result.size() > 0 ? result : "/";
    }
};