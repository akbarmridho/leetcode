#include <bits/stdc++.h>
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    /**
     * Sn = n(n+1)/2 = 66
     * 1 2 3 4 5 6 7 8 9 10 11
     *
     * LOOP 1
     *
     * HALF SUM = 33
     * SET 1
     * sum 0 max el 11 => sum 11 max el 10
     * sum 11 max el 10 remaining sum = 22 => sum 21 max el 9
     * sum 21 max el 9 remaining 11 =>
     */

    uint64_t n;
    cin >> n;

    uint64_t sum = n * (n + 1) / 2;

    if (sum % 2 != 0)
    {
        cout << "NO\n";
        return 0;
    }

    vector<uint64_t> set1, set2;
    vector<bool> visited(n, false);

    uint64_t half_sum = sum / 2;

    uint64_t s1_sum = 0;
    uint64_t max_element = n;

    while (s1_sum < half_sum)
    {
        uint64_t remaining_sum = half_sum - s1_sum;

        if (remaining_sum > max_element)
        {
            set1.push_back(max_element);
            s1_sum += max_element;
            visited[max_element - 1] = true;
            max_element--;
        }
        else
        {
            set1.push_back(remaining_sum);
            s1_sum += remaining_sum;
            visited[remaining_sum - 1] = true;
        }
    }

    for (uint64_t i = 0; i < visited.size(); i++)
    {
        if (!visited[i])
        {
            set2.push_back(i + 1);
        }
    }

    if (!set1.empty())
    {
        cout << "YES\n";

        cout << set1.size() << "\n";

        for (auto val : set1)
        {
            cout << val << " ";
        }

        cout << "\n";
    }

    if (!set2.empty())
    {
        cout << set2.size() << "\n";

        for (auto val : set2)
        {
            cout << val << " ";
        }

        cout << "\n";
    }

    return 0;
}