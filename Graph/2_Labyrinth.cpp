#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin>>n>>m;

    vector<vector<char>> map(n, vector<char>(m));
    int sr=0, sc=0;
    int er=0, ec=0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>map[i][j];
            if(map[i][j]=='A'){
                sr=i;
                sc=j;
            }
            if(map[i][j]=='B'){
                er=i;
                ec=j;
            }
        }
    }

    

    return 0;
}