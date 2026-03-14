#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:

    a sequence is valid if no of peaks > no of valleys..

    we need to find the no of subsequences of p that are valid..

    atleast 1 peak should be there..

    when we create a lot of peaks valleys are also formed..

    beside them.. not always..

    maybe it is just no  of elements to the left  that are strictly smaller to this * no of elements to the

    right of this element that are strictly smaller..


    no becaues these peaks can be combined together and new subsequences can be formed..

    and if i just do n(n - 1) >> 1 of these indexes, maybe some overalapping might happen..


    also just taking the no of elements that are less than this doesnt guarentee a valid subsequence

    becuase those elements might be forming valleys ..

    also just right*left is also wrong !!

    there are more combinations that can be made ..

    1 10 5 4 5 4

    here for 10 4 on right and 1 left ..

    for this comb which is considered valid :

    1 10 5 4 5 4 is wrong..

    looks like  a dp question where you focus on peak elements..

    and find the no of adj values ..

    its a perm no are not repeating..

    so 1 10 5 4 ...

    i could take any subsequecee..

    it will still cause error..

    among the right and left small 1 len we can always take..

    from 2.. len of right / left side there are cases that will lead to invalid subsequences..




*/
const int mod = 998244353;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    return 0;
}
