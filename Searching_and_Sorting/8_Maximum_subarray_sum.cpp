#include<bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define ll long long
#define pb push_back
#define loop(i, a, b) for(int i=a; i<b; i++)

ll maximumSubArraySum(int n, vector<ll>& arr){
    ll currSum=0, maxSum=INT_MIN;
    for(int i=0; i<n; i++){
        currSum += arr[i];

        maxSum = max(maxSum, currSum);
        if(currSum < 0) currSum = 0;
    }

    return maxSum;
}

int main(){
    int n;
    cin>>n;

    vector<ll> arr(n);
    for(auto &it: arr) cin>>it;

    cout<<maximumSubArraySum(n, arr)<<'\n';

    return 0;
}