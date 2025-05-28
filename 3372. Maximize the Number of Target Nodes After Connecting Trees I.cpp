class Solution {
public:
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        // Build graph2 from edges2 and find max reachable nodes within (k - 1) distance
        vector<vector<int>> graph2 = buildGraph(edges2);
        int maxReach = 0;
        int size2 = graph2.size();
        for (int i = 0; i < size2; ++i) {
            maxReach = max(maxReach, countNodes(graph2, i, -1, k - 1));
        }

        // Build graph1 from edges1 and calculate result
        vector<vector<int>> graph1 = buildGraph(edges1);
        int size1 = graph1.size();
        vector<int> result(size1, maxReach);
        for (int i = 0; i < size1; ++i) {
            result[i] += countNodes(graph1, i, -1, k);
        }

        return result;
    }

private:
    // Build undirected graph from edge list
    vector<vector<int>> buildGraph(const vector<vector<int>>& edges) {
        int n = edges.size() + 1;
        vector<vector<int>> graph(n);
        for (auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        return graph;
    }

    // DFS to count reachable nodes within distance d
    int countNodes(const vector<vector<int>>& graph, int node, int parent, int d) {
        if (d < 0) return 0;

        int count = 1; // count the current node
        for (int neighbor : graph[node]) {
            if (neighbor != parent) {
                count += countNodes(graph, neighbor, node, d - 1);
            }
        }
        return count;
    }
};
