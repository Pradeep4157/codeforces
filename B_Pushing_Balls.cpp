#include <bits/stdc++.h>
#define ll int64_t
using namespace std;
bool possi(int i, int j, vector<vector<char>> &arr)
{
    bool res = false;
    int dupi = i;
    while (dupi >= 0 && arr[dupi][j] == '1')
        dupi--;
    if (dupi == -1)
        return true;
    dupi = i;
    int dupj = j;
    while (dupj >= 0 && arr[i][dupj] == '1')
        dupj--;
    if (dupj == -1)
        return true;
    else
        return false;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> arr(n, vector<char>(m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> arr[i][j];
            }
        }
        bool possible = 1;
        for (int i = 1; i < n; i++)
        {
            for (int j = 1; j < m; j++)
            {
                if (arr[i][j] == '1' && !possi(i, j, arr))
                {

                    possible = false;
                    break;
                }
            }
            if (possible == false)
                break;
        }
        if (possible)
        {
            cout << "YES" << endl;
        }
        else
            cout << "NO" << endl;
    }
    return 0;
}
