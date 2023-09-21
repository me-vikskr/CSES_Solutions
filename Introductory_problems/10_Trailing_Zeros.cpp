#include<bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define ll long long
#define pb push_back
#define loop(i, a, b) for(int i=a; i<b; i++)

int main(){
    int n;
    cin>>n;

    //calculate no. of 5 occurs in n!
    int five = 0, i=1;
    while(n >= (pow(5, i))){
        five += (n/pow(5, i++));
    }

    //calculate no. of 2 occurs in n!
    int two=0;
    i=1;
    while(n >= (pow(2, i))){
        two += (n/pow(2, i++));
    }

    int ans = min(five, two);

    cout<<ans<<'\n';

    return 0;
}