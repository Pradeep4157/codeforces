#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:
    IF POSSIBLE:
        ALL THE ELEMENTS=MIN ELEMENT OF THE ARRAY
    ARR[I]-X*K=MINELE
    (ARR[I]-MINELE)%K==0

*/
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int minele = *min_element(arr.begin(), arr.end());
    int res = 0;
    bool ok = 1;
    for (int i = 0; i < n; i++)
    {
        int rem = (arr[i] - minele) % k;
        if (rem)
        {
            ok = false;
            break;
        }
        res += (arr[i] - minele) / k;
    }
    if (ok == false)
        cout << -1 << endl;
    else
        cout << res << endl;
    return 0;
}
