#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    int n, q;
    cin>>n>>q;

    vector<int> arr(n, 0);
    for(auto &it: arr) cin>>it;

    //calculating prefix sum
    vector<ll> prefSum(n+1, 0);
    prefSum[0] = 0;
    for(int i=0; i<n; i++){
        prefSum[i+1] = prefSum[i] + arr[i];
    }

    while(q--){
        int start, end;
        cin>>start>>end;

        cout<<prefSum[end] - prefSum[start-1]<<'\n';
    }

    return 0;
}