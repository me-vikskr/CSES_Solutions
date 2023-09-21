#include<bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define ll long long
#define pb push_back
#define loop(i, a, b) for(int i=a; i<b; i++)

vector<int> sumOfTwoValues(int n, vector<int> arr, int x){
    vector<int> ans;
    
    map<int, int> mpp;
    for(int i=0; i<n; i++){
        if(mpp.count(x - arr[i])){
            ans.push_back(i+1);
            ans.push_back(mpp[x-arr[i]]+1);

            return ans;
        }
        mpp[arr[i]] = i;
    }

    return {-1};
}

int main(){
    int n, x;
    cin>>n>>x;

    vector<int> arr(n);
    for(auto &it: arr) cin>>it;


    vector<int> ans = sumOfTwoValues(n, arr, x);
    if(ans[0]==-1) cout<<"IMPOSSIBLE"<<'\n';
    else{
        sort(ans.begin(), ans.end());
        for(auto it: ans) cout<<it<<" ";
    }
    cout<<'\n';

    return 0;
}