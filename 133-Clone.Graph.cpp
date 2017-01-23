/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
private:
    UndirectedGraphNode *dfsClone(UndirectedGraphNode *node, unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> &cloneMap) {
        auto it = cloneMap.find(node);
        if (it != cloneMap.end()) {
            return it->second;
        }
        UndirectedGraphNode *cloneNode = new UndirectedGraphNode(node->label);
        cloneMap[node] = cloneNode;
        for (int i = 0; i < node->neighbors.size(); i++) {
            cloneNode->neighbors.push_back(dfsClone(node->neighbors[i], cloneMap));
        }
        return cloneNode;
    }
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (!node)
            return NULL;
        unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> cloneMap;

        return dfsClone(node, cloneMap);
    }
};