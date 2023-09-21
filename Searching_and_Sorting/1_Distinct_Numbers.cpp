#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    map<int, int> mpp;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        mpp[x]++;
    }

    cout << mpp.size() << '\n';

    return 0;
}