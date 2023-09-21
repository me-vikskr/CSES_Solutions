#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long

// f(ind, val) = no. of ways to fill the arr up to index ind, if x(i) = val;

// int f(int ind, int x, vector<int>& arr, int m, vector<vector<int>>& dp){
//     if(ind==arr.size()){
//         return 1;
//     }

//     if(dp[ind][x]!=-1) return dp[ind][x];

//     if(arr[ind]==0){
//         ll ans1 = f(ind+1, x, arr, m, dp)%mod;

//         ll ans2 = 0;
//         if(x-1>=1) ans2 = f(ind+1, x-1, arr, m, dp)%mod;
        
//         ll ans3 = 0;
//         if(x+1<=m) ans3 = f(ind+1, x+1, arr, m, dp)%mod;

//         return dp[ind][x] = (ans1+ans2+ans3)%mod;
//     }
//     else{
//         ll ans = 0;
//         if(abs(arr[ind]-x)<=1) ans = f(ind+1, arr[ind], arr, m, dp)%mod;

//         return ans;
//     }
// }

// int solution(vector<int>& arr, int n, int m){
//     ll ans = 0;
//     vector<vector<int>> dp(n, vector<int>(m+1, -1));
    
//     //solving for 0-th index separately
//     if(arr[0]==0){
//         for(int x=1; x<=m; x++){
//             ans = (ans + f(1, x, arr, m, dp)%mod)%mod;
//         }
//     }
//     else ans = f(1, arr[0], arr, m, dp)%mod;

//     return ans;
// }

// tabulation
int solution(vector<int>& arr, int n, int m){
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
    
    for(int x=1; x<=m; x++){
        dp[n][x] = 1;
    }

    for(int ind=n-1; ind>=1; ind--){
        for(int x=1; x<=m; x++){
            if(arr[ind]==0){
                ll ans1 = dp[ind+1][x]%mod;

                ll ans2 = 0;
                if(x-1>=1) ans2 = dp[ind+1][x-1]%mod;
                
                ll ans3 = 0;
                if(x+1<=m) ans3 = dp[ind+1][x+1]%mod;

                dp[ind][x] = (ans1+ans2+ans3)%mod;
            }
            else{
                ll ans = 0;
                if(abs(arr[ind]-x)<=1) ans = dp[ind+1][arr[ind]]%mod;

                dp[ind][x] = ans;
            }
        }
    }

    //for index 0
    ll ans = 0;
    if(arr[0]==0){
        for(int x=1; x<=m; x++){
            ans = (ans + dp[1][x])%mod;
        }
    }
    else ans = dp[1][arr[0]];

    return ans;
}

int main(){
    int n, m;
    cin>>n>>m;

    vector<int> arr(n);
    for(auto &it: arr) cin>>it;

    cout<<solution(arr, n, m)<<'\n';

    return 0;
}