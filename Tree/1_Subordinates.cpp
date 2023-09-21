#include<bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define ll long long
#define pb push_back
#define loop(i, a, b) for(int i=a; i<b; i++)

vector<int> subOrdinates(int n, vector<int>& arr){
    map<int, set<int>> tree;
    vector<int> ans(n, 0);
    for(int i=2; i<=n; i++){
        int parent = arr[i-2];
        int subOrd = i;
        tree[parent].insert(subOrd);
        ans[parent-1]++;
    }

    return ans;
}

int main(){
    int n;
    cin>>n;

    vector<int> arr(n-1);
    for(int& it: arr) cin>>it;

    vector<int> ans = subOrdinates(n, arr);

    for(auto it: ans) cout<<it<<" ";
    cout<<'\n';

    return 0;
}