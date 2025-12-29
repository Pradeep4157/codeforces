#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:

    now ai ranges from 1.. 1e9 ..

    N<=1e4..

    so to decode..

        we can decode on the digits..

        and to separate the numbers to represent

        a , we can use something like z or a ..

        lets say we use z ..

        now for all the numbers in the array

        we start from the end ..

        every digit is represents from a.. j

        a - > 1
        b - > 2
        ..

        j - > 0

        now in encoding we get all digits

        equivalent char..

        and reverse it so that its easier to decode..

        we push this string along with 'z' at the end..


        DECODING:
            we use stringstream to get string till we find a z..

            and then with current string..

            we keep a number = 0 and keep multiplying by 10 and adding the digit..


    SO it exceeds the string size it is like 109999 it should be <=1e5
    110000

    so if for digit i am representing a char  then i cant use a char to denote space 
    



*/
map<int, char> encoding;
map<char, int> decoding;
string encode(vector<int> &arr, int n)
{
    string res;
    for (int i = 0; i < n; i++)
    {

        int curr = arr[i];
        string temp;
        while (curr)
        {
            int last = curr % 10;
            curr /= 10;
            temp += encoding[last];
        }
        reverse(temp.begin(), temp.end());
        if (i != n - 1)
            temp += 'z';
        res += temp;
    }
    return res;
}
vector<int> decode(string &s)
{
    vector<int> res;
    stringstream ss(s);
    string token;
    while (getline(ss, token, 'z'))
    {
        if (!token.empty())
        {
            int number = 0;
            for (auto a : token)
            {
                number = (number * 10) + decoding[a];
            }
            res.push_back(number);
        }
    }
    return res;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // encoding map creation..
    encoding[0] = 'j';
    decoding['j'] = 0;
    for (int i = 1; i <= 9; i++)
    {
        encoding[i] = (i - 1 + 'a');
        decoding[i - 1 + 'a'] = i;
    }
    // for (auto a : decoding)
    //     cout << a.first << ":" << a.second << endl;
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
        string s = encode(arr, n);
        cout << s << endl;
    }
    else
    {
        // now we decode..
        string s;
        cin >> s;
        vector<int> res = decode(s);
        cout << res.size() << endl;
        for (auto a : res)
            cout << a << " ";
        cout << endl;
    }
    return 0;
}
