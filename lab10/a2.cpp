#include <vector>
#include <queue>
#include <iostream>
using namespace std;
int n, m;
int mushroom(vector<vector<int> >& grid){
    int m = grid.size();
    int n = grid[0].size();

    int mar = 0, time = -1;

    vector<pair<int,int> > dirs;
    dirs.push_back(make_pair(0,1));
    dirs.push_back(make_pair(0,-1));
    dirs.push_back(make_pair(1,0));
    dirs.push_back(make_pair(-1,0));

    queue<pair<int, int> > q;

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j] == 1) mar++;
            if(grid[i][j]==2) q.push(make_pair(i,j));
        }
    }

    while(!q.empty()){
        int  size = q.size();
        for(int i=0; i<size; i++){
            pair<int,int> cur = q.front();
            q.pop();
            for(size_t j=0; j<dirs.size();j++){
                int x = cur.first + dirs[j].first;
                int y = cur.second + dirs[j].second;
    // cout << mar;
                if( x >= 0 && x < m && y>=0 && y<n && grid[x][y]==1){
                    grid[x][y] = 2;
                    q.push(make_pair(x, y));
                    mar--;
                }
            }
        }
        time++;
    }
    if(mar>0) return -1;
    if(time<0) return 0;
    return time;
}


int main(){
cin >> n >> m;
vector<vector<int> > v(n,vector<int> (m));
for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        cin>>v[i][j];
    }
}


cout <<mushroom(v);


}
