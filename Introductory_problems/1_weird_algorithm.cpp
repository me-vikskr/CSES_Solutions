#include <bits/stdc++.h>
using namespace std;

void solve()
{
    long long n;
    cin >> n;

    vector<long long> ans;
    ans.push_back(n);

    while (n != 1)
    {
        if (n % 2 == 0)
            n /= 2;
        else
            n = n * 3 + 1;

        ans.push_back(n);
    }

    for (auto it : ans)
        cout << it << " ";
    cout << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin>>t;
    while (t--)
    {
        solve();
    }
}