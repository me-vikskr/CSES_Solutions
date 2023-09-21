#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n - 1, 0);
    for (int i = 0; i < n - 1; i++)
        cin >> arr[i];

    sort(arr.begin(), arr.end());
    bool printed = false;
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] != i + 1)
        {
            cout << i + 1;
            printed = true;
            break;
        }
    }

    if (!printed)
        cout << n << '\n';

    return 0;
}