#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:
THE GAME EITHER ENDS IN ONE MOVE/ O MOVES

LETS SAY THE ARR[I] WHICH ALICE IS EXCHANGING REALLY BIG AT MAX IT CAN
BE 1E9 AND THE OTHER NUMBER THAT GETS SWAPPED IS 1(THIS IS MIN WE CAN HAVE)
SO AFTER ALL THE EXCHANGES LETS SAY THAT EVEN IF THE SIZE OF THE ARRAY
IS 2,
AT THE END OF ALL THE OPERATIONS SINCE 1E100 IS EVEN AT THE END
ARRRAY WILL LOOK LIKE: [1,1E9]: 2*1E100-1E9-1
WHICH IS FAR WORSE THAN JUST 1E9-1

HENCE PROVED THE GAME ALWAYS FINISHES IN 0 OR 1 MOVES

0 MOVES:
    EITHER ALICE DOES NOT WANT ANY OF ITS EVEN INDEXED ARRAY ELEMENTS
    TO BE SWAPPED WITH ANY ODD INDEXED ARRAY ELEMENT

    SO AT THE END OF THE DAY ALL THAT MATTERS IS LEFT MOST OCCURENCE
    OF MIN ELEMENT AND RIGHT MOST OCCURENCE OF MIN ELEMENT AMONG EVEN
    INDEXED ARRAY ELEMENTS AND WE WILL SWAP IT WITH:

    IS THIS TRUE?
        LETS SAY THE ARRAY LOOKS LIKE THIS:[2,....1,100]
        100 IS AT ODD INDEX, 2 AND 1 ARE AT EVEN INDEX, EVEN THOUGH
        1 IS THE MINIMUM, BUT IF WE SWAP 2 WITH 100
        RES INC BY 100+100-2-2+SIZE OF ARRAY-1


        ELSE IF WE CHOOSE 1 TO SWAP WITH 100:
            RES INC BY 100+100-1-1+1

    SO IT IS NOT ALWAYS BENEFICIAL TO SWAP MIN WITH MAX WE HAVE TO ALSO
    CONSIDER THE DISTANCE FACTOR

    THE ONLY THINGS THAT MATTER IS THAT ODD INDEXED ELEMNT>EVEN INDEXED
    ELEMENT AND DISTANCE SHOULD BE MAXIMIZED

    PROCESS:
        BEFORE THIS  WE WILL ALSO MAINTAIN LEFT MOST AND RIGHT MOST
        INDEX OF EVEN INDEXED ARRAY ELEMENTS IN A MAP
        WE CAN MAINTAIN PREFIX AND SUFFIX OF EVEN INDEXED ELEMENTS:


        SUFFIX CREATION:
            SUFFIX[N-1]=ARR[N-1]
            FOR(I=N-2->0):
                SUFFIX[I]=SUFFIX[I+1]
                IF(I IS Odd):
                    INT INDEXOFCURR=MP[SUFFIX[I]].SECOND;
                    INT DIST=INDEXOFCURR-I;
                    INT ACTUALVALUE=DIST+SUFFIX[I];
                    IF(ACTUALVALUE<ARR[I]):
                        SUFFIX[I]=ARR[I]

        SIMILARLY FOR PREFIX CREATION:
            PREFIX[0]=ARR[0];
            FOR(I=1->N):
                PREFIX[I]=PREFIX[I-1]
                IF(I IS odd):
                    INT INDEXOFCURR=MP[PREFIX[I]].FIRST;
                    INT DIST=I-INDEXOFCURR;
                    INT ACTUALVALUE=DIST+PREFIX[I];
                    IF(ACTUALVALUE<ARR[I]):
                        PREFIX[I]=ARR[I]


        NOW AFTER THIS,
            FIRST WE CALC THE BASE RES
            FOR(I=0->N):
                IF(I IS EVEN):
                    RES+=ARR[I]
                ELSE:
                    RES-=ARR[I]
            INT MAXI=RES;
            FOR(I=0->N;I+=2)
                INT BESTLEFT=PREFIX[I];
                INT BESTRIGHT=SUFFIX[I];
                INT CURR1=RES;
                INT CURR2=RES;
                CURR1-=2*ARR[I]
                CURR1+=2*PREFIX[I]
                CURR1+=I-MP[PREFIX[I]].FIRST
                CURR2-=2*ARR[I]
                CURR2+=2*SUFFIX[I]
                CURR2+=MP[SUFFIX[I]].SECOND-I
                MAXI=MAX({MAXI,CURR1,CURR2})

    RETURN MAXI


    1 CAUTION THAT WE NEED TO  TAKE IF THE ARRAY IS ODD WE CAN MAKE SUFFIX[N-1]=ARR[N-1]

    1 more thing which we can do is that if we dont want to swap even indexed element with odd ones then we can swap first element with last even indexed element


    once changed the < -> <= a lot of tc passed:
        so the no affect is wrong?


*/
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        if (n == 1)
        {
            cout << arr[0] << endl;
            continue;
        }
        map<int, pair<int, int>> mp;
        for (int i = 0; i < n; i++)
        {
            if (i & 1)
            {
                if (mp.find(arr[i]) == mp.end())
                {
                    // this is the first time i am seeing this element
                    mp[arr[i]].first = i;
                }
                mp[arr[i]].second = i;
            }
        }

        vector<int> suffix(n, -1), prefix(n, -1);
        int end = n - 1;
        if ((n - 1) % 2 == 0)
            end--;
        suffix[end] = arr[end];
        end--;
        prefix[1] = arr[1];
        for (int i = end; i >= 0; i--)
        {
            suffix[i] = suffix[i + 1];
            if (i & 1)
            {
                int indexofcurr = mp[suffix[i]].second;
                int dist = indexofcurr - i + 1;
                int actualvalue = 2 * suffix[i] + dist;
                if (actualvalue <= 2 * arr[i])
                {
                    suffix[i] = arr[i];
                }
            }
        }
        for (int i = 2; i < n; i++)
        {
            prefix[i] = prefix[i - 1];
            if (i & 1)
            {
                int indexofcurr = mp[prefix[i]].first;
                int dist = i - indexofcurr;
                int actualvalue = 2 * prefix[i] + dist + 1;
                if (actualvalue <= 2 * arr[i])
                {
                    prefix[i] = arr[i];
                }
            }
        }
        int res = 0;
        for (int i = 0; i < n; i++)
        {
            if (i & 1)
            {
                res -= arr[i];
            }
            else
                res += arr[i];
        }
        int maxi = res;
        if (n > 2)
        {
            int endeven = n - 1;
            if (endeven & 1)
                endeven--;
            maxi += endeven;
        }
        for (int i = 0; i < n; i += 2)
        {
            if (i % 2 == 0)
            {
                int bestleft = prefix[i];
                int bestright = suffix[i];
                int curr1 = res;
                int curr2 = res;
                curr1 -= 2 * arr[i];
                curr1 += 2 * prefix[i];
                curr1 += (i - mp[prefix[i]].first);
                curr2 -= 2 * arr[i];
                curr2 += 2 * suffix[i];
                curr2 += (mp[suffix[i]].second - i);
                maxi = max({maxi, curr1, curr2});
            }
        }
        cout << maxi << endl;
    }
    return 0;
}
