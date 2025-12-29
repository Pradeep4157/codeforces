#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:

    since ai is from 1 ,26 the encoding is straight forward just

    encode 1 as a , 2 as b ..  26 as z


*/
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    map<int, char> encoding;
    map<char, int> decoding;
    for (int i = 1; i <= 26; i++)
    {
        encoding[i] = (i - 1 + 'a');
        decoding[i - 1 + 'a'] = i;
    }

    string s;
    cin >> s;

    if (s == "first")
    {
        // do the encoding ..
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        string s;
        for (auto a : arr)
        {
            s += encoding[a];
        }
        cout << s << endl;
    }
    else
    {
        // now we decode..
        string s;
        cin >> s;
        vector<int> arr;
        for (auto a : s)
        {
            arr.push_back(decoding[a]);
        }
        cout << arr.size() << endl;
        for (auto a : arr)
            cout << a << " ";
        cout << endl;
    }
    return 0;
}
