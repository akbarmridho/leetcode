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

    uint64_t numbers[n];

    for (uint64_t i = 0; i < n; i++)
    {
        cin >> numbers[i];
    }

    uint64_t steps = 0;
    uint64_t i = 0;

    if (n == 1)
    {
        cout << 0;
        return 0;
    }

    while (i < n - 1)
    {
        if (numbers[i + 1] < numbers[i])
        {
            steps += numbers[i] - numbers[i + 1];
            numbers[i + 1] = numbers[i];
        }
        i++;
    }

    cout << steps;

    return 0;
}