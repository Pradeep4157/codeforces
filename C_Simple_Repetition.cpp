#include <bits/stdc++.h>
#define ll int64_t
using namespace std;
bool isPrime(int n)
{
    // this is because 0 and 1 are  not prime number
    if (n <= 1)
        return false;
    // this is because 2 and 3 are prime numbers;
    if (n <= 3)
        return true;
    // removing numbers that are divisible by 2 and 3
    if (n % 2 == 0 || n % 3 == 0)
        return false;
    for (int i = 5; i * i <= n; i += 6)
    {
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    }
    return true;
}
string isprime(int x, int k)
{
    if (k > 1 && x > 1)
    {
        return "NO";
    }
    else
    {
        string res = to_string(x);
        string curr = to_string(x);
        while (k > 1)
        {
            res += curr;
            k--;
        }
        int y = stoi(res);
        if (isPrime(y))
        {
            return "YES";
        }
        else
            return "NO";
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        cout << isprime(n, k) << endl;
    }
    return 0;
}
