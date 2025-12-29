#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, k;
        cin >> n >> m >> k;

        vector<vector<int>> grid(n, vector<int>(m));
        if (m % k == 0)
        {

            bool reverse = false;
            for (int i = 0; i < n; i++)
            {

                if (reverse == false)
                {
                    int index = 1;
                    reverse = 1;
                    for (int j = 0; j < m; j++)
                    {
                        grid[i][j] = index;
                        index++;
                        if (index > k)
                            index = 1;
                    }
                }
                else
                {
                    int index = 1;
                    reverse = false;
                    grid[i][0] = k;
                    for (int j = 1; j < m; j++)
                    {
                        grid[i][j] = index;
                        index++;
                        if (index > k)
                            index = 1;
                    }
                }
            }
        }
        else
        {
            int index = 1;
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    grid[i][j] = index;
                    index++;
                    if (index > k)
                        index = 1;
                }
            }
        }
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                cout << grid[i][j] << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}
