#include<bits/stdc++.h>
using namespace std;
                   
int getLargestDigit(int n){
    int largestDigit = 0;
    while(n){
        int dig = n%10;
        largestDigit = max(largestDigit, dig);

        n/=10;
    }

    return largestDigit;
}

int solution(int n){
    int cnt = 0;
    while(n){
        n -= getLargestDigit(n);
        cnt++;
    }

    return cnt;
}

int main(){
    int n;
    cin>>n;

    cout<<solution(n)<<'\n';

    return 0;
}