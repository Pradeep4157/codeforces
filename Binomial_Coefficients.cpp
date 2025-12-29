#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:

    so we have to calc ncr for m numbers so for each we can precompute factorial and
praactorial on the go since it will take logn time

    else we can precompute inverse factorial as well , so we will implement both

    the methods

    so the n+tlogn method worked :) , it should have

    now method  2 where we are going to implement it using precomputing inverse factorial

    as well so the overall time complexity will reduct from n + tlogn -> n + t

*/
int N = 1e6 + 5;
vector<int> factorial;
vector<int> inversefactorial;
const int mod = (int)(1e9 + 7);
int binpow(int a, int b)
{
    if (b == 0)
        return 1;
    else if (b & 1)
        return a * binpow(a, b - 1) % mod;
    else
    {
        int temp = binpow(a, b >>= 1);
        return temp * temp % mod;
    }
}
int inverse(int a)
{
    return binpow(a, mod - 2);
}
void precompute()
{
    inversefactorial.resize(N + 1);
    factorial.resize(N + 1);
    factorial[0] = 1;
    for (int i = 1; i <= N; i++)
        factorial[i] = i * factorial[i - 1] % mod;

    //  precomputing inverses
    inversefactorial[N] = inverse(factorial[N]);
    for (int i = N - 1; i >= 0; i--)
    {
        inversefactorial[i] = inversefactorial[i + 1] * (i + 1) % mod;
    }
}

int ncr(int n, int r)
{
    int numerator = factorial[n];
    int denominator = inversefactorial[r] * inversefactorial[n - r] % mod;
    return numerator * denominator % mod;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    precompute();
    int t;
    cin >> t;
    while (t--)
    {
        int n, r;
        cin >> n >> r;
        cout << ncr(n, r) << endl;
    }
    return 0;
}
