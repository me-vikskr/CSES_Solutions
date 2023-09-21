#include<bits/stdc++.h>
using namespace std;

// int f(int ind, int money, vector<int>& prices, vector<int>& pages, vector<vector<int>>& dp){
//     //base case
//     if(ind==0){
//         if(prices[0]<=money) return pages[0];
//         return -1e8;
//     }

//     if(dp[ind][money]!=-1) return dp[ind][money];

//     int notPick = f(ind-1, money, prices, pages, dp);
//     int pick = -1e8;
//     if(prices[ind] <= money) pick = pages[ind] + f(ind-1, money-prices[ind], prices, pages, dp);

//     return dp[ind][money] = max(pick, notPick);
// }

int solution(vector<int>& prices, vector<int>& pages, int n, int x){
    vector<vector<int>> dp(n+1, vector<int>(x+1, 0));

    for(int ind=1; ind<=n; ind++){
        for(int money=0; money<=x; money++){
            int notPick = dp[ind-1][money];
            int pick = 0;
            if(prices[ind-1] <= money) pick = pages[ind-1] + dp[ind-1][money-prices[ind-1]];

            dp[ind][money] = max(pick, notPick);
        }
    }

    return dp[n][x];
}

int main(){
    int n, x;
    cin>>n>>x;

    vector<int> prices(n, 0);
    for(int i=0; i<n; i++) cin>>prices[i];

    vector<int> pages(n, 0);
    for(int i=0; i<n; i++) cin>>pages[i];

    cout<<solution(prices, pages, n, x)<<'\n';

    return 0;
}