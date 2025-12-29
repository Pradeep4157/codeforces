#include <bits/stdc++.h>
#define ll int64_t
using namespace std;
bool isvowel(char a)
{
    if (a == 'a' || a == 'e' || a == 'i' || a == 'u' || a == 'o' || a == 'A' || a == 'E' || a == 'I' || a == 'U' || a == 'O')
        return 1;
    else
        return 0;
}
ll recursion(string s)
{
    if (s.size() == 1)
    {
        if (isvowel(s[0]))
        {
            return 1;
        }
        else
            return 0;
    }
    return isvowel(s[0]) + recursion(s.substr(1));
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    getline(cin, s);

    cout << recursion(s) << endl;
    return 0;
}
