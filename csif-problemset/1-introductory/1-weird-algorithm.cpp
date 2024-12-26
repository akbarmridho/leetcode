#include <bits/stdc++.h>
#include <cstdio>
#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    uint64_t input;

    cin >> input;
    cout << input;

    while (input != 1)
    {
        if (input % 2 == 0)
        {
            input = input / 2;
        }
        else
        {
            input = 3 * input + 1;
        }

        cout << " " << input;
    }

    return 0;
}