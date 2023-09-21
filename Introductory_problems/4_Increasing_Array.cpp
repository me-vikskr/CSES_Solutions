#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    long long cnt = 0;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] < arr[i - 1])
        {
            int diff = arr[i - 1] - arr[i];
            arr[i] += diff;
            cnt += diff;
        }
    }

    cout << cnt << '\n';

    return 0;
}