#include <bits/stdc++.h>
#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    uint64_t n;

    cin >> n;

    uint64_t i = 0;
    uint64_t val = 1;

    while (i < n)
    {
        if (val >= UINT64_MAX / 2)
        {
            val = val % (1000000007);
        }

        val *= 2;

        i++;
    }

    cout << val % (1000000007) << "\n";
    return 0;
}