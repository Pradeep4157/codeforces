#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:
    SO THE MAX DIFF=MAX_ELE-MIN_ELE
    TOTAL WAYS=FREQ(MIN_ELE)*FREQ[MAX_ELE]

*/
const long long mod = 1000000007LL;

int factorial(int n)
{
    int res = 0LL;
    for (int i = 1LL; i <= n; i++)
    {
        res += (i) % mod;
    }
    return res;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    map<int, int> mp;
    for (auto a : arr)
        mp[a]++;
    int maxi = *max_element(arr.begin(), arr.end());
    int mini = *min_element(arr.begin(), arr.end());
    cout << maxi - mini << " " << ((maxi == mini) ? (factorial(mp[maxi] - 1)) : mp[maxi] * mp[mini]) << endl;
    return 0;
}
