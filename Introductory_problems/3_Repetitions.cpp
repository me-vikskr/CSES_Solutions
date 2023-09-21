#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;

    int n = s.size();

    int maxLen = 0;
    int i = 0, j = 0;
    while (j < n)
    {
        if (s[j] == s[i])
        {
            maxLen = max(maxLen, j - i + 1);
            j++;
        }
        else
        {
            i = j;
        }
    }

    cout << maxLen << '\n';

    return 0;
}