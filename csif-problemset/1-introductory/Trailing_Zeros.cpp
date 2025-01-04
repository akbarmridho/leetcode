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

    uint64_t result = 0;

    uint64_t divisor = 5;

    while (divisor <= n)
    {
        result += n / divisor;

        divisor *= 5;
    }

    cout << result;

    return 0;
}