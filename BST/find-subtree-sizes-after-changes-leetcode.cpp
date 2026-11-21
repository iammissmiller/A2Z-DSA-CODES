
class Solution {
public:
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();

        // Build the original tree
        vector<vector<int>> tree(n);

        for (int i = 1; i < n; i++) {
            tree[parent[i]].push_back(i);
        }

        // Find the new parent of every node
        vector<int> newParent = parent;
        vector<int> last(26, -1);
        vector<int> previous( n, -1);

        // {node, entering or exiting}
        stack<pair<int, bool>> st;
        st.push({0, true});

        while (!st.empty()) {
            auto [u, entering] = st.top();
            st.pop();

            int c = s[u] - 'a';

            if (entering) {
                previous[u] = last[c];

                if (last[c] != -1) {
                    newParent[u] = last[c];
                }

                last[c] = u;

                // Exit event after all children
                st.push({u, false});

                // Visit children
                for (int i = tree[u].size() - 1; i >= 0; i--) {
                    st.push({tree[u][i], true});
                }
            }
            else {
                // Backtrack: restore previous ancestor
                last[c] = previous[u];
            }
        }

        // Build the modified tree
        vector<vector<int>> newTree(n);

        for (int i = 1; i < n; i++) {
            newTree[newParent[i]].push_back(i);
        }

        // Generate traversal order
        vector<int> order;
        stack<int> nodes;
        nodes.push(0);

        while (!nodes.empty()) {
            int u = nodes.top();
            nodes.pop();

            order.push_back(u);

            for (int v : newTree[u]) {
                nodes.push(v);
            }
        }

        // Calculate subtree sizes in reverse order
        vector<int> ans(n, 1);

        for (int i = n - 1; i > 0; i--) {
            int u = order[i];
            ans[newParent[u]] += ans[u];
        }

        return ans;
    }
};
