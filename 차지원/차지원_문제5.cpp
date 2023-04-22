#include <iostream>
#include <vector>
using namespace std;

vector<int> solution(vector<vector<int>>& edges) {
    vector<int> parents(edges.size(), 0);
    vector<int> stack = {1};

    parents[1] = 1;
    while (!stack.empty()) {
        int cur = stack.back();
        stack.pop_back();
        for (int child: edges[cur]) {
            if (parents[child] == 0) {
                parents[child] = cur;
                stack.push_back(child);
            }
        }
    }

    return parents;
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    vector<vector<int>> edges(n + 1);

    int a, b;
    for (int i = 0; i < n - 1; i++) {
        cin >> a >> b;
        edges[b].push_back(a);
        edges[a].push_back(b);
    }

    vector<int> parents = solution(edges);
    for (int i = 2; i < n + 1; i++) {
        cout << parents[i] << "\n";
    }

    return 0;
}
