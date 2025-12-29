#include <bits/stdc++.h>
using namespace std;
bool check(int k, vector<int> &arr, vector<int> &b, vector<int> &diff, int minsum)
{
    for (auto a : diff)
    {
        int first = arr[a];
        int second = b[a];
        if (first > second)
            swap(first, second);
        int forward = second - first;
        int backward = 9 - forward;
        if (forward > backward)
            swap(forward, backward);
        int newminsum = minsum - forward;
        int newk = k - backward;
        if (newk >= newminsum && (newk - newminsum) % 2 == 0)
            return true;
    }
    return false;
}
int main()
{
    // your code goes here
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        int K = k;
        vector<int> arr(n);
        vector<int> b(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        for (int i = 0; i < n; i++)
            cin >> b[i];
        vector<int> diff;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] != b[i])
                diff.push_back(i);
        }
        if (diff.empty())
        {
            if (k < 9)
            {
                cout << "No" << endl;
                continue;
            }
            else
            {
                int rem = k % 9;
                if (rem & 1)
                {
                    cout << "No" << endl;
                    continue;
                }
                else
                {
                    cout << "Yes" << endl;
                    continue;
                }
            }
        }
        int minsum = 0;
        bool possible = true;
        for (auto a : diff)
        {
            int first = arr[a];
            int second = b[a];
            if (first > second)
                swap(first, second);
            int forward = second - first;
            int backward = 9 - forward;
            int use = min(forward, backward);
            minsum += use;
            if (k < use)
            {
                possible = false;
                break;
            }
            k -= use;
        }

        if (k % 2 && k < 9)
        {
            possible = check(K, arr, b, diff, minsum);
        }
        if (possible)
        {
            cout << "Yes" << endl;
        }
        else
            cout << "No" << endl;
    }
}
