#include<bits/stdc++.h>
using namespace std;

int number_Of_Movies_Can_Watch(vector<pair<int, int>>& movie, int n){
    sort(movie.begin(), movie.end());

    int cnt = 1;
    int end = movie[0].first;
    for(int i=1; i<n; i++){
        if(movie[i].second >= end){
            end = movie[i].first;
            cnt++;
        }
    }

    return cnt;
}

int main(){
    int n;
    cin>>n;

    vector<pair<int, int>> movie;
    for(int i=0; i<n; i++){
        int start, end;
        cin>>start>>end;

        movie.push_back({end, start});
    }

    cout<<number_Of_Movies_Can_Watch(movie, n)<<'\n';

    return 0;
}