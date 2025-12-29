#include <bits/stdc++.h>
using namespace std;
vector<vector<char>> rotate(vector<vector<char>> arr)
{
    int n = arr.size();
    vector<vector<char>> res(n, vector<char>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            char curr = arr[i][j];
            int newi = n - j - 1;
            int newj = n - i - 1;
            res[j][n - 1 - i] = arr[i][j];
        }
    }
    return res;
}
int find(vector<vector<char>> first, vector<vector<char>> second)
{
    int res = 0;
    int n = first.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (first[i][j] != second[i][j])
                res++;
        }
    }
    return res;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<vector<char>> arr(n, vector<char>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cin >> arr[i][j];
    }
    vector<vector<char>> t(n, vector<char>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cin >> t[i][j];
    }
    vector<vector<char>> first = rotate(arr);
    vector<vector<char>> second = rotate(first);
    vector<vector<char>> third = rotate(second);
    int res = find(arr, t);
    res = min(res, find(first, t) + 1);
    res = min(res, find(second, t) + 2);
    res = min(res, find(third, t) + 3);
    cout << res << endl;
    return 0;
}
