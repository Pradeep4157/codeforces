#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
    101
   1010
   1111
   50
    5
   3333
   3300
   33
   3030
    303
   330
   33

   589
    490
    +49
    539
    000
    450
     45
    495
   5555
   55->5500+55=5555


   333
   300
     3

     303
   311

   THERE  WILL BE +VE NUMBER OF ZEROES
   -> EITHER ONE ZERO/TWO/THREE/..N-1
   N>=11
   X0
   +X
   N=524
   ZEROES=1
   100
    524-10=514
    10->99
    500
    12?
    0
    1->1
    10
     1
    11
    BINARY SEARCH??
*/
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
        int n = stoll(s);
        set<int> st;
        int size = s.size();
        for (int zeroes = 1; zeroes <= size; zeroes++)
        {
            string curr;
            int index = size - 1;
            for (int i = 0; i < zeroes; i++)
            {
                curr += s[index];
                index--;
            }
            cout << curr << endl;
        }
    }
    return 0;
}
