
#include <bits/stdc++.h>
using namespace std;

vector<int> dx = {2, 2, -2, -2, 1, -1, 1, -1};
vector<int> dy = {1, -1, 1, -1, 2, 2, -2, -2};
int n;
bool isvalid(int x, int y)
{
    return (x >= 1 && y >= 1 && x <= n && y <= n);
}
int KnightWalk(int N, int Sx, int Sy, int Fx, int Fy)
{
    // Complete the function
    n = N;
    queue<pair<int, int>> q;
    vector<vector<bool>> vis(n + 1, vector<bool>(n + 1, false));
    int steps = 0;
    int res = -1;
    q.push({Sx, Sy});
    while (!q.empty())
    {
        int SIZE = q.size();
        for (int i = 0; i < SIZE; i++)
        {
            pair<int, int> front = q.front();
            int x = front.first;
            int y = front.second;
            q.pop();
            if (vis[x][y] == 1)
                continue;
            vis[x][y] = 1;

            if (front.first == Fx && front.second == Fy)
            {
                res = steps;
                break;
            }
            // else it will move in whatever directions possible..
            for (int i = 0; i < dx.size(); i++)
            {
                int next_x = x + dx[i];
                int next_y = y + dy[i];
                if (isvalid(next_x, next_y) && !vis[next_x][next_y])
                {
                    q.push({next_x, next_y});
                }
            }
        }
        steps++;
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int test_case;
    cin >> test_case;

    while (test_case--)
    {
        int N, Sx, Sy, Fx, Fy;
        cin >> N >> Sx >> Sy >> Fx >> Fy;

        cout << KnightWalk(N, Sx, Sy, Fx, Fy) << "\n";
    }
}
