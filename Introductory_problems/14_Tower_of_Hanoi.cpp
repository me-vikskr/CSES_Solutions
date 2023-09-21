#include<bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define ll long long
#define pb push_back

void solve(int a, int b, int c, int n){
    if(n==0) return;

    solve(a, c, b, n-1);
    cout<<a<<" "<<c<<'\n';
    solve(b, a, c, n-1);
}

int main(){
    int n;
    cin>>n;

    //number of steps
    cout<< (1<<n) - 1<<endl;

    solve(1, 2, 3, n);

    return 0;
}