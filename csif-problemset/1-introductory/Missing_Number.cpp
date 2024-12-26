#include <bits/stdc++.h>
#include <cstdio>
#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    uint64_t n;

    cin >> n;

    bool arrs[n] = {false};

    uint64_t val;

    for (uint64_t i = 0; i < n - 1; i++)
    {
        cin >> val;
        arrs[val - 1] = true;
    }

    for (uint64_t i = 0; i < n; i++)
    {
        if (!arrs[i])
        {
            cout << i + 1;
        }
    }

    return 0;
}