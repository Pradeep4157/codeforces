#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:
    WE WILL MAKE FREQ ARRAY WHERE WE WILL STORE THE FREQUENCY OF THE ARRAY ELEMENTS

    WITH THE HELP OF THIS THE FIRST HOLE WILL TELL US THE MEX OF THE ARRAY
    AFTER THAT WE WILL TRAVERSE THROUGH THE ARRAY AND IF THE ELEMENT> MEX THEN ARRAY
    ELEMENT WILL BE CONVERTED TO MEX AND IF THE ELEMENT IS LESSER THAN MEX
    AND THE ELEMENTS FREQ IS GREATER THAN 1 THEN THAT ELEMENT WILL ALSO BE
    CONVERTED TO MEX

*/
void make(vector<int> &arr)
{
    int n = arr.size();
    vector<int> freq(n + 1);
    for (auto a : arr)
    {
        freq[a]++;
    }
    int mex = n;
    for (int i = 0; i <= n; i++)
    {
        if (freq[i] == 0)
        {
            mex = i;
            break;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > mex)
            arr[i] = mex;
        else
        {
            if (freq[arr[i]] > 1)
                arr[i] = mex;
        }
    }
    return;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        make(arr);
        k--;
        if (k > 0)
        {
            if (k & 1)
                k = 1;
            else
                k = 2;
        }
        while (k)
        {
            k--;
            make(arr);
        }
        int res = accumulate(arr.begin(), arr.end(), 0LL);
        cout << res << endl;
    }
    return 0;
}
