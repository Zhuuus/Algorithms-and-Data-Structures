#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int Island(vector<vector<char>>& grid) {
    int m = grid.size();
    int n = grid[0].size();

    int islands = 0;

    vector<pair<int, int>> dirs;
    dirs.push_back(make_pair(0, 1));
    dirs.push_back(make_pair(0, -1));
    dirs.push_back(make_pair(1, 0));
    dirs.push_back(make_pair(-1, 0));

    queue<pair<int, int>> q;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == '1') {
                q.push(make_pair(i, j));
                while (!q.empty()) {
                    pair<int, int> cur = q.front();
                    q.pop();
                    for (size_t d = 0; d < dirs.size(); ++d) {
                        int x = cur.first + dirs[d].first;
                        int y = cur.second + dirs[d].second;

                        if (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == '1') {
                            grid[x][y] = '2';
                            q.push(make_pair(x, y));
                        }
                    }
                }
                islands++;
            }
        }
    }

    return islands;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<char>> v(n, vector<char>(m));

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++) {
            v[i][j] = s[j];
        }
    }

    cout << Island(v);

    return 0;
}
