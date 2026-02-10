#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:


    so the game is decided on the basis of when they are row to each other

    alice
    bob

    this is where whoever has the turn is going to win..

    now if the turn is going to be of opp then why would the player go there.

    they would rather take tie than losing..

    now that is the case

    so we need to find the op whether they cane escape or not

    if yes then its tie

    else it is whoever had the chance at the adj..

    how do we find the chance person..

    if dist is even then bob has chance else

    alice..

    now we know who has the chance..

    now we check whether op can run..

    so they will run in  diagonal op to opponent..

    and winner is going to run in diagonal towards the opponent..



*/
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {

        int n, m, a1, a2, b1, b2;
        cin >> n >> m >> a1 >> a2 >> b1 >> b2;

        if (a1 >= b1)
        {
            cout << "Draw" << endl;
            continue;
        }
        int dist = abs(a1 - b1);
        // bob has chance..
        if ((dist % 2) == 0)
        {
            int row_meet = b1 - (dist / 2);
            int dist_left = row_meet - a1;
            int dist_for_bob = b1 - row_meet;

            // now let alice run left and right both..
            int left_a2 = a2 - dist_left;
            left_a2 = max(left_a2, 1LL);
            int right_a2 = a2 + dist_left;
            right_a2 = min(right_a2, m);

            int left_b2 = b2 - dist_for_bob;
            left_b2 = max(left_b2, 1LL);
            int right_b2 = b2 + dist_for_bob;
            right_b2 = min(right_b2, m);

            if ((left_b2 <= left_a2) && (right_b2 >= right_a2))
            {
                cout << "Bob" << endl;
            }
            else
                cout << "Draw" << endl;
        }
        // alice has chance..
        else
        {
            int row_meet = (dist + 1) / 2 + a1;

            int dist_left = b1 - row_meet;
            int dist_for_alice = row_meet - a1;

            int left_a2 = a2 - dist_for_alice;
            left_a2 = max(left_a2, 1LL);
            int right_a2 = a2 + dist_for_alice;
            right_a2 = min(right_a2, m);

            int left_b2 = b2 - dist_left;
            left_b2 = max(left_b2, 1LL);
            int right_b2 = b2 + dist_left;

            right_b2 = min(right_b2, m);

            // cout << row_meet << endl;
            // cout << left_a2 << ":" << left_b2 << endl;
            // cout << right_a2 << ":" << right_b2 << endl;

            if ((left_a2 <= left_b2) && (right_a2 >= right_b2))
            {
                cout << "Alice" << endl;
            }
            else
                cout << "Draw" << endl;
        }
    }
    return 0;
}
