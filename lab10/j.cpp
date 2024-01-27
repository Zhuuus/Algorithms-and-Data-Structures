#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector <int> g[100];
queue<int> q;
int n,m,x,y;
int used[100];
int d[100];
vector<vector<int> > BigVertices(100,vector<int>(100));

void bfs(int x){
    int BigFamily =0;
    q.push(x);
    d[x]=0;
    used[x]=1;
    BigVertices[x][0]=1;
    while(!q.empty()){
        x = q.front();
        for(int i=0;i<g[x].size();i++){
            y = g[x][i];
            if(used[y] == 0){
                BigVertices[x][0]+=1;
                used[y] = 1;
                d[y] = 0;
                d[y] = d[x] + 1;
                q.push(y);
            }
        }
        q.pop();
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<m;j++){
        if(BigVertices[i][j]>BigFamily){
            BigFamily = BigVertices[i][j];
            }
        }
    }
    cout << BigFamily;
}


int main(){
    cin >> n >> m;
    for(int i=0;i<m;i++){
        cin >>x >>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    bfs(1);
    
}