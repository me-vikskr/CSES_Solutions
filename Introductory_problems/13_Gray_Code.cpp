#include<bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define ll long long
#define pb push_back

vector<string> generateGrayCode(int n){
    if(n==1){
        return {"0", "1"};
    }

    vector<string> prev = generateGrayCode(n-1);
    vector<string> ans;
    int m = prev.size();
    for(int i=0; i<m; i++){
        ans.pb(prev[i] + "0");
    }
    for(int i=m-1; i>=0; i--){
        ans.pb(prev[i]+"1");
    }
    return ans;
}

int main(){
    int n;
    cin>>n;

    vector<string> ans = generateGrayCode(n);
    for(auto it: ans){
        cout<<it<<'\n';
    }

    return 0;
}