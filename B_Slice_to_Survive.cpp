#include <bits/stdc++.h>
#define int long long
using namespace std;
int leftcut(int left, int right, int up, int down, int a, int b)
{
    // rem=right,up,down
    int res = 0;
    int rightportion = right - b + 1;
    int updown = down - up;
    res = updown * rightportion;
    return res;
}
int rightcut(int left, int right, int up, int down, int a, int b)
{
    int leftportion = b - left;
    int updown = down - up;
    int res = updown * leftportion;
    return res;
}
int upcut(int left, int right, int up, int down, int a, int b)
{
    int downportion = down - a + 1;
    int leftright = right - left;
    int res = leftright * downportion;
    return res;
}
int downcut(int left, int right, int up, int down, int a, int b)
{
    int upportion = a - up;
    int leftright = right - left;
    int res = leftright * upportion;
    return res;
}
vector<int> makecentre(int left, int right, int up, int down)
{
    int dist = right - left;
    int mid = (dist) / 2;
    int a = right - mid;
    dist = down - up;
    mid = dist / 2;
    int b = down - mid;
    return {a, b};
}
int find(int left, int right, int up, int down)
{
    int dist = down - up;
    int count = 0;
    while (dist > 1)
    {
        dist = (dist + 1) / 2;
        count++;
    }

    dist = right - left;
    while (dist > 1)
    {
        dist = (dist + 1) / 2;
        count++;
    }
    return count;
}
int_fast32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, a, b;
        cin >> n >> m >> a >> b;
        if (n == 1 && m == 1)
        {
            cout << 0 << endl;
            continue;
        }
        int ansssss;
        int left = 0, right = m, up = 0, down = n;
        int count = INT_MAX;
        int res1 = upcut(left, right, up, down, a, b);
        int res2 = downcut(left, right, up, down, a, b);
        int res3 = rightcut(left, right, up, down, a, b);
        int res4 = leftcut(left, right, up, down, a, b);
        int mini = min({res1, res2, res3, res4});

        if (mini == mini)
        {

            int currcount = find(left, right, a - 1, down);
            count = min(count, currcount + 1);
        }
        if (mini == mini)
        {

            int currcount = find(left, right, up, a);
            count = min(count, currcount + 1);
        }
        if (mini == mini)
        {
            int currcount = find(left, b, up, down);
            count = min(count, currcount + 1);
        }
        if (mini == mini)
        {
            int currcount = find(b - 1, right, up, down);
            count = min(count, currcount + 1);
        }
        cout << count << endl;
    }
    return 0;
}