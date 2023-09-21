#include<bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define ll long long
#define pb push_back
#define loop(i, a, b) for(int i=a; i<b; i++)

ll calculateCost(vector<ll>& arr, int n, int ind){
    ll cost = 0;

    for(int i=0; i<n; i++){
        cost += abs(arr[ind] - arr[i]);
    }

    return cost;
}

ll stickLength(int n, vector<ll>& arr){
    sort(arr.begin(), arr.end());
    
    ll minCost = LONG_LONG_MAX;
    ll cost = calculateCost(arr, n, n/2);

    minCost = min(minCost, cost);

    return minCost;
}

int main(){
    int n;
    cin>>n;

    vector<ll> arr(n);
    for(auto &it: arr) cin>>it;

    cout<<stickLength(n, arr)<<'\n';

    return 0;
}