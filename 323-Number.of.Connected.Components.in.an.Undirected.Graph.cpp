class Solution {
private:
    vector<int> id;

    int findRoot(int i) {
        if (id[i] != i)
            id[i] = findRoot(id[i]);
        return id[i];
    }

    bool unite(int a, int b) {
        int p = findRoot(a), q = findRoot(b);
        if (p == q) return false;
        if (p < q) id[q] = p;
        else id[p] = q;
        return true;
    }
public:
    int countComponents(int n, vector<pair<int, int>>& edges) {
        id.resize(n);
        for (int i = 0; i < n; i++) id[i] = i;
        int count = n;
        for (int i = 0; i < edges.size(); i++)
            if (unite(edges[i].first, edges[i].second))
                count--;
        return count;
    }
};