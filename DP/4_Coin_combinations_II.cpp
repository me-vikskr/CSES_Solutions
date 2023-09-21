#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007

// int f(int ind, int tar, vector<int>& coins, vector<vector<int>>& dp){
//     if(ind==0){
//         if(tar%coins[0]==0) return 1;
//         return 0;
//     }

//     if(dp[ind][tar]!=-1) return dp[ind][tar];

//     int notPick = f(ind-1, tar, coins, dp);
//     int pick = 0;
//     if(coins[ind] <= tar) pick = f(ind, tar-coins[ind], coins, dp);

//     return dp[ind][tar] = (pick+notPick)%mod;
// }

int solution(vector<int>& coins, int n, int x){
    vector<vector<int>> dp(n, vector<int>(x+1, 0));
    
    //base case
    for(int tar=0; tar<=x; tar++) dp[0][tar] = tar%coins[0]==0;

    for(int ind=1; ind<n; ind++){
        for(int tar=0; tar<=x; tar++){
            int notPick = dp[ind-1][tar];
            int pick = 0;
            if(coins[ind] <= tar) pick = dp[ind][tar-coins[ind]];

            dp[ind][tar] = (pick+notPick)%mod;
        }
    }

    return dp[n-1][x];
}

int main(){
    int n, x;
    cin>>n>>x;

    vector<int> coins(n, 0);
    for(int i=0; i<n; i++) cin>>coins[i];

    cout<<solution(coins, n, x)<<'\n';

    return 0;   
}