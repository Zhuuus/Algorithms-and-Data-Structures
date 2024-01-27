#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class DSU {
    int* parent;
    int* rank;

public:
    DSU(int n) {
        parent = new int[n];
        rank = new int[n];

        for (int i = 0; i < n; i++) {
            parent[i] = -1;
            rank[i] = 1;
        }
    }

    int find(int i) {
        if (parent[i] == -1)
            return i;

        return parent[i] = find(parent[i]);
    }

    void unite(int x, int y) {
        int s1 = find(x);
        int s2 = find(y);

        if (s1 != s2) {
            if (rank[s1] < rank[s2]) {
                parent[s1] = s2;
            } else if (rank[s1] > rank[s2]) {
                parent[s2] = s1;
            } else {
                parent[s2] = s1;
                rank[s1] += 1;
            }
        }
    }
};

class Graph {
    vector<vector<int> > edgelist;
    int V;

public:
    Graph(int V) {
        this->V = V;
    }

    void addEdge(int x, int y, int w) {
        edgelist.push_back(vector<int>{w, x, y});
    }

    void kruskals_mst() {
        sort(edgelist.begin(), edgelist.end());

        DSU s(V);
        int ans = 0;
  

        for (int i = 0; i < edgelist.size(); i++) {
            int w = edgelist[i][0];
            int x = edgelist[i][1];
            int y = edgelist[i][2];

            if (s.find(x) != s.find(y)) {
                s.unite(x, y);
                ans += w;
               
            }
        }
        cout  << ans;
    }
};

int main() {

    int n;
    cin >> n;
    int arr[n];
    Graph g(n);
    for (int i = 0; i < n; i++) {
        int w;
        cin >> w;
        arr[i] = w;
    }

    for (int j = 0; j < n; j++) {
        for (int i = 0; i < n; i++) {
            if(j != i) g.addEdge(j, i, arr[j] + arr[i]); // corrected the index
        }
    }

    g.kruskals_mst();

    return 0;
}