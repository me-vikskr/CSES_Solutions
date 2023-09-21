#include<bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define ll long long
#define pb push_back
#define loop(i, a, b) for(int i=a; i<b; i++)

void solve(int ind, string& s, int n, set<string>& ans){
    if(ind==n-1){
        ans.insert(s);
        return;
    }

    for(int i=ind; i<n; i++){
        swap(s[ind], s[i]);
        solve(ind+1, s, n, ans);
        swap(s[ind], s[i]);
    }
}

int main(){
    string s;
    cin>>s;

    int n = s.size();
    set<string> ans;
    solve(0, s, n, ans);
    cout<<ans.size()<<'\n';

    for(auto it: ans){
        cout<<it<<'\n';
    }

    return 0;
}