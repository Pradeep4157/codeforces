#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:

        n*n grid, some are black..

        i should paint white->black..

        1) at least one should be black..

        2) all should be connected ..

        3) no 3 consec vertically / horizontally ..

        we cant paint black-> white ..


        so if already black 3 consec..
            ans is false ..

        and in the same row also if there are more than 2 ..

        then also its not possible..

        also int he same column ..

        also the 2 must be connected..


        only nec condtions are that they count of every

        row && column <=2 && they must be connected


        now there is some condition for the disconnected ones...

        now when we are connecting we are obv going to

        connect them vertically ...

            so no one should have 2 vertically ..

            maybe the way we connect them can be bruteforced..


            so how do we bruteforce ..

            so for every cell :
                there are two cases either i make it black / it was already a black cell..


                if i made it black ..

                    && any other cell apart from parent is black move to that cell && do  connected comp--
                    if it is black and there is any other cell apart from parent that is black then we have connnected

                    two comp ..
                        move to that cell ..

            now this is a common part :
                whether painted black.. or already black..

                    we try painting its neighbors..

            if already black move to that cell or try painting some white cells..





*/
int n;
vector<int> dx = {-1, 1, 0, 0};
vector<int> dy = {0, 0, -1, 1};
bool isvalid(int x, int y)
{
    return (x >= 0 && x < n && y >= 0 && y < n);
}
void dfs(vector<vector<char>> &arr, vector<vector<bool>> &vis, int i, int j)
{
    vis[i][j] = 1;
    for (int z = 0; z < 4; z++)
    {
        int nextx = i + dx[z];
        int nexty = j + dy[z];
        if (isvalid(nextx, nexty) && arr[nextx][nexty] == '#' && !vis[nextx][nexty])
        {
            dfs(arr, vis, nextx, nexty);
        }
    }
}
bool connectedcomp(vector<vector<char>> &arr)
{
    int res = 0;
    map<int, int> mp;
    vector<vector<bool>> vis(n, vector<bool>(n, false));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (!vis[i][j] && arr[i][j] == '#')
            {
                mp[i - j]++;
                if (i != 0 || j != 0)
                    mp[i + j]++;
                if (isvalid(i, j + 1))
                {
                    mp[i + 1 - j]++;
                    mp[i + 1 + j]++;
                }
                res++;
                dfs(arr, vis, i, j);
            }
        }
    }

    if (res == 0)
        return 1;
    bool ok = false;
    for (auto a : mp)
    {

        if (a.second == res)
        {
            ok = 1;
        }
    }
    return ok;
}

bool find(int i, int j, int pari, int parj, bool madeblack, vector<vector<char>> &arr, int comp)
{
    if (comp == 1)
        return 1;
    bool curr = 0;
    // if this is made black && there is somone
    return curr;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {

        cin >> n;
        vector<vector<char>> arr(n, vector<char>(n));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
                cin >> arr[i][j];
        }

        // first check that only 2 per rows && that too connected..
        bool ok = 1;
        for (int i = 0; i < n; i++)
        {
            int currcount = 0;
            int x, y;
            for (int j = 0; j < n; j++)
            {
                if (arr[i][j] == '#')
                {
                    x = i;
                    y = j;
                    currcount++;
                }
            }
            if (currcount > 2)
            {
                ok = false;
                break;
            }
            if (currcount == 2)
            {
                if (arr[x][y - 1] != '#')
                    ok = false;
            }
        }
        // now col check that 2 per column && that too connected..

        for (int j = 0; j < n; j++)
        {
            int currcount = 0;
            int x, y;
            for (int i = 0; i < n; i++)
            {
                if (arr[i][j] == '#')
                {
                    x = i;
                    y = j;
                    currcount++;
                }
            }
            if (currcount > 2)
                ok = false;
            if (currcount == 2)
            {
                if (arr[x - 1][y] != '#')
                    ok = false;
            }
        }

        // now we have comp..

        // now we will try to  connect all of them ..

        if (ok == false)
        {
            cout << "NO" << endl;
            continue;
        }
        ok = connectedcomp(arr);
        if (ok == false)
            cout << "NO" << endl;
        else
            cout << "YES" << endl;
    }
}
