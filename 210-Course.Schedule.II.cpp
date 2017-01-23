class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        if (numCourses == 0)
            return vector<int>();

        vector<int> inNode(numCourses, 0);
        vector<vector<int>> edges(numCourses, vector<int>());
        unordered_set<int> eNode;
        vector<int> result;

        for (auto p: prerequisites) {
            inNode[p.first]++;
            edges[p.second].push_back(p.first);
        }

        for (int i = 0; i < numCourses; i++)
            if (inNode[i] == 0)
                eNode.insert(i);
        while (!eNode.empty()) {
            auto it = eNode.begin();
            result.push_back(*it);
            for (int j: edges[*it]) {
                inNode[j]--;
                if (inNode[j] == 0)
                eNode.insert(j);
            }
            eNode.erase(*it);
        }
        if (result.size() != numCourses)
            return vector<int>();
        else
            return result;

    }
};