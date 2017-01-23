class Solution {
private:
    bool dfs(int i, vector<vector<pair<int, int>>> &edges, vector<bool> &vi, vector<bool> &visited) {
        if (vi[i])
            return false;
        vi[i] = true;
        visited[i] = true;
        for (auto p: edges[i]) {
            int j = p.first;
            if (!dfs(j, edges, vi, visited))
                return false;
        }
        vi[i] = false;
        return true;
    }
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<bool> visited(numCourses, false);
        vector<vector<pair<int, int>>> edges(numCourses);

        for (auto p: prerequisites) {
            edges[p.second].push_back(p);
        }

        for (int i = 0; i < numCourses; i++) {
            if (!visited[i]) {
                vector<bool> vi(numCourses, false);
                if (!dfs(i, edges, vi, visited))
                    return false;
            }
        }
        return true;
    }
};