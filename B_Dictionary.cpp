#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:

    IT IS SAME QUESTION OF FINDING THE KTH PERMUTATION:
        IT IS REVERSED QUESTION OF FINDING THE
        KTH PERMUTATION:
            K=0;
            THE CURRENT CHAR'S INDEX IN THE ARRAY:
                K+=(INDEX IN THE ARRAY):
                ERASE THAT ELEMENT FROM THE ARRAY:


*/
int find(vector<char> &arr, char c)
{
    int index = -1;
    for (int i = 0; i < 26; i++)
    {
        if (arr[i] == c)
        {
            index = i;
            break;
        }
    }
    arr.erase(arr.begin() + index);

    return index;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        vector<char> arr;
        for (int i = 0; i < 26; i++)
            arr.push_back('a' + i);
        int k = 0;
        for (int i = 0; i < 2; i++)
        {
            int index = find(arr, s[i]);
            if (i == 0)
                index *= 25;
            k += index;
        }
        cout << k + 1 << endl;
    }

    return 0;
}
