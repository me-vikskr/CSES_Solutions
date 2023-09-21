#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;

    for(long long k=1; k<=n; k++){
        //(all number of ways to place 2 horse) - (all invalid ways to place 2 horses)
        cout<<(k*k)*(k*k-1)/2 - (4*(k-2)*(k-1))<<'\n';
    }

    return 0;
}