#include <bits/stdc++.h>
#define int long long
using namespace std;
bool positive(vector<int> pos)
{
    int n = pos.size();
    int middle = (n - 1) / 2;
    int first = pos[0];
    sort(pos.begin(), pos.end());
    if (pos[middle] == first)
        return true;
    int index = n - 1;
    for (int i = 0; i < n; i++)
    {
        if (pos[i] == first)
        {
            index = i;
            break;
        }
    }
    if (index > middle)
    {
        int greaterreq = index - middle;
        int negversion = -first;
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            if (pos[i] <= negversion)
                count++;
        }
        if (count >= greaterreq)
            return 1;
        else
            return 0;
    }
    else
    {
        // because the element is positive all the elements on the right are greater
        return true;
    }
}
bool negative(vector<int> neg)
{
    int n = neg.size();
    int middle = (n - 1) / 2;
    int first = neg[0];
    sort(neg.begin(), neg.end());
    if (neg[middle] == first)
        return true;
    int index = n - 1;
    // maybe i might need to  traverse from the back
    for (int i = 0; i < n; i++)
    {
        if (neg[i] == first)
        {
            index = i;
            break;
        }
    }
    if (index > middle)
    {
        return true;
    }
    else
    {
        int posversion = abs(first);
        int count = 0;
        int req = middle - index;
        for (int i = n - 1; i >= 0; i--)
        {
            if (neg[i] < posversion)
                break;
            count++;
        }
        if (count >= req)
            return 1;
        else
            return 0;
    }
}
int_fast32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        int first = arr[0];
        vector<int> neg;
        if (first < 0)
        {
            neg = arr;
            arr[0] = abs(first);
        }
        else
        {
            neg = arr;
            neg[0] = -first;
        }
        if (first == 0)
        {
            if (positive(arr))
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
            continue;
        }
        if (!positive(arr) && !negative(neg))
            cout << "NO" << endl;
        else
            cout << "YES" << endl;
    }

    return 0;
}
