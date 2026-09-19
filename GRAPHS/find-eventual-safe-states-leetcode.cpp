class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();

        vector<vector<int>> reverseGraph(n);
        vector<int> outDegree(n);

        queue<int> q;

        // Reverse all edges
        for (int i = 0; i < n; i++) {
            outDegree[i] = graph[i].size();

            for (int next : graph[i]) {
                reverseGraph[next].push_back(i);
            }

            // Terminal nodes
            if (outDegree[i] == 0)
                q.push(i);
        }

        // Work backwards from terminal nodes
        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (int parent : reverseGraph[node]) {
                outDegree[parent]--;

                if (outDegree[parent] == 0)
                    q.push(parent);
            }
        }

        vector<int> ans;

        for (int i = 0; i < n; i++) {
            if (outDegree[i] == 0)
                ans.push_back(i);
        }

        return ans;
    }
};
