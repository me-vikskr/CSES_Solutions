#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007

int f(int val, int tar, vector<vector<int>>& dp){
    if(tar==0) return 1;
    if(val>6) return 0;

    if(dp[val][tar]!=-1) return dp[val][tar];
    
    long long notPick = f(val+1, tar, dp);
    long long pick = 0;
    if(val<=tar) pick = f(1, tar-val, dp);

    return dp[val][tar] = (int)((pick + notPick)%mod);
}

int solution(int n){
    vector<vector<int>> dp(7, vector<int>(n+1, -1));
    return f(1, n, dp);
}

int main(){
    int n;
    cin>>n;

    cout<<solution(n)<<'\n';
}