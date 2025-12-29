#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:

    we can bf all the values since..

        the values range is small ...

            {0,1,32,243}

        so we bf every a value..
            and we check in the set that whether this b value is there or not ..

                if yes ..
                then we mark the global a's,b's and return;



*/
int a, b;
int n;
set<int> st;
void recursion(int i)
{
    if (i > 1500)
        return;
    int curr = (i * i * i * i * i);
    int rem = curr - n;
    if (st.count(rem))
    {
        a = curr;
        b = rem;
        return;
    }
    recursion(i + 1);
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    map<int, int> pos;
    map<int, int> neg;
    for (int i = 0; i <= 1500; i++)
    {
        int curr = (i * i * i * i * i);
        st.insert(curr);
        st.insert(-curr);
        neg[-curr] = -i;
        pos[curr] = i;
    }

    cin >> n;
    recursion(0);

    int first = pos[a];
    int second = -1;
    if (b < 0)
        second = neg[b];
    else
        second = pos[b];
    cout << first << " " << second << endl;
    return 0;
}
