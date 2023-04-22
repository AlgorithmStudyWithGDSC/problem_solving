#include <iostream>
#include <vector>
using namespace std;

pair<int, int> bfs(vector<vector<int>>& edges, vector<vector<pair<int, int>>>& tree, int root) {
    vector<pair<int, int>> stack;
    vector<bool> visited(edges.size(), false);
    pair<int, int> maxNode = make_pair(0, 0);

    stack.push_back(make_pair(root, 0));
    visited[root] = true;
    
    while (!stack.empty()) {
        auto cur = stack.back();
        stack.pop_back();
        int node = cur.first;
        int distance = cur.second;

        for (auto& p : tree[node]) {
            int v = p.first;
            int e = p.second;
            if (!visited[v]) {
                visited[v] = true;
                auto node = make_pair(v, distance + e);
                stack.push_back(node);

                if (distance + e > maxNode.second) {
                    maxNode = node;
                }
            }
        }
    }

    return maxNode;
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> edges(n + 1);
    vector<vector<pair<int, int>>> tree(n + 1);

    for (int i = 1; i < n + 1; i++) {
        int x;
        while (cin >> x && x != -1) {
            edges[i].push_back(x);
        }

        for (int j = 1; j < edges[i].size(); j += 2) {
            tree[edges[i][0]].push_back(make_pair(edges[i][j], edges[i][j + 1]));
        }
    }

    auto end = bfs(edges, tree, 1);
    auto result = bfs(edges, tree, end.first);

    cout << result.second;
    return 0;
}
