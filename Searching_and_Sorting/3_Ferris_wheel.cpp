#include<bits/stdc++.h>
using namespace std;

int minNumOfGondolas(vector<int>& weights, int n, int x){
    sort(weights.begin(), weights.end());

    int ans = 0;
    int i=0, j=n-1;
    while(i<=j){
        if(i==j){
            ans++;
            break;
        }

        if(weights[i]+weights[j] <= x){
            i++, j--;
            ans++;
        }
        else{
            ans++;
            j--;
        }
    }

    return ans;
}

int main(){
    int n, x;
    cin>>n>>x;

    vector<int> weights(n, 0);
    for(auto &it: weights) cin>>it;

    cout<<minNumOfGondolas(weights, n, x)<<'\n';

    return 0;
}