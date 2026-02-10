#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:

    so first we will keep adding just x boys and y girls after all this..

    there would be some a boys and b girls left..

    rem is n - x - y..

    and no of rooms used  = min(b/x,g/y)

    and rem is the rem

    if rem can be fit in these then ok else nope..

    now still there are some more rooms that are not fully used..

    we can reduce here if a whole room can be shifted to another room..

    we might still be able to put more than 2 classes in  a single class..

    is it how many class can i put in a single class, then there is some

    rem..

    this rem if i can fit in those classes then yes but i might still remove

    some classes from them and fit these in them..

    should i bs when possible..

    so impossible chck is simple i will allow only x and y in each

    then rem if they can fit then yes else no..


*/
int b, g, x, y, n;
bool possible(int mid)
{
    // first we fill x and y in each class..
    int B = b;
    int G = g;
    B -= x * mid;
    G -= y * mid;
    int rem_pos = mid * (n - x - y);
    int rem_child = B + G;
    rem_child -= rem_pos;
    if (rem_child > 0)
        return false;
    else
        return true;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {

        cin >> b >> g >> x >> y >> n;
        bool ok = 1;

        int boy_classes = b / x;
        int girl_classes = g / y;
        int curr_class = min(boy_classes, girl_classes);
        int boys_rem = b - curr_class * x;
        int girls_rem = g - curr_class * y;
        int rem_place = (n - x - y) * curr_class;
        if (rem_place < (boys_rem + girls_rem))
        {
            ok = false;
        }
        if (ok == false)
        {
            cout << -1 << endl;
            continue;
        }
        // now it is possible..
        int low = 1, high = curr_class;
        int res = high;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (possible(mid))
            {
                res = mid;
                high = mid - 1;
            }
            else
                low = mid + 1;
        }
        cout << res << endl;
    }
    return 0;
}
