#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;

int mushroom(vector<vector<int> >& grid) {
    int m = grid.size();
    int n = grid[0].size();

    int mar = 0, t = -1;

    vector<pair<int, int> > dirs;
    dirs.push_back(make_pair(0, 1));
    dirs.push_back(make_pair(0, -1));
    dirs.push_back(make_pair(1, 0));
    dirs.push_back(make_pair(-1, 0));

    queue<pair<int, int> > q;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 1) mar++;
            else if (grid[i][j] == 2) q.push(make_pair(i, j));
        }
    }

    while (!q.empty()) {
        int sz = q.size();
        for (int i = 0; i < sz; i++) {
            pair<int, int> cur = q.front();
            q.pop();
            for (size_t d = 0; d < dirs.size(); ++d) {
                int x = cur.first + dirs[d].first;
                int y = cur.second + dirs[d].second;
                if (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == 1) {
                    grid[x][y] = 2;
                    q.push(make_pair(x, y));
                    mar--;
                }
            }
        }
        t++;
    }
    if (mar > 0) return -1;
    if (t == -1) return 0;
    return t;
}

int main() {
    cin >> n >> m;
    vector<vector<int> > v(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> v[i][j];
        }
    }
    cout << mushroom(v);
    return 0;
}
