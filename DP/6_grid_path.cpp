#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007

int f(int i, int j, vector<vector<char>>& grid, int n, vector<vector<int>>& dp){
    //out of bound
    if(i<0 || i>n || j<0 || j>n || grid[i][j]=='*') return 0;
    //base case
    if(i==0 && j==0) return 1;

    if(dp[i][j]!=-1) return dp[i][j];

    long long left = f(i, j-1, grid, n, dp);
    long long up = f(i-1, j, grid, n, dp);

    return dp[i][j] = (left+up)%mod;
}

int solution(vector<vector<char>>& grid){
    int n=grid.size();
    vector<vector<int>> dp(n, vector<int>(n, -1));
    return f(n-1, n-1, grid, n, dp);
}

int main(){
    int n;
    cin>>n;

    vector<vector<char>> grid(n, vector<char>(n, '.'));
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>grid[i][j];
        }
    }

    cout<<solution(grid)<<'\n';

    return 0;
}