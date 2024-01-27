#include <bits/stdc++.h>
using namespace std;


class Graph {
    public: 
	vector<vector<int> > edgelist;
    int V, E;

    Graph(int V, int E) { 
        this->V = V;
        this->E = E;
    }

    void addEdge(int x, int y, int w) { 
		edgelist.push_back({ x, y, w });
    }

    void printArr(int dist[], int n) {
        printf("Vertex Distance from Source\n");
        for (int i = 0; i < n; ++i)
            printf("%d \t\t %d\n", i, dist[i]);
    }

    void bellmanFord(int src) {
        int dist[V];

        for (int i = 0; i < V; i++)
            dist[i] = INT_MAX;
        dist[src] = 0;

        for (int i = 1; i <= V - 1; i++) {
            for (int j = 0; j < E; j++) {
                int u = edgelist[j][0];
                int v = edgelist[j][1];
                int weight = edgelist[j][2];
                if (dist[u] != INT_MAX
                    && dist[u] + weight < dist[v])
                    dist[v] = dist[u] + weight;
            }
        }

        for (int i = 0; i < E; i++) {
            int u = edgelist[i][0];
            int v = edgelist[i][1];
            int weight = edgelist[i][2];
            if (dist[u] != INT_MAX
                && dist[u] + weight < dist[v]) {
                printf("Graph contains negative weight cycle");
                return;
            }
        }
        printArr(dist, V);
        return;
    }
};

int main() {
	int V = 5;
	int E = 8;
    Graph g(V, E);
    g.addEdge(0, 1, -1);
    g.addEdge(0, 2, 4);
    g.addEdge(1, 2, 3);
    g.addEdge(1, 3, 2);
    g.addEdge(1, 4, 2);
    g.addEdge(3, 2, 5);
    g.addEdge(3, 1, 1);
    g.addEdge(4, 3, -3);
	
	g.bellmanFord(0);

	return 0;
}