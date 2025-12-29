#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:
    so i have a prod will coolness of 1 ,

    after n days its coolness should be a and after 2n days its coolness should be b

    i can multiply with whatever i want

    we will just make it b at 2n day

*/
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

#ifndef ONLINE_JUDGE
    freopen("final_product_chapter_1_input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t;
    cin >> t;
    int index = 1;
    while (t--)
    {
        int n, a, b;
        cin >> n >> a >> b;

        cout << "Case #" << index++ << ": ";
        for (int i = 0; i < 2 * n - 1; i++)
            cout << 1 << " ";
        cout << b << endl;
    }
    return 0;
}
