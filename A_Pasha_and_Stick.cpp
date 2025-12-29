#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:

        so the brute force way is that i start from i=2 , taking all even numbers
        and for every i, i will have n-i which will also be even and store i/2,(n-i)/2
        in a set only if i/2 != (n-i)/2 and return the size of the set


        but do we need to go all the way till n to find all the possible configurations?

            possibly no because at some point n-i start becoming smaller and it's like mirror
            things start to happen.

            so mostly we just need to go till n/2

            for 20:
                2,18->1,9
                4,16->2,8
                6,14->3,7
                8,12->4,6
                10,10 this is where we stop because this will lead to square
                creation which we dont want
                and after this
                12,8 we are just going back

        and there's an edge case that if n<=2 or if n is odd we cant make any
        rectangle because two sided pairs should be equal and in odd only
        one pair can happen and of size 2 we cant make any because 2 cant
        be separarted into 4 parts
*/
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    if (n <= 2 || (n & 1))
    {
        cout << 0 << endl;
        return 0;
    }
    int res = 0;
    for (int i = 2; i < n / 2; i += 2)
    {
        res++;
    }
    cout << res << endl;
    return 0;
}
