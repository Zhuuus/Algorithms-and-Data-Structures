#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

bool topologicalSort(int n, vector<pair<int, int>> &requirements, vector<int> &result) {
    vector<int> inDegree(n + 1, 0);
    unordered_map<int, vector<int>> adjList;

    // Build the graph and calculate in-degrees
    for (const auto &req : requirements) {
        adjList[req.first].push_back(req.second);
        inDegree[req.second]++;
    }

    // Perform topological sorting
    queue<int> q;
    for (int i = 1; i <= n; ++i) {
        if (inDegree[i] == 0) {
            q.push(i);
            result.push_back(i);
        }
    }

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        for (int neighbor : adjList[current]) {
            inDegree[neighbor]--;
            if (inDegree[neighbor] == 0) {
                q.push(neighbor);
                result.push_back(neighbor);
            }
        }
    }

    return result.size() == n;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> requirements;
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        requirements.push_back({x, y});
    }

    vector<int> result;
    if (topologicalSort(n, requirements, result)) {
        cout << "Possible\n";
        for (int quest : result) {
            cout << quest << " ";
        }
        cout << endl;
    } else {
        cout << "Impossible\n";
    }

    return 0;
}
