#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:

    we take some permutation and its inverse permutation that is q[p[i]] = i..

    f(a) is sum from 1..n-1 where p[i] < p[i + 1]
    + sum from 1..n - 1 where q[i] >  q[i + 1]

    if this f(a) >= k then this permutation is valid..

    1,2,3
    1,2,3

    in the sorted permutations f(a) == n - 1..


    4,3,2,1
    4,3,2,1

    so for both sorted and reverse sorted f(a)  == n - 1..

    2,4,5,1,3,6
    4,1,5,2,3,6


*/
int find_score(vector<int> &arr, vector<int> &b)
{
    int n = arr.size();
    int res = 0;
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] < arr[i + 1])
        {
            res++;
        }
    }
    for (int i = 0; i < n - 1; i++)
    {
        if (b[i] > b[i + 1])
            res++;
    }
    return res;
}
vector<int> inverse_array(vector<int> &arr)
{
    int n = arr.size();
    vector<int> res(arr.size());
    for (int i = 0; i < n; i++)
    {
        res[arr[i]] = i + 1;
    }
    return res;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 1; i <= n; i++)
    {
        arr[i - 1] = i;
    }
    int count = 0;
    while (count++ < 5)
    {
        vector<int> b = inverse_array(arr);
        int res = find_score(arr, b);
        cout << res << endl;
        if (res >= 6)
        {
            for (auto a : arr)
            {
                cout << a << " ";
            }
            cout << endl;
        }
        next_permutation(arr.begin(), arr.end());
    }

    return 0;
}
