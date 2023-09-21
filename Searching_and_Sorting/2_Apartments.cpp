#include<bits/stdc++.h>
using namespace std;

int numOfApp(vector<int>& req, vector<int>& apart, int k){
    int n = req.size(), m = apart.size();

    sort(apart.begin(), apart.end());
    sort(req.begin(), req.end());
    
    int i=0, j=0, cnt=0;
    while(i<n && j<m){
        if(apart[j]<=(req[i]+k) && apart[j]>=(req[i]-k)){
            cnt++;
            j++;
            i++;
        }
        else if(apart[j]>(req[i]+k)){
            i++;
        }
        else if(apart[j]<(req[i]-k)){
            j++;
        }
    }

    return cnt;
}

int main(){
    int n, m, k;
    cin>>n>>m>>k;

    vector<int> req(n, 0);
    for(int i=0; i<n; i++) cin>>req[i];

    vector<int> apart(m, 0);
    for(int i=0; i<m; i++) cin>>apart[i];

    cout<<numOfApp(req, apart, k)<<'\n';

    return 0;
}