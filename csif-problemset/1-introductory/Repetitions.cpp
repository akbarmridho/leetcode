#include <bits/stdc++.h>
#include <cstdio>
#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    char input;
    uint64_t maxlen = 0;
    uint64_t curlen = 0;
    char curchar = 'X'; // sentinel

    // ATGC

    while (cin >> input)
    {
        if (input != curchar)
        {
            if (curlen > maxlen)
            {
                maxlen = curlen;
            }
            curlen = 1;
            curchar = input;
        }
        else
        {
            curlen++;
        }
    }

    if (curlen > maxlen)
    {
        maxlen = curlen;
    }

    cout << maxlen;

    return 0;
}