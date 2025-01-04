#include <bits/stdc++.h>
#include <cstdio>
#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    /**
     * How to solve this:
     *
     * Count how many ways two knight can be placed in K x K blocks, then subtract it by
     * count how many ways two knight can clashed each other in K x K blocks
     *
     * How many for two knight can be placed in K x K blocks: K^2 C 2 = K^2 * (K^2-1) / 2
     *
     * How many way two knight can be clashed in 2x3 and 3x2 block: 2
     * How many 2x3 and 3x2 block on K x K blocks = (K-1) x (K-2)
     *
     * Total = K^2 * (K^2-1) / 2 - 4 (K-1) x (K-2)
     */

    uint64_t val;

    cin >> val;

    cout << "0\n";

    for (uint64_t i = 2; i <= val; i++)
    {
        cout << i * i * (i * i - 1) / 2 - 4 * (i - 1) * (i - 2) << "\n";
    }

    return 0;
}