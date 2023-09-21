#include<bits/stdc++.h>
using namespace std;

vector<int> solution(vector<int>& prices, int n, vector<int>& maxPrices, int m){
    multiset<int> tickets;
    for(int i: prices) tickets.insert(i);

    vector<int> ans;
    for(auto maxPrice: maxPrices){
        auto ub = tickets.upper_bound(maxPrice);
        if(ub==tickets.begin()){
            ans.push_back(-1);
        }
        else{
            ub--;
            ans.push_back(*ub);
            tickets.erase(ub);
        }
    }

    return ans;
}

int main(){
    int n, m;
    cin>>n>>m;

    vector<int> prices(n, 0);
    for(int &price: prices) cin>>price;

    vector<int> maxPrices(m, 0);
    for(int &maxPrice: maxPrices) cin>>maxPrice;

    vector<int> ans = solution(prices, n, maxPrices, m);
    for(auto it: ans){
        cout<<it<<'\n';
    }

    return 0;
}