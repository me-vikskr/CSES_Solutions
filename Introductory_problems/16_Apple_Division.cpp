#include<bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define ll long long
#define pb push_back
#define loop(i, a, b) for(int i=a; i<b; i++)

// sum1 + sum2 = totSum;
// sum2 = totSum - sum1 
// diff = abs(sum2-sum1) = abs(totSum - sum1 - sum1);

void f(int ind, ll& sum1, vector<int>& arr, ll totSum, ll& minDiff){
    if(ind<0){
        minDiff = min(minDiff, abs(totSum - (2*sum1)));
        return;
    }

    //notPick
    f(ind-1, sum1, arr, totSum, minDiff);

    //pick
    sum1 += arr[ind];
    f(ind-1, sum1, arr, totSum, minDiff);
    sum1 -= arr[ind];
}

int minDiff(vector<int>& arr, int n){    
    ll totSum = accumulate(arr.begin(), arr.end(), (ll)0);
    // cout<<totSum<<'\n';
    ll minDiff = LONG_LONG_MAX;
    ll sum1 = 0;
    f(n-1, sum1, arr, totSum, minDiff);

    return minDiff;
}

int main(){
    int n;
    cin>>n;

    vector<int> arr(n);
    for(auto& it: arr) cin>>it;

    cout<<minDiff(arr, n)<<'\n';

    return 0;
}