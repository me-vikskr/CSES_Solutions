#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long
#define pb push_back
#define loop(i, a, b) for(int i=a; i<b; i++)

// TC: O(log(n))
ll power2(ll x, ll n){
    if(n==0) return 1;
    if(n==1) return x;

    if(n%2==0){
        return ((power2(x, n/2)%mod)*(power2(x, n/2)%mod))%mod;
    }
    return (x*(power2(x, (n-1)/2)%mod)*(power2(x, (n-1)/2)%mod))%mod;
}

// TC: O(n)
ll power(ll x, ll n){
    ll ans = 1;
    for(ll i=1; i<=n; i++){
        ans = ((ans%mod)*(x%mod))%mod;
    }

    return ans;
}

int main(){
    ll n;
    cin>>n;

    cout<<power2(2, n)<<'\n';

    return 0;
}