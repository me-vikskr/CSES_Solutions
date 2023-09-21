#include <bits/stdc++.h>
using namespace std;

// int f(int ind, int tar, vector<int> &coins, vector<vector<int>> &dp)
// {
//     if (ind == 0)
//     {
//         if (tar % coins[0] == 0)
//             return tar / coins[0];
//         return 1e9;
//     }

//     if (dp[ind][tar] != -1)
//         return dp[ind][tar];

//     int notPick = f(ind - 1, tar, coins, dp);
//     int pick = 1e9;
//     if (coins[ind] <= tar)
//         pick = 1 + f(ind, tar - coins[ind], coins, dp);

//     return dp[ind][tar] = min(pick, notPick);
// }

int solution(vector<int> &coins, int n, int x)
{
    vector<vector<int>> dp(n, vector<int>(x + 1, 0));
    //base case
    for(int tar=0; tar<=x; tar++){
        if (tar % coins[0] == 0) dp[0][tar] = tar / coins[0];
        else dp[0][tar] = 1e9;
    }

    for(int ind = 1; ind<n; ind++){
        for(int tar=0; tar<=x; tar++){
            int notPick = dp[ind - 1][tar];
            int pick = 1e9;
            if (coins[ind] <= tar) pick = 1 + dp[ind][tar - coins[ind]];

            dp[ind][tar] = min(pick, notPick);
        }
    }

    if(dp[n-1][x]>=1e9) return -1;
    return dp[n-1][x];
}

int main()
{
    int n, x;
    cin >> n >> x;

    vector<int> coins(n, 0);
    for (int i = 0; i < n; i++)
        cin >> coins[i];

    cout << solution(coins, n, x) << '\n';

    return 0;
}