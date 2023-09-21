#include<bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define ll long long
#define pb push_back

ll power(ll a, ll b){
    if(b==0) return 1;

    if(b%2==1){
        return ((a%mod)*(power(a, b-1)%mod))%mod;
    }

    return power((a*a)%mod, b/2)%mod;
}

int main(){
    int n;
    cin>>n;

    while(n--){
        ll a, b;
        cin>>a>>b;

        cout<<power(a, b)<<'\n';
    }

    return 0;
}