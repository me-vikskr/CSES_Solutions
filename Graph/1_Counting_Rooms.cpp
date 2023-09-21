#include<bits/stdc++.h>
using namespace std;

void dfs(int r, int c, vector<vector<char>>& graph, vector<vector<int>>& vis, int n, int m){
    vis[r][c] = 1;

    int dr[] = {0, -1, 0, 1};
    int dc[] = {-1, 0, 1, 0};
    for(int i=0; i<4; i++){
        int nr = r + dr[i];
        int nc = c + dc[i];

        if(nr>=0 && nr<n && nc>=0 && nc<m && graph[nr][nc]=='.' && !vis[nr][nc]){
            dfs(nr, nc, graph, vis, n, m);
        }
    }
}

int main(){
    int n, m;
    cin>>n>>m;

    vector<vector<char>> graph(n, vector<char>(m));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>graph[i][j];
        }
    }

    vector<vector<int>> vis(n, vector<int>(m, 0));
    int cnt = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(graph[i][j]=='.'){
                if(!vis[i][j]){
                    dfs(i, j, graph, vis, n, m);
                    cnt++;
                }
            }
        }
    }

    cout<<cnt<<'\n';

    return 0;
}