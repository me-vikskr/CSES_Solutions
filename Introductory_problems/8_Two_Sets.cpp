#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> solution(int n, int target){
    if(n==3){
        return {{1,2},{3}};
    }
    if(n==4){
        return {{1,4},{2,3}};
    }

    bool even = n%2==0;

    vector<vector<int>> ans;
    vector<int> ans1;
    vector<int> ans2;
    if(even){
        int i=1, j=n;
        bool flag = true;
        while(i<j){
            if(flag){
                ans1.push_back(i++);
                ans1.push_back(j--);
                flag = !flag;
            }
            else{
                ans2.push_back(i++);
                ans2.push_back(j--);
                flag = !flag;
            }
        }

        ans.push_back(ans1);
        ans.push_back(ans2);
    }
    else{
        int i=1;
        bool flag = true;
        while(i<n-1){
            if(flag){
                ans1.push_back(i++);
                ans1.push_back(i++);
                flag = !flag;
            }
            else{
                ans2.push_back(i++);
                ans2.push_back(i++);
                flag = !flag;
            }
        }
        ans2.push_back(n);

        ans.push_back(ans1);
        ans.push_back(ans2);
    }

    return ans;
}

int main(){
    int n;
    cin>>n;

    long long sum = (long)(n)*(long)(n+1)/2;
    if(sum%2!=0) cout<<"NO"<<'\n';
    else{
        cout<<"YES"<<'\n';
        vector<vector<int>> ans = solution(n, sum/2);
        
        cout<<ans[0].size()<<'\n';
        for(auto it: ans[0]) cout<<it<<" ";
        cout<<'\n';
        
        cout<<ans[1].size()<<'\n';
        for(auto it: ans[1]) cout<<it<<" ";
        cout<<'\n';
    }

    return 0;
}