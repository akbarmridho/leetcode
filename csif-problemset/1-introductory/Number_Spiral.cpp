#include <bits/stdc++.h>
#include <cstdio>
#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    uint64_t n;
    uint64_t row;
    uint64_t col;

    cin >> n;

    for (uint64_t i = 0; i < n; i++)
    {
        cin >> row;
        cin >> col;

        uint64_t diagonal;

        if (row < col)
        {
            diagonal = col;
        }
        else
        {
            diagonal = row;
        }

        /**
         * Quadratic sequence
         */
        uint64_t diagonal_value = diagonal * diagonal - diagonal + 1;

        if (row == col)
        {
            cout << diagonal_value;
        }
        else
        {
            if (diagonal % 2 == 0)
            {
                if (row < col)
                {
                    // move up
                    cout << (diagonal_value - (col - row));
                }
                else
                {
                    // move left
                    cout << (diagonal_value + (row - col));
                }
            }
            else
            {
                if (row < col)
                {
                    // move up
                    cout << (diagonal_value + (col - row));
                }
                else
                {
                    // move left
                    cout << (diagonal_value - (row - col));
                }
            }
        }

        if (i != n - 1)
        {
            cout << "\n";
        }
    }

    return 0;
}