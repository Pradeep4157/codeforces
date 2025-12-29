#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:

    so either we are going to try to group a's or b's together

    now the block can start and any index

    for every b i can bring all the left ones beside it what is the operations for that


*/
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        vector<int> prefb(n, 0), suffb(n, 0), prefa(n, 0), suffa(n, 0);
        // creating prefix for b

        int prevb = 0;
        int prev = -1;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == 'b')
            {
                if (prev == -1)
                {
                    // this is the first b
                    // nothing to do
                }
                else
                {
                    int dist = i - 1 - prev;
                    dist *= prevb;

                    prefb[i] = dist + prefb[prev];
                }
                prevb++;
                prev = i;
            }
        }
        int preva = 0;
        prev = -1;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == 'a')
            {
                if (prev == -1)
                {
                    // this is the first b
                    // nothing to do
                }
                else
                {
                    int dist = i - 1 - prev;
                    dist *= preva;

                    prefa[i] = dist + prefa[prev];
                }
                preva++;
                prev = i;
            }
        }
        int nextb = 0;
        int next = -1;
        for (int i = n - 1; i >= 0; i--)
        {
            if (s[i] == 'b')
            {
                if (next == -1)
                {
                    // there's no next b
                    // nothing to do here also
                }
                else
                {
                    int dist = next - i - 1;
                    dist *= nextb;
                    suffb[i] = dist + suffb[next];
                }
                nextb++;
                next = i;
            }
        }
        int nexta = 0;
        next = -1;
        for (int i = n - 1; i >= 0; i--)
        {
            if (s[i] == 'a')
            {
                if (next == -1)
                {
                    // there's no next b
                    // nothing to do here also
                }
                else
                {
                    int dist = next - i - 1;
                    dist *= nexta;
                    suffa[i] = dist + suffa[next];
                }
                nexta++;
                next = i;
            }
        }
        // we have every thing

        // choosing all elements here
        int res = LLONG_MAX;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == 'a')
            {
                int curr = 0;
                curr += prefa[i];
                curr += suffa[i];
                res = min(res, curr);
            }
            else
            {
                int curr = prefb[i];
                curr += suffb[i];
                res = min(res, curr);
            }
        }
        cout << res << endl;
    }
    return 0;
}
