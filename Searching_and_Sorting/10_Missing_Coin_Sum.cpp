#include<bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define ll long long
#define pb push_back
#define loop(i, a, b) for(int i=a; i<b; i++)

ll missingCoinSum(int n, vector<ll>& coins){
    sort(coins.begin(), coins.end());

    ll smallestSum = 1;
    for(int i=0; i<n; i++){
        if(coins[i] <= smallestSum){
            smallestSum += coins[i];
        }
        else break;
    }

    return smallestSum;
}

int main(){
    int n;
    cin>>n;

    vector<ll> coins(n);
    for(auto& it: coins) cin>>it;

    cout<<missingCoinSum(n, coins)<<'\n';

    return 0;
}