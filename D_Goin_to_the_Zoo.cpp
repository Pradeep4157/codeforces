#include <bits/stdc++.h>
using namespace std;
int n, m;
bool done(vector<int> &count)
{
    for (auto a : count)
        if (a < 2)
            return false;
    return true;
}
vector<int> increase(vector<int> prev, int inc, vector<vector<int>> &animals, int zoonumber)
{
    vector<int> res = prev;
    for (int j = 0; j < m; j++)
    {
        if (animals[zoonumber][j] > 0)
            res[j] += inc;
    }
    return res;
}
int recursion(int start, vector<int> &cost, vector<vector<int>> &animals, vector<int> count)
{
    if (start == n)
    {
        if (done(count))
            return 0;
        else
            return 1e9;
    }
    if (done(count))
        return 0;
    // visit this zoo 0 times
    int res1 = recursion(start + 1, cost, animals, count);
    // visit this zoo 1 times
    vector<int> newcount = increase(count, 1, animals, start);
    int res2 = recursion(start + 1, cost, animals, newcount) + cost[start];
    // visit this zoo 2 times
    vector<int> newnewcount = increase(count, 2, animals, start);
    int res3 = recursion(start + 1, cost, animals, newnewcount) + (cost[start] * 2);
    return min({res1, res2, res3});
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    vector<int> cost(n);
    for (int i = 0; i < n; i++)
        cin >> cost[i];
    vector<vector<int>> animals(n, vector<int>(m, 0));
    for (int i = 0; i < m; i++)
    {
        int type = i;
        int k;
        cin >> k;
        for (int j = 0; j < k; j++)
        {
            int zoo;
            cin >> zoo;
            zoo--;
            animals[zoo][i]++;
        }
    }

    vector<int> count(m, 0);
    int res = recursion(0, cost, animals, count);
    cout << res << endl;
    return 0;
}
