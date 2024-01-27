#include <iostream>
#include <vector>

using namespace std;
    int n,x,y;
void dfs(vector<vector <int> )
int main(){
    cin >> n;
    vector<vector<int> > v(n,vector<int> (n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> v[i][j];
        }
    }
    dfs(v);

}
