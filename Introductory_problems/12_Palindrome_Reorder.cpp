#include<bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define ll long long
#define pb push_back
#define loop(i, a, b) for(int i=a; i<b; i++)

bool isPossible(string& s, vector<int>& mpp){
    for(char ch: s){
        mpp[ch-'A']++;
    }

    int odd = 0;
    for(auto it: mpp){
        if(it%2 != 0) odd++;
    }

    if(odd<=1) return true;
    return false;
}

string palindrome(string& s, vector<int>& mpp){
    string left = "";
    int midCnt = 0;
    char middle;
    string mid = "";
    string right = "";

    int i=0;
    for(int i=0; i<26; i++){
        int cnt = mpp[i];
        if(cnt%2!=0){
            middle = (i+'A');
            midCnt = mpp[i];
            continue;
        }

        cnt /= 2;
        while(cnt--){
            left += (i+'A');
        }
    }

    //mid
    while(midCnt--){
        mid += (middle);
    }

    right = left;
    reverse(right.begin(), right.end());

    string ans = left + mid + right;

    return ans;
}

int main(){
    string s;
    cin>>s;

    vector<int> mpp(26, 0);
    bool check = isPossible(s, mpp);
    if(!check){
        cout<<"NO SOLUTION"<<'\n';
    }
    else{
        string ans = palindrome(s, mpp);
        cout<<ans<<'\n';
    }

    return 0;
}