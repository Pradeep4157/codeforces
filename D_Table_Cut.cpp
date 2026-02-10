#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:


we can think of this as every column needs to have one '_'

so among all these rows of this column if i choose to add this '_'

so when i add this _ in this row then the ones that a gets is suffix of

this column till this row and the no of ones that b gets is prefix

till row - 1..

and i also need to merge it with next column and i can merge it

with next column's some row >= this row..

that is suffix dp of next column...

and the transition is going to be

this next dp is not the only factor 

the amount of rows it is below this also affects 

because all the prefix of those rows goes to a and suffix 

of all those rows goes to b...




*/
vector<vector<int>> parent;
vector<vector<int>> dp;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> arr(n, vector<int>(m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
                cin >> arr[i][j];
        }

        int res = recursion()
    }
    return 0;
}
