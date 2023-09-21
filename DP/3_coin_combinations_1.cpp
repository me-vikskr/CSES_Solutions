#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007

// int f(int tar, vector<int>& coins, int n, vector<int>& dp){
//     //base case
//     if(tar<0) return 0;
//     if(tar==0) return 1;

//     if(dp[tar]!=-1) return dp[tar];

//     long long ans = 0;
//     for(int i=0; i<n; i++){
//         ans += f(tar-coins[i], coins, n, dp);
//         ans = ans%mod;
//     }

//     return dp[tar] = ans;
// }

int solution(vector<int>& coins, int n, int x){
    vector<int> dp(x+1, 0);
    dp[0] = 1;

    for(int tar = 1; tar<=x; tar++){
        long long ans = 0;
        for(int i=0; i<n; i++){
            if(tar-coins[i] >= 0){
                ans += dp[tar-coins[i]];
                ans = ans%mod;   
            }
        }
        dp[tar] = ans;
    }

    return dp[x];
}

int main(){
    int n, x;
    cin>>n>>x;

    vector<int> coins(n, 0);
    for(int i=0; i<n; i++) cin>>coins[i];

    cout<<solution(coins, n, x)<<'\n';

    return 0;
}