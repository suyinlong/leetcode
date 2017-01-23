class Solution {
private:
    bool dfs(unordered_map<string, vector<string>> &edges, vector<string> &result, int n) {
        if (result.size() == n)
            return true;
        auto it = edges.find(result.back());
        if (it == edges.end())
            return false;
        for (int i = 0; i < it->second.size(); i++) {
            string dest = it->second[i];
            it->second.erase(it->second.begin() + i);
            result.push_back(dest);
            if (dfs(edges, result, n))
                return true;
            result.pop_back();
            it->second.insert(it->second.begin() + i, dest);
        }
        return false;
    }
public:
    vector<string> findItinerary(vector<pair<string, string>> tickets) {
        unordered_map<string, vector<string>> edges;

        for (auto t: tickets) {
            if (edges.count(t.first) == 0)
                edges[t.first] = vector<string>(1, t.second);
            else
                edges.find(t.first)->second.push_back(t.second);
        }

        for (auto it = edges.begin(); it != edges.end(); it++)
            sort(it->second.begin(), it->second.end());

        vector<string> result;
        result.push_back("JFK");
        dfs(edges, result, tickets.size() + 1);
        return result;
    }
};