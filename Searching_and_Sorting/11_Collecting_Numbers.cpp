#include<bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define ll long long
#define pb push_back
#define loop(i, a, b) for(int i=a; i<b; i++)

int numOfRounds(int n, vector<int>& arr){
    int maxDiff = 0;
    for(int i=0; i<n; i++){
        int diff = abs(arr[i]-i);
        maxDiff = max(maxDiff, diff);
    }

    return maxDiff;
}

int main(){
    int n;
    cin>>n;

    vector<int> arr(n);
    for(auto &it: arr) cin>>it;

    cout<<numOfRounds(n, arr)<<'\n';

    return 0;
}