#include<bits/stdc++.h>
using namespace std;

int maxNumOfCust(vector<pair<int, int>>& time, int n){
    int maxi=0;
    sort(time.begin(), time.end());
    
    int cnt=0;
    for(auto it: time){
        cnt += it.second;
        maxi = max(maxi, cnt);
    }

    return maxi;
}

int main(){
    int n;
    cin>>n;

    //if a person comes -> 1
    //if a person leaves -> -1
    vector<pair<int, int>> time;
    for(int i=0; i<n; i++){
        int start, end;
        cin>>start>>end;
        time.push_back({start, 1});
        time.push_back({end, -1});
    }

    cout<<maxNumOfCust(time, n)<<'\n';

    return 0;
}