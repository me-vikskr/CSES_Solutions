#include<bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define ll long long
#define pb push_back
#define loop(i, a, b) for(int i=a; i<b; i++)

/* 
    Let X moves for 1 removal and Y moves for 2 removal
    a-2X-Y = 0;
    b-2Y-X = 0;
    => a = 2X+Y
    => b = X+2Y

    => a+b = 3(X+Y) => multiple of three

    and, max(a,b) = 2*min(a,b);
*/

int main(){
    int t;
    cin>>t;

    while(t--){
        ll a, b;
        cin>>a>>b;

        if(max(a, b) > 2*min(a, b)){
            cout<<"NO"<<'\n';
        }
        else{
            ll sum = a+b;
            if(sum%3==0) cout<<"YES"<<'\n';
            else cout<<"NO"<<'\n';
        }
    }

    return 0;
}