#include <bits/stdc++.h>
#define ll int64_t
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, x, y;
    cin >> n >> x >> y;
    string s;
    cin >> s;
    vector<int> res;
    int currx = 0, curry = 0;
    for (auto a : s)
    {
        if (a == 'S')
        {
            currx++;
        }
        else if (a == 'N')
        {
            currx--;
        }
        else if (a == 'E')
        {
            curry++;
        }
        else
        {
            curry--;
        }
        if (currx == x && curry == y)
            res.push_back(1);
        else
            res.push_back(0);
    }
    for (auto a : res)
        cout << a;
    cout << endl;
    return 0;
}
