#include <bits/stdc++.h>
#include <cstdio>
#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int64_t n;

    cin >> n;

    if (n == 1)
    {
        cout << "1";
        return 0;
    }

    if (n == 2 || n == 3)
    {
        cout << "NO SOLUTION";
        return 0;
    }

    int64_t even_start = 2;
    int64_t odd_start = 1;
    int64_t even_end = 2;
    int64_t odd_end = 1;

    if (n % 2 == 0)
    {
        even_end = n;
        odd_end = n - 1;
    }
    else
    {
        even_end = n - 1;
        odd_end = n;
    }

    while (even_start <= even_end)
    {
        cout << even_start << " ";
        even_start += 2;
    }

    while (odd_start <= odd_end)
    {
        if (odd_start == odd_end)
        {
            cout << odd_start;
        }
        else
        {
            cout << odd_start << " ";
        }

        odd_start += 2;
    }

    return 0;
}